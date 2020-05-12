#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int sayisalLotoIst[2][50];
int sansTopuIst1[2][35];
int sansTopuIst2[2][15];
int onNumaraIst[2][81];
int superLotoIst[2][55];
int sayisalLotoTP=0,sansTopuTP=0,on_numaraTP=0,superLotoTP=0;
void cekilisIst_duzenleme()
{
    int i;
    for(i=1;i<50;i++)
    {
        sayisalLotoIst[0][i]=i;
        sayisalLotoIst[1][i]=0;
    }
    for(i=1;i<35;i++)
    {
        sansTopuIst1[0][i]=i;
        sansTopuIst1[1][i]=0;
    }
    for(i=1;i<15;i++)
    {
        sansTopuIst2[0][i]=i;
        sansTopuIst2[1][i]=0;
    }
    for(i=1;i<81;i++)
    {
        onNumaraIst[0][i]=i;
        onNumaraIst[1][i]=0;
    }
    for(i=1;i<55;i++)
    {
        superLotoIst[0][i]=i;
        superLotoIst[1][i]=0;
    }
}
void cekirdek()
{
    int cekirdek=0;
    printf("Rastgele sayi ureticisi icin bir sayi giriniz: ");
    scanf("%d",&cekirdek);
    srand(cekirdek);
    system ("cls");
}
int main()
{
    cekilisIst_duzenleme();
    cekirdek();
    ana_menu();
}
void ana_menu()
{
    int secimAna=0;
    char secimCikis="";
    printf("  *****ANA MENU*****\n\n1. Sans oyunlari.\n2. Cekilis istatistikleri.\n3. Cikis.\nSeciminizi giriniz: ");
    scanf("%d",&secimAna);
    system ("cls");
    if (secimAna < 1 || secimAna > 3)
    {
        printf("Lutfen [1-3] araliginda bir deger giriniz.\n\n");
        ana_menu();
    }
    else if (secimAna == 1)
    {
        alt_menu();
    }
    else if (secimAna == 2)
    {
        cekilis_istatistikleri();
    }
    else if (secimAna == 3)
    {
        printf("Cikmak istediginize emin misiniz? (e/E/h/H) :");
        cikisAna:
        scanf("%s",&secimCikis);
        system ("cls");
        switch (secimCikis)
        {
            case 'e' :
            case 'E' :
                break;
            case 'h' :
            case 'H' :
                ana_menu();
            default :
                printf("Cikis icin lutfen (e/E/h/H) seceneklerinden birini seciniz!\n");
                goto cikisAna;
        }
    }
}
void alt_menu()
{
    int secimAlt,toplam_odul=0;
    toplam_odul=(sayisalLotoTP+sansTopuTP+on_numaraTP+superLotoTP);
    printf("*****SANS OYUNLARI ALT MENUSU*****\n\n1. Sayisal Loto Oynama.\n2. Sans Topu Oynama.\n3. On Numara Oynama.\n4. Super Loto Oynama.\n5. Ana Menu.\n(Toplam odulunuz: %d puan) Seciminizi giriniz: ",toplam_odul);
    scanf("%d",&secimAlt);
    system ("cls");
    if (secimAlt < 1 || secimAlt > 5)
    {
        printf("Lutfen [1-5] araliginda bir deger giriniz.\n\n");
        alt_menu();
    }
    else if (secimAlt == 1)
    {
        sayisal_loto();
    }
    else if (secimAlt == 2)
    {
        sans_topu();
    }
    else if (secimAlt == 3)
    {
        on_numara();
    }
    else if (secimAlt == 4)
    {
        super_loto();
    }
    else if (secimAlt == 5)
    {
        ana_menu();
    }
}
void cekilis_istatistikleri()
{
    int i,a,b,tut[2][1];
    system ("cls");
    printf("Sayisal loto icin en cok cikmis 6 sayi:\n");
    for(a=1;a<50;a++)
    {
        for(b=1;b<49;b++)
        {
            if (sayisalLotoIst[1][b]<sayisalLotoIst[1][b+1])
            {
                tut[0][0]=sayisalLotoIst[0][b];
                tut[1][0]=sayisalLotoIst[1][b];
                sayisalLotoIst[0][b]=sayisalLotoIst[0][b+1];
                sayisalLotoIst[1][b]=sayisalLotoIst[1][b+1];
                sayisalLotoIst[0][b+1]=tut[0][0];
                sayisalLotoIst[1][b+1]=tut[1][0];
            }
        }
    }
    for(i=1;i<7;i++)
    {
        printf("- %d sayisi %d kez cikti.\n",sayisalLotoIst[0][i],sayisalLotoIst[1][i]);
    }
    printf("\nSans topu icin en cok cikmis 5+1 sayi:\n");
    for(a=1;a<35;a++)
    {
        for(b=1;b<34;b++)
        {
            if (sansTopuIst1[1][b]<sansTopuIst1[1][b+1])
            {
                tut[0][0]=sansTopuIst1[0][b];
                tut[1][0]=sansTopuIst1[1][b];
                sansTopuIst1[0][b]=sansTopuIst1[0][b+1];
                sansTopuIst1[1][b]=sansTopuIst1[1][b+1];
                sansTopuIst1[0][b+1]=tut[0][0];
                sansTopuIst1[1][b+1]=tut[1][0];
            }
        }
    }
    for(i=1;i<6;i++)
    {
        printf("- %d sayisi %d kez cikti.\n",sansTopuIst1[0][i],sansTopuIst1[1][i]);
    }
    for(a=1;a<15;a++)
    {
        for(b=1;b<14;b++)
        {
            if (sansTopuIst2[1][b]<sansTopuIst2[1][b+1])
            {
                tut[0][0]=sansTopuIst2[0][b];
                tut[1][0]=sansTopuIst2[1][b];
                sansTopuIst2[0][b]=sansTopuIst2[0][b+1];
                sansTopuIst2[1][b]=sansTopuIst2[1][b+1];
                sansTopuIst2[0][b+1]=tut[0][0];
                sansTopuIst2[1][b+1]=tut[1][0];
            }
        }
    }
    printf("- (+) %d sayisi %d kez cikti.\n",sansTopuIst2[0][1],sansTopuIst2[1][1]);
    printf("\nOn numara icin en cok cikmis 10 sayi:\n");
    for(a=1;a<81;a++)
    {
        for(b=1;b<80;b++)
        {
            if (onNumaraIst[1][b]<onNumaraIst[1][b+1])
            {
                tut[0][0]=onNumaraIst[0][b];
                tut[1][0]=onNumaraIst[1][b];
                onNumaraIst[0][b]=onNumaraIst[0][b+1];
                onNumaraIst[1][b]=onNumaraIst[1][b+1];
                onNumaraIst[0][b+1]=tut[0][0];
                onNumaraIst[1][b+1]=tut[1][0];
            }
        }
    }
    for(i=1;i<11;i++)
    {
        printf("- %d sayisi %d kez cikti.\n",onNumaraIst[0][i],onNumaraIst[1][i]);
    }
    printf("\nSuper loto icin en cok cikmis 5 sayi:\n");
    for(a=1;a<55;a++)
    {
        for(b=1;b<54;b++)
        {
            if (superLotoIst[1][b]<superLotoIst[1][b+1])
            {
                tut[0][0]=superLotoIst[0][b];
                tut[1][0]=superLotoIst[1][b];
                superLotoIst[0][b]=superLotoIst[0][b+1];
                superLotoIst[1][b]=superLotoIst[1][b+1];
                superLotoIst[0][b+1]=tut[0][0];
                superLotoIst[1][b+1]=tut[1][0];
            }
        }
    }
    for(i=1;i<6;i++)
    {
        printf("- %d sayisi %d kez cikti.\n",superLotoIst[0][i],superLotoIst[1][i]);
    }
    do
    {
        printf("\nAna menuye donmek icin lutfen 0 giriniz!: ");
        scanf("%d",&a);
        system ("cls");
    }
    while(a!=0);
        ana_menu();
}
void sayisal_loto()
{
    int i,a,b,c,tut=0,sayisalLotoSayac=0,sayisalLotoPuan=0,rndSayi = 0,kdizi[6],bdizi[6];
    char d="";
    printf("-Lutfen [1-49] arasi 6 farkli sayi girin:\n");
    for(a=0; a<6;a++)
    {
        printf("%d. sayiyi giriniz: \n",a+1);
        scanf("%d", &b);
        if (b<1 || b>49)
        {
            printf("!Gecersiz sayi girdiniz!\n");
            a--;
            continue;
        }
        kdizi[a]=b;
    }
    //kullanici siralama
    for (a=0;a<6;a++)
    {
        for (b=0;b<5;b++)
        {
            if (kdizi[b]>kdizi[b+1])
            {
               tut=kdizi[b];
               kdizi[b]=kdizi[b+1];
               kdizi[b+1]=tut;
            }
        }
    }
    system ("cls");
    printf("-Sizin sayilariniz : ");
    for (i=0;i<6;i++)
    {
        printf("%d\t",kdizi[i]);
    }

    for (i=0; i<6; i++)
    {
        rndSayi = (rand()%49+1);
        for (c=0;c<i;c++)
        {
          if(rndSayi==bdizi[c])
            {
                break;
            }
        }
        if(c!=i)
        {
            i--;
            continue;
        }
        bdizi[i] = rndSayi;
        for(a=1;a<50;a++)
        {
            if(sayisalLotoIst[0][a]==rndSayi)
            {
                sayisalLotoIst[1][a]++;
            }
        }
    }
    //bilgisayar siralama
    for (a=0;a<6;a++)
    {
        for (b=0;b<5;b++)
        {
            if (bdizi[b]>bdizi[b+1])
            {
               tut=bdizi[b];
               bdizi[b]=bdizi[b+1];
               bdizi[b+1]=tut;
            }
        }
    }
    printf("\n\n-Cekiliste cikan sayilar : ");
    for (i=0;i<6;i++)
    {
        printf("%d\t",bdizi[i]);
    }
    for (a=0;a<6;a++)
    {
        for (b=0;b<6;b++)
        {
            if (kdizi[a]==bdizi[b])
            {
                sayisalLotoSayac++;
            }
        }
    }
    sayisalLotoPuan=0;
    printf("\n\n-Tutturdugunuz sayi adeti: %d",sayisalLotoSayac);
    if (sayisalLotoSayac==6)
    {
        sayisalLotoPuan += 256;
    }
    else if (sayisalLotoSayac==5)
    {
        sayisalLotoPuan += 128;
    }
    else if (sayisalLotoSayac==4)
    {
        sayisalLotoPuan += 64;
    }
    else if (sayisalLotoSayac==3)
    {
        sayisalLotoPuan += 32;
    }
    sayisalLotoTP+=sayisalLotoPuan;
    printf("\n\n-Bu oyundan kazandiginiz puan: %d\n\n-Sayisal loto oyunundan kazandiginiz toplam puan: %d\n\n-Bir oyun daha oynamak istiyor musunuz? (e/E/h/H): ",sayisalLotoPuan,sayisalLotoTP);
    cikis:
    scanf("%s",&d);
    system ("cls");
    switch (d)
    {
        default :
            printf("!Cikis icin lutfen (e/E/h/H) seceneklerinden birini seciniz!\n");
            goto cikis;
        case 'e' :
        case 'E' :
            sayisal_loto();
        case 'h' :
        case 'H' :
            alt_menu();
    }

}
void sans_topu()
{
    int i=0,a=0,c=0,b=0,tut=0,ksans,bsans,rndSayi,rndSayiSans,sansTopuPuan=0,sansTopuSayac=0,sansTopuSayac2=0,bdizisans[5],kdizisans[5];
    char d="";
    printf("-Lutfen [1-34] araliginda 5 farkli sayi girin:\n");
    for(a=0; a<5;a++)
    {
        printf("%d. sayiyi giriniz:\n",a+1);
        scanf("%d", &b);
        if (b<1 || b>34)
        {
           printf("!Gecersiz sayi girdiniz!\n");
           a--;
           continue;
        }
        kdizisans[a]=b;
    }
    do
    {
    printf("-Lutfen [1-14] araliginda sayi girin:\n");
    scanf("%d", &ksans);
    }
    while(ksans<1 || ksans>14);

    for (a=0;a<5;a++)
    {
        for (b=0;b<4;b++)
        {
            if (kdizisans[b]>kdizisans[b+1])
            {
               tut=kdizisans[b];
               kdizisans[b]=kdizisans[b+1];
               kdizisans[b+1]=tut;
            }
        }
    }
    system ("cls");
    printf("-Sizin sayilariniz: ");
    for (i=0;i<5;i++)
    {
        printf("%d\t",kdizisans[i]);
    }
    printf("+ %d",ksans);
    for (i=0; i<5; i++)
    {
        rndSayi = (rand()%34+1);
        for (c=0;c<i;c++)
        {
          if(rndSayi==bdizisans[c])
            {
                break;
            }
        }
        if(c!=i)
        {
            i--;
            continue;
        }
        bdizisans[i] = rndSayi;
        for(a=1;a<35;a++)
        {
            if(sansTopuIst1[0][a]==rndSayi)
            {
                sansTopuIst1[1][a]++;
            }
        }
    }
    rndSayiSans = (rand()%14+1);
    for(a=1;a<15;a++)
    {
        if(sansTopuIst2[0][a]==rndSayiSans)
        {
            sansTopuIst2[1][a]++;
        }
    }
    for (a=0;a<5;a++)
    {
        for (b=0;b<4;b++)
        {
            if (bdizisans[b]>bdizisans[b+1])
            {
               tut=bdizisans[b];
               bdizisans[b]=bdizisans[b+1];
               bdizisans[b+1]=tut;
            }
        }
    }
    printf("\n\n-Cekiliste cikan sayilar :");
    for (i=0;i<5;i++)
    {
        printf("%d\t",bdizisans[i]);

    }
    printf("+ %d",rndSayiSans);
    sansTopuSayac=0,sansTopuSayac2=0;
    for (a=0;a<5;a++)
    {
        for (b=0;b<5;b++)
        {
            if (kdizisans[a]==bdizisans[b])
            {
                sansTopuSayac++;
            }
        }
    }
    if (rndSayiSans==ksans)
    {
        sansTopuSayac2++;
    }
    printf("\n\n-Tutturdugunuz sayi adeti: %d",(sansTopuSayac+sansTopuSayac2));
    sansTopuPuan=0;
    if (sansTopuSayac==5 && sansTopuSayac2==1)
    {
        sansTopuPuan += 256;
    }
    else if (sansTopuSayac==5)
    {
        sansTopuPuan += 128;
    }
    else if (sansTopuSayac==4 && sansTopuSayac2==1)
    {
        sansTopuPuan += 64;
    }
    else if (sansTopuSayac==4 && sansTopuSayac2==1)
    {
        sansTopuPuan += 32;
    }
    else if (sansTopuSayac==3 && sansTopuSayac2==1)
    {
        sansTopuPuan += 16;
    }
    else if (sansTopuSayac==3)
    {
        sansTopuPuan +=8;
    }
    else if (sansTopuSayac==2 && sansTopuSayac2==1)
    {
        sansTopuPuan += 4;
    }
    else if (sansTopuSayac==1 && sansTopuSayac2==1)
    {
        sansTopuPuan += 2;
    }
    sansTopuTP+=sansTopuPuan;
    printf("\n\n-Bu oyundan kazandiginiz puan: %d\n\n-Sans topu oyunundan toplam kazandiginiz puan: %d\n\n-Bir oyun daha oynamak istiyor musunuz? (e/E/h/H): ",sansTopuPuan,sansTopuTP);
    cikis:
    scanf("%s",&d);
    system ("cls");
    switch (d)
    {
        default :
            printf("!Cikis icin lutfen (e/E/h/H) seceneklerinden birini seciniz!\n");
            goto cikis;
        case 'e' :
        case 'E' :
            sans_topu();
        case 'h' :
        case 'H' :
            alt_menu();
    }
}
void on_numara()
{
    int on_numaraSayac=0,on_numaraPuan=0,a,b,c,i,rndSayi=0,tut,kdizion_numara[10],bdizion_numara[22];
    char d="";
    printf("-Lutfen [1-80] arasinda 10 farkli sayi giriniz:\n");
    for(a=0;a<10;a++)
    {
        printf("%d. sayiyi giriniz:\n",a+1);
        scanf("%d",&b);
        if(b<1 || b>=81)
        {
            printf("!Gecersiz sayi girdiniz!\n");
            a--;
            continue;
        }
        kdizion_numara[a]=b;
    }
    for(a=0;a<10;a++)
    {
        for(b=0;b<9;b++)
        {
            if(kdizion_numara[b]>kdizion_numara[b+1])
            {
                tut=kdizion_numara[b];
                kdizion_numara[b]=kdizion_numara[b+1];
                kdizion_numara[b+1]=tut;
            }
        }
    }
    system ("cls");
    printf("-Sizin sayilariniz: ");
    for(i=0;i<10;i++)
    {
        printf("%d \t",kdizion_numara[i]);
    }
    for (i=0; i<22; i++)
    {
        rndSayi = (rand()%80+1);
        for (c=0;c<i;c++)
        {
          if(rndSayi==bdizion_numara[c])
            {
                break;
            }
        }
        if(c!=i)
        {
            i--;
            continue;
        }
        bdizion_numara[i] = rndSayi;
        for(a=1;a<81;a++)
        {
            if(onNumaraIst[0][a]==rndSayi)
            {
                onNumaraIst[1][a]++;
            }
        }
    }
    for(a=0;a<22;a++)
    {
        for(b=0;b<21;b++)
        {
            if(bdizion_numara[b]>bdizion_numara[b+1])
            {
                tut=bdizion_numara[b];
                bdizion_numara[b]=bdizion_numara[b+1];
                bdizion_numara[b+1]=tut;
            }
        }
    }
    printf("\n\n-Cekiliste cikan sayilar: ");
    for(i=0;i<22;i++)
    {
        printf(" %d\t",bdizion_numara[i]);
    }
    for(a=0;a<10;a++)
    {
        for(b=0;b<22;b++)
        {
            if(kdizion_numara[a]==bdizion_numara[b])
            {
                on_numaraSayac++;
            }
        }
    }
    printf("\n\n-Tutturdugunuz sayi adeti: %d",on_numaraSayac);
    if (on_numaraSayac==10)
    {
        on_numaraPuan += 256;
    }
    else if (on_numaraSayac==9)
    {
        on_numaraPuan += 128;
    }
    else if (on_numaraSayac==8)
    {
        on_numaraPuan += 64;
    }
    else if (on_numaraSayac==7)
    {
        on_numaraPuan += 32;
    }
    else if (on_numaraSayac==6)
    {
        on_numaraPuan += 16;
    }
    else if (on_numaraSayac==0)
    {
        on_numaraPuan += 8;
    }
    on_numaraTP+=on_numaraPuan;
    printf("\n\n-Bu oyundan kazandiginiz puan: %d\n\n-On numara oyunundan toplam kazangidiniz puan: %d\n\n-Bir oyun daha oynamak istiyor musunuz? (e/E/h/H): ",on_numaraPuan,on_numaraTP);
    cikis:
    scanf("%s",&d);
    system ("cls");
    switch (d)
    {
        default :
            printf("!Cikis icin lutfen (e/E/h/H) seceneklerinden birini seciniz!\n");
            goto cikis;
        case 'e' :
        case 'E' :
            on_numara();
        case 'h' :
        case 'H' :
            alt_menu();
    }
}
void super_loto()
{
    int i,a,b,c,tut=0,superlotoSayac=0,superlotoPuan=0,rndSayi = 0,kdizi[6],bdizi[6];
    char d="";
    printf("-Lutfen [1-54] arasi 6 farkli sayi girin!:\n");
    for(a=0; a<=5;a++)
    {
        printf("%d. sayiyi giriniz:\n",a+1);
        scanf("%d",&b);
        if (b<1 || b>=55)
        {
            printf("!Gecersiz sayi girdiniz!\n");
            a--;
            continue;
        }
        kdizi[a]=b;
    }
    //ksiralama
    for (a=0;a<6;a++)
    {
        for (b=0;b<5;b++)
        {
            if (kdizi[b]>kdizi[b+1])
            {
               tut=kdizi[b];
               kdizi[b]=kdizi[b+1];
               kdizi[b+1]=tut;
            }
        }
    }
    system ("cls");
    printf("-Sizin sayilariniz : ");
    for (i=0;i<6;i++)
    {
        printf("%d\t",kdizi[i]);
    }
    for (i=0; i<6; i++)
    {
        rndSayi = (rand()%54+1);
        for (c=0;c<i;c++)
        {
          if(rndSayi==bdizi[c])
            {
                break;
            }
        }
        if(c!=i)
        {
            i--;
            continue;
        }
        bdizi[i] = rndSayi;
        for(a=1;a<55;a++)
        {
            if(superLotoIst[0][a]==rndSayi)
            {
                superLotoIst[1][a]++;
            }
        }
    }
    //bsiralama
    for (a=0;a<6;a++)
    {
        for (b=0;b<5;b++)
        {
            if (bdizi[b]>bdizi[b+1])
            {
               tut=bdizi[b];
               bdizi[b]=bdizi[b+1];
               bdizi[b+1]=tut;
            }
        }
    }
    printf("\n\n-Cekiliste cikan sayilar : ");
    for (i=0;i<6;i++)
    {
        printf("%d\t",bdizi[i]);
    }
    for (a=0;a<6;a++)
    {
        for (b=0;b<6;b++)
        {
            if (kdizi[a]==bdizi[b])
            {
                superlotoSayac++;
            }
        }
    }
    printf("\n\n-Tutturdugunuz sayi adeti: %d",superlotoSayac);
    if (superlotoSayac==6)
    {
        superlotoPuan += 256;
    }
    else if (superlotoSayac==5)
    {
        superlotoPuan += 128;
    }
    else if (superlotoSayac==4)
    {
        superlotoPuan += 64;
    }
    else if (superlotoSayac==3)
    {
        superlotoPuan += 32;
    }
    superLotoTP+=superlotoPuan;
    printf("\n\n-Bu oyundan kazandiginiz puan: %d\n\n-Super loto oyunundan toplan kazandiginiz puan: %d\n\n-Bir oyun daha oynamak istiyor musunuz? (e/E/h/H): ",superlotoPuan,superLotoTP);
    cikis:
    scanf("%s",&d);
    system ("cls");
    switch (d)
    {
        default :
            printf("!Cikis icin lutfen (e/E/h/H) seceneklerinden birini seciniz!\n");
            goto cikis;
        case 'e' :
        case 'E' :
            super_loto();
        case 'h' :
        case 'H' :
            alt_menu();
    }
}
