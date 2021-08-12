#include "mini.h"

int main(){
  List *list=list_init();
  int test=-1,i=0;
  FILE *fiche_file;
  while(test !=0){ printf("\n\n______________________BIENVENUE____________________________\n_____________________Gestion de fiche de paix__________________\n");
    choix();
    scanf("%d",&test);
    switch(test){
      case 1 : {
        i=0;
        do{printf(">>>>>ajout d'une fiche<<<<<<<\n\n");
          list_ajouter(list,fiche_creer(list));
          printf("voulez vous ajouter une autre fiche ?\n");
          printf("tapez 1 pour non, 0 pour oui : ");
          scanf("%d",&i);
        }while(i==0);
        break;
      }
      case 2 : {printf(">>>>>>>>>>affichage de tous les fiches<<<<<<<\n\n");
        printf("numero |salaire | mois |Nom | Prenom | Num cnss| grade |\n");
        list_afficher(list);
        break;
      }
      case 3 : {printf(">>>>>>>recherche d'une fiche a l'aide de son numero<<<<<<<<\n\n");
        int numero;
        printf("donner le numero de fiche a chercher: ");
        scanf("%d",&numero);
        if(list_rechercher(list,numero)==NULL)
          printf("la fiche n'existe pas encore \n");
        else
          fiche_afficher((list_rechercher(list,numero)->fiche));
        break;
      }
      case 4 : {printf(">>>>>>>supprimer une fiche en donnant son numero<<<<<<<<<<<\n\n");
        int numero=-1;
        printf("Donner le numero de fiche a supprimer : ");
        scanf("%d", &numero);
        if(list_rechercher(list,numero)==NULL){
          printf("la fiche n'existe pas encore \n");
          break;
        }
        if(list_suppression(list,numero)==0){
          printf("Suppression avec succees.\n");
          break;
        }
        printf("erreur!!\n");
      }
      case 5 : {printf(">>>>>>>>lecture des fiches<<<<<<<<\n\n");
        fiche_file=fopen("fiche.txt","r");
        if(fiche_file==NULL)
          printf("le fichier n'existe pas");
        else {
          int h=1;
          while(h<=count_lines()){
            printf("en train d'ajouter la ligne numero %d....\n",h);
            list_ajouter(list,list_file_ajouter(fiche_file));
            h++;
          }
        }
        break;
      }
      case 0 : {printf("\n\n>>>>>>>>>>>Good_Bye<<<<<<<<<<<\n\n");
        if(list->size != 0){
          fiche_file=fopen("fiche.txt","wt");
          if(fiche_file==NULL)
            printf("le fichier n'existe pas");
          else
            list_file(list,fiche_file);
        }

            exit(0);
      }
            default :{
            printf("________________ERREUR______________\n");
                }
    }
  }
}
