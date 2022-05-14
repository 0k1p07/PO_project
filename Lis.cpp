#pragma once
#include "Lis.h"


int Lis::mozliwoscRuchu(WspXY kierunki[4])
{
	int polozenie_x = wspolrzedne.getwX();
	int polozenie_y = wspolrzedne.getwY();
	int ilosc_dostepnych_kierunkow = 0;
	//po prawej
	if (polozenie_x + 1 < uniwersum->getX())
	{
		WspXY wsp(polozenie_y, polozenie_x + 1);
		Organizm* na_polu = uniwersum->getPole(wsp);
		if (na_polu == NULL || na_polu->getSila() < sila)
		{
			kierunki[ilosc_dostepnych_kierunkow] = wsp;
			ilosc_dostepnych_kierunkow++;
		}
	}
	//po lewej
	if (polozenie_x - 1 >= 0)
	{
		WspXY wsp(polozenie_y, polozenie_x - 1);
		Organizm* na_polu = uniwersum->getPole(wsp);
		if (na_polu == NULL || na_polu->getSila() < sila)
		{
			kierunki[ilosc_dostepnych_kierunkow] = wsp;
			ilosc_dostepnych_kierunkow++;
		}
	}
	//na gorze
	if (polozenie_y + 1 < uniwersum->getY())
	{
		WspXY wsp(polozenie_y + 1, polozenie_x);
		Organizm* na_polu = uniwersum->getPole(wsp);
		if (na_polu == NULL || na_polu->getSila() < sila)
		{
			kierunki[ilosc_dostepnych_kierunkow] = wsp;
			ilosc_dostepnych_kierunkow++;
		}
	}
	//na dole
	if (polozenie_y - 1 >= 0)
	{
		WspXY wsp(polozenie_y - 1, polozenie_x);
		Organizm* na_polu = uniwersum->getPole(wsp);
		if (na_polu == NULL || na_polu->getSila() < sila)
		{
			kierunki[ilosc_dostepnych_kierunkow] = wsp;
			ilosc_dostepnych_kierunkow++;
		}
	}
	return ilosc_dostepnych_kierunkow;
}

Organizm* Lis::potomek(WspXY wybrane_pole)
{
	return new Lis( wybrane_pole,uniwersum);
}

Lis::Lis(WspXY wsp, Swiat* uni)
{
	id = gatunek(lis);
	sila = 3;
	inicjatywa = 7;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_LISA;
	wiek = 0;
	tura_ostatniego_rozmozenia = -1;
}

Lis::~Lis() {}

void Lis::rysowanie() const
{
	changeColour(KOLOR_L);
	printf("L");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void Lis::Wypisz(std::ostream& out) const
{
	out << "Lis Sila(" << sila << ") Wiek(" << wiek << ") Inicjatywa(" << inicjatywa << ") XY" << wspolrzedne << " ";
}

