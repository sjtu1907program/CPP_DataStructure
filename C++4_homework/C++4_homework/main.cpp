#include<iostream>
#include"mines.h"
using namespace std;

minesPlace createGame()
{
	cout << "*********************************" << endl;
	cout << "         请选择游戏难度          " << endl;
	cout << "*********************************" << endl;
	cout << "*    1.场地6x6      地雷数4     *" << endl;
	cout << "*    2.场地9x9      地雷数12    *" << endl;
	cout << "*    3.场地13x13    地雷数30    *" << endl;
	cout << "*    4.自定义 (边长1-99)        *" << endl;
	cout << "*********************************" << endl;
	cout << endl << "请输入所选难度：";
	int sel, n, m;
	cin >> sel;
	while (true)
	{
		if (sel < 1 || sel > 4)
		{
			cout << endl << "*** 请选择正确的游戏难度! ****" << endl << endl;
			cout << "请输入所选难度：";
			cin >> sel;
		}
		else
		{
			break;
		}
	}
	switch (sel)
	{
	case 1:
		n = 6;
		m = 4;
		break;
	case 2:
		n = 9;
		m = 12;
		break;
	case 3:
		n = 13;
		m = 30;
		break;
	case 4:
		while (true)
		{
			cout << endl << "请输入边长：";
			cin >> n;
			if (n <= 0 || n >= 100)
			{
				cout << endl << "*** 请输入正确的边长(1-99)! ***" << endl;
				continue;
			}
			break;
		}
		while (true)
		{
			cout << endl << "请输入地雷个数：";
			cin >> m;
			if (m <= 0 || m >= n*n)
			{
				cout << endl << "*** 请输入合适的地雷个数! ***" << endl;
				continue;
			}
			break;
		}
		break;
	}
	system("cls");
	minesPlace a{ n, m };
	return a;
}

int main() 
{
	int i;
	while (true)
	{
		system("cls");
		minesPlace n = createGame();
		n.input();
		cout << "是否重新开始游戏(1.是  2.否):";
		cin >> i;
		while (true)
		{
			if (i != 1 && i != 2)
			{
				cout << endl << "*** 请选择正确的选项! ****" << endl << endl;
				cout << "是否重新开始游戏(1.是  2.否):";
				cin >> i;
			}
			else
			{
				break;
			}
		}
		if (i == 2)
		{
			break;
		}
	}
}