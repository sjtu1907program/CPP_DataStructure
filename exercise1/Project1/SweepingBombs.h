#pragma once
#include<iostream>
#include<vector>
#include <random>
#include <ctime>
using namespace std;


class SweepingBombs {

private:
	void MainLoop();

	//点击行为（左键）
	void Click(int c,int r);

	//标记行为（右键）
	void Mark(int c, int r);

	void Reveal(int c, int r);


	//雷图初始化
	void SetMines(int avoid_c, int avoid_r);

	void MineNeighbor(int c, int r);

	void PrintMap();

	void PrintMine();
	
	void PrintTip();

	void PrintHelp();


public:


	SweepingBombs(int c, int r, int m);
	
	//进入游戏的函数
	void StartGame();


private:
	const int col;
	const int row;
	const int minesCnt;

	bool initMineFlag = false;	
	int revealCount = 0;		//用于胜利判定
	int markCount = 0;

	//用于用户输入
	char command;
	int _c, _r;

	vector<vector<char>> m_userMap;
	vector<vector<int>> m_mineMap;//-1为雷，自然数为周围一圈雷数
};







