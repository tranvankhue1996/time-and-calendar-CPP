#include "Graphics.h"

void CGraphics::setColor(int Color) {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, Color);
}
//Đưa Con Trỏ Tới Tọa Độ
void CGraphics::gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
//Bảng Phụ
void CGraphics::ProBoard(int width, int height, int x, int y) {
	for (int i = 0; i < height; i++) {
		gotoxy(x, y + i);
		if (i == 0) {
			for (int t = 0; t < width; t++) {
				if (t == 0) cout << "ÚÄ";
				else if (t == width - 1) cout << "Ä¿";
				else cout << "ÄÄÄ";
			}
		}
		else if (i == height - 1) {
			for (int b = 0; b < width; b++) {
				if (b == 0) cout << "ÀÄ";
				else if (b == width - 1) cout << "ÄÙ";
				else cout << "ÄÄÄ";
			}
		}
		else {
			for (int m = 0; m < width; m++) {
				if (m == 0) cout << "³ ";
				else if (m == width - 1) cout << " ³";
				else cout << "   ";
			}
		}
	}
}
//Thiết Lập Bảng
void CGraphics::setBoardConsole(int width, int height, char* title) {
	HANDLE wHnd;    // Handle để ghi lên console.
	HANDLE rHnd;    // Handle để đọc từ console.

	// Khởi tạo giá trị đọc/ghi cho handle.
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);

	// Thay đổi tiêu đề cho cửa sổ:
	SetConsoleTitle(TEXT(title));

	// Thiết lập thông tin về kích thước mới:
	SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };

	// Thay đổi kích thước của Console:
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

	// COORD chứa thông tin về kích thước bộ đệm:
	COORD bufferSize = { width, height };

	// Thay đổi kích thước bộ đệm:
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}