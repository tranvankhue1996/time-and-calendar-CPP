#include "Date.h"

int CDate::DayinMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

CDate::CDate()
{
	m_Day = 1;
	m_Month = 1;
	m_Year = 1;
	m_wDay = -1;
}

CDate::CDate(int d, int m, int y) {
	m_Day = d;
	m_Month = m;
	m_Year = y;
	m_wDay = wDay();
}

void CDate::setTime() {
	time_t hientai = time(0);
	//char* dt = ctime(&hientai); //đưa ra chuỗi
	tm *time = localtime(&hientai); //đưa ra struct
	m_Year = time->tm_year + 1900;
	m_Month = time->tm_mon + 1;
	m_Day = time->tm_mday;
	m_wDay = time->tm_wday + 1;
}

int CDate::wDay() {
	int S = 0;
	for (int i = 1; i < m_Month; i++) {
		S += DayinMonth[i];
		if (i == 2 && InspectLeapYear()) S++;
	}
	for (int i = 1; i < m_Year; i++) {
		S += 365;
		if (InspectLeapYear()) S++;
	}
	return S % 7;
}

void CDate::output(ostream& os) {
	if (m_Day < 10) { os << "0";}
	os << m_Day << "/";
	if (m_Month < 10)  { os << "0"; }
	os << m_Month << "/";
	os << m_Year;
}

bool CDate::InspectLeapYear() {
	if ((m_Year % 4 == 0 && m_Year % 100 != 0) || m_Year % 400 == 0)
		return true;
	return false;
}

void CDate::Paint(int x, int y) {
	//----------------------------------
	int CountMax = DayinMonth[m_Month];
	if (m_Month == 2 && InspectLeapYear()) CountMax++;
	int Count = 1;
	int Start = this->wDay();
	//----------------------------------
	int DayBefore = DayinMonth[m_Month - 1];
	if (m_Month - 1 == 0) DayBefore = DayinMonth[12];
	if (m_Month - 1 == 2 && InspectLeapYear()) DayBefore++;
	int DayAfter = 1;
	setColor(7);
	gotoxy(x, y);
	//----------------------------------
	cout << "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
	gotoxy(x, y + 1);
	cout << "³" << setw(17);
	output(cout);
	if (m_Day < 10) cout << setw(16);
	else cout << setw(17);
	cout << "³" << endl;
	gotoxy(x, y + 2);
	cout << "ĂÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄ´";
	gotoxy(x, y + 3);
	for (int i = 0; i < 8; i++) {
		setColor(7);
		cout << "³";
		switch (i) {
		case 0: setColor(12);
			cout << "  CN ";
			break;
		case 1: setColor(14);
			cout << " Hai ";
			break;
		case 2: setColor(14);
			cout << "  Ba ";
			break;
		case 3: setColor(14);
			cout << "  Tu ";
			break;
		case 4: setColor(14);
			cout << " Nam ";
			break;
		case 5: setColor(14);
			cout << " Sau ";
			break;
		case 6: setColor(12); 
			cout << " Bay ";
			break;
		}
	}
	gotoxy(x, y + 4);
	cout << "ĂÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄ´";
	for (int i = 0; i < 6; i++) {
		gotoxy(x, y + 5 + 2*i);
		cout << "³";
		for (int j = 1; j < 8; j++) {
			if (i == 0 && j < Start || Count > CountMax) {
				cout << setw(4);
				setColor(8);
				if (Count < CountMax) cout << DayBefore - (Start - j) + 1;
				else cout << DayAfter++;
				setColor(7);
				cout << setw(2) << "³";
			}
			else {
				if (Count == m_Day) {
					setColor(164);
					cout << setw(4) << Count++ << setw(2);
				}
				else {
					setColor(144);
					cout << setw(4) << Count++ << setw(2);
				}
				setColor(7);
				cout << " ³";
			}
		}
		gotoxy(x, y + 5 + 2*i + 1);
		if (i != 5) cout << "ĂÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄ´";
		else cout << "ÀÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÙ";
	}
}

int CDate::retDay() {
	return m_Day;
}

int CDate::retMonth() {
	return m_Month;
}

CDate::~CDate()
{
}
