#pragma once
#include <vector>
#include "WspXY.h"
#include "Organizm.h"


class Organizm;

class Swiat
{
public:
	Swiat(int N, int M);

	void wykonajTure();
	void rysujSwiat();
	void zabijOrganizm(Organizm* martwy);
	bool dodajOrganizm(Organizm* nowy);
	void dodawanieOrganizmu(Organizm* nowy);
	bool dodajOrganizmPoczatkowy(Organizm* nowy);
	void sortujOrganizmy();
	void usunCiala();
	void przesun_organizm(Organizm* ruszany, WspXY cel);

	int getX() const;
	int getY() const;
	Organizm* getPole(WspXY pole) const;
	int getTura() const;

	int bezpiecznePola(WspXY wspPola, WspXY kierunki[4]);
	int wolnePola(WspXY wspPola, WspXY kierunki[4]);

	~Swiat();

private:
	int tura;
	int X;
	int Y;
	Organizm*** map;
	std::vector<Organizm*> organizmy;
	std::vector<Organizm*> deadNote;//wyczysc na koniec tury!!
};
