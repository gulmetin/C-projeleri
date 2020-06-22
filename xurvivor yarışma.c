#include <stdio.h>
#include <stdlib.h>
int parkur(){
    int a= 49+rand()%101;
    return a;
}
int kacengel(){
    int a= 2+rand()%5;
    return a;
}
int  engelmetre(int p){
    int a= 5+rand()%p;
    return a;
}
int aralarindaasal(int HP,int b){
   int ks;
   if(HP<b)ks=HP;
   else ks=b;

   for(int i=2;i<=ks;i++){
      if(HP%i==0 && b%i==0)
         return 1;
   }
   return 2;
}
void siralama(int e,int *engelmet){

   for(int i=1; i<e; i++)
     {
         for(int j=0; j<e-i; j++)
         {
             if(engelmet[j] > engelmet[j+1])
             {
                      int tut = engelmet[j];
                        engelmet[j] = engelmet[j+1];
                        engelmet[j+1] = tut;
             }
         }
     }

}
void oyun(){
srand(time(NULL));
    FILE *pDosya;
    pDosya = fopen("Log.txt","w");
    int HP=100;
    printf("XURVIVOR yarismasina hosgeldiniz.\n");
    printf("Yarisma basladi HP=%d\n",HP);
    fprintf(pDosya,"Yarisma basladi HP=%d\n",HP);

    int p = parkur();
    printf("parkur %d\n",p);
    int e = kacengel();
    printf("engel %d",e);
    int *engelmet;
    engelmet= malloc(sizeof(int)*e);

    for(int i=0;i<e;i++){
        engelmet[i]= engelmetre(p);
              for(int j=0;j<i;j++){
                    if(engelmet[j]==engelmet[i])
                        i--;
                  }
    }

   siralama(e,engelmet);

     for(int i=0;i<e;i++){
        printf("\n %d", engelmet[i]);
     }

     for(int i=0;i<e;i++){
         printf("\nYarismaci %d. metrede bir engelle karsilasti.\n",engelmet[i]);
         fprintf(pDosya,"\nYarismaci %d. metrede bir engelle karsilasti.\n",engelmet[i]);
         int r = aralarindaasal(HP,engelmet[i]);

         if(r==2){
            printf("%d ve %d aralarinda asaldir.\n",HP,engelmet[i]);
            fprintf(pDosya,"%d ve %d aralarinda asaldir.\n",HP,engelmet[i]);
            HP=HP-engelmet[i];
         }
         else if(r==1){
            printf("%d ve %d aralarinda asal degildir.\n",HP,engelmet[i]);
            fprintf(pDosya,"%d ve %d aralarinda asal degildir.\n",HP,engelmet[i]);
         }

         printf("HP= %d\n",HP);
         fprintf(pDosya,"HP= %d\n",HP);
          if(HP<0){
            i=e;
            printf("Can kalmadi.Yarisma bitti.Tekrar deneyin.\n");
            fprintf(pDosya,"Can kalmadi.Yarisma bitti.Tekrar deneyin.\n");
          }

     }

     if(HP>0){
        printf("TEBRIKLER! Kazandiniz.");
        fprintf(pDosya,"TEBRIKLER! Kazandiniz.");
     }


    free(engelmet);


}
int main()
{
    oyun();
    return 0;
}
