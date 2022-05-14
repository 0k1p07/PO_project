#pragma once
#include "f_rys.h"
#include <thread>
#include <chrono>
#include <Windows.h>

using namespace std;

void cls()
{
	system("cls");
}

void goTo(size_t x, size_t y)
{
	cout << ESC_SQ << y << ';' << x << 'H';
}

void changeColour(size_t background, size_t foreground)
{
	cout << ESC_SQ << background << 'm' << ESC_SQ << foreground << 'm';
}

void clearLine(size_t numer_linii)
{
	goTo(0, numer_linii);
	cout << string(255, ' ');
}

void freeze(int czas)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(czas));
}