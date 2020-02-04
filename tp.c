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
    float **T;
    float **R;//matrice d'adjacence
    float **P;//matrice de probabilité
    float **Trans;//matrice transposée

    float *posInit;//position initaile du promeneur


    float *tab;

    printf("Entrez le nombre de lignes : ");
    scanf("%d", &v);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &w);
    T = calloc(v , sizeof(float*));
    Trans = calloc(v , sizeof(float*));

    P = calloc(v , sizeof(int*));

    tab= calloc(w , sizeof(float));
	posInit= calloc(w , sizeof(float));

    R = calloc(v-1 , sizeof(float*));

    for (i = 0 ; i < v ; i++)
    {
        T[i] = calloc(w, sizeof(float));
        Trans[i] = calloc(w, sizeof(float));

        P[i] = calloc(w, sizeof(float));

        R[i] = calloc(w, sizeof(float));

    }
    printf("Tableau donné à l'initialisation:\n");
    for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
         printf("%.2f", T[i][j]);
     printf("\n");
    }
    for (i=0; i<v; i++)
    for (j=0; j<w; j++)
        {
         printf("Elément[%d][%d] : ",i,j);
         scanf("%f", &T[i][j]);
        }
  /* Affichage du tableau */
 printf("Tableau donné :\n");
 for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
         printf("%.2f", T[i][j]);
     printf("\n");
    }
    /*calcule matrice d'adjancence
    int a,b=0;
    for (i=1; i<v; i++)
    {
     for (j=0; j<w; j++)
     {
		 if(T[i][j]==j)
		 {
			 
			R[i][j]=1;
			printf("on rempli le tab %d %d avec %d \n",i-1,j,R[i-1][j]);
			
		 }
		 else
		 {
			R[i][j]=0; 
			printf("on rempli le tab %d %d avec %d \n",i-1,j-1,R[i-1][j-1]);

		 }
		 b+=1;
	  }
	  a+=1;
    }
     printf("affichage matrice d'incidence :\n");
 for (i=0; i<v-1; i++)
    {
     for (j=0; j<w; j++)
     printf("la mat %d %d est %d \n",i,j,R[i][j]);

     printf("%d", R[i][j]);
     printf("\n");
    }*/
	/*calcul de la transposée*/
    printf("matrice transposée \n");
    for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
     {
		 Trans[i][j]=T[j][i];
         printf("%.2f", Trans[i][j]);
	 }
     printf("\n");
    }
    int s=0;
    for(j=0;j<w;j++)
    {
		for (i=0; i<v; i++)
		{
			
		 s=s+T[j][i];
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
     printf("matrice de transition ou de probabilité \n");
     int r=0;
	for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
     {
        printf("%.2f", Trans[i][j]/tab[j]);
     }
		printf("\n");
    }
    //position aléatoire du promeneur
    for(i=0;i<w;i++)
    {
		posInit[i]=(rand()%2);
	}
	printf("la position du promeneur est \n");
     for (i=0; i<w; i++)
     {
        printf("%.2f", posInit[i]);
		printf("\n");
     }

}

/*calcul de la transposée
    printf("matrice transposée \n");
    for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
         printf("%d", T[j][i]);
     printf("\n");
    }
     printf("matrice de transition \n");
	for (i=0; i<v; i+v)
    {
     for (j=0; j<w; j++)
         printf("%d", T[j][i]);
     printf("\n");
    }
*/




