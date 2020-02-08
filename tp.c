#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>




# define ALPHA 0.85
# define TOLERANCE 0.000006

void aff();
int main()
{

 aff();
}


void aff()
{
    int v, w, i,j;
    int **T,**R;
    float **Trans,**P,**V,**tab_New;
    float **Proba;
    float *tab;
    int k = 0;
    float *a,*b;
    float *x_1,*x1,*xk,*xk_1;


    /*printf("Entrez le nombre de lignes : ");
    scanf("%d", &v);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &w);*/
    v=5;
    w=4;
    T = calloc(v , sizeof(int*));
	Trans = calloc(v , sizeof(float*));
	P = calloc(v , sizeof(float*));
	Proba = calloc(v , sizeof(float*));


    R = calloc(v-1 , sizeof(int*));
    tab = calloc(w , sizeof(float));
    V  = calloc(2 , sizeof(float*)); //V contient les tableaux des vecteurs x-1 et x0 ( respectivement dans V[0] et V[1] )
	a  = calloc(w , sizeof(float));
	b  = calloc(w , sizeof(float));
	x_1 = calloc(w , sizeof(float));
	x1 = calloc(w , sizeof(float));
	xk = calloc(w , sizeof(float));
	xk_1=calloc(w , sizeof(float));

	tab_New = calloc(v , sizeof(float*));


    for (i = 0 ; i < v ; i++)
    {
        T[i] = calloc(w, sizeof(int));
		Trans[i] = calloc(w, sizeof(float));
		Proba[i] = calloc(w, sizeof(float));
		P[i] = calloc(w, sizeof(float));
        R[i] = calloc(w, sizeof(int));
        tab_New[i] = calloc(w, sizeof(float));
    }

    for (i = 0 ; i < 2 ; i++)
    {
       V[i] = calloc(w, sizeof(float));
	}
	
	
		for (j = 0 ; j < w ; j++)
			{
				V[1][j] = 1.00/w;
			}
       /*if (i > 0)
       {
          V[i][1] = 1;
         /* for (j = 0 ; j < w ; j++)
          {
            V[i][j] = 1/w;  je voulais faire comme la prof mais ici ça donne toujours 0.00
          }
       }*/
		
      
    printf("la valeur de 1.00/w est %.2f \n",1.00/w);

    printf("Vecteurs x-1 suivi de x0:\n");
    for (i=0; i<2; i++)
    {

      for (j=0; j<w; j++)
      {
        printf("%.2f", V[i][j]);
      }
      printf("\n");
    }


 float Norme(float **V,int w)
 {
   float val=0.00;
   float norme=0.00;
   for(i=0;i<w;i++)
   {
      a[i] = V[0][i] - V[1][i];
      b[i] = a[i]*a[i];
   }

   for(i=0;i<w;i++)
   {
		val+=b[i];
   }

   norme=sqrtf(val);
   for(i=0; i<w; i++)
   {
		 V[1][i] = V[0][i];
   }

   printf("La norme est %.2f \n",norme);
   return norme;
 }


    printf("Tableau donné à l'initialisation:\n");
    for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
         printf("%d", T[i][j]);
     printf("\n");
    }
    /*for (i=0; i<v; i++)
    for (j=0; j<w; j++)
        {
         printf("Elément[%d][%d] : ",i,j);
         scanf("%d", &T[i][j]);
        }*/
    T[0][0] =4;
    T[0][1] =-1;
    T[0][2] =-1;
    T[0][3] =-1;

    T[1][0] =0;
    T[1][1] =1;
    T[1][2] =2;
    T[1][3] =-1;

    T[2][0] =1;
    T[2][1] =0;
    T[2][2] =3;
    T[2][3] =2;

    T[3][0] =2;
    T[3][1] =0;
    T[3][2] =1;
    T[3][3] =-1;

    T[4][0] =3;
    T[4][1] =2;
    T[4][2] =-1;
    T[4][3] =-1;


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
     int t=2;
     float e;
     float div;
     div=1.00/w;
     e=(1-ALPHA)*(1.00/w);
     printf("la valeur de e est %.2f %.2f \n",e,div);

	for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
     {
        //printf("%.2f", Trans[i][j]/tab[j]);
        //P[i][j]=Trans[i][j]/tab[j];
        if(Trans[i][j]!=0)
        {
			P[i][j]=ALPHA*(Trans[i][j]/tab[j])*e;
		}
		else
		{
			P[i][j]=1.00/w;
		}
		
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
     

//boucle pour les calculs


 //printf(" %.2f",Norme(V,w));
  while(Norme(V,w) >= 1)
	{
		for(i=0; i<w; i++)
		{
             for (k=0; k<w; k++)
             {
                x_1[i] += P[i][k]*V[0][k];
             }
		}
		for (k=0; k<w; k++)
             {
                V[0][k] = x_1[k];
             }

	}

 

/* printf(" %.2f",Norme(V,w));
 printf(" %.2f",Norme(V,w));*/

}



