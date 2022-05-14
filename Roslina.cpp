#include "Roslina.h"

void Roslina::akcja()
{
	wiek++;
	std::cout << *this;
	rozsiewanie();
}

void Roslina::rozsiewanie()
{
	if (wiek > 1)
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
				std::cout << " rozsiala " << *nasionko << std::endl;
				uniwersum->dodajOrganizm(nasionko);
			}
			else
			{
				std::cout << "nie rozsiala sie" << std::endl;
			}
		}
		else
		{
			std::cout << "nie rozsiala sie" << std::endl;
		}
	}
	else
	{
		std::cout << "nie rozsiala sie" << std::endl;
	}
}

wynik_kolizji Roslina::kolizja(Organizm* wchodzacy)
{
	std::cout << " zjadl " << *this << " i ";
	uniwersum->zabijOrganizm(this);
	return wynik_kolizji(ruch);
}



Roslina::~Roslina(){}