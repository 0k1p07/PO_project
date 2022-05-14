#pragma once
#include "mlecz.h"

Mlecz::Mlecz(WspXY wsp, Swiat* uni)
{
	id = gatunek(trawa);
	sila = 0;
	inicjatywa = 0;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = PLODNOSC_MLECZA;
	wiek = 0;
}

Mlecz::~Mlecz() {}

void Mlecz::rozsiewanie()
{
	if (wiek > 1)
	{
		bool czy_rozsiala = false;
		
		for (int i = 0; i < 3; i++)
		{
			WspXY wolne_pola[4];
			int ilosc_wolnych_pol = uniwersum->wolnePola(wspolrzedne, wolne_pola);

			if (ilosc_wolnych_pol > 0)
			{
				int szansa_rozmnozenia = rand() % 100;
				if (szansa_rozmnozenia < plodnosc)
				{
					WspXY wybrane_pole = wolne_pola[rand() % ilosc_wolnych_pol];
					Organizm* nasionko = potomek(wybrane_pole);
					std::cout << " rozsial " << *nasionko;
					uniwersum->dodajOrganizm(nasionko);
					czy_rozsiala = true;
				}
			}

		}
		if (!czy_rozsiala)
		{
			std::cout << "nie rozsial sie" << std::endl;
		}
	}
	else
	{
		std::cout << "nie rozsial sie" << std::endl;
	}
}

void Mlecz::rysowanie() const
{
	changeColour(KOLOR_M);
	printf("m");
	changeColour(KOLOR_PODSTAWOWY);
}

inline void Mlecz::Wypisz(std::ostream& out) const
{
	out << "Mlecz Sila(" << sila << ") Wiek(" << wiek << ") XY" << wspolrzedne << " ";
}

Organizm* Mlecz::potomek(WspXY wsp)
{
	return new Mlecz(wsp, uniwersum);
}