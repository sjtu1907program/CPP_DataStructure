#pragma once
#include <vector>
using namespace std;

class SweepingBombs {
public:
	SweepingBombs(int row, int col, float difficulty);
	void play(int x, int y);
	bool gameover;
	void PrintGrid();
private:
	vector<vector<int> > m_grid;
	vector<vector<bool> > m_status;
	void PlantBombs(float difficulty);
	int bombsCount;
	int openedGridCount;
	void FillGrid();
	void ShowGrid();
};
