#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int sayilar[10], *diziPtr;
    int diziTek[10], *diziPT;
    int diziCift[10], *diziPC;
    int a=0,b=0; //tek ve cift atamasý icin

    diziPtr=sayilar;
    diziPT=diziTek;
    diziPC=diziCift;
    printf("Sayilar:\n");
    for(int i=0;i<10;i++)
    {
        *(diziPtr+i)= 1+rand()%100;
        printf("%d\n",*(diziPtr+i));

        if(*(diziPtr+i)%2==0){
         *(diziPC+a)= *(diziPtr+i);
         a++;
        }
        else{
         *(diziPT+b)= *(diziPtr+i);
         b++;
        }
    }
    printf("\nCift sayilar:\n");
    EkranaYazdir(diziCift,a);
    printf("\nTek sayilar:\n");
    EkranaYazdir(diziTek,b);

    return 0;

}
void EkranaYazdir(int dizi[],int n)
{
    int *pdizi;
    pdizi=dizi;
    for(int i=0;i<n;i++)
    {
        printf("%d\n", *(pdizi+i));
    }
}
