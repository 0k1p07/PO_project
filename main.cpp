#include <iostream>
#include <ctime>
#include "Organizm.h"
#include "Wilk.h"
#include "owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"
#include "f_rys.h"
#include <Windows.h>




int main()
{
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	freeze(2000);

	goTo(MAP_X, MAP_Y);
	changeColour(KOLOR_WYBIERZ);
	std::cout << "START";
	goTo(MAP_X, MAP_Y +1);
	std::cout << "ABY ROZPOCZAC KLIKNIJ ENTER";
	goTo(MAP_X, MAP_Y + 2);
	std::cout << "ABY WYJSC KLIKNIJ ESC";

	bool wybrane = false;

	while (!wybrane)
	{
		int wybor = _getch();
		if (wybor == ENTER)
		{
			wybrane = true;
		}
		if (wybor == ESC)
		{
			return 0;
		}
	}

	cls();
	goTo(MAP_X, MAP_Y);
	changeColour(KOLOR_WYBIERZ);
	std::cout << "Podaj rozmiar swiata" << std::endl;
	int x;
	goTo(MAP_X, MAP_Y+1);
	std::cout << "X: ";
	std::cin >> x;
	int y;
	goTo(MAP_X, MAP_Y+2);
	std::cout << "Y: ";
	std::cin >> y;

	cls();

	Swiat moj_swiat(y, x);

	srand(time(NULL));

	WspXY wsp;
	Organizm* nowy = new Czlowiek(wsp, &moj_swiat);	
	//moj_swiat.dodawanieOrganizmu(nowy);

	for(int i=0;i<ILOSC_WILKOW;i++)
	{
		nowy = new Wilk(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	for (int i = 0; i < ILOSC_OWIEC;i++)
	{
		nowy = new Owca(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	for (int i = 0; i < ILOSC_LISOW; i++)
	{
		nowy = new Lis(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	for (int i = 0; i < ILOSC_ZOLWI; i++)
	{
		nowy = new Zolw(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	for (int i = 0; i < ILOSC_ANTYLOP; i++)
	{
		nowy = new Antylopa(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	for (int i = 0; i < ILOSC_TRAWY; i++)
	{
		nowy = new Trawa(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	for (int i = 0; i < ILOSC_MLECZY; i++)
	{
		nowy = new Mlecz(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	for (int i = 0; i < ILOSC_GUARANY; i++)
	{
		nowy = new Guarana(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	for (int i = 0; i < ILOSC_WILCZYCHJAGOD; i++)
	{
		nowy = new WilczeJagody(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	for (int i = 0; i < ILOSC_BARSZCZU; i++)
	{
		nowy = new BarszczSosnowskiego(wsp, &moj_swiat);
		moj_swiat.dodawanieOrganizmu(nowy);
	}
	
	moj_swiat.rysujSwiat();

	bool koniec = false;
	while(!koniec)
	{
		int koniec = _getch();
		if (koniec == ESC)
		{
			koniec = true;
			break;
		}
		else if (koniec == ENTER)
		{
			moj_swiat.wykonajTure();
		}
	}

	return 0;
}