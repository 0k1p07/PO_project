#pragma once
#include <iostream>
#include <conio.h>
#include "stale.cpp"
#include "WspXY.h"
#include "Swiat.h"
#include "f_rys.h"

class Swiat;

class Organizm
{
public:
	virtual void akcja() = 0;
	virtual wynik_kolizji kolizja(Organizm* wchodzacy) = 0;
	virtual void rysowanie() const = 0;
	
	WspXY getWspolrzedne() const;
	gatunek getID() const;
	virtual int getSila() const;
	void setWsporzedne(WspXY nowe_wsp);

	virtual inline void Wypisz(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& os, Organizm& organizm);
	bool operator <(const Organizm& o);

	virtual ~Organizm();
protected:
	gatunek id;
	int sila;
	int inicjatywa;
	WspXY wspolrzedne;
	Swiat* uniwersum;
	int plodnosc;
	int wiek;
};