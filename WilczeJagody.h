#pragma once
#include "Roslina.h"
class WilczeJagody :
	public Roslina
{
public:
	WilczeJagody(WspXY wsp, Swiat* uni);
	~WilczeJagody() override;

	wynik_kolizji kolizja(Organizm* wchodzacy) override;

	void rysowanie() const override;
	inline void Wypisz(std::ostream& out) const override;

	Organizm* potomek(WspXY wsp) override;
};

