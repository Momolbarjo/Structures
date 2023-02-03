#include <stdio.h>


typedef struct {
    int jour;
    int mois;
    int annee;
} Date;



typedef struct {

    char prenom[150];
    Date date_naissance;
} Personne;


int compareDate(Date date1, Date date2) {
    if (date1.annee != date2.annee) {
        return 0;
    }
    if (date1.mois != date2.mois) {
        return 0;
    }
    if (date1.jour != date2.jour) {
        return 0;
    }
    return 1;
}

Personne constructeur_Personne(){
    Personne a;
    printf("Quel est votre prenom : ");
    scanf("%s", a.prenom);
    printf("Saisir le jour de votre naissance: ");
    scanf("%d", &a.date_naissance.jour);
    while (a.date_naissance.jour>30 || a.date_naissance.jour<0)
    {
        printf("Erreur, Saisir un  jour correct : ");
        scanf("%d", &a.date_naissance.jour);
    }
    printf("Saisir le mois de votre naissance : ");
    scanf("%d", &a.date_naissance.mois);
    while (a.date_naissance.mois>12 || a.date_naissance.mois<0)
    {
        printf("Erreur, Saisir un  mois correct : ");
        scanf("%d", &a.date_naissance.mois);
    }
    printf("Saisir l'annee de votre naissance: ");
    scanf("%d", &a.date_naissance.annee);
    while (a.date_naissance.annee<0)
    {
        printf("Erreur, Saisir une annee correct : ");
        scanf("%d", &a.date_naissance.annee);
    }
    printf("\n");
    return  a;
}

Personne bonAnniversaire( Personne tab[10],Date date){

for(int i=0;i<10;i++){


    if(compareDate(tab[i].date_naissance, date) == 1){

        printf("Bon anniversaire a toi %s",tab[i].prenom);
        printf("\n");
    }
}
}

void main(){

Personne personne[10];

for(int i=0;i<10;i++){
personne[i]=constructeur_Personne();
}
Date dateAnniversaire;
dateAnniversaire.jour=7;
dateAnniversaire.mois=10;
dateAnniversaire.annee=2004;

 bonAnniversaire(personne,dateAnniversaire);
}
