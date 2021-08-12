#include "mini.h"

void choix(){
  printf("\n\n>>>>>>>>>>>quelles options choisirez vous<<<<<<<<<< \n");
  printf("1. pour ajouter une fiche de paie tapez 1\n");
  printf("2. pour afficher les fiches de paie tapez 2\n");
  printf("3. pour rechercher une fiche dans la liste tapez 3\n");
  printf("4. pour la supprimer tapez 4\n");
  printf("5. pour lire a partir d'un fichier tapez 5\n");
  printf("6. pour sortir tapez 0\n");
}

Fiche fiche_creer(List *list){
  Fiche fiche;
  int num;
  do {
    printf("Donner le numero de la fiche : ");
    scanf("%d", &num);
  }while(list_rechercher(list,num) != NULL);
  fiche.numero=num;
  printf("Donner le salaire : ");
  scanf("%f",&fiche.salaire);
  do
  {
  printf("Donner le num du mois : ");
  scanf("%d", &fiche.mois);
  if (fiche.mois>12)
   printf("\n_____donner un numero de mois correct s'il vous plait___\n");
  }while(fiche.mois>12);
  printf("Donner le nom : ");
  scanf("%s", fiche.employer.nom);
  printf("Donner le prenom : ");
  scanf("%s",fiche.employer.prenom);
  printf("Donner le num cnss : ");
  scanf("%d", &fiche.employer.num_cnss);
  printf("Donner le grade : ");
  scanf("%s",fiche.employer.grade);
  return fiche;
}

void fiche_afficher(Fiche fiche){
  char annee[12][12]={"JANVIER","FEVRIER","MARS","AVRIL","MAI","JUIN","JUILLET","AOUT","SEPTEMBRE","OCTOBRE","NOVEMBRE","DECEMBRE"};
  printf("%d | %f | %s | %s | %s | %d | %s \n",fiche.numero,fiche.salaire,annee[fiche.mois-1],fiche.employer.nom,fiche.employer.prenom,fiche.employer.num_cnss,fiche.employer.grade);
}
void fiche_file_write(Fiche fiche, FILE *fiche_file){
  fprintf(fiche_file,"%d %f %d %s %s %d %s\n",fiche.numero,fiche.salaire,fiche.mois,fiche.employer.nom,fiche.employer.prenom,fiche.employer.num_cnss,fiche.employer.grade);
}

int count_lines(){
  char c=0;
  int numLine=0;
  FILE *fiche_file=fopen("fiche.txt","r");
  do{
    c = fgetc(fiche_file);
    if (c == '\n')
      numLine++;
  } while(c != EOF);
  fclose(fiche_file);
  return numLine;
}

Fiche list_file_ajouter(FILE *fiche_file){
  Fiche fiche;
  fscanf(fiche_file,"%d %f %d %s %s %d %s",&fiche.numero,&fiche.salaire, &fiche.mois, fiche.employer.nom, fiche.employer.prenom, &fiche.employer.num_cnss, fiche.employer.grade);
  return fiche;
}

List *list_init(){
  List *list=(List *)malloc(sizeof(*list));
  list->size=0;
  list->head=NULL;
  return list;
}

int list_ajouter(List *list,Fiche fiche){
  Element *element=(Element *)malloc(sizeof(*element));
  if(element == NULL || list == NULL)
    return -1;
  element->fiche=fiche;
  element->next=list->head;
  list->head=element;
  list->size++;
  return 0;
}

int list_afficher(List *list){
  int i=0,j=0;
  Element *position=(list->head);
  for(i=list->size;i>0;i--){
    if(i==1)
      fiche_afficher(list->head->fiche);
    else{
      for(j=2;j<=i;j++){
        position=position->next;
      }
      fiche_afficher(position->fiche);
      position=list->head;
    }
  }
  return 0;
  free(position);
}


int list_file(List *list,FILE *fiche_file){
  int i=0,j=0;
  Element *position=(list->head);
  for(i=list->size;i>0;i--){
    if(i==1)
      fiche_file_write(list->head->fiche,fiche_file);
    else{
      for(j=2;j<=i;j++)
        position=position->next;
      fiche_file_write(position->fiche,fiche_file);
      position=list->head;
    }
  }
  return 0;
}

Element *list_rechercher(List *list, int numero){
  int i=0,j=0;
  Element *position=(list->head);
  for(i=list->size;i>0;i--){
    if(i==1 && (list->head->fiche).numero == numero)
        return list->head;
    else{
      for(j=2;j<=i;j++){
        position=position->next;
      }
      if((position->fiche).numero == numero)
        return position;
      position=list->head;
    }
  }
  return NULL;
}

int list_suppression(List *list,int numero){
  int i=0,j=0;
  Element **position=&(list->head);
  for(i=list->size;i>0;i++){
    if(i==1 && (list->head->fiche).numero == numero){
      //delete head of list
      list->head=list->head->next;
      list->size--;
      free(position);
      return 0;
    }
    else{
      for(j=2;j<i;j++){
        if((((*position)->next->fiche)).numero==numero){
          Element *oldN=(*position)->next;
          (*position)->next=oldN->next;
          free(oldN);
          list->size--;
          return 0;
        }
        position=&(*position)->next;
      }
      position=&(list->head);
    }
  }
  return 1;
}
