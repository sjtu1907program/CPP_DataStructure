#pragma once
#include <vector>
#include <tchar.h>
#include <iostream>

using namespace std;

class SweepingBombs {

public:
	SweepingBombs(int row, int col);
	void print();
	void play(int x,int y);
	~SweepingBombs();
private:
	vector<vector<int> > m_grid;
	vector<vector<bool>> m_status;
	int col{};
	int row{};
private:	
	void NumInit();
	void initPrint();
	void GameControl();
};

