#include "SmartWatch.h"


CSmartWatch::CSmartWatch()
{
	m_Clock = new CClock;
	m_Date = new CDate;
	m_Clock->setBoardConsole(46, 33, "SMART CALENDAR AfD v1.0");
}

CSmartWatch::~CSmartWatch()
{
	delete m_Clock, m_Date;
}

void CSmartWatch::Paint() {
	//Paint Date
	m_Date->setTime();
	m_Date->Paint(1,10);

	//Paint Board
	m_Clock->ProBoard(15, 9, 1, 1);
	m_Clock->ProBoard(15, 5, 1, 27);

	//Cout Notification
	this->Notification(m_Date->retDay(), m_Date->retMonth(), 3, 29);

	//Painting Clock
	while (true) {
		m_Clock->setTime();
		m_Clock->Paint(3, 3);
		if (m_Clock->NextDay() == true) {
			m_Date->setTime();
			m_Date->Paint(1, 10);
			this->Notification(m_Date->retDay(), m_Date->retMonth(), 3, 29);
		}
		if (m_Clock->oclock() == true) {
			Ring(1);
		}
	}
}

void CSmartWatch::Notification(int d, int m, int x, int y) {
	m_Clock->gotoxy(x, y);
	m_Clock->setColor(2);
	char Alpha = 16;
	cout << Alpha;
	m_Clock->gotoxy(x + 2, y);
	//Thang 1
	if (d == 1 && m == 1) { m_Clock->setColor(236); cout << "CHUC MUNG NAM MOI"; }
	else if (d == 9 && m == 1) { m_Clock->setColor(121); cout << "TRUYEN THONG HOC SINH SINH VIEN VN"; }
	//Thang 2
	else if (d == 3 && m == 2) { m_Clock->setColor(206); cout << "NGAY THANH LAP DANG CONG SAN VN"; }
	else if (d == 27 && m == 2) { m_Clock->setColor(121); cout << "NGAY THAY THUOC VN"; }
	else if (d == 14 && m == 2) { m_Clock->setColor(125); cout << "NGAY LE TINH YEU VALENTINE"; }
	//Thang 3
	else if (d == 8 && m == 3) { m_Clock->setColor(125); cout << "NGAY QUOC TE PHU NU"; }
	else if (d == 26 && m == 3) { m_Clock->setColor(206); cout << "NGAY THANH LAP DOAN TNCS HO CHI MINH"; }
	//Thang 4
	else if (d == 30 && m == 4) { m_Clock->setColor(206); cout << "NGAY GIAI PHONG HOAN TOAN MIEN NAM"; }
	//Thang 5
	else if (d == 1 && m == 5) { m_Clock->setColor(121); cout << "NGAY QUOC TE LAO DONG"; }
	else if (d == 13 && m == 5) { m_Clock->setColor(125); cout << "NGAY CUA ME"; }
	else if (d == 15 && m == 5) { m_Clock->setColor(124); cout << "NGAY THANH LAP DOI TNTP HO CHI MINH"; }
	//Thang 6
	else if (d == 1 && m == 6) { m_Clock->setColor(121); cout << "NGAY QUOC TE THIEU NHI"; }
	else if (d == 17 && m == 6) { m_Clock->setColor(121); cout << "NGAY CUA BO"; }
	else if (d == 21 && m == 6) { m_Clock->setColor(115); cout << "NGAY BAO CHI VIET NAM"; }
	else if (d == 28 && m == 6) { m_Clock->setColor(115); cout << "NGAY GIA DINH VIET NAM"; }
	//Thang 7
	else if (d == 27 && m == 7) { m_Clock->setColor(206); cout << "NGAY THUONG BINH LIET SI"; }
	else if (d == 28 && m == 7) { m_Clock->setColor(206); cout << "THANH LAP CONG DOAN VIET NAM"; }
	//Thang 8
	else if (d == 19 && m == 8) { m_Clock->setColor(206); cout << "CACH MANG THANG TAM (19/08/1945)"; }
	//Thang 9
	else if (d == 2 && m == 9) { m_Clock->setColor(206); cout << "QUOC KHANH NUOC VIET NAM DAN CHU CH"; }
	else if (d == 10 && m == 9) { m_Clock->setColor(206); cout << "THANH LAP MAT TRAN TO QUOC VIET NAM"; }
	else if (d == 12 && m == 9) { m_Clock->setColor(206); cout << "XO VIET NGHE TINH (12/09/1930)"; }
	//Thang 10
	else if (d == 1 && m == 10) { m_Clock->setColor(117); cout << "NGAY QUOC TE NGUOI CAO TUOI"; }
	else if (d == 15 && m == 10) { m_Clock->setColor(121); cout << "NGAY HOI THANH NIEN VN"; }
	else if (d == 20 && m == 10) { m_Clock->setColor(125); cout << "NGAY THANH LAP HOI LIEN HIEP PHU NU VN"; }
	//Thang 11
	else if (d == 20 && m == 11)  { m_Clock->setColor(115); cout << " CHAO MUNG NGAY NHA GIAO VIET NAM"; }
	else if (d == 23 && m == 11) { m_Clock->setColor(124); cout << "NGAY THANH LAP HOI CHU THAP DO VN"; }
	//Thang 12
	else if (d == 1 && m == 12) { m_Clock->setColor(124); cout << "NGAY THE GIOI PHONG CHONG AIDS"; }
	else if (d == 22 && m == 12) { m_Clock->setColor(44); cout << "NGAY THANH LAP QUAN DOI NHAN DAN VN"; }
	else if (d == 25 && m == 12) {
		m_Clock->setColor(124);
		cout << "CHUC ";
		m_Clock->setColor(113);
		cout << "MUNG ";
		m_Clock->setColor(114);
		cout << "GIANG ";
		m_Clock->setColor(125);
		cout << "SINH";
	}
	else cout << "                                   ";
}

void CSmartWatch::Ring(int Signal) {
	if (Signal == 1) Beep(1000, 700);
}
