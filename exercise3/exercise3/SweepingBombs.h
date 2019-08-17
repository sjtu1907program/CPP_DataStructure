#pragma once
#include <vector>
#include<time.h>
#include<iostream>
#include<stack>


using namespace std;
typedef struct Point {
	int x;
	int y;
}Point;
class SweepingBombs
{
public:
	SweepingBombs(int row, int col,int bombs);
	void Play(int x, int y);
	bool getStatus() {
		return gameStatus;
	}
private:
	vector<vector<int> > m_grid;//0为没有炸弹 -1为有炸弹 1为9宫格有一颗炸弹
	vector<vector<bool> > m_status;
	bool gameStatus;
	int RandomNumber() {
		
		srand((int)time(0));
		return (rand() % (m_grid.size()*m_grid[0].size()-1))+1;
	};
	void ScanLineSeedFill(int x, int y);
	void SearchLineNewSeed(stack<Point>& stk, int xLeft, int xRight,int row);
	int  FindLeft(int x, int y);
	int FindRight(int x, int y);
	void SetBombs(int row,int col,int bombs);
	void Show_Status();
	
};

