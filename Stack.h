#pragma once
#include <iostream>
#include <ostream>
#include "Queue.h"

using namespace std;

struct Yigin {
	Kuyruk k1, k2; //y���n i�in kullan�lacak kuyruk de�i�kenleri
	void olustur(); //ba�lang�� i�in gereken tan�mlar� i�erir
	void kapat(); //program bitiminde bellek iadesi yapar
	void ekle(int); //kuyru�a yeni veri ekler
	int cikar(); //kuyruktan s�radaki eleman� ��kar�r
	bool bosMu(); //kuyruk bo� mu kontrol eder
	int tepe(); //y���n�n tepesindeki eleman� okur
	void yazdir(); //y���n elemanlar�n� s�rayla ekrana yazar
	int size;
};


inline void Yigin::olustur()
{
	size = 0;
	k1.olustur();
	k2.olustur();
}

inline void Yigin::kapat()
{
	k1.kapat();
	k2.kapat();
}

inline void Yigin::ekle(int data)
{
	size++;
	k2.ekle(data);

	while (!k1.bosmu())
	{
		k2.ekle(k1.bas->veri);
		k1.cikar();
	}

	Kuyruk k = k1;
	k1 = k2;
	k2 = k;
}

inline int Yigin::cikar()
{
	if (k1.bosmu()) 
		return 0;

	size--;
	return k1.cikar();

}

inline bool Yigin::bosMu()
{
	return size == 0;
}

inline int Yigin::tepe()
{
	if (k1.bosmu())
		return -1;
	return k1.bas->veri;
}

inline void Yigin::yazdir()
{
	while (!bosMu())
	{
		cout << tepe() << " ";
		cikar();
	}

}
