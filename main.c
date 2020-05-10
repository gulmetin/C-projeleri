#include <stdio.h>
#include <stdlib.h>

typedef struct{
   char plaka[15];
   char renk[50];
   char model[50];
} ARACBILGI;
typedef struct{
    char saat[10];
} GIRIS;
ARACBILGI arac_oz[1000];
GIRIS arac_giris[1000];
int s=0,a=0; //s=Arac sayisini gösterir.
int main(){
   Anamenu();
    return 0;
}
void AracEkle(){
   int i;
   printf("\nKac Arac Eklemek Istersiniz?\n");
   scanf("%d",&i);
   s=s+i;

   for(a;a<s;a++){
    printf("\nPlakayi giriniz.\n");
    scanf("%s",&arac_oz[a].plaka);
    printf("Modeli giriniz.\n");
    scanf("%s",&arac_oz[a].model);
    printf("Renk giriniz.\n");
    scanf("%s",&arac_oz[a].renk);
    printf("Giris saati giriniz.\n");
    scanf("%s",&arac_giris[a].saat);
   }
   Anamenu();
}
void AraclariListele(){
    for(int i=0; i<s; i++){
        printf("\nARAC %d BILGILERI\n", i+1);
        printf("Plaka:"); puts(arac_oz[i].plaka);
        printf("Model:"); puts(arac_oz[i].model);
        printf("Renk:");  puts(arac_oz[i].renk);
        printf("Giris Saati:"); puts(arac_giris[i].saat);
    }
  Anamenu();
}
void Cikis(){
    exit(0);
}
void Anamenu(){
    int b;
    printf("\nMevcut arac sayisi: %d \n",s);
    printf(" Arac eklemek icin 1\n Araclari listelemek icin 2\n Cikis icin 3'e basiniz.\n");
    scanf("%d",&b);
    switch(b){
    case 1:
        AracEkle();
    case 2:
        AraclariListele();
    case 3:
         Cikis();
    }
}
