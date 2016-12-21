#pragma warning(disable:4996)
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iostream>
using namespace std;
#pragma once

class CGraphics
{
public:
	void setColor(int Color);
	void gotoxy(int x, int y);
	void ProBoard(int width, int height, int x, int y);
	void setBoardConsole(int width, int height, char* title);
};

