#pragma once

#include <vector>
//homework
using namespace std;
class SweepingBombs {
public:
	SweepingBombs(int row, int col);
	void play(int x, int y); //画家算法  种子填充算法
private:
	vector<vector<int> >m_grid;
	vector<vector<bool> >m_status;//是否被打开
};
