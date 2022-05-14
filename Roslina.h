#pragma once
#include "Organizm.h"
class Roslina :
	public Organizm
{
public:
	virtual ~Roslina();
	virtual void akcja();
	virtual wynik_kolizji kolizja(Organizm* wchodzacy);
	virtual void rozsiewanie();

	virtual Organizm* potomek(WspXY wsp) = 0;
};

