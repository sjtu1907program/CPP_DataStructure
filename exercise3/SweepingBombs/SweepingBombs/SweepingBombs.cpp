#include "SweepingBombs.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

SweepingBombs::SweepingBombs(int row, int col, float difficulty)
{
	m_grid.resize(row, vector<int>(col, 0));
	m_status.resize(row, vector<bool>(col, false));
	gameover = false;
	openedGridCount = 0;

	PlantBombs(difficulty);
	FillGrid();
	ShowGrid();
	cout << endl;
	PrintGrid();
}

void SweepingBombs::PlantBombs(float difficulty)
{
	bombsCount = (int)(m_grid.size() * m_grid[0].size() * difficulty);
	int bombs = bombsCount;;
	cout << "Bombs count : " << bombs << endl;
	srand((int)time(0));
	while (bombs!=0)
	{
		int randomRow = rand() % m_grid.size();
		int randomCol = rand() % m_grid[0].size();
		if (m_grid[randomRow][randomCol] != -1)
		{
			m_grid[randomRow][randomCol] = -1;
			bombs--;
		}
	}
}

void SweepingBombs::FillGrid()
{
	for (int i = 0; i < m_grid.size(); i++)
	{
		for (int j = 0; j < m_grid[0].size(); j++)
		{
			if (m_grid[i][j] == 0)	//遍历数值为0的格子
			{
				for (int m = i - 1; m <= i + 1; m++)
				{
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (m >= 0 && m < m_grid.size() && n >= 0 && n < m_grid[0].size())	//查找格子周围一圈的雷数
						{
							if (m_grid[m][n] == -1)
							{
								m_grid[i][j]++;
							}
						}
					}
				}
			}
		}
	}
}

void SweepingBombs::PrintGrid()
{
	cout << "\t";
	for (int i = 0; i < m_grid[0].size(); i++)
	{
		cout << "[" << i << "]" << "\t";
	}
	cout << endl;
	for (int i = 0; i < m_grid.size(); i++)
	{
		cout<< "[" << i << "]" << "\t";
		for (int j = 0; j < m_grid[0].size(); j++)
		{
			if (!m_status[i][j])	//格子没打开
			{
				cout << " #" << "\t";
			}
			else
			{
				cout << " " << m_grid[i][j] << "\t";
			}
		}
		cout << endl;
	}
}

void SweepingBombs::ShowGrid()
{
	cout << "\t";
	for (int i = 0; i < m_grid[0].size(); i++)
	{
		cout << "[" << i << "]" << "\t";
	}
	cout << endl;
	for (int i = 0; i < m_grid.size(); i++)
	{
		cout << "[" << i << "]" << "\t";
		for (int j = 0; j < m_grid[0].size(); j++)
		{		
			cout << " " << m_grid[i][j] << "\t";
		}
		cout << endl;
	}
}

void SweepingBombs::play(int x, int y)
{
	if (m_status[x][y])		//格子已经打开过
	{
		//cout << "Error: Row " << x << " Col " << y << " is opened." << endl;
		return;
	}
	else
	{
		m_status[x][y] = true;
		openedGridCount++;
		if (m_grid[x][y] == -1)		//打开地雷
		{
			cout << "The bomb is triggered. You lose! " << endl;
			gameover = true;
			return;
		}
		else if(m_grid[x][y] == 0)		//打开空格
		{
			if (x >= 1 && m_grid[x - 1][y] != -1)
			{
				play(x - 1, y);
			}
			if (y >= 1 && m_grid[x][y - 1] != -1)
			{
				play(x, y - 1);
			}
			if (x <= m_grid.size() - 2 && m_grid[x + 1][y] != -1)
			{
				play(x + 1, y);
			}
			if (y <= m_grid[0].size() - 2 && m_grid[x][y + 1] != -1)
			{
				play(x, y + 1);
			}
		}
	}
	if (openedGridCount + bombsCount == m_grid.size()*m_grid[0].size())
	{
		cout << "The bomb is not triggered. You win! " << endl;
		gameover = true;
		return;
	}
}

