#include<stdio.h>


//Değişkenler tanımlanıyor...
int a[4096];
int b[4096];
int c[8192][8192];

int aa[4096];
int bb[4096];
int cc[8192][8192];

int d[8192][4096];
int s[4096][6];

int s2[8192];

int au,bu = 0;



// Fonksiyonlar ön tanımlanıyor...
int sayiuzun();
int topla();
int cikar();
int carpma();
int bolme();
int temizle();


int main()
{

	printf("ok\n");

	return 0;
}

int temizle()
{
	for(int i=0;i<4096;i++)
	{
		a[i] = 0; b[i] = 0;
		aa[i] = 0; bb[i] = 0;
		
		for(int m=0;m<6;m++) {
		s[i][m] = 0; }
	}

	for(int j=0;j<8192;j++) {

	for(int n=0;n<4096;n++) {
	
		d[j][n] = 0;

	}	

		for(int k=0;k<8192;k++)    {
		c[j][k] = 0; cc[j][k] = 0; } 
	}

	for(int l=0;l<8192;l++) {
		s2[l] = 0;      }
	

	return 0;
}

int topla() //aa[] ve bb[] toplanacak sayılar c[][0] sonuç 
{

	int x,y,z;
	int i = 0;
	int cr = 0;	

	do
	{
		x = aa[i];
		y = bb[i];
		z = x + y;

		if(z>9) { cc[i+1][0] = 1;

		cc[i][0] = cc[i][0] + (z-10);
		
		} else {

		z = cc[i][0] + (z);		
		
		if(z>9) { cc[i][0] = (z-10); cc[i+1][0] = 1; } 
		//eğer elde 1 varsa 5+4+elde = 10
		
		else { cc[i][0] = z; } // olacağı için bu istisna burada yakalanıyor..

		}

		i++;
	} 
	while(i<4096);
	
}

