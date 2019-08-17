#include "SweepingBombs.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Row and Col ?" << endl;
	cout << "Row : ";
	int row;
	cin >> row;
	cout << "Col : ";
	int col;
	cin >> col;
	cout << "Difficulty ? (0~1)" << endl;
	cout << "Difficulty : ";
	float diffi;
	cin >> diffi;
	auto s = SweepingBombs(row, col, diffi);
	cout << endl;

	while (!s.gameover)
	{
		cout << "Select x and y" << endl;
		cout << "x : ";
		int x;
		cin >> x;
		cout << "y : ";
		int y;
		cin >> y;
		cout << endl;
		s.play(x, y);
		s.PrintGrid();
		cout << endl;
	}

	return 0;
}