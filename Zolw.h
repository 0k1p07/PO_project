#pragma once
#include "Zwierze.h"
class Zolw :
	public Zwierze
{
public:
	Zolw(WspXY wsp, Swiat* uni);
	~Zolw() override;

	void rysowanie() const override;
	void Wypisz(std::ostream& out) const override;

	int mozliwoscRuchu(WspXY kierunki[4]) override;
	wynik_kolizji kolizja(Organizm* wchodzacy) override;

	Organizm* potomek(WspXY wybrane_pole) override;
};

