#pragma once
#include "Graphics.h"

class CClock : public CGraphics
{
protected:
	int m_Hours, m_Minutes, m_Seconds;
public:
	CClock();
	CClock(int h, int m, int s);
	void output(ostream& os);
	void setTime();
	void Paint(int x, int y);
	void setText(int n, int x, int y);
	bool oclock();
	bool NextDay();
	~CClock();
};

