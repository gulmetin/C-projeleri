#include <stdio.h>
#include <stdlib.h>

int main()
{
    char karakter[100];
    int uzunluk=0;
    int n=0;
    char ters[100];

    printf("Bir sey giriniz:\n");
    gets(karakter);

    uzunluk=strlen(karakter);
    for(n=0;n<uzunluk;n++)
    {
         ters[n]= karakter[uzunluk-1-n];
    }

      ters[n]='\0';
      printf("ters:%s\n",ters);
      int a=0;
       for(int i=0; i<uzunluk; i++)
      {
          if(ters[i]==' ')
            continue;
          else if(a<uzunluk){
            if(a%4==3)
                printf("%c,",ters[i]);
            else
               printf("%c",ters[i]);
            a++;
          }
      }


    return 0;
}
