#include <stdio.h>
#define nbcar 30
#define nbMaxV 20

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
               

/* declaration de la structure Etagere */
typedef struct { int occupation[nbMaxV];
                 Voiture composition[nbMaxV] ;
               } Etagere ; 



/* Sous-Programme lecture_Date */
/* Description des paramètres */
/* L: d : Date  */               
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
/* D: d : Date  */
void  affichage_Date(Date d) {
    printf("\n%d/%d/%d\n\n", d.jour, d.mois, d.annee);
}



/* Sous-Programme lecture_Voiture */
/* Description des paramètres */
/* L: voit : Voiture  */
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
/* D: voit : Voiture  */
void affichage_Voiture(Voiture voit){
   printf("\ncode: %d\n", voit.code);
   printf("marque: %s\n", voit.marque);
   printf("type: %s\n", voit.type);
   printf("couleur: %s\n", voit.couleur);
   printf("prixAchat: %f\n", voit.prixAchat);
   printf("dateAchat: ");
   affichage_Date(voit.dateAchat);
}



/* Sous-Programme init_Etagère */
/* Description des paramètres */
/* L: eta : Etagere, ind : Entier */
Etagere  init_Etagere(){
     Etagere eta;
     int ind;  /* indice de parcours de l'étagère */
     for(ind=0; ind<nbMaxV; ind++)
       eta.occupation[ind]= 0; /* 0 pour FAUX */
     return eta;
}



/* Sous-Programme ajout_Voiture */
/* Description des paramètres */
/* D: voit : Voiture, emp : Entier  */
/* D/R: eta : Etagere   */
/* R: ajout : Entier */
void  ajout_Voiture(Voiture voit, Etagere*pteta, int emp, int*ptajout){
     if((emp<1) || (emp>nbMaxV) || (pteta->occupation[emp-1]))   /* pteta->occupation[emp-1] equivalent à (*pteta).occupation[emp-1] */
          *ptajout = 0; /* 0 pour le passage à faux */
     else {
          *ptajout = 1; /* 1 pour le passage à vrai */
          pteta->composition[emp-1] = voit;
          pteta->occupation[emp-1] = 1;
     }
}



/* Sous-Programme affichage_Etagere */
/* Description des paramètres */
/* D: eta : Etagere    */
/* L: ind : Entier */
void affichage_Etagere(Etagere eta){
   int ind = 0; /* indice de parcours de l'étagère */
   for(ind=0; ind<nbMaxV; ind++){ 
      if (eta.occupation[ind]== 1){
          printf("\nnumero d'emplacement sur l'etagère: %d", ind);
          affichage_Voiture(eta.composition[ind]);
      }  
   }    
}



/* Sous-Programme remplissage_Etagere */
/* Description des paramètres */
/* D/R: eta : Etagere    */
/* L : emp : Entier, voit : Voiture, ind : Entier */
void  remplissage_Etagere(Etagere*pteta){
    int emp;
    Voiture voit;
    int ajout;
    int ind=0; /*compteur de voiture */
    *pteta=init_Etagere();
    printf("\nveuillez saisir le numéro d'emplacement de la voiture à ajouter: \n");
    scanf("%d", &emp);
    while ((ind<nbMaxV) && (emp!=-1)){
      printf("\nveuillez saisir les informations de la voiture à ajouter \n");
      voit=lecture_Voiture();
      ajout_Voiture(voit, pteta, emp, &ajout); 
      if(ajout==1){
        printf("\nl'ajout de la voiture a été effectué\n");
        ind++;
      }
      else
        printf("\nl'ajout de la voiture n'a pas été effectué\n");
      printf("\nveuillez saisir le numéro d'emplacement de la voiture à ajouter(saisissez -1 pour arreter la saisir de la liste de voiture) : \n");
      scanf("%d", &emp);
    }
}



/* Sous-Programme suppression_Voiture */
/* Description des paramètres */
/* D/R: eta : Etagere */
/* D: code : Entier */
/* R: suppression : Entier */ 
/* L: parcours : Entier */
void suppression_Voiture(Etagere*pteta, int code, int*ptsuppression){
     int parcours; /* indice de parcours de l'étagere */
     parcours=0;
     while((parcours<nbMaxV) && ((!pteta->occupation[parcours]) || (pteta->composition[parcours].code!=code))) 
        parcours++;
     if (parcours<nbMaxV){
        *ptsuppression = 1;
        pteta->occupation[parcours]=0;
     }
     else
        *ptsuppression=0;
}



int main(){
  Etagere eta;
  int code;
  int suppression;
  int ind=0;  
  remplissage_Etagere(&eta);
  printf("\n\nAffichage des informations des voitures présentes sur l'etagère\n");
  affichage_Etagere(eta);
  
  for(ind=0; ind<2; ind++){ 
    printf("\nveuillez saisir le code de la voiture à supprimer: \n");
    scanf("%d", &code);
    suppression_Voiture(&eta, code, &suppression);
    if(suppression==1)
        printf("\nla suppression a été effectuée\n");
    else
        printf("\nla suppression n'a pas été effectuée\n");
  } 
  printf("\n\nNouvel affichage des informations des voitures présentes sur l'etagère\n");  
  affichage_Etagere(eta); 
  return 0;
}
  
  







