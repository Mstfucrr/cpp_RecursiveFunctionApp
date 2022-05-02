
#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

void siraliEkle(struct Yigin* s, int x)
{
    if (s->bosMu() || x > s->tepe()) {
        s->ekle(x);
        return;
    }

    int temp = s->cikar();
    siraliEkle(s, x);

    s->ekle(temp);
}

void yiginCikar(Yigin* s)
{
	if (!s->bosMu())
	{
		int x = s->cikar();
		yiginCikar(s);
        siraliEkle(s, x);
	}
}

int main()
{
    cout << endl;

    Yigin y;
    y.olustur();
    y.ekle(3);
    y.ekle(1);
    y.ekle(7);
    y.ekle(4);
    y.ekle(8);
    cout << "Orjinal Yigin: " << endl;
    y.yazdir();
    y.kapat();
    cout << endl;
    cout << "------------------------" << endl;

    y.olustur();
    y.ekle(3);
    y.ekle(1);
    y.ekle(7);
    y.ekle(4);
    y.ekle(8);
    cout << "Sirali Yigin: " << endl;

    yiginCikar(&y);

    y.yazdir();
    y.kapat();
    cout << endl;
    cout << endl;

}