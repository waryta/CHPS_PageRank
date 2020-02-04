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
    int **T;
    float **R;//matrice d'adjacence
    float **P;//matrice de probabilité
    float **Trans;//matrice transposée

    float *posInit;//position initaile du promeneur


    int *tab;

    printf("Entrez le nombre de lignes : ");
    scanf("%d", &v);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &w);
    T = calloc(v , sizeof(int*));
    Trans = calloc(v , sizeof(float*));

    P = calloc(v , sizeof(int*));

    tab= calloc(w , sizeof(int));
	posInit= calloc(w , sizeof(float));

    R = calloc(v-1 , sizeof(float*));

    for (i = 0 ; i < v ; i++)
    {
        T[i] = calloc(w, sizeof(float));
        Trans[i] = calloc(w, sizeof(float));

        P[i] = calloc(w, sizeof(float));

    }
	
    for (i = 0 ; i < v-1 ; i++)
    {
        R[i] = calloc(w, sizeof(int));

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
    /*calcule matrice d'adjancence*/
	    

    for (i=1; i<v; i++)
    { printf( "\n i vaut %d",i);
     for (j=1; j<w; j++)
     {
		 if(T[i][j]!=-1)
		 {
			R[i-1][T[i][j]]=1;

			printf("\n on rempli le tab %d %d avec %.2f \n",i-1,T[i][j],R[i-1][T[i][j]]);

		 }

	  }
    }
	
	for (i=0; i<v; i++)
    {
     for (j=0; j<w; j++)
     {
		 printf("la mat %d %d est %.2f \n",i,j,R[i][j]);

		 printf("%.2f", R[i][j]);
	 }
     printf("\n");
    }

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
        printf("%d", tab[i]);
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




