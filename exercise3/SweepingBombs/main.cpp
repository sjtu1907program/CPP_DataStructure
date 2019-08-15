#include <iostream>
#include "SweepingBombs.h"
using namespace std;
int main() {
	int rows,cols;
	cout << "Please Enter rows and cols: " << endl;
	bool checkInput = true;
	while (checkInput)
	{
		cin >> rows >> cols;
		if (rows >= 40 || cols >= 40)
			cout << "Too High, Enter Aagin" << endl;
		else if (rows < 2 || cols < 2)
			cout << "Too Simple or Input Error" << endl;
		else
		{
			checkInput = false;
		}
	}

	//input difficulty
	checkInput = true;
	int diffi;
	cout << "Please choice Difficulty: level 1,2,or3:" << endl;
	while (checkInput)
	{
		cin >> diffi;
		if (diffi < 1 || diffi>3) {
			cout << "please input DIFFICULTY again! " << endl;
		}
		else
		{
			checkInput = false;
		}
	}
	SweepingBombs game(rows, cols, diffi);
	int x, y;
	while (!game.gameEnd)
	{
		cin >> x >> y;
		game.play(x, y);
	}
	return 0;
}