#pragma once
#include "Roslina.h"
class Trawa :
	public Roslina
{
public:
	Trawa(WspXY wsp, Swiat *uni);
	~Trawa() override;

	void rysowanie() const override;
	inline void Wypisz(std::ostream& out) const override;

	Organizm* potomek(WspXY wsp) override;
};

