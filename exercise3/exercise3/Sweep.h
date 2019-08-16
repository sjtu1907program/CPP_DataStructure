#pragma once
#include<vector>
#include<ctime>
#include<iostream>
using namespace std;
class SweepingBombs {
public:
	SweepingBombs(int row, int col);
	bool Play(int x, int y);
	void ResetLevel(int level);
	void Print();
private:
	std::vector<std::vector<int> >  m_grid;
	vector<vector<bool> > m_status;
	int col;
	int row;
};

enum DIFFICULT_LEVEL
{
	DIFFICULT_LEVEL_EASY,
	DIFFICULT_LEVEL_NORMAL,
	DIFFICULT_LEVEL_HARD
};