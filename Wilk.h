#pragma once
#include "Zwierze.h"

class Wilk :
	public Zwierze
{
public:
	Wilk(WspXY wsp, Swiat* uni);
	~Wilk() override;

	void rysowanie() const override;
	void Wypisz(std::ostream& out) const override;

	Organizm* potomek(WspXY wybrane_pole) override;
};

