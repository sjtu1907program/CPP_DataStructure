#include"SweepingBombs.h"
#include<iostream>
using namespace std;


int main()
{
	SweepingBombs Game(16, 30, 50);//行数，列数，雷数
	Game.StartGame();
	system("pause");
	return 0;
}
