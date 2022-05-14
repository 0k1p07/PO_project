#pragma once
#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(WspXY wsp, Swiat* uni)
{
	id = gatunek(wilcze_jagody);
	sila = 99;
	inicjatywa = 0;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_WILCZYCHJAGOD;
	wiek = 0;
}

WilczeJagody::~WilczeJagody() {}

wynik_kolizji WilczeJagody::kolizja(Organizm* wchodzacy)
{
	return wynik_kolizji(smierc);
}

void WilczeJagody::rysowanie() const
{
	changeColour(KOLOR_J);
	printf("j");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void WilczeJagody::Wypisz(std::ostream& out) const
{
	out << "Wilcze Jagody Sila(" << sila << ") Wiek(" << wiek << ") XY" << wspolrzedne << " ";
}

Organizm* WilczeJagody::potomek(WspXY wsp)
{
	return new WilczeJagody(wsp, uniwersum);
}