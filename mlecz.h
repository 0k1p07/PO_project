#pragma once
#include "Roslina.h"

class Mlecz :
	public Roslina
{
public:
	Mlecz(WspXY wsp, Swiat* uni);
	~Mlecz() override;

	void rozsiewanie() override;

	void rysowanie() const override;
	inline void Wypisz(std::ostream& out) const override;

	Organizm* potomek(WspXY wsp) override;
};

