#pragma once
#include <iostream>
#include <ostream>

using namespace std;

struct Dugum {
	int veri; //düðümün sayýsal deðeri
	Dugum* sonraki; //sonraki düðüme iþaretçi
};
struct Kuyruk {
	Dugum* bas; //kuyruðun baþýndaki elemanýn adresini tutar
	Dugum* son; //kuyruðun sonundaki elemanýn adresini tutar
	void olustur(); //baþlangýç için gereken tanýmlarý içerir
	void kapat(); //program bitiminde bellek iadesi yapar
	void ekle(int); //kuyruða yeni veri ekler
	int cikar(); //kuyruktan sýradaki elemaný çýkarýr
	bool bosmu(); //kuyruk boþ mu kontrol eder
};


inline void Kuyruk::olustur()
{
	bas = nullptr;
	son = nullptr;
	

}

inline void Kuyruk::kapat()
{
	Dugum* p;
	while (bas)
	{
		p = bas;
		bas = bas->sonraki;
		delete p;
	}
}

inline void Kuyruk::ekle(int data)
{
	Dugum* yenidugum = new Dugum;
	yenidugum->veri = data;
	yenidugum->sonraki = NULL;
	if (bas == NULL)
	{
		bas = yenidugum;
		son = bas;
		// ilk eleman ekle
	}
	else
	{
		son->sonraki = yenidugum;
		son = yenidugum;

	}
}

inline int Kuyruk::cikar()
{
	Dugum* ustdugum;
	int gecici;
	ustdugum = bas;
	bas = bas->sonraki;
	gecici = ustdugum->veri;
	delete ustdugum;
	return gecici;
}

inline bool Kuyruk::bosmu()
{
	return bas == NULL;
}


