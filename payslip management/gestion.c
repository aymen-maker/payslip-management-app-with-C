#include "gestion.h"
#include <stdio.h>
#include <string.h>

fiche ajouter()
{
    fiche emp;
    printf("Donner le numero de la fiche : ");
    scanf("%d",&emp.numero);
    printf("Donner le salaire : ");
    scanf("%f",&emp.salaire);
    printf("Donner le num du mois: ");
    scanf("%d",&emp.mois);
    printf("Donner le nom : ");
    scanf("%s", emp.employ.nom);
    printf("Donner le prenom : ");
    scanf("%s",emp.employ.prenom);
    printf("Donner le num cnss : ");
    scanf("%d",&emp.employ.num_cnss);
    printf("Donner le grade : ");
    scanf("%s",emp.employ.grade);
    return emp;
}

void afficher(fiche elt)
{
    char annee[12][12]={"JANVIER","FEVRIER","MARS","AVRIL","MAI","JUIN","JUILLET","AOUT","SEPTEMBRE","OCTOBRE","NOVEMBRE","DECEMBRE"};
    printf("%d | %f | %s | %s | %s | %d | %s \n",elt.numero,elt.salaire,annee[elt.mois-1],elt.employ.nom,elt.employ.prenom,elt.employ.num_cnss,elt.employ.grade);
}


int rechercher(fiche tab_fiche[],int longueur, int numero)
 {int i;
    for(i=0;i<longueur;i++)
    {
     if (tab_fiche[i].numero==numero)
        return i;

    }
    return -1;
}



int supp(fiche tab_fiche[], int longueur,  int numero)
{
     int i,taille;
    for(i=rechercher(tab_fiche, longueur,numero);i<longueur-1;i++)
    {
        tab_fiche[i]=tab_fiche[i+1];
    }
   taille=longueur-1;
   return taille;

}

