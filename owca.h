#pragma once
#include "Zwierze.h"
class Owca :
	public Zwierze
{
public:
	Owca(WspXY wsp, Swiat* uni);
	~Owca() override;

	void rysowanie() const override;
	void Wypisz(std::ostream& out) const override;

	Organizm* potomek(WspXY wybrane_pole) override;
};

