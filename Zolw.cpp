#pragma once
#include "Zolw.h"

int Zolw::mozliwoscRuchu(WspXY kierunki[4])
{
	int polozenie_x = wspolrzedne.getwX();
	int polozenie_y = wspolrzedne.getwY();
	int ilosc_dostepnych_kierunkow = 0;

	int szansa_ruchu = rand() % 100;

	if (szansa_ruchu < 25)
	{
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
	}
	return ilosc_dostepnych_kierunkow;
}

wynik_kolizji Zolw::kolizja(Organizm* wchodzacy)
{
	if (wchodzacy->getID() == this->id)
	{
		this->rozmnozenie();
		return wynik_kolizji(rozmnazanie);
	}
	if (wchodzacy->getSila()>=5)
	{
		if (wchodzacy->getSila() < sila)
		{
			return wynik_kolizji(smierc);
		}
		else if (wchodzacy->getSila() >= sila)
		{
			std::cout << " zabil " << *this << " i ";
			uniwersum->zabijOrganizm(this);
			return wynik_kolizji(ruch);
		}
	}
	else
	{
		return wynik_kolizji(odepchniecie);
	}
}

Organizm* Zolw::potomek(WspXY wybrane_pole)
{
	return new Zolw(wybrane_pole, uniwersum);
}

Zolw::Zolw(WspXY wsp, Swiat* uni)
{
	id = gatunek(zolw);
	sila = 2;
	inicjatywa = 1;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_ZOLWIA;
	wiek = 0;
	tura_ostatniego_rozmozenia = -1;
}

Zolw::~Zolw() {}

void Zolw::rysowanie() const
{
	changeColour(KOLOR_Z);
	printf("Z");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void Zolw::Wypisz(std::ostream& out) const
{
	out << "Zolw Sila(" << sila << ") Wiek(" << wiek << ") Inicjatywa(" << inicjatywa << ") XY" << wspolrzedne << " ";
}

