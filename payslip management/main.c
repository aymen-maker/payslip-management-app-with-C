#include <stdio.h>
#include <string.h>
#include "gestion.h"


int main()
{
    int l=10,longueur=0,i;
    int ajout=0,numero,x;
    fiche tab_fiche[max_taille];
    while(l != 0)
    {
        printf("\n>>>>>>>>>>>quelles options choisirez vous \n\n1-pour ajouter une fiche de paie tapez 1\n2-pour afficher les fiches de paie tapez 2\n3-pour rechercher un fichez dans le tableau tapez 3\n4-pour le supprimer tapez 4\n5-pour sortir tapez 0\n");
        scanf("%d",&l);
        switch(l)
        {
            case 1 : {printf("\n\n>>>>>>>>ajout d'une fiche<<<<<<<<\n\n");
               while(ajout==0)
                {
                   tab_fiche[longueur]=ajouter();
                   longueur++;
                   printf("ajouter 0 non 1: ");
                   scanf("%d",&ajout);
                }
                ajout = 0;
                break;
            }
            case 2 : {printf("\n\n>>>>>>>>affichage des fiches<<<<<<<<\n\n");
                printf("numero |salaire | mois |Nom | Prenom | Num cnss| grade |\n");
                for(i=0;i<longueur;i++)
                    {
                    afficher(tab_fiche[i]);
                    }
                break;
                }
            case 3 : {printf("\n\n>>>>>>>>recherche d'une fiche par son numero<<<<<<<<\n\n");
                printf("donner le numero de fiche a chercher: ");
                scanf("%d",&numero);
                x=rechercher(tab_fiche, longueur,numero);
                printf("le nom à chercher est a l'indice %d \n",x);
                break;
                }
            case 4 : {printf("\n\n>>>>>>>>suppression d'une fiche<<<<<<<<\n\n");
                longueur=supp(tab_fiche,longueur,numero);
                for(i=0;i<longueur;i++)
                    {
                    afficher(tab_fiche[i]);
                    }
                break;
                }
            case 0 : { printf("\n\n>>>>>>>>GOOD BYE<<<<<<<<\n\n");
                return 0;
                break;}
            default : {
                printf("choix incorrect");
                l=-1;}
        }

    }
    return -1;

}
