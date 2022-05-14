#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
	public Roslina
{

public:
	BarszczSosnowskiego(WspXY wsp, Swiat* uni);
	~BarszczSosnowskiego() override;

	wynik_kolizji kolizja(Organizm* wchodzacy) override;
	void akcja() override;

	void rysowanie() const override;
	inline void Wypisz(std::ostream& out) const override;

	int zwierzetaWokol(Organizm* pola[4]);
	void zatrujZwierze(Organizm* pole);

	Organizm* potomek(WspXY wsp) override;
};

