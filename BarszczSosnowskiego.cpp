#pragma once
#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(WspXY wsp, Swiat* uni)
{
	id = gatunek(barszcz_sosnowskiego);
	sila = 10;
	inicjatywa = 0;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_BARSZCZUSOSNOWSKIEGO;
	wiek = 0;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {}

wynik_kolizji BarszczSosnowskiego::kolizja(Organizm* wchodzacy)
{
	uniwersum->zabijOrganizm(this);
	return wynik_kolizji(smierc);
}

void BarszczSosnowskiego::akcja()
{
	wiek++;
	std::cout << *this;

	rozsiewanie();

	Organizm* zwierzeta[4];
	int ilosc_zwierzat = zwierzetaWokol(zwierzeta);
	for (int i = 0; i < ilosc_zwierzat; i++)
	{
		zatrujZwierze(zwierzeta[i]);
	}
}

int BarszczSosnowskiego::zwierzetaWokol(Organizm* pola[4])
{
	int polozenie_x = wspolrzedne.getwX();
	int polozenie_y = wspolrzedne.getwY();
	int ilosc_zwierzat = 0;
	//po prawej
	if (polozenie_x + 1 < uniwersum->getX())
	{
		WspXY wsp(polozenie_y, polozenie_x + 1);
		Organizm* pole = uniwersum->getPole(wsp);
		if (pole != NULL && pole->getID() >= 0)
		{
			pola[ilosc_zwierzat] = pole;
			ilosc_zwierzat++;
		}
	}
	//po lewej
	if (polozenie_x - 1 >= 0)
	{
		WspXY wsp(polozenie_y, polozenie_x - 1);
		Organizm* pole = uniwersum->getPole(wsp);
		if (pole != NULL && pole->getID() >= 0)
		{
			pola[ilosc_zwierzat] = pole;
			ilosc_zwierzat++;
		}
	}
	//na gorze
	if (polozenie_y + 1 < uniwersum->getY())
	{
		WspXY wsp(polozenie_y + 1, polozenie_x);
		Organizm* pole = uniwersum->getPole(wsp);
		if (pole != NULL && pole->getID() >= 0)
		{
			pola[ilosc_zwierzat] = pole;
			ilosc_zwierzat++;
		}
	}
	//na dole
	if (polozenie_y - 1 >= 0)
	{
		WspXY wsp(polozenie_y - 1, polozenie_x);
		Organizm* pole = uniwersum->getPole(wsp);
		if (pole != NULL && pole->getID() >= 0)
		{
			pola[ilosc_zwierzat] = pole;
			ilosc_zwierzat++;
		}
	}
	return ilosc_zwierzat;
}

void BarszczSosnowskiego::zatrujZwierze(Organizm* pole)
{
	goTo(MAP_X, MAP_Y + uniwersum->getY() + 6);
	std::cout << "i zatrul " << *pole;
	uniwersum->zabijOrganizm(pole);
}

void BarszczSosnowskiego::rysowanie() const
{
	changeColour(KOLOR_B);
	printf("b");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void BarszczSosnowskiego::Wypisz(std::ostream& out) const
{
	out << "Barszcz Sosnowskiego Sila(" << sila << ") Wiek(" << wiek << ") XY" << wspolrzedne << " ";
}

Organizm* BarszczSosnowskiego::potomek(WspXY wsp)
{
	return new BarszczSosnowskiego(wsp, uniwersum);
}
