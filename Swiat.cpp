#pragma once
#include "Swiat.h"
#include "f_rys.h"

Swiat::Swiat(int N, int M)
{ 
	tura = 0;
	X = N;
	Y = M;
	map = new Organizm * *[Y];
	for (int i = 0; i < Y; i++)
	{
		map[i] = new Organizm * [X];
	}
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			map[i][j] = NULL;
		}
	}
}

void Swiat::dodawanieOrganizmu(Organizm* dodawany)
{
	int y = (std::rand() % Y);
	int x = (std::rand() % X);
	WspXY wsp(y, x);
	Organizm* nowy = dodawany;
	nowy->setWsporzedne(wsp);

	while (!dodajOrganizmPoczatkowy(nowy))
	{
		int y = (std::rand() % Y);
		int x = (std::rand() % X);
		WspXY wsp(y, x);
		nowy->setWsporzedne(wsp);
	}
}

bool Swiat::dodajOrganizmPoczatkowy(Organizm* nowy)
{
	WspXY wsp = nowy->getWspolrzedne();
	if (map[wsp.getwY()][wsp.getwX()] == NULL)
	{
		map[wsp.getwY()][wsp.getwX()] = nowy;
		organizmy.push_back(nowy);
		return true;
	}
	else
	{
		return false;
	}
}


bool Swiat::dodajOrganizm(Organizm* nowy)
{
	WspXY wsp = nowy->getWspolrzedne();
	if (map[wsp.getwY()][wsp.getwX()] == NULL)
	{
		map[wsp.getwY()][wsp.getwX()] = nowy;
		organizmy.push_back(nowy);
		goTo(MAP_X + 4 + 2 * wsp.getwX(), MAP_Y + wsp.getwY());
		nowy->rysowanie();
		goTo(MAP_X, MAP_Y + Y + 6);
		return true;
	}
	else
	{
		return false;
	}
}

void Swiat::zabijOrganizm(Organizm* martwy)
{
	WspXY wsp = martwy->getWspolrzedne();
	map[wsp.getwY()][wsp.getwX()] = NULL;
	goTo(MAP_X + 4 + 2 * wsp.getwX(), MAP_Y + wsp.getwY());
	printf(" ");
	goTo(MAP_X, MAP_Y + Y + 6);
	/*
	for (int i = 0; i < organizmy.size(); i++)
	{
		std::cout << organizmy[i] << std::endl;
	}
	*/
	deadNote.push_back(martwy);
}

void Swiat::sortujOrganizmy()
{

	//for (int i = 0; i < organizmy.size(); i++) std::cout << organizmy[i] << *organizmy[i] << std::endl;
	for (unsigned int i = 0; i < organizmy.size(); i++)
	{
		for (unsigned int j = 1; j < organizmy.size() - i; j++)
		{
			if (*organizmy[j - 1]  < *organizmy[j])
			{
				std::swap(organizmy[j - 1], organizmy[j]);
			}
		}
	}
	//for (int i = 0; i < organizmy.size(); i++) std::cout << organizmy[i] << *organizmy[i] << std::endl;
}

void Swiat::usunCiala()
{
	while(deadNote.size()!=0)
	{
		for (unsigned int i = 0; i < organizmy.size(); i++)
		{
			//std::cout << organizmy[i]<<std::endl;
			if (organizmy[i] == deadNote[0])
			{
				organizmy.erase(organizmy.begin() + i);
			}
		}
		delete deadNote[0];
		deadNote.erase(deadNote.begin());
	}
}

void Swiat::wykonajTure()
{
	sortujOrganizmy();

	for (unsigned int i = 0; i < organizmy.size(); i++)
	{
		if (getPole(organizmy[i]->getWspolrzedne()) == organizmy[i])
		{
			clearLine(MAP_Y + Y + 5);
			clearLine(MAP_Y + Y + 6);
			clearLine(MAP_Y + Y + 7);
			clearLine(MAP_Y + Y + 8);
			goTo(MAP_X , MAP_Y + Y + 5);
			organizmy[i]->akcja();
			freeze(FREEZE_TIME_INF);
		}
	}
	rysujSwiat();
	usunCiala();
	tura++;
}

Organizm* Swiat::getPole(WspXY pole) const
{
	return map[pole.getwY()][pole.getwX()];
}

int Swiat::getTura() const
{
	return tura;
}

void Swiat::przesun_organizm(Organizm* ruszany, WspXY cel)
{
	if (map[cel.getwY()][cel.getwX()] == NULL)
	{
		map[ruszany->getWspolrzedne().getwY()][ruszany->getWspolrzedne().getwX()] = NULL;
		goTo(MAP_X + 4 + 2 * ruszany->getWspolrzedne().getwX(), MAP_Y + ruszany->getWspolrzedne().getwY());
		printf(" ");
		ruszany->setWsporzedne(cel);
		map[cel.getwY()][cel.getwX()] = ruszany;
		goTo(MAP_X + 4 + 2 * cel.getwX(), MAP_Y + cel.getwY());
		ruszany->rysowanie();
		goTo(MAP_X, MAP_Y + Y + 6);

	}
}

