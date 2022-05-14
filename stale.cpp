#pragma once

#define MAP_X 60
#define MAP_Y 5

#define PLODNOSC_WILKA 50
#define PLODNOSC_OWCY 75
#define PLODNOSC_LISA 75
#define PLODNOSC_ZOLWIA 75
#define PLODNOSC_ANTYLOPY 75
#define PLODNOSC_TRAWY 60
#define PLODNOSC_MLECZA 60
#define PLODNOSC_GARANY 60
#define PLODNOSC_WILCZYCHJAGOD 50
#define PLODNOSC_BARSZCZUSOSNOWSKIEGO 50

#define KOLOR_PODSTAWOWY 0,0
#define KOLOR_WYBIERZ 31,31

#define KOLOR_C 92,103
#define KOLOR_W 31,100
#define KOLOR_O 30,107
#define KOLOR_L 30,43
#define KOLOR_Z 47,32
#define KOLOR_A 43,93

#define KOLOR_T 11,92
#define KOLOR_M 12,38
#define KOLOR_G 13,34
#define KOLOR_J 12,31
#define KOLOR_B 12,35

#define STRZALKA_GORA 80
#define STRZALKA_DOL 72
#define STRZALKA_LEWO 75
#define STRZALKA_PRAWO 77
#define ENTER 13
#define ESC 27

#define ESC_SQ "\x1B\x5b"
#define FREEZE_TIME_MAP 20
#define FREEZE_TIME_INF 100

#define ILOSC_WILKOW 8
#define ILOSC_OWIEC 20
#define ILOSC_LISOW 20
#define ILOSC_ZOLWI 20
#define ILOSC_ANTYLOP 20
#define ILOSC_TRAWY 8
#define ILOSC_MLECZY 8
#define ILOSC_GUARANY 8
#define ILOSC_WILCZYCHJAGOD 8
#define  ILOSC_BARSZCZU 8



enum wynik_kolizji
{
	odepchniecie = 0,
	smierc = 1,
	ruch = 2,
	rozmnazanie = 3,
	bonusDoSily = 4
};

enum gatunek
{
	barszcz_sosnowskiego = -5,
	wilcze_jagody = -4,
	guarana = -3,
	mlecz = -2,
	trawa = -1,
	czlowiek = 0,
	wilk = 1,
	owca = 2,
	lis = 3,
	zolw = 4,
	antylopa = 5
};
