#pragma once
#include <vector>

using namespace std;

class SweepingBombs {
public:
	SweepingBombs(int row, int col);
	void play(int x, int y);
private:
	vector<vector<int> > m_grid;
	vector<vector<bool> > m_status;
};