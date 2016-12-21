#include "Date.h"
#include "Clock.h"
#pragma once
class CSmartWatch
{
private:
	CDate* m_Date;
	CClock* m_Clock;
public:
	CSmartWatch();
	~CSmartWatch();
	void Paint();
	void Notification(int d, int m, int x, int y);
	void Ring(int Signal);
};

