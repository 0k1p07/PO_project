#pragma once
#include <iostream>

class WspXY
{
public:
	WspXY();
	WspXY(int y, int x);
	int getwX() const;
	int getwY() const;
	void setX(int x);
	void setY(int y);
	friend std::ostream& operator<<(std::ostream& os,const WspXY& wsp);
	inline void Wypisz(std::ostream& out) const;
private:
	int x;
	int y;
};

