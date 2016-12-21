#pragma once
#include "Graphics.h"

class CDate : public CGraphics
{
private:
	int m_Day, m_Month, m_Year;
	int m_wDay;
	static int DayinMonth[];
public:
	CDate();
	CDate(int d, int m, int y);
	~CDate();
	void setTime();
	int wDay();
	void output(ostream& os);
	bool InspectLeapYear();
	void Paint(int x, int y);
	int retDay();
	int retMonth();
};
