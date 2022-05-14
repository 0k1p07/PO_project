#pragma once
#include "Zwierze.h"

void Zwierze::akcja()
{
	wiek++;

	std::cout << *this;

	WspXY kierunki[4];
	int ilosc_kierunków = mozliwoscRuchu(kierunki);
	if (ilosc_kierunków > 0)
	{
		WspXY kierunek_ruchu = kierunki[rand() % ilosc_kierunków];
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
		else if (wynik == wynik_kolizji(rozmnazanie))
		{
			std::cout << " rozmnozyl sie z " << *pole << std::endl;
			tura_ostatniego_rozmozenia = uniwersum->getTura();
		}
		else if (wynik == wynik_kolizji(odepchniecie))
		{
			std::cout << " zostal odepchniety przez " << *pole << std::endl;
		}
		else if (wynik == wynik_kolizji(bonusDoSily))
		{
			zwiekszSile(3);
			std::cout << "wiekszyl sile i ruszyl sie na " << kierunek_ruchu << std::endl;
			uniwersum->przesun_organizm(this, kierunek_ruchu);
		}
	}
	else
	{
		std::cout << "nie rusza sie" << std::endl;
	}
}

wynik_kolizji Zwierze::kolizja(Organizm* wchodzacy)
{
	if (wchodzacy->getID() == this->id)
	{
		this->rozmnozenie();
		return wynik_kolizji(rozmnazanie);
	}
	if (wchodzacy->getSila() < this->getSila())
	{
		return wynik_kolizji(smierc);
	}
	else if (wchodzacy->getSila() >= this->getSila())
	{
		std::cout << " zabil " << *this << " ";
		uniwersum->zabijOrganizm(this);
		return wynik_kolizji(ruch);
	}
}

void Zwierze::rozmnozenie()
{
	int szansa = rand() % 100;
	if (tura_ostatniego_rozmozenia != uniwersum->getTura() && szansa <= plodnosc)
	{
		WspXY bezpieczne_pola[4];
		int ilosc_bezpiecznych_pol = uniwersum->bezpiecznePola(wspolrzedne, bezpieczne_pola);
		if (ilosc_bezpiecznych_pol > 0)
		{
			WspXY wybrane_pole = bezpieczne_pola[rand() % ilosc_bezpiecznych_pol];

			bool zadeptany = false;
			Organizm* na_polu = uniwersum->getPole(wybrane_pole);
			if (na_polu != NULL)
			{
				uniwersum->zabijOrganizm(na_polu);
				zadeptany = true;
			}
			Organizm* dziecko = potomek(wybrane_pole);
			dziecko->setWsporzedne(wybrane_pole);
			uniwersum->dodajOrganizm(dziecko);
			tura_ostatniego_rozmozenia = uniwersum->getTura();
			std::cout << "dziecko:" << *dziecko;
			if (zadeptany)
			{
				std::cout << "(zadeptalo" << *na_polu << ") ";
			}
		}
	}
	else
	{
		std::cout << "(nieudane)";
	}

}

int Zwierze::mozliwoscRuchu(WspXY kierunki[4])
{
	int polozenie_x = wspolrzedne.getwX();
	int polozenie_y = wspolrzedne.getwY();
	int ilosc_dostepnych_kierunkow = 0;
	//po prawej
	if (polozenie_x + 1 < uniwersum->getX())
	{
		WspXY wsp(polozenie_y, polozenie_x + 1);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	//po lewej
	if (polozenie_x - 1 >= 0)
	{
		WspXY wsp(polozenie_y, polozenie_x - 1);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	//na gorze
	if (polozenie_y + 1 < uniwersum->getY())
	{
		WspXY wsp(polozenie_y + 1, polozenie_x);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	//na dole
	if (polozenie_y - 1 >= 0)
	{
		WspXY wsp(polozenie_y - 1, polozenie_x);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	return ilosc_dostepnych_kierunkow;
}

void Zwierze::zwiekszSile(int modyfikator)
{
	sila += modyfikator;
}

Zwierze::~Zwierze() {}