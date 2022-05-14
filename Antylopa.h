#pragma once
#include "Zwierze.h"
class Antylopa :
	public Zwierze
{
public:
	Antylopa(WspXY wsp, Swiat* uni);
	~Antylopa() override;

	void rysowanie() const override;
	void Wypisz(std::ostream& out) const override;

	int mozliwoscRuchu(WspXY kierunki[4]) override;
	wynik_kolizji kolizja(Organizm* wchodzacy) override;

	Organizm* potomek(WspXY wybrane_pole) override;
};