int carp() //a[] çarpan b[] çarpım s2[] sonuç  
{

	int x,y,z;
	int i,j = 0;
	
	int t = 0;

	do { i = j;
	do
	{
		x = a[i]; // çarpan
		y = b[j]; // çarpım 
		z = x * y; // işlem
	
	if     (z>=90) { d[i+1][j] = 9; z = d[i][j] + (z - 90); }
	else if(z>=80) { d[i+1][j] = 8; z = d[i][j] + (z - 80); }
	else if(z>=70) { d[i+1][j] = 7; z = d[i][j] + (z - 70); }
	else if(z>=60) { d[i+1][j] = 6; z = d[i][j] + (z - 60); }
	else if(z>=50) { d[i+1][j] = 5; z = d[i][j] + (z - 50); }
	else if(z>=40) { d[i+1][j] = 4; z = d[i][j] + (z - 40); }
	else if(z>=30) { d[i+1][j] = 3; z = d[i][j] + (z - 30); }
	else if(z>=20) { d[i+1][j] = 2; z = d[i][j] + (z - 20); }
	else if(z>=10) { d[i+1][j] = 1; z = d[i][j] + (z - 10); }
	else           { z = d[i][j] + z; }
	
	if(z>9) { d[i+1][j]++; d[i][j] = (z - 10); }
	else { d[i][j] = z; }

		i++;

	} while(i<(j+4096)); j++; } while(j<4096);
	

	// sonuçlar alt alta birer basamak kaydırılarak yerleştirildikten
	// sonra toplama işlemine başla..


	i = 0; j = 0; 

	do { z = 0;
	do { z = z + d[i][j]; j++; } while(j<4096); // z nin içine sonuç
	// dizisi birer sütun şeklinde toplanır ve sonucu max 5 basamaklı
	// bir sayı olarak yerleşir sonra z nin içinden s[][] dizisine 
	// basamak ikinci boyut sonuçlar dizisi olarak yerleştirilir. 
	// s[sayı][basamak];

	if(z>=90000) { 	s[i][4] = 9; z = z - 90000; }
	if(z>=80000) { 	s[i][4] = 8; z = z - 80000; }
	if(z>=70000) { 	s[i][4] = 7; z = z - 70000; }
	if(z>=60000) { 	s[i][4] = 6; z = z - 60000; }
	if(z>=50000) { 	s[i][4] = 5; z = z - 50000; }
	if(z>=40000) { 	s[i][4] = 4; z = z - 40000; }
	if(z>=30000) { 	s[i][4] = 3; z = z - 30000; }
	if(z>=20000) { 	s[i][4] = 2; z = z - 20000; }
	if(z>=10000) { 	s[i][4] = 1; z = z - 10000; }

	if(z>=9000) { 	s[i][3] = 9; z = z - 9000; }
	if(z>=8000) { 	s[i][3] = 8; z = z - 8000; }
	if(z>=7000) { 	s[i][3] = 7; z = z - 7000; }
	if(z>=6000) { 	s[i][3] = 6; z = z - 6000; }
	if(z>=5000) { 	s[i][3] = 5; z = z - 5000; }
	if(z>=4000) { 	s[i][3] = 4; z = z - 4000; }
	if(z>=3000) { 	s[i][3] = 3; z = z - 3000; }
	if(z>=2000) { 	s[i][3] = 2; z = z - 2000; }
	if(z>=1000) { 	s[i][3] = 1; z = z - 1000; }

	if(z>=900) { 	s[i][2] = 9; z = z - 900; }
	if(z>=800) { 	s[i][2] = 8; z = z - 800; }
	if(z>=700) { 	s[i][2] = 7; z = z - 700; }
	if(z>=600) { 	s[i][2] = 6; z = z - 600; }
	if(z>=500) { 	s[i][2] = 5; z = z - 500; }
	if(z>=400) { 	s[i][2] = 4; z = z - 400; }
	if(z>=300) { 	s[i][2] = 3; z = z - 300; }
	if(z>=200) { 	s[i][2] = 2; z = z - 200; }
	if(z>=100) { 	s[i][2] = 1; z = z - 100; }

	if(z>=90) { 	s[i][1] = 9; z = z - 90; }
	if(z>=80) { 	s[i][1] = 8; z = z - 80; }
	if(z>=70) { 	s[i][1] = 7; z = z - 70; }
	if(z>=60) { 	s[i][1] = 6; z = z - 60; }
	if(z>=50) { 	s[i][1] = 5; z = z - 50; }
	if(z>=40) { 	s[i][1] = 4; z = z - 40; }
	if(z>=30) { 	s[i][1] = 3; z = z - 30; }
	if(z>=20) { 	s[i][1] = 2; z = z - 20; }
	if(z>=10) { 	s[i][1] = 1; z = z - 10; }

	s[i][0] = z;
	
	i++;

	} while (i<4096);
	

	//s2[] ye son sonuçtablosu max değer 45 olamk üzere yerleştirilir..
	


	int i1,i2,is = 0;
	
	for(int i3=0;i3<4096;i3++)
	{ 
		i2 = i3; i1 = 0;

		do {

		is = is + s[i1][i2]; 
		i1++; i2--; 
		
		} while(i2>=0);

		s2[i3] = is;
	}

	// max 45 olan değerleri (10 > 45) tekrar işliyor ve nihayi sonuca
	// ulaşıyor 

	i = 0;

	do { 
	if(s2[i]>39) { s2[i+2] = s2[i+2] + 4; s2[i] = s2[i] - 40; } 
	if(s2[i]>29) { s2[i+2] = s2[i+2] + 1; s2[i] = s2[i] - 30; } 
	if(s2[i]>19) { s2[i+2] = s2[i+2] + 1; s2[i] = s2[i] - 20; } 
	if(s2[i]>9) { s2[i+2] = s2[i+2] + 1; s2[i] = s2[i] - 10; } 
	i++; } while (i<4096);


	/*

	i = 0;

	do {
	z = z + s[i][0]; 
	i++;
	} while(i<4096);
		
	if(z>=90000) { z = z - 90000; s2[4] = s2[4] + 9; }
	if(z>=80000) { z = z - 80000; s2[4] = s2[4] + 8; }
	if(z>=70000) { z = z - 70000; s2[4] = s2[4] + 7; }
	if(z>=60000) { z = z - 60000; s2[4] = s2[4] + 6; }
	if(z>=50000) { z = z - 50000; s2[4] = s2[4] + 5; }
	if(z>=40000) { z = z - 40000; s2[4] = s2[4] + 4; }
	if(z>=30000) { z = z - 30000; s2[4] = s2[4] + 3; }
	if(z>=20000) { z = z - 20000; s2[4] = s2[4] + 2; }
	if(z>=10000) { z = z - 10000; s2[4] = s2[4] + 1; }
	
	if(z>=9000) { z = z - 9000; s2[3] = s2[3] + 9; }
	if(z>=8000) { z = z - 8000; s2[3] = s2[3] + 8; }
	if(z>=7000) { z = z - 7000; s2[3] = s2[3] + 7; }
	if(z>=6000) { z = z - 6000; s2[3] = s2[3] + 6; }
	if(z>=5000) { z = z - 5000; s2[3] = s2[3] + 5; }
	if(z>=4000) { z = z - 4000; s2[3] = s2[3] + 4; }
	if(z>=3000) { z = z - 3000; s2[3] = s2[3] + 3; }
	if(z>=2000) { z = z - 2000; s2[3] = s2[3] + 2; }
	if(z>=1000) { z = z - 1000; s2[3] = s2[3] + 1; }
	
	if(z>=900) { z = z - 900; s2[2] = s2[2] + 9; }
	if(z>=800) { z = z - 800; s2[2] = s2[2] + 8; }
	if(z>=700) { z = z - 700; s2[2] = s2[2] + 7; }
	if(z>=600) { z = z - 600; s2[2] = s2[2] + 6; }
	if(z>=500) { z = z - 500; s2[2] = s2[2] + 5; }
	if(z>=400) { z = z - 400; s2[2] = s2[2] + 4; }
	if(z>=300) { z = z - 300; s2[2] = s2[2] + 3; }
	if(z>=200) { z = z - 200; s2[2] = s2[2] + 2; }
	if(z>=100) { z = z - 100; s2[2] = s2[2] + 1; }
	
	if(z>=90) { z = z - 90; s2[1] = s2[1] + 9; }
	if(z>=80) { z = z - 80; s2[1] = s2[1] + 8; }
	if(z>=70) { z = z - 70; s2[1] = s2[1] + 7; }
	if(z>=60) { z = z - 60; s2[1] = s2[1] + 6; }
	if(z>=50) { z = z - 50; s2[1] = s2[1] + 5; }
	if(z>=40) { z = z - 40; s2[1] = s2[1] + 4; }
	if(z>=30) { z = z - 30; s2[1] = s2[1] + 3; }
	if(z>=20) { z = z - 20; s2[1] = s2[1] + 2; }
	if(z>=10) { z = z - 10; s2[1] = s2[1] + 1; }
	
	s2[0] = z;
	


	if(s2[1]>9) { s2[2]++; s2[1] = s2[1] - 10; }
	if(s2[2]>9) { s2[3]++; s2[2] = s2[2] - 10; }
	if(s2[3]>9) { s2[4]++; s2[3] = s2[3] - 10; }
	if(s2[4]>9) { s2[5]++; s2[4] = s2[4] - 10; }
	*/

	return 0;
}