Swiat::~Swiat()
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			delete map[i][j];
		}
	}

	for (int i = 0; i < Y; i++)
	{
		delete[] map[i];
	} 

	delete[] map;
}


void Swiat::rysujSwiat()
{
	cls();
	changeColour(KOLOR_PODSTAWOWY);
	goTo(0, 5);
	std::cout << "Krzysztof Domagalski 180471"; 
	changeColour(0, 4);
	for (int i = 0; i < X; i++)
	{
		goTo(MAP_X + 3+2*i, MAP_Y - 1);
		printf("%2i ", i);
	}
	/*
	for (int i = 0; i < X; i++)
	{
		goTo(MAP_X + 3+3*i, MAP_Y - 1);
		printf("___");
	}
	*/
	changeColour(KOLOR_WYBIERZ);
	goTo(MAP_X, MAP_Y -2);
	std::cout << "ABY ZAKONCZYC SYMULACJE KLIKNIJ ESC, ABY KONTYNUUOWAC KLIKNIJ ENTER";
	goTo(0, MAP_Y+5);
	std::cout << "TURA " << tura;
	changeColour(KOLOR_PODSTAWOWY);
	for (int i = 0; i < Y; i++)
	{

		goTo(MAP_X, MAP_Y + i);
		printf("%2i | ", i);
		for (int j = 0; j < X; j++)
		{
			goTo(MAP_X + 4 + 2 * j, MAP_Y + i);
			if (map[i][j] == NULL)
			{
				std::cout << " ";
			}
			else
			{
				map[i][j]->rysowanie();
			}
			std::cout << "  ";
			
		}


	}
	freeze(FREEZE_TIME_MAP);
}

int Swiat::bezpiecznePola(WspXY wspPola, WspXY kierunki[4])
{
	int polozenie_x = wspPola.getwX();
	int polozenie_y = wspPola.getwY();
	int ilosc_dostepnych_kierunkow = 0;
	//po prawej
	if (polozenie_x + 1 < X && ((map[polozenie_y][polozenie_x + 1] == NULL)|| map[polozenie_y][polozenie_x + 1]->getSila()==0))
	{
		WspXY wsp(polozenie_y, polozenie_x + 1);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	//po lewej
	if (polozenie_x - 1 >= 0 && ((map[polozenie_y][polozenie_x - 1] == NULL) || map[polozenie_y][polozenie_x - 1]->getSila() == 0))
	{
		WspXY wsp(polozenie_y, polozenie_x - 1);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	//na gorze
	if (polozenie_y + 1 < Y && ((map[polozenie_y + 1][polozenie_x] == NULL) || map[polozenie_y + 1][polozenie_x]->getSila() == 0))
	{
		WspXY wsp(polozenie_y + 1, polozenie_x);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	//na dole
	if (polozenie_y - 1 >= 0 && ((map[polozenie_y - 1][polozenie_x] == NULL) || map[polozenie_y - 1][polozenie_x]->getSila() == 0))
	{
		WspXY wsp(polozenie_y - 1, polozenie_x);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	return ilosc_dostepnych_kierunkow;
}


int Swiat::wolnePola(WspXY wspPola, WspXY kierunki[4])
{
	int polozenie_x = wspPola.getwX();
	int polozenie_y = wspPola.getwY();
	int ilosc_dostepnych_kierunkow = 0;
	//po prawej
	if (polozenie_x + 1 < X && (map[polozenie_y][polozenie_x + 1] == NULL))
	{
		WspXY wsp(polozenie_y,polozenie_x + 1);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	//po lewej
	if (polozenie_x - 1 >= 0 && (map[polozenie_y][polozenie_x - 1] == NULL))
	{
		WspXY wsp(polozenie_y, polozenie_x - 1);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	//na gorze
	if (polozenie_y + 1 < Y && (map[polozenie_y + 1][polozenie_x] == NULL))
	{
		WspXY wsp(polozenie_y + 1,polozenie_x);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	//na dole
	if (polozenie_y - 1 >= 0 && (map[polozenie_y - 1][polozenie_x] == NULL))
	{
		WspXY wsp(polozenie_y - 1,polozenie_x);
		kierunki[ilosc_dostepnych_kierunkow] = wsp;
		ilosc_dostepnych_kierunkow++;
	}
	return ilosc_dostepnych_kierunkow;
}

int Swiat::getX() const
{
	return X;
}

int Swiat::getY() const
{
	return Y;
}