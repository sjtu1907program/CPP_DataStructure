#pragma once
#include<vector>
#include<ctime>
#include<iostream>
#include<stack>
using namespace std;
class SweepingBombs {
public:
	SweepingBombs(int row, int col);
	bool Play(int x, int y);
	void ResetLevel(int level);
	void FullFillOpen(int y, int x);
	int FullFillLeft(int y, int x);
	int FullFillRight(int y, int x);
	void SetNewSeed(stack<int> &fx, stack<int> &fy, int tLeft, int tRight, int y);
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