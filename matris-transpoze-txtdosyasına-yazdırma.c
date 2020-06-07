#include <stdio.h>
#include <stdlib.h>

int yeniMatris()
{   srand(time(NULL));

    int sa,su,i,j,b,**matris;
    printf("Dizi satirini giriniz.");
    scanf("%d", &sa);
    printf("Dizi sutununu giriniz.");
    scanf("%d", &su);
    if(sa>su)
       b=sa;
    else
       b=su;
    matris=calloc(sa,sizeof(int));
    for(i=0;i<b;i++){
        matris[i]=calloc(su,sizeof(int));
    }
    if(matris==NULL){
        printf("Yetersiz bellek alani.\n");
        }

    else{
        printf("Yer basariyla ayrilmistir.\n");
        printf("\nMatris\n");
        for(i=0;i<sa;i++)
        {
            for(j=0;j<su;j++){
               matris[i][j]=5+rand()%39995;
               printf("%d\t",matris[i][j]);
            }
          printf("\n");
        }


        bubbleSort(sa,su,matris);
    }
    free(matris);
}
  void bubbleSort(int sa,int su,int **dizi)
{
    int tut,i,j,k,a;
    for(a=0; a<(sa*su); a++){
        for(i=0;i<sa;i++){
            for(j=0;j<su;j++){
                    for(k=j+1;k<su;k++){
                        if(dizi[i][j]>dizi[i][j+1]){
                            tut=dizi[i][j];
                            dizi[i][j]=dizi[i][j+1];
                            dizi[i][j+1]=tut;}
                    }
                    if((i+1)<sa){
                            if(dizi[i][su-1]>dizi[i+1][1]){
                            tut=dizi[i][su-1];
                            dizi[i][su-1]=dizi[i+1][1];
                            dizi[i+1][1]=tut;}}
                    else{
                        if(dizi[sa-2][su-1]>dizi[sa-1][1]){
                            tut=dizi[sa-2][su-1];
                            dizi[sa-2][su-1]=dizi[sa-1][1];
                            dizi[sa-1][1]=tut;}}
            }

       }
    }
    printf("Siralama\n");
    for(i=0;i<sa;i++)
        {
            for(j=0;j<su;j++){
               printf("%d\t",dizi[i][j]);
            }
          printf("\n");
        }
    tdosyaYazdir(sa,su,dizi);
}
int tdosyaYazdir(int sa,int su,int **dizi)
{
    FILE *pDosya;
    int i,j,b,**transpoze;
    if(sa>su)
       b=sa;
    else
       b=su;
    transpoze=calloc(b,sizeof(int));
    for(i=0;i<b;i++){
        transpoze[i]=calloc(b,sizeof(int));
    }
    for(i=0; i<sa; ++i){
        for(j=0; j<su; ++j)
        {
            transpoze[j][i] = dizi[i][j];
        }
    }

    pDosya = fopen("transpoze.txt","w");
    fprintf(pDosya,"\nMATRIS\n");
    for(i=0;i<sa;i++){
        for(j=0;j<su;j++){
            fprintf(pDosya,"%d\t",dizi[i][j]);
        }
        fprintf(pDosya,"\n");
    }
    fprintf(pDosya,"\nTRANSPOZE\n");

    for(i=0;i<su;i++){
        for(j=0;j<sa;j++){
            fprintf(pDosya,"%d\t",transpoze[i][j]);
        }
        fprintf(pDosya,"\n");
    }
fclose(pDosya);
printf("\nTranspoze yazdirma islemi tamam!\n");
kaprekar(sa,su,transpoze);

}
void kaprekar(int sa,int su, int **diziT){

    int *sayiK;
    int c=(sa*su),d=0;
    sayiK=calloc(c,sizeof(int));
     for(int i=0;i<su;i++){
        for(int j=0;j<sa;j++){
            int bas=1,sayikare,sayibas,sonuc=1,sonuc2=1;
            sayikare=(diziT[i][j]*diziT[i][j]);
            sayibas=diziT[i][j];
            while(sayibas>=10){
             sayibas=sayibas/10;
             bas++;
           }
           int sayikarebas=sayikare;
           int baskare=1;
           while(sayikarebas>=10){
             sayikarebas=sayikarebas/10;
             baskare++;
           }

    int ters=baskare-bas;
    for(int a=0;a<bas;a++){
            sonuc=sonuc*10;
     }

     for(int a=0;a<ters;a++){
        sonuc2=sonuc2*10;
     }
    int sag=sayikare%sonuc;
    int sol1=sayikare/sonuc2;
    int sol2=sayikare/(sonuc2*10);

    if((sag+sol1)==diziT[i][j]){
        sayiK[d]=diziT[i][j];
        d++;
    }
    else if((sag+sol2)==diziT[i][j]){
        sayiK[d]=diziT[i][j];
        d++;
    }

       }
      }

kaprekaryazdir(sa,su,sayiK);
}
void kaprekaryazdir(int sa,int su, int *sayiK){
    FILE *dosya;
    dosya = fopen("kaprekar.txt","w+");
    for(int i=0;i<(sa*su);i++)
            fprintf(dosya,"%d\t",sayiK[i]);
    if(sayiK[1]==0)
        fprintf(dosya,"\nKaprekar sayisi yoktur.\n");

    printf("\nKaprekar Yazdirma islemi tamam!");
    fclose(dosya);

}

int main()
{
    yeniMatris();
    return 0;
}

