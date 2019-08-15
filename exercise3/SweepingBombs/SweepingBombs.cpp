#include "SweepingBombs.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
SweepingBombs::SweepingBombs(int rows, int cols,int dif) {
	double difficluty = 0.1f*dif;
	m_grid = vector<vector<int>>(rows, vector<int>(cols,0));
	m_status = vector<vector<bool>>(rows, vector<bool>(cols, false));
	int gridSize = rows * cols;
	int BombNum = gridSize *difficluty;
	winNum = gridSize - BombNum;
	srand(time(NULL));
	//place bombs
	while (BombNum>0)
	{
		int r = rand()%rows;
		int c = rand()% cols;
		if (m_grid[r][c] == 0) {
			--BombNum;
			m_grid[r][c] = -1;
		}
	}
	//show map
	cout << setw(4)<< ' ';
	for (int i = 1; i <= cols; ++i) {
		cout << setw(4) << i;
	}
	cout << endl;
	for (int i = 0; i < rows; ++i) {
		cout << setw(4) << i + 1 ;
		for (int j = 0; j < cols; ++j) {
			cout << setw(4) << "@";
		}
		cout << endl;
	}
}
void SweepingBombs::play(int x,int y){
	--x; --y;
	int rows = m_grid.size();
	int cols = m_grid[0].size();
	int gridSize = cols * rows;
	//check input
	if (x < 0 || y < 0 || x >= rows || y >= cols) {
		cout << "Please Input Right Point!" << endl;
		return;
	}
	//firstPlay: game should not end
	if (firstPlay) {
		firstPlay = false;
		//test if end
		if (m_grid[x][y] == -1) {
			bool setAnother = false;
			while (!setAnother)
			{
				int randPos = rand() % gridSize;
				int r = randPos % rows;
				int c = randPos % cols;
				if (m_grid[r][c] == 0) {
					m_grid[r][c] = -1;
					setAnother = true;
				}
			}
			m_grid[x][y] = 0;
		}

		//inital m_gird
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if(m_grid[i][j]!=-1)
					m_grid[i][j] = countNum(i, j);
			}
		}
	}
	
	//touch (x,y)
	if (m_status[x][y]) {
		cout << "This point has been touched!" << endl;
	}
	else
	{
		if (m_grid[x][y] == -1) {
			cout << "Game Over!" << endl;
			cout << setw(4) << ' ';
			for (int i = 1; i <= cols; ++i) {
				cout << setw(4) << i;
			}
			cout << endl;
			for (int i = 0; i < rows; i++) {
				cout << setw(4) << i + 1;
				for (int j = 0; j < cols; j++) {
					if (m_grid[i][j] == -1)
						cout << setw(4) << '*';
					else
					{
						if (m_status[i][j] == true) {
							cout << setw(4) << m_grid[i][j];
						}
						else
						{
							cout << setw(4) << "@";
						}
					}
				}
				cout << endl;
			}
			gameEnd = true;
			return;
		}
		else
		{
			showNeibor(x,y);
		}
	}
	//check win
	if (winNum == 0&&!gameEnd) {
		cout << "You win! " << endl;
		gameEnd = true;
	}
	//show map
	cout << setw(4) <<' ';
	for (int i = 1; i <= cols; ++i) {
		cout << setw(4) << i;
	}
	cout << endl;
	for (int i = 0; i < rows; i++) {
		cout << setw(4) << i + 1 ;
		for (int j = 0; j < cols; j++) {
			if (m_status[i][j])
				cout << setw(4) << m_grid[i][j];
			else
			{
				cout << setw(4) << "@";
			}
		}
		cout << endl;
	}
}
void SweepingBombs::showNeibor(int x,int y) {
	if (x < 0 || y < 0 || x >= m_status.size() || y >= m_status[0].size() || m_status[x][y] == true) return;
	m_status[x][y] = true;
	--winNum;
	if (m_grid[x][y] == 0) {
		showNeibor(x + 1, y);
		showNeibor(x + 1, y+1);
		showNeibor(x + 1, y-1);
		showNeibor(x - 1, y);
		showNeibor(x - 1, y+1);
		showNeibor(x - 1, y-1);
		showNeibor(x, y-1);
		showNeibor(x, y+1);
	}
}
int SweepingBombs::countNum(int x, int y) {
	int res = 0;
	int rows = m_grid.size();
	int cols = m_grid[0].size();
	if (x > 0) {
		if (m_grid[x - 1][y] == -1) ++res;
		if (y < cols-1) if (m_grid[x - 1][y + 1] == -1) ++res;
		if(y>0) if (m_grid[x - 1][y - 1] == -1) ++res;
	}
	if (x < rows-1) {
		if (m_grid[x + 1][y] == -1) ++res;
		if(y<cols-1) if (m_grid[x + 1][y + 1] == -1) ++res;
		if (y > 0) if (m_grid[x + 1][y - 1] == -1) ++res;
	}
	if(y>0)
		if (m_grid[x][y-1] == -1) ++res;
	if(y<cols-1)
		if (m_grid[x][y+1] == -1) ++res;
	return res;
}


