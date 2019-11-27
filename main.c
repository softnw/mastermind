#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define TAILLEMAX 4
#define ESSAIEMAX 12

void init_Chaine(char *t_Chaine);
void inittab(int *n_tab);
void color(int t, int f);

int main()
{
//int n_gamers[TAILLEMAX];
//int n_tab[TAILLEMAX];
char c_visu[TAILLEMAX+1][ESSAIEMAX];
char c_tab[TAILLEMAX+1];
char c_rep[TAILLEMAX+1];
int i;
int j;
int k = 0;
int n_just;
int n_apeupret;
srand(time(NULL));

//inittab(n_tab);
init_Chaine(c_tab);

for (j=0;j<ESSAIEMAX;j++) // creation du tableau d'historique
{
    for (i=0;i<TAILLEMAX;i++)
    {
        c_visu[i][j]='_';

    }


}



while (k<12)
{
    n_just = 0;
    n_apeupret =0;


    color(15,0);
    printf("\n entrez 4 chiffres\n"); //on demande au joueur de rentrer ses chiffres
            scanf("%s",c_rep);
            fflush(stdin);
            printf("\n \n");



    for (i=0;i<TAILLEMAX;i++)
    {
        c_visu[i][k]=c_rep[i];

    }

    for (j=0;j<ESSAIEMAX;j++) //on affiche le tableau des essaie avec les bonnes couleurs
    {

        for(i=0;i<TAILLEMAX;i++)
        {

            if((c_visu[0][j]==c_tab[i])||(c_visu[1][j]==c_tab[i])||(c_visu[2][j]==c_tab[i])||(c_visu[3][j]==c_tab[i]))
            {
                color(14,0);
                 if(c_visu[i][j]==c_tab[i])
            {
                    color(2,0);
            }


            }else{
                color(12,0);
            }

        printf("%c",c_visu[i][j]);
        }
        printf("\n");
    }





    for (i=0;i<TAILLEMAX;i++) //on regarde si les nombres sont au bon endroit ou non
    {
        for (j=0;j<TAILLEMAX;j++)
        {
            if (c_tab[i]==c_rep[j])
                {
                    if (i==j)
                        {
                            n_just++;

                        }else{
                            n_apeupret++;

                        }
                }
        }

    }
    //printf("vous avez %d au mauvais endroit, et %d au bon endroit",n_apeupret,n_just);

    if(n_just == 4) //condition de sortie de la boucle
        {
            k = 15;
        }else{
            k++;
        }



}
/*for (i=0;i<TAILLEMAX;i++)
{
    printf("%d",n_gamers[i]);
}*/

 if (k==15) //victoire/defaite
{   color(15,0);
    printf("\n woaw bien joué mon giga pote");
}else{
    color(15,0);
    printf("\n c'est perdu mec");
}


    return 0;
}

/*void inittab(int *n_tab) //initialisation du tableau
{
    int i;
    for(i=0;i<4;i++)
    {
    int n_random = rand() % 10;
    n_tab[i] = n_random;
    //printf("%d",n_tab[i]);
    }
}*/

void init_Chaine(char *t_Chaine) //creation du nombre a deviner
 {
    char c_rand;
    srand(time(NULL));
    for (int i=0 ; i<4 ; i++)
    {
        c_rand= '0' + rand()%10;
        //t_Chaine[i]= '0' + rand()%10;
        while((c_rand==t_Chaine[0])||(c_rand==t_Chaine[1])||(c_rand==t_Chaine[2])||(c_rand==t_Chaine[3]))
            {
                c_rand= '0' + rand()%10;
            }
        t_Chaine[i]= c_rand;
    }
    //printf("%s \n \n", t_Chaine);
}


void color(int t, int f) //gestion des couleurs
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,f*16+t);
}
