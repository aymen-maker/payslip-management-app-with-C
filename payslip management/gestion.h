#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED
#include <stdio.h>
#include <string.h>
#define max_taille 25

typedef struct
{
    char nom[max_taille];
    char prenom[max_taille];
     int num_cnss;
    char grade[20];
}employer;

typedef struct
{
     int numero ;
    float salaire ;
    int mois;
    employer employ;
}fiche;


fiche ajouter();
void afficher(fiche elt);
int rechercher(fiche tab_fiche[],int longueur, int numero);
int supp(fiche tab_fiche[], int longueur,  int numero);


#endif // GESTION_H_INCLUDED
