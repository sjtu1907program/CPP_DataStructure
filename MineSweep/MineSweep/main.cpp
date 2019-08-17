#include <iostream>
#include <vector>
#include "MineSweeper.h"

using namespace std;



void GetInput(int16_t & rows, int16_t & cols, int16_t & mode, int16_t & bombs);
void MineSweeperTest();

int main(void)
{
	
	MineSweeperTest();
	system("pause");
}

void MineSweeperTest() {
	int16_t rows{ 5 }, cols{ 5 };
	int16_t mode{ 2 };
	int16_t bombs{ 0 };
	GetInput(rows, cols, mode, bombs);
	cout << endl << rows << "  " << cols << " " << mode << bombs << endl;
	MineSweeper * ms = nullptr;
	ms = new MineSweeper(rows, cols, Mode::HARD);
	ms->print();

	if (mode == 5)
	{
		ms = new MineSweeper(rows, cols, bombs);
	}
	else {
		switch (mode) {
		case 1:
			ms = new MineSweeper(rows, cols, Mode::EASY);
			break;
		case 2:
			ms = new MineSweeper(rows, cols, Mode::NORMAL);
			break;
		case 3:
			ms = new MineSweeper(rows, cols, Mode::HARD);
			break;
		case 4:
			ms = new MineSweeper(rows, cols, Mode::CRAZY);
			break;
		}
	}

	int x, y;
	cout << "Input x and y:";
	while (((cin >> x) && (cin >> y))) {
		if (x == -1 && y == -1) ms->show();
		else {
			bool error = !ms->play(x, y);
			if (error)
				cout << "input error. input x and y again:" << endl;
		}
		if (ms->checkOver()) break;
		cout << "Input x and y:";
	}
	cout << "game over!" << endl;
}

void GetInput(int16_t & rows, int16_t & cols, int16_t & mode, int16_t & bombs) {
	cout << "please input rows and cols of map(rows:>3 and cols:>3):" << endl;
	while (!((cin >> rows) && (cin >> cols)) || rows <= 3 || cols <= 3) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Error:: please input the valid data (rows(>3) and cols(>3)):" << endl;
	}

	cout << "please input mode(1:easy  2:normal  3:hard  4:crazy  5:custom):" << endl;
	while ((!(cin >> mode) && (cin.get() != '\n')) || mode <= 0 || mode > 5) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Error:: please input valid mode(1:easy  2:normal  3:hard  4:crazy  5:custom):" << endl;
	}
	if (mode == 5)
	{
		int16_t bombs{ 0 };
		cout << "please input the number of bombs:" << endl;
		while (!(cin >> bombs) || bombs <= 0) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Error:: please input the number of bombs:" << endl;
		}
	}
}