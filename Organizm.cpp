#pragma once
#include "Organizm.h"



std::ostream& operator<<(std::ostream& os, Organizm& organizm)
{
	organizm.Wypisz(os);
	return os;
}

bool Organizm::operator <(const Organizm& o)
{
	if (this->inicjatywa != o.inicjatywa)
	{
		return (inicjatywa < o.inicjatywa);
	}
	else
	{
		return (this->wiek < o.wiek);
	}

}

WspXY Organizm::getWspolrzedne() const
{
	return wspolrzedne;
}

gatunek Organizm::getID() const
{
	return id;
}

int Organizm::getSila() const
{
	return sila;
}

void Organizm::setWsporzedne(WspXY nowe_wsp)
{
	wspolrzedne = nowe_wsp;
}

Organizm::~Organizm() {}