int bolme() // a[] bölünen b[] bölen 
{
	int x,y;
	int s1,s2 = 0;


	if(sayiuzun()) { // a[] sayısı b[] den uzun veya aynı olmalı
		
		for(int k=4095;k>0;k--) {
	
		if(a[k] > 0 && b[k]<a[k]) { s1=1; break; }
		if(a[k] > 0 && b[k]>a[k]) { s1=0; break; } } 
		// a[] sayı değeri b[] den büyük olmalı

	if(s1>0) {

	do {

		cikarma();

		for(int k=4095;k>0;k--) {
	
		if(c[k][0] > 0 && b[k]<c[k][0]) { s1=1; break; }
		if(c[k][0] > 0 && b[k]>c[k][0]) { s1=0; break; } } 
		// a[] sayı değeri b[] den büyük olmalı

	} while(s1>0);

	} }

	return 0;
}

int cikarma() // a[] çıkartılan b[] çıkaran 
{

	int x,y;
	int s1,s2 = 0;
	int ii,jj = 0;

	if(sayiuzun()) { // a[] sayısı b[] den uzun veya aynı olmalı ve uzunluklar 
	// au ve bu değişkenlerine set edilmeli
		
		for(int k=4095;k>0;k--) {
	
		if(a[k] > 0 && b[k]<a[k]) { s1=1; break; }
		if(a[k] > 0 && b[k]>a[k]) { s1=0; break; } } 
		// a[] sayı değeri b[] den büyük olmalı

	if(s1>0) {

	do {
	
		s2 = b[ii] - a[ii]; // a[] dan b[] çıkartıp ilk sonucu s2 ye koy
	
		if(s2>=0) { c[ii][0] = s2; } // ilk sonuç 0 dan küçük olmamalı 

		else { // 0 dan küçükse eğer

			for(int i=1;i<4096;i++) { 
			// bir fazla başlamalı bir rakam önden başlayacak

				if(a[ii+i] > 0) { // a[] nın bir önceki rakamı gözetle
				
					a[ii+i]--; // 0 dan büyükse bi rakam al

					c[ii][0] = s2 + 10; // mevcut rakama 10 ekle

					break;

				} else { a[ii+i] = 9; } // if(a[ii+i] > 0) sonu..

	// birden fazla rakam 0 çıkarsa aralara 9 eklemek gerekecek 
	// 20001 için :> 2000|1 den 2 çıkınca > 1999|11 yani 1999|9 kalır ... 

				} // for(int i=1;i<4096;i++) sonu..
 
			}  // else sonu..

	au--; ii++;  

	} while (au>0); // do sonu..

	} //if(s1>0) 

	} // if(sayiuzun) sonu..

	return 0;
}


int sayiuzun()
{
	au = 0; bu = 0;	
	int su = 0;
	
	for(int i=4095;i>0;i--) { // bölünen sayının rakamları sol baştan inceleniyor 
	if(a[i]>0) { au = i; break; } } // sıfırdan farklı rakam görüldüğünde a[] sayı-
	// sının uzunluğunu da bulmuş olacağız
	
	for(int j=4095;j>0;j--) { // bölen sayının rakamları sol baştan inceleniyor 
	if(b[j]>0) { bu = j; break; } } // sıfırdan farklı rakam görüldüğünde b[] sayı-
	// sının uzunluğunu da bulmuş olacağız

	if(au>=bu) { su = 1; }  // eğer a[] daha uzun veya eşit ise b[] den 1 çevirir

	return su;
}




