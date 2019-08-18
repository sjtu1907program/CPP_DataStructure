#include<iostream>
#include<vector>
#include <random>
#include <ctime>
#include"SweepingBombs.h"
using namespace std;

void SweepingBombs::MainLoop()
{
	cin >> command;
	if (command == 'h' || command == 'H')
	{
		PrintHelp(); return;
	}
	else {
		cin >> _c >> _r;

		if (_c<1 || _c>col || _r<1 || _r>row) {
			cout << "wrong index\n";
			PrintTip();
			return;
		}
		switch (command)
		{
		case 'c':case 'C':
			Click(_c - 1, _r - 1);
			break;
		case 'm':case 'M':
			Mark(_c - 1, _r - 1);
			break;
		default:
			cout << "wrong command\n";
			PrintTip();
			return;
		}

	}
	PrintMap();

	if (revealCount == col * row - minesCnt)
	{
		cout << "-------YOU WIN!!!-------\n";
		system("pause");
	}
	PrintTip();
}

//点击行为（左键）
void SweepingBombs::Click(int c, int r)
{
	if (m_userMap[c][r] != '+')
	{
		cout << "无效操作\n";
		return;
	}//被标记或已被打开的情况，无效果
	if (!initMineFlag)//在第一次点击后生成雷地图
	{
		SetMines(c, r);
		initMineFlag = true;
	}

	if (m_mineMap[c][r] == -1)//踩到雷
	{
		cout << "------- G A M E   O V E R -------\n";
		PrintMine();
		system("pause");
	}
	else
	{
		Reveal(c, r);
	}
}

//标记行为（右键）
void SweepingBombs::Mark(int c, int r)
{
	if (m_userMap[c][r] == '+') {
		m_userMap[c][r] = 'X';
		markCount++;
	}
	else if (m_userMap[c][r] == 'X') {
		m_userMap[c][r] = '+';
		markCount--;
	}
}

void SweepingBombs::Reveal(int c, int r)
{
	if (c < 0 || c >= col || r < 0 || r >= row)return;//递归时碰到边界
	if (m_userMap[c][r] != '+')return;//已被打开

	m_userMap[c][r] = m_mineMap[c][r] + '0';
	revealCount++;

	if (m_mineMap[c][r] == 0)//若为0，继续打开周围一圈
	{
		Reveal(c - 1, r - 1);	Reveal(c - 1, r);	Reveal(c - 1, r + 1);
		Reveal(c, r - 1);	Reveal(c, r + 1);
		Reveal(c + 1, r - 1);	Reveal(c + 1, r);	Reveal(c + 1, r + 1);
	}
}


//雷图初始化
void SweepingBombs::SetMines(int avoid_c, int avoid_r)
{
	default_random_engine e;
	e.seed(unsigned(time(0)));
	uniform_int_distribution<unsigned> range_c(0, col - 1);
	uniform_int_distribution<unsigned> range_r(0, row - 1);

	int c, r;
	bool flag;//flag为true代表本次roll的位置可行

	for (int i = 0; i < minesCnt; i++)//设置99个雷
	{
		flag = false;
		while (!flag) {
			c = range_c(e);
			r = range_r(e);

			//检查此处放雷是否可行
			flag = true;
			if (m_mineMap[c][r] == -1)flag = false;//要回避已经放下的
			if (c == avoid_c && r == avoid_r)flag = false;//需要回避第一次点击（即此函数的参数）
		}
		m_mineMap[c][r] = -1;

		//设置好雷之后要将周围一圈的数字置好
		MineNeighbor(c - 1, r - 1); MineNeighbor(c - 1, r); MineNeighbor(c - 1, r + 1);
		MineNeighbor(c, r - 1); MineNeighbor(c, r + 1);
		MineNeighbor(c + 1, r - 1); MineNeighbor(c + 1, r); MineNeighbor(c + 1, r + 1);
	}

	//TODO:回避被完全围死的雷（规避九宫格的都是雷的情况）

	//PrintMine();
}

void SweepingBombs::MineNeighbor(int c, int r)
{
	if (c < 0 || c >= col || r < 0 || r >= row)return;//递归时碰到边界
	if (m_mineMap[c][r] != -1)//如果不是雷的话，数字++
		m_mineMap[c][r]++;
}

void SweepingBombs::PrintMap()
{
	for (int j = 0; j <= row; j++)
	{
		if (j % 5 == 0)
			if (j % 10 == 0)cout << "0 ";
			else cout << "5 ";
		else cout << "  ";
	}
	cout << endl;
	for (int i = 0; i < col; i++)
	{
		if ((i + 1) % 5 == 0)
			if ((i + 1) % 10 == 0)cout << "0 ";
			else cout << "5 ";
		else cout << "  ";

		for (int j = 0; j < row; j++)
			cout << m_userMap[i][j] << ' ';
		cout << endl;
	}
}

void SweepingBombs::PrintMine()
{
	cout << "雷图:" << endl << "--------------------------" << endl;
	for (int j = 0; j <= row; j++)
	{
		if (j % 5 == 0)
			if (j % 10 == 0)cout << "0 ";
			else cout << "5 ";
		else cout << "  ";
	}
	cout << endl;
	for (int i = 0; i < col; i++)
	{
		if ((i + 1) % 5 == 0)
			if ((i + 1) % 10 == 0)cout << "0 ";
			else cout << "5 ";
		else cout << "  ";

		for (int j = 0; j < row; j++)
			cout << m_mineMap[i][j] << ' ';
		cout << endl;
	}
	cout << "--------------------------" << endl;
}

void SweepingBombs::PrintTip()
{
	cout << "输入你的下一步：\n";
	cout << "[c _ _]--点开, [m _ _]--标记雷, [h]--统计与帮助" << endl;
}

void SweepingBombs::PrintHelp()
{
	cout << "已点开" << revealCount << "格\n";
	cout << "按照标记还剩" << minesCnt - markCount << "个雷\n";
	cout << "我还没写帮助\n";
}



SweepingBombs::SweepingBombs(int c, int r, int m) :col(c), row(r), minesCnt(m)
	{
		vector<int> tmp1(row, 0);
		vector<char> tmp2(row, '+');
		for (int i = 0; i < col; i++)
		{
			m_mineMap.push_back(tmp1);
			m_userMap.push_back(tmp2);
		}

	}

	//进入游戏的函数
void SweepingBombs::StartGame()
{
	PrintMap();
	cout << "输入你的下一步：\n";
	cout << "[c _ _]--点开, [m _ _]--标记雷, [h]--统计与帮助" << endl;
	while (true)
	{
		MainLoop();
	}
}