#include <stdio.h>
#define nbcar 30

/* declaration de la structure Date */
typedef struct { int jour;
                 int mois;
                 int annee;
               } Date ;

/* declaration de la structure voiture */
typedef struct { int code;
                 char marque[nbcar];
                 char type[nbcar];
                 char couleur[nbcar];
                 float prixAchat;
                 Date dateAchat;
               } Voiture ;


/* Sous-Programme lecture_Date */
/* Description des paramètres */
/* L: d : Date    */               
Date lecture_Date() {
    Date d;
    printf("\nveuillez saisir une date au format jour/mois/annee (le nombre saisi pour le jour est compris entre 1 et 31 inclus, pour le mois est compris entre 1 et 12 et pour l'annee est supérieure a 2000): \n");
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
/* D: d : Date    */
void  affichage_Date(Date d) {
    printf("\n%d/%d/%d\n\n", d.jour, d.mois, d.annee);
}



/* Sous-Programme lecture_Voiture */
/* Description des paramètres */
/* L: voit : Voiture    */
Voiture lecture_Voiture(){
     Voiture voit;
     printf("code: \n"); 
     scanf("%d", &voit.code);
     printf("marque: \n");
     scanf("%s", voit.marque);
     printf("type: \n");
     scanf("%s", voit.type);
     printf("couleur: \n");
     scanf("%s", voit.couleur);
     printf("prix d'achat: \n");
     scanf("%f", &voit.prixAchat);
     printf("date d'achat: ");
     voit.dateAchat=lecture_Date();
     return voit;
}



/* Sous-Programme affichage_Voiture */
/* Description des paramètres */
/* D: Voit : Voiture */
void affichage_Voiture(Voiture voit){
   printf("code: %d\n", voit.code);
   printf("marque: %s\n", voit.marque);
   printf("type: %s\n", voit.type);
   printf("couleur: %s\n", voit.couleur);
   printf("prixAchat: %f\n", voit.prixAchat);
   printf("dateAchat: ");
   affichage_Date(voit.dateAchat);
}



int main(){
  Date d;
  Voiture voit;
  d=lecture_Date();
  printf("\nAffichage de la date: ");
  affichage_Date(d);
  
  printf("\nsaisie des informations de la voiture: \n\n");
  voit=lecture_Voiture();
  printf("\n\nAffichage des information de la voiture: \n\n");
  affichage_Voiture(voit);
  return 0;
}







