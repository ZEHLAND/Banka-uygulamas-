

//Bankamatik uygulamas� kullanc� bilgilerini isteyerek 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main(void)
{
	setlocale(LC_ALL, "Turkish"); 
	char isim[5] = "ali"; //Burada kulan�c�n�n ismini ve parolas�n� giriyoruz ki bankaya girerken yanl�� parola girilince i�lem yap�lmas�n diye
	int parola = 1234;
	int bakiye = 100;
	int secim;
	int yatirilacak_para;
	int cekilecek_para;

	char istenicek_isim[100];
	int istenicek_parola;
	int deneme=1;
	int kalan=0;

	printf("Bankamatige hosgeldiniz :) \n\nLutfen isminizi giriniz:");  //Bu 4 sat�rda m�steri isim ve parolas�n� girmesini istedik
	scanf("%s", &istenicek_isim, sizeof(istenicek_isim)); //Normalde sizeof olmas�ne gerek yok faat vs code sntax hatas� verdi�i i�in kullanmak zorunday�z 
	printf("Lutfen sifrenizi giriniz:");
	scanf("%d", &istenicek_parola);
	
	while(deneme<3 && istenicek_parola!=parola)
	{
		if(istenicek_parola==parola)
		{
			printf("Do�ru Paralo Tebrikler...");
			break;
		}
		else
		{
			deneme=deneme+1;
			kalan = 3 - deneme;
			printf("L�tfen Tekrar Deneyiniz./ %d kalan deneme ",kalan);
			scanf("%d", &istenicek_parola);
		} 
    }
	  if (strcmp(isim, istenicek_isim) == 0 && deneme<3) //Burada strcmp komutu k�sayoldur yani isim ile al�nacak ismi kars�la�t�r�p ayn� ise i�leme devam ediyor
	   {
		printf("\nBasarili bir sekilde giris saglanmistir:\n\n");
		printf("Lutfen isleminizi seciniz :)\n1-) Para Yatirma\n2-)Para cekme\n3-) Kullanici bilgileri\n");
	     scanf("%d", &secim);

   	  if (secim == 1)
		{
			printf("Lutfen paranizi yatiriniz:");
			scanf("%d", &yatirilacak_para);
			bakiye = bakiye + yatirilacak_para;
			printf("Paraniz basarili bir sekilde yatirilmistir\nYatirdiginiz para=%d\nGuncel bakiyeniz=%d", yatirilacak_para, bakiye);
		}
        else if (secim == 2)
		{
			printf("Cekilecek para miktarini giriniz:");
			scanf("%d", &cekilecek_para);
			bakiye = bakiye - cekilecek_para;
			printf("Paraniz basarili bir sekilde ceilmistir\ncektiginiz para=%d\nGuncel bakiyeniz=%d", cekilecek_para, bakiye);
		}
	    else if (secim == 3)
		{
			printf("Kullanici arayuzune hosgeldiniz :)\n");
			printf("Kullanici adiniz:%s\nKullanici sifreniz:%d\nHesabinizdaki bakiye=%d\n\n\n", isim, parola, bakiye);
		}
		else
			printf("Yanlis secim yaptiniz lutfen tekrar giriniz:\n\n");
	}
	else
	{
		printf("��FRE VEYA �S�M HATALI L�TFEN TEKRAR DENEY�N�Z...\n");
	}
	
    system("PAUSE");
	return 0;
}
