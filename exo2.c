#include <stdio.h>


typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

Date constructeur_Date(){
    Date a;
    printf("Saisir le jour : ");
    scanf("%d", &a.jour);
    while (a.jour>30 || a.jour<0)
    {
        printf("Erreur, Saisir un  jour correct : ");
        scanf("%d", &a.jour);
    }
    printf("Saisir le mois: ");
    scanf("%d", &a.mois);
    while (a.mois>12 || a.mois<0)
    {
        printf("Erreur, Saisir un  mois correct : ");
        scanf("%d", &a.mois);
    }
    printf("Saisir l'annee: ");
    scanf("%d", &a.annee);
    while (a.annee<0)
    {
        printf("Erreur, Saisir une annee correct : ");
        scanf("%d", &a.annee);
    }
    return  a;
}


Date enleve_jour(Date a, int jour){
Date newDate;
if(jour >= 360){
    newDate.annee=a.annee -(jour/360);
    jour=jour%360;
    newDate.jour=a.jour-jour;
if (newDate.jour<=0){
    newDate.mois=a.mois+(newDate.jour/30);
    newDate.jour=(newDate.jour%30);
if (newDate.jour==0){
    newDate.jour=1;
}
}
else{
    newDate.mois=a.mois;
}
if(newDate.mois<=0){
    newDate.annee=newDate.annee+(newDate.mois/12);
    newDate.mois=(newDate.mois%12);
    if (newDate.mois==0){
        newDate.mois=1;
    }
}
else{
    newDate.annee=newDate.annee;
}
}
else if( jour<360){
newDate.jour=a.jour-jour;
if (newDate.jour<=0){
    newDate.mois=a.mois+(newDate.jour/30);
    newDate.jour=(newDate.jour%30);
if (newDate.jour==0){
    newDate.jour=1;
}
}
else{
    newDate.mois=a.mois;
}
if(newDate.mois<=0){
    newDate.annee=a.annee+(newDate.mois/12);
    newDate.mois=(newDate.mois%12);
    if (newDate.mois==0){
        newDate.mois=1;
    }
}
else{
    newDate.annee=a.annee;
}
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
    newDate.jour=(newDate.jour%30);
if (newDate.jour==0){
    newDate.jour=1;
}
}
else{
    newDate.mois=a.mois;
}
if(newDate.mois>12){
    newDate.annee=newDate.annee+(newDate.mois/12);
    newDate.mois=(newDate.mois%12);
    if (newDate.mois==0){
        newDate.mois=1;
    }
}
else{
    newDate.annee=newDate.annee;
}
}
else if( jour<360){
newDate.jour=a.jour+jour;
if (newDate.jour>30){
    newDate.mois=a.mois+(newDate.jour/30);
    newDate.jour=(newDate.jour%30);
if (newDate.jour==0){
    newDate.jour=1;
}
}
else{
    newDate.mois=a.mois;
}
if(newDate.mois>12){
    newDate.annee=a.annee+(newDate.mois/12);
    newDate.mois=(newDate.mois%12);
    if (newDate.mois==0){
        newDate.mois=1;
    }
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
affiche_Date(ajoute_jour(test,242));
affiche_Date(enleve_jour(ajoute_jour(test,242),3));
}
