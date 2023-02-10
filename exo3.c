#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
    float attaque;
    float defense;
    float esquive;
    float points2vie;
    char nom[100];
} Ninja;

Ninja combat(Ninja a, Ninja b){

void srand(unsigned int seed);
srand(time(NULL));
float degat1,degat2,degatInflige1,degatInflige2;

while (b.points2vie>0 && a.points2vie >0)
{
degat1=(float)rand()/(float)RAND_MAX ;

if (degat1<= b.esquive){
    printf("Hop, c'est l'esquive de %s\n",b.nom);

}
else{

degatInflige1=a.attaque-b.defense;
if (degatInflige1<0){

    degatInflige1=0;
                    }

b.points2vie=b.points2vie-degatInflige1;
printf("Aie %s, tu perds %f points de vie,ne t'inquiete pas il te reste %f points de vie\n",b.nom,degatInflige1,b.points2vie);

}
degat2=(float)rand()/(float)RAND_MAX;

if (degat2<= a.esquive)
    {
    printf("Hop, c'est l'esquive de %s\n",a.nom);

    }
else{
degatInflige2=b.attaque-a.defense;
if (degatInflige2<0){

    degatInflige2=0;
                    }

a.points2vie=a.points2vie-degatInflige2;
printf("Aie %s, tu perds %f points de vie,ne t'inquiete pas il te reste %f points de vie\n",a.nom,degatInflige2,a.points2vie);
    }

    printf("\n");
}
if(a.points2vie<=0 && b.points2vie<=0)
            {
    printf("Egalite...\n");
            }
else if(a.points2vie >0 && b.points2vie<=0)
        {
    printf("Bravo mon %s sucre au sucre,tu as dead ca chakal\n",a.nom);
        }
else if(b.points2vie >0 && a.points2vie<=0)
    {

    printf("Bravo mon %s sucre au sucre,tu as dead ca chakal\n",b.nom);
    }
}

void main()
{
Ninja var1,var2;
srand(time(NULL));

var1.attaque=(float)((rand()%51))/10+5;
var2.attaque=(float)((rand()%51))/10+5;

var1.defense=(float)((rand()%31)/10)+2;
var2.defense=(float)((rand()%31)/10)+2;

var1.esquive=((float)rand() / (float)RAND_MAX) + 0.1;
var2.esquive=((float)rand() / (float)RAND_MAX) + 0.1;

var1.points2vie=(float)((rand()%210)/10)+80;
var2.points2vie=(float)((rand()%210)/10)+80;

printf("Entrez le nom du ninja 1: ");
scanf("%s",var1.nom);

printf("\nEntrez le nom du ninja 2: ");
scanf("%s",var2.nom);

printf("\n");

combat(var1,var2);

}
