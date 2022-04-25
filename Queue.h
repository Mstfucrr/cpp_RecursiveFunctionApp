#pragma once
#include <iostream>
#include <ostream>

using namespace std;

struct Dugum {
	int veri; //d���m�n say�sal de�eri
	Dugum* sonraki; //sonraki d���me i�aret�i
};
struct Kuyruk {
	Dugum* bas; //kuyru�un ba��ndaki eleman�n adresini tutar
	Dugum* son; //kuyru�un sonundaki eleman�n adresini tutar
	void olustur(); //ba�lang�� i�in gereken tan�mlar� i�erir
	void kapat(); //program bitiminde bellek iadesi yapar
	void ekle(int); //kuyru�a yeni veri ekler
	int cikar(); //kuyruktan s�radaki eleman� ��kar�r
	bool bosmu(); //kuyruk bo� mu kontrol eder
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


