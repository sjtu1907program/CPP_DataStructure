#include "SweepingBombs.h"

SweepingBombs::SweepingBombs(int row, int col)
{
	this->row = row;
	this->col = col;
	vector<vector<int>> vec(row, vector<int>(col));
	vector<vector<bool>> vec2(row, vector<bool>(col));
	m_grid = vec;
	m_status = vec2;
	for (int i{}; i < row; ++i)
	{
		for (int j{}; j < col; j++)
		{
			m_grid[i][j] = (rand() % (row*col+20)) < row*col ? 0 : -1;
		}
	} 
	NumInit();
	initPrint();
	GameControl();
}

void SweepingBombs::NumInit()
{
	for (int i{}; i < row; i++)
	{
		for (int j{}; j < col; j++)
		{
			
			if (m_grid[i][j] != -1)
			{
				int count{};
				if ((i - 1) > 0 && (j - 1) > 0 && m_grid[i - 1][j - 1] == -1)
				{
					count++;
				}
				if ((i - 1) > 0 && m_grid[i - 1][j] != -1)
				{
					count++;
				}
				if ((i - 1) > 0 && (j + 1) < col && m_grid[i - 1][j + 1] == -1)
				{
					count++;
				}
				if ((j - 1) > 0 && m_grid[i][j - 1] == -1)
				{
					count++;
				}
				if ((j + 1) < col && m_grid[i][j + 1] == -1)
				{
					count++;
				}
				if ((i + 1) < row && (j - 1) > 0 && m_grid[i + 1][j - 1] == -1)
				{
					count++;
				}
				if ((i + 1) < row  && m_grid[i + 1][j] == -1)
				{
					count++;
				}
				if ((i + 1) < row && (j + 1) < col && m_grid[i + 1][j + 1] == -1)
				{
					count++;
				}
				m_grid[i][j] = count;
			}
		}
	}
}

void SweepingBombs::initPrint()
{
	for (int i{}; i < row; i++)
	{
		for (int j{}; j < col; j++)
		{
			cout << m_grid[i][j] << "  ";
		}
		cout << endl << endl;
	}
}

void SweepingBombs::print()
{
	for (int i{} ; i< row;i++)
	{
		for (int j{}; j < col; j++)
		{
			if (m_status[i][j])
			{
				cout << " " << m_grid[i][j] ;
			}
			else
			{
				cout << " *";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void SweepingBombs::play(int x, int y)
{

	if (m_grid[x - 1][y - 1] != 0)
	{
		m_status[x - 1][y - 1] = true;
	}
	else
	{
		Reveal(x-1,y-1);
	}
}

void SweepingBombs::Reveal(int x, int y)
{
	int i = x ;
	int j = y ;
	if (m_grid[i][j] == 0)
	{
		int count{};
		if ((i - 1) > 0 && (j - 1) > 0 && m_grid[i - 1][j - 1] == -1)
		{
			Reveal(i - 1,j - 1 );
		}
		if ((i - 1) > 0 && m_grid[i - 1][j] != -1)
		{
			Reveal(i - 1, j );
		}
		if ((i - 1) > 0 && (j + 1) < col && m_grid[i - 1][j + 1] == -1)
		{
			Reveal(i - 1, j + 1);
		}
		if ((j - 1) > 0 && m_grid[i][j - 1] == -1)
		{
			Reveal(i , j - 1);
		}
		if ((j + 1) < col && m_grid[i][j + 1] == -1)
		{
			Reveal(i , j + 1);
		}
		if ((i + 1) < row && (j - 1) > 0 && m_grid[i + 1][j - 1] == -1)
		{
			Reveal(i + 1, j - 1);
		}
		if ((i + 1) < row  && m_grid[i + 1][j] == -1)
		{
			Reveal(i + 1, j);
		}
		if ((i + 1) < row && (j + 1) < col && m_grid[i + 1][j + 1] == -1)
		{
			Reveal(i + 1, j + 1);
		}
	}
	m_status[i][j] = true;
	return;
}

void SweepingBombs::GameControl()
{
	int x{}, y{};
	do
	{
		print();
		scanf_s("%d %d", &x, &y);
		cout << endl;
		play(x, y);	
	}while (m_grid[x - 1][y - 1] != -1);
	
	cout << "Game Over!" << endl;
	initPrint();
}

SweepingBombs::~SweepingBombs()
{

}
