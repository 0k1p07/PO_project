#pragma once
#include "Czlowiek.h"

void Czlowiek::akcja()
{
	goTo(MAP_X, MAP_Y - 4);
	changeColour(KOLOR_WYBIERZ);
	std::cout << "ABY UZYC UMIEJETNOSCI KLIKNIJ L, ABY SIE RUSZYC WYBIERZ KIERUNEK STRZALKA";
	changeColour(KOLOR_PODSTAWOWY); 

	wiek++;
	goTo(MAP_X, MAP_Y + uniwersum->getY() + 5);
	std::cout << *this;

	bool kierunek_wybrany = false;
	
	WspXY kierunek_ruchu;
	while (!kierunek_wybrany)
	{
		int akcja = _getch();
		if (akcja == 108)
		{
			wypijEliksir();
		}
		else if (akcja == 224)
		{
			akcja = _getch();
			switch (akcja)
			{
				case STRZALKA_GORA:
				{
					kierunek_ruchu.setX(wspolrzedne.getwX());
					kierunek_ruchu.setY(wspolrzedne.getwY()+1);
					kierunek_wybrany = true;
				}
				break;
				case STRZALKA_DOL:
				{
					kierunek_ruchu.setX(wspolrzedne.getwX());
					kierunek_ruchu.setY(wspolrzedne.getwY() - 1);
					kierunek_wybrany = true;
				}
				break;
				case STRZALKA_LEWO:
				{
					kierunek_ruchu.setX(wspolrzedne.getwX()-1);
					kierunek_ruchu.setY(wspolrzedne.getwY());
					kierunek_wybrany = true;
				}
				break;
				case STRZALKA_PRAWO:
				{
					kierunek_ruchu.setX(wspolrzedne.getwX() + 1);
					kierunek_ruchu.setY(wspolrzedne.getwY());
					kierunek_wybrany = true;
				}
				break;
			}
		}
	}



	if (kierunek_ruchu.getwX() < uniwersum->getX()&& kierunek_ruchu.getwY() < uniwersum->getY()
		&& kierunek_ruchu.getwX() >=0 && kierunek_ruchu.getwY()>=0)
	{
		Organizm* pole = uniwersum->getPole(kierunek_ruchu);
		wynik_kolizji wynik;

		if (pole != NULL)
		{
			wynik = pole->kolizja(this);
		}
		if (pole == NULL || wynik == wynik_kolizji(ruch))
		{
			std::cout << "ruszyl sie na " << kierunek_ruchu << std::endl;
			uniwersum->przesun_organizm(this, kierunek_ruchu);
		}
		else if (wynik == wynik_kolizji(smierc))
		{
			std::cout << "zostal zabity przez " << *pole << std::endl;
			uniwersum->zabijOrganizm(this);
		}
		else if (wynik == wynik_kolizji(odepchniecie))
		{
			std::cout << " zostal odepchniety przez " << *pole << std::endl;
		}
		else if (wynik == wynik_kolizji(bonusDoSily))
		{
			zwiekszSile(3);
			std::cout << "zwiekszyl sile i ruszyl sie na " << kierunek_ruchu << std::endl;
			uniwersum->przesun_organizm(this, kierunek_ruchu);
		}
	}
	else
	{
		std::cout << *this << "nie rusza sie" << std::endl;
	}
	if (umiejetnosc_cooldown > 0)
	{
		umiejetnosc_cooldown--;
	}
	if (magiczny_eliksir > 0)
	{
		magiczny_eliksir--;
	}
	clearLine(MAP_Y - 4);
}

void Czlowiek::wypijEliksir()
{
	if (umiejetnosc_cooldown == 0)
	{
		if (sila < 10)
		{
			magiczny_eliksir = 10 - sila;
		}
		else
		{
			magiczny_eliksir = 0;
		}
		umiejetnosc_cooldown = 10;
		std::cout << "wypil eliksir ";
	}
	else
	{
		std::cout << "nowy eliksir nie jest gotowy ";
	}

}

wynik_kolizji Czlowiek::kolizja(Organizm* wchodzacy)
{
	if (wchodzacy->getSila() < this->getSila())
	{
		return wynik_kolizji(smierc);
	}
	else if (wchodzacy->getSila() >= this->getSila())
	{
		std::cout << " zabil " << *this << " i ";
		uniwersum->zabijOrganizm(this);
		return wynik_kolizji(ruch);
	}
}

Organizm* Czlowiek::potomek(WspXY wybrane_pole)
{
	return new Czlowiek(wybrane_pole, uniwersum);
}

Czlowiek::Czlowiek(WspXY wsp, Swiat* uni)
{
	id = gatunek(czlowiek);
	sila = 5;
	inicjatywa = 4;
	wspolrzedne = wsp;
	uniwersum = uni;
	plodnosc = 0;
	wiek = 0;
	tura_ostatniego_rozmozenia = -1;
	magiczny_eliksir = 0;
	umiejetnosc_cooldown = 0;
}

Czlowiek::~Czlowiek() {}

void Czlowiek::rysowanie() const
{
	changeColour(KOLOR_C);
	printf("C");
	changeColour(KOLOR_PODSTAWOWY);
}

int Czlowiek::getSila() const
{
	return sila + magiczny_eliksir;
}

inline void Czlowiek::Wypisz(std::ostream& out) const
{
	out << "Czlowiek Sila(" << sila << "+" << magiczny_eliksir << ") cooldown(" << umiejetnosc_cooldown <<") Wiek(" << wiek << ") XY" << wspolrzedne << " ";
}

