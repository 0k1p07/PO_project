#pragma once
#include "Zwierze.h"
class Czlowiek :
	public Zwierze
{
public:
	Czlowiek(WspXY wsp, Swiat* uni);
	~Czlowiek() override;

	int getSila() const override;

	void wypijEliksir();

	void rysowanie() const override;
	void Wypisz(std::ostream& out) const override;

	wynik_kolizji kolizja(Organizm* wchodzacy) override;
	void akcja() override;

	Organizm* potomek(WspXY wybrane_pole) override;
private:
	int umiejetnosc_cooldown;
	int magiczny_eliksir;
};

