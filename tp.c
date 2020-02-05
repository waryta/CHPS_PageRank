#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void aff();
int main()
{

 aff();
}



void aff()
{
    int v, w, i,j;
    int **T,**R;
    float **Trans,**P,**V;
    float *tab;
    float alpha = 0.85;
    float E =0.000006;
    int k = 0;


    printf("Entrez le nombre de lignes : ");
    scanf("%d", &v);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &w);
    T = calloc(v , sizeof(int*));
	Trans = calloc(v , sizeof(float*));
	P = calloc(v , sizeof(float*));

    R = calloc(v-1 , sizeof(int*));
    tab = calloc(w , sizeof(float));
    V = calloc(2 , sizeof(float*)); //V contient les tableaux des vecteurs x-1 et x0 ( respectivement dans V[0] et V[1] )



    for (i = 0 ; i < v ; i++)
    {
        T[i] = calloc(w, sizeof(int));
		Trans[i] = calloc(w, sizeof(float));
		P[i] = calloc(w, sizeof(float));
        R[i] = calloc(w, sizeof(int));

    }

    for (i = 0 ; i < 2 ; i++)
    {
       V[i] = calloc(w, sizeof(float));

       if (i == 1)
       {
          V[i][1] = 1;
         /* for (j = 0 ; j < w ; j++)
          {
            V[i][j] = 1/w;  je voulais faire comme la prof mais ici ça donne toujours 0.00
          }*/
       }

    }

    printf("Vecteurs x-1 suivi de x0:\n");
    for (i=0; i<2; i++)
    {

      for (j=0; j<w; j++)
      {
        printf("%.2f", V[i][j]);
      }
      printf("\n");
    }

    printf("Tableau donné à l'initialisation:\n");
    for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
         printf("%d", T[i][j]);
     printf("\n");
    }
    for (i=0; i<v; i++)
    for (j=0; j<w; j++)
        {
         printf("Elément[%d][%d] : ",i,j);
         scanf("%d", &T[i][j]);
        }
  /* Affichage du tableau */
 printf("Tableau donné :\n");
 for (i=0; i<v; i++)
   {
     for (j=0; j<w; j++)

         printf("%d", T[i][j]);

     printf("\n");
  }
    printf("cc1");
     /*calcule matrice d'adjancence*/

	for (i=1; i<v; i++)
    {
     for (j=1; j<w; j++)
     {
		 if(T[i][j]!=-1)
		 {
			 R[i-1][T[i][j]]=1;

			printf("\n on rempli le tab %d %d avec %d \n",i-1,T[i][j],R[i-1][T[i][j]]);

		 }
		 else
		 {
			R[i-1][T[i][j]]=0;
			printf("\n on rempli le tab %d %d avec %d \n",i-1,T[i][j],R[i-1][T[i][j]]);

		 }

	 }
   }
	 for (i=0; i<v-1; i++)
    {
     for (j=0; j<w; j++)
     //printf("la mat %d %d est %d \n",i,j,R[i][j]);

     printf("%d", R[i][j]);
     printf("\n");
    }
/*calcul de la transposée*/
    printf("matrice transposée \n");
    for (i=0; i<v-1; i++)
    {
     for (j=0; j<w; j++)
     {
		 Trans[i][j]=R[j][i];
         printf("%.2f", Trans[i][j]);
	 }
     printf("\n");
    }
    int s=0;
    for(j=0;j<w;j++)
    {
		for (i=0; i<v-1; i++)
		{

		 s=s+Trans[i][j];
		 tab[j]=s;
		}
		 printf("la somme est %d \n",s);
		 s=0;

     }
     printf("pour la matrice de probabilité \n");
     for (i=0; i<w; i++)
     {
        printf("%.2f", tab[i]);
		printf("\n");
     }

     int r=0;
	for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
     {
        printf("%.2f", Trans[i][j]/tab[j]);
        P[i][j]=Trans[i][j]/tab[j];
     }
		printf("\n");
    }
 printf("matrice de transition ou de probabilité \n");
     for (i=0; i<w; i++)
     {
		 for (j=0; j<w; j++)
			{
				printf("%.2f", P[i][j]);
			}
				printf("\n");
     }



}



