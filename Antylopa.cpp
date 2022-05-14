#pragma once
#include "Antylopa.h"


int Antylopa::mozliwoscRuchu(WspXY kierunki[4])
{
	int polozenie_x = wspolrzedne.getwX();
	int polozenie_y = wspolrzedne.getwY();
	int ilosc_dostepnych_kierunkow = 0;

	//po prawej
	if (polozenie_x + 2 < uniwersum->getX())
	{
		WspXY wsp(polozenie_y, polozenie_x + 2);
		Organizm* na_polu = uniwersum->getPole(wsp);
		if (na_polu == NULL || na_polu->getSila() < sila)
		{
			kierunki[ilosc_dostepnych_kierunkow] = wsp;
			ilosc_dostepnych_kierunkow++;
		}
	}
	//po lewej
	if (polozenie_x - 2 >= 0)
	{
		WspXY wsp(polozenie_y, polozenie_x - 2);
		Organizm* na_polu = uniwersum->getPole(wsp);
		if (na_polu == NULL || na_polu->getSila() < sila)
		{
			kierunki[ilosc_dostepnych_kierunkow] = wsp;
			ilosc_dostepnych_kierunkow++;
		}
	}
	//na gorze
	if (polozenie_y + 2 < uniwersum->getY())
	{
		WspXY wsp(polozenie_y + 2, polozenie_x);
		Organizm* na_polu = uniwersum->getPole(wsp);
		if (na_polu == NULL || na_polu->getSila() < sila)
		{
			kierunki[ilosc_dostepnych_kierunkow] = wsp;
			ilosc_dostepnych_kierunkow++;
		}
	}
	//na dole
	if (polozenie_y - 2 >= 0)
	{
		WspXY wsp(polozenie_y - 2, polozenie_x);
		Organizm* na_polu = uniwersum->getPole(wsp);
		if (na_polu == NULL || na_polu->getSila() < sila)
		{
			kierunki[ilosc_dostepnych_kierunkow] = wsp;
			ilosc_dostepnych_kierunkow++;
		}
	}

	return ilosc_dostepnych_kierunkow;
}

wynik_kolizji Antylopa::kolizja(Organizm* wchodzacy)
{
	if (wchodzacy->getID() == this->id)
	{
		this->rozmnozenie();
		return wynik_kolizji(rozmnazanie);
	}

	int szansa_na_ucieczke = rand() % 100;

	if (szansa_na_ucieczke<50)
	{
		WspXY wolne_pola[4];
		int ilosc_wolnych_pol = uniwersum->wolnePola(wspolrzedne, wolne_pola);
		if (ilosc_wolnych_pol > 0)
		{
			WspXY wybrane_pole = wolne_pola[rand() % ilosc_wolnych_pol];
			uniwersum->przesun_organizm(this, wybrane_pole);
			std::cout << *this << "uciekla na " << wybrane_pole;
			return wynik_kolizji(ruch);
		}
	}
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

Organizm* Antylopa::potomek(WspXY wybrane_pole)
{
	return new Antylopa(wybrane_pole,uniwersum);
}

Antylopa::Antylopa(WspXY wsp, Swiat* uni)
{
	id = gatunek(antylopa);
	sila = 4;
	inicjatywa = 4;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_ANTYLOPY;
	wiek = 0;
	tura_ostatniego_rozmozenia = -1;
}

Antylopa::~Antylopa() {}

void Antylopa::rysowanie() const
{
	changeColour(KOLOR_A);
	printf("A");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void Antylopa::Wypisz(std::ostream& out) const
{
	out << "Antylopa Sila(" << sila << ") Wiek(" << wiek << ") Inicjatywa(" << inicjatywa << ") XY" << wspolrzedne << " ";
}

