#pragma once
#include "Roslina.h"
class Guarana :
	public Roslina
{
public:
	Guarana(WspXY wsp, Swiat* uni);
	~Guarana() override;

	wynik_kolizji kolizja(Organizm* wchodzacy) override;

	void rysowanie() const override;
	inline void Wypisz(std::ostream& out) const override;

	Organizm* potomek(WspXY wsp) override;
};

