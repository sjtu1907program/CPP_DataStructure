#pragma once
#include <vector>
#include <tchar.h>
#include <iostream>

using namespace std;

class SweepingBombs {

public:
	SweepingBombs(int row, int col);
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
	void Reveal(int x, int y, bool bForce = false );
	void play(int x, int y);
	void print();
};

