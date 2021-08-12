#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define max_taille 25

typedef struct Employer Employer;
struct Employer{
  char nom[max_taille];
  char prenom[max_taille];
  int num_cnss;
  char grade[20];
};

typedef struct Fiche Fiche;
struct Fiche{
  int numero;
  float salaire;
  int mois;
  Employer employer;
};


typedef struct Element Element;
struct Element{
  Fiche fiche;
  Element *next;
};

typedef struct List List;
struct List{
  int size;
  Element *head;
};

void choix();
Fiche fiche_creer();
void fiche_afficher(Fiche fiche);
List *list_init();
int list_ajouter(List *list,Fiche fiche);
int list_afficher(List *list);
Element *list_rechercher(List *list,int numero);
int list_suppression(List *list,int numero);
void fiche_file_write(Fiche fiche, FILE *fiche_file);
int list_file(List *list,FILE *fiche_file);
Fiche list_file_ajouter(FILE *fiche_file);
int count_lines();
#endif
