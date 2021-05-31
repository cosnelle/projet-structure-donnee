#include <stdio.h>

/* declaration de la structure Date */
typedef struct { int jour;
                 int mois;
                 int annee;
               } Date ;
               

/* Sous-Programme lecture_Date */
/* Description des paramètres */
/* L: d : Date */
Date lecture_Date() {
    Date d;
    printf("\nveuillez saisir une date au format jour/mois/annee (le nombre saisi pour le jour est compris entre 1 et 31 inclus, pour le mois est compris entre 1 et 12 et pour l'annee est supérieur à 2000): \n");
    scanf("%d/%d/%d", &d.jour, &d.mois, &d.annee);
    
    while((d.jour<1) || (d.jour>31) || (d.mois<1) || (d.mois>12) || (d.annee<2000)) {
      printf("\nla date saisi est incorrect\n");  
      printf("\nveuillez saisir une nouvelle date au format jour/mois/annee (l'annee saisi doit être supérieur ou égal à 2000): \n");
      scanf("%d/%d/%d", &d.jour, &d.mois, &d.annee);
    }
    return d;
}


/* Sous-Programme Affichage_Date */
/* Description des paramètres */
/* D: d : Date */
void  affichage_Date(Date d) {
    printf("\n%d/%d/%d\n\n", d.jour, d.mois, d.annee);
}


int main(){
  Date d;
  d= lecture_Date();
  printf("\nAffichage de la date: \n");
  affichage_Date(d);
  return 0;
}
  







