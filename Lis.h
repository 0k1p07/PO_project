#pragma once
#include "Zwierze.h"
class Lis :
	public Zwierze
{
public:
	Lis(WspXY wsp, Swiat* uni);
	~Lis() override;

	void rysowanie() const override;
	void Wypisz(std::ostream& out) const override;

	int mozliwoscRuchu(WspXY kierunki[4]) override;

	Organizm* potomek(WspXY wybrane_pole) override;
};

