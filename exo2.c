#include <stdio.h>


typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

Date constructeur_Date(){
    Date d;

    printf("Saisir le jour : ");
    scanf("%d",&d.jour);
    while (d.jour>30 || d.jour<1)
    {
        printf("Erreur, Saisir un  jour correct : ");
        scanf("%d", &d.jour);
    }
    printf("Saisir le mois: ");
    scanf("%d", &d.mois);
    while (d.mois>12 || d.mois<1)
    {
        printf("Erreur, Saisir un  mois correct : ");
        scanf("%d", &d.mois);
    }
    printf("Saisir l'annee: ");
    scanf("%d", &d.annee);
    while (d.annee<0)
    {
        printf("Erreur, Saisir une annee correct : ");
        scanf("%d", &d.annee);
    }

    return  d;
}


Date enleve_jour(Date a, int jour){
    Date newDate = a;
    int m;
    if(jour >= 360){
        newDate.annee = a.annee - (jour/360);
        jour = jour % 360;
    }

    if(jour >= 30){
        m = jour / 30;
        newDate.mois = a.mois - m;
    }
    else{
        newDate.mois = a.mois;
    }

    newDate.jour = a.jour - (jour % 30);
    while(newDate.jour <= 0){
        newDate.mois--;
        if(newDate.mois <= 0){
            newDate.annee--;
            newDate.mois = 12;
        }
        newDate.jour += 30;
    }
    return newDate;
}

Date ajoute_jour(Date a, int jour){
Date newDate;
if(jour >= 360){
    newDate.annee=a.annee +(jour/360);
    jour=jour%360;
    newDate.jour=a.jour+jour;
if (newDate.jour>30){
    newDate.mois=a.mois+(newDate.jour/30);
    newDate.jour=(newDate.jour%30+1)-1;
}

if(newDate.mois>12){
    newDate.annee=newDate.annee+(newDate.mois/12);
    newDate.mois=(newDate.mois%12)+1;

}
else{
    newDate.annee=newDate.annee;
}
}
else if( jour<360){
newDate.jour=a.jour+jour;
if (newDate.jour>30){
    newDate.mois=a.mois+(newDate.jour/30);
    newDate.jour=(newDate.jour%30+1)-1;

}

if(newDate.mois>12){
    newDate.annee=a.annee+(newDate.mois/12);
    newDate.mois=(newDate.mois%12)+1;

}
else{
    newDate.annee=a.annee;
}
}
return newDate;
}

void affiche_Date(Date x){
if (x.jour<10 && x.mois<10){
    printf("La date est le 0%d/0%d/%d",x.jour, x.mois,x.annee);
}
else if (x.jour<10){
    printf("La date est le 0%d/%d/%d",x.jour, x.mois,x.annee);
}
else if (x.mois<10){
    printf("La date est le %d/0%d/%d",x.jour, x.mois,x.annee);
}
else{
    printf("La date est le %d/%d/%d",x.jour, x.mois,x.annee);
}
printf("\n");
}

void main() {
    Date test;
    test=constructeur_Date();
    affiche_Date(test);
    affiche_Date(ajoute_jour(test,365));
    affiche_Date(enleve_jour(ajoute_jour(test,365),5));
}
