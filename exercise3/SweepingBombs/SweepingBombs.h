#ifndef _Sweeping_Bombs
#define _Sweeping_Bombs
#include <vector>
using namespace std;
class SweepingBombs {

public:
	SweepingBombs(int row, int col,int dif);
	void play(int x, int y);
	bool gameEnd{ false };
private:
	vector<vector<int>> m_grid;
	vector<vector<bool>> m_status;
	int winNum;
	void showNeibor(int x,int y);
	int countNum(int x, int y);
	bool firstPlay{true};
};
#endif // _Sweeping_Bombs
