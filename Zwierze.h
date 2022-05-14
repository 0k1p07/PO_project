#pragma once
#include "Organizm.h"

class Zwierze :
	public Organizm
{
public:

	void rozmnozenie();
	virtual ~Zwierze();
	virtual void akcja();
	virtual wynik_kolizji kolizja(Organizm* wchodzacy);

	virtual int mozliwoscRuchu(WspXY kierunki[4]);
	void zwiekszSile(int modyfikator);
	virtual Organizm* potomek(WspXY wybrane_pole) = 0;

protected:
	int tura_ostatniego_rozmozenia;
};

