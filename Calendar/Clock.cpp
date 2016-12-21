#include "Clock.h"


CClock::CClock()
{
	m_Hours = 0;
	m_Minutes = 0;
	m_Seconds = 0;
}

CClock::CClock(int h, int m, int s) {
	m_Hours = h;
	m_Minutes = m;
	m_Seconds = s;
}

CClock::~CClock()
{
}

void CClock::output(ostream& os) {
	os << m_Hours << ":" << m_Minutes << ":" << m_Seconds;
}

void CClock::setTime() {
	time_t hientai = time(0);
	//char* dt = ctime(&hientai); //đưa ra chuỗi
	tm *time = localtime(&hientai); //đưa ra struct
	m_Hours = time->tm_hour;
	m_Minutes = time->tm_min;
	m_Seconds = time->tm_sec;
}

void CClock::Paint(int x, int y) {
	if (m_Seconds % 2 == 0) {
		setColor(12);
		setText(10, x + 11, y);
		setText(10, x + 25, y);
	}
	else {
		setColor(0);
		setText(10, x + 11, y);
		setText(10, x + 25, y);
	}
	setColor(15);
	setText(m_Hours / 10, x, y);
	setText(m_Hours % 10, x + 5, y);
	setText(m_Minutes / 10, x + 12, y);
	setText(m_Minutes % 10, x + 18, y);
	setText(m_Seconds / 10, x + 26, y);
	setText(m_Seconds % 10, x + 32, y);
}

void CClock::setText(int n,int x,int y) {
	switch (n) {
	case 0: gotoxy(x, y); cout << " ÛÛÛÛ "; gotoxy(x, y + 1); cout << " Û  Û "; gotoxy(x, y + 2); cout << " Û  Û "; gotoxy(x, y + 3); cout << " Û  Û "; gotoxy(x, y + 4); cout << " ÛÛÛÛ ";
		break;
	case 1: gotoxy(x, y); cout << "    Û "; gotoxy(x, y + 1); cout << "    Û "; gotoxy(x, y + 2); cout << "    Û "; gotoxy(x, y + 3); cout << "    Û "; gotoxy(x, y + 4); cout << "    Û ";
		break;
	case 2: gotoxy(x, y); cout << " ÛÛÛÛ "; gotoxy(x, y + 1); cout << "    Û "; gotoxy(x, y + 2); cout << " ÛÛÛÛ "; gotoxy(x, y + 3); cout << " Û    "; gotoxy(x, y + 4); cout << " ÛÛÛÛ ";
		break;
	case 3: gotoxy(x, y); cout << " ÛÛÛÛ "; gotoxy(x, y + 1); cout << "    Û "; gotoxy(x, y + 2); cout << " ÛÛÛÛ "; gotoxy(x, y + 3); cout << "    Û "; gotoxy(x, y + 4); cout << " ÛÛÛÛ ";
		break;
	case 4: gotoxy(x, y); cout << " Û  Û "; gotoxy(x, y + 1); cout << " Û  Û "; gotoxy(x, y + 2); cout << " ÛÛÛÛ "; gotoxy(x, y + 3); cout << "    Û "; gotoxy(x, y + 4); cout << "    Û ";
		break;
	case 5: gotoxy(x, y); cout << " ÛÛÛÛ "; gotoxy(x, y + 1); cout << " Û    "; gotoxy(x, y + 2); cout << " ÛÛÛÛ "; gotoxy(x, y + 3); cout << "    Û "; gotoxy(x, y + 4); cout << " ÛÛÛÛ ";
		break;
	case 6: gotoxy(x, y); cout << " ÛÛÛÛ "; gotoxy(x, y + 1); cout << " Û    "; gotoxy(x, y + 2); cout << " ÛÛÛÛ "; gotoxy(x, y + 3); cout << " Û  Û "; gotoxy(x, y + 4); cout << " ÛÛÛÛ ";
		break;
	case 7: gotoxy(x, y); cout << " ÛÛÛÛ "; gotoxy(x, y + 1); cout << "    Û "; gotoxy(x, y + 2); cout << "    Û "; gotoxy(x, y + 3); cout << "    Û "; gotoxy(x, y + 4); cout << "    Û ";
		break;
	case 8: gotoxy(x, y); cout << " ÛÛÛÛ "; gotoxy(x, y + 1); cout << " Û  Û "; gotoxy(x, y + 2); cout << " ÛÛÛÛ "; gotoxy(x, y + 3); cout << " Û  Û "; gotoxy(x, y + 4); cout << " ÛÛÛÛ ";
		break;
	case 9: gotoxy(x, y); cout << " ÛÛÛÛ "; gotoxy(x, y + 1); cout << " Û  Û "; gotoxy(x, y + 2); cout << " ÛÛÛÛ "; gotoxy(x, y + 3); cout << "    Û "; gotoxy(x, y + 4); cout << " ÛÛÛÛ ";
		break;
	case 10: gotoxy(x, y + 1); cout << "Û";  gotoxy(x, y + 3); cout << "Û";
		break;

	}

}

bool CClock::oclock() {
	if (m_Minutes == 0 && m_Seconds == 0) return true;
	return false;
}

bool CClock::NextDay() {
	if (m_Hours == 0 && m_Minutes == 0 && m_Seconds == 0) return true;
	return false;
}
