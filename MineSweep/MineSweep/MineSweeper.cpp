#include "MineSweeper.h"

#include <iostream>
#include <math.h>
#include <time.h>



/* 雷区的生成，*/
void MineSweeper::createMap(int _rows, int _cols) {
	if (_rows <= 3 || _cols <= 3)
		throw "m_rows or m_cols is too small";
	m_grid = vector<vector<int>>(_rows + 2,vector<int>(_cols + 2, SAFE_CELL));
	m_status = vector<vector<bool>>(_rows + 2,vector<bool>(_cols + 2,false));
	//在实际的雷区外周扩展一圈空白区，方便之后的计算
}

MineSweeper::MineSweeper(int _rows, int _cols) {
	new (this)MineSweeper(_rows, _cols, Mode::NORMAL);
}

MineSweeper::MineSweeper(int _rows, int _cols, Mode mode) {
	//雷的数量与地图有关
	switch (mode) {
	case Mode::EASY:
		m_mines = (_rows * _cols) / 16;
		break;
	case Mode::NORMAL:
		m_mines = (_rows * _cols) / 8;
		break;
	case Mode::HARD:
		m_mines = (_rows * _cols) / 6;
		break;
	case Mode::CRAZY:
		m_mines = (_rows * _cols) / 4;
		break;
	default:
		m_mines = _rows + _cols;
		break;
	}
	new (this)MineSweeper(_rows,_cols, m_mines);

}
MineSweeper::MineSweeper(int _rows, int _cols, int _mines) {
	m_rows = _rows;
	m_cols = _cols;
	m_mines = _mines;
	m_gameover = false;
	m_safeCells = m_rows * m_cols - m_mines;
	//生成初始地图
	createMap(m_rows, m_cols);
	m_foundedSafeCounts = 0;
	shuffle(); //洗牌，生成随机位置的地雷
	envValConfig();	//根据地雷配置其他cell的内容
}


MineSweeper::~MineSweeper(void) {

}

//打开制定的位置
bool MineSweeper::play(int x, int y) {
	if (x <= 0  || x > m_cols) return false;
	if (y <= 0 || y > m_rows) return false;
	bool result = true;
	if (m_status[x][y]) {
		cout << "this cell has been open!" << endl;
		return true;
	}
	m_status[x][y] = true;
	int val = m_grid[x][y];
	if (val == MINE_CELL) {
		if (0 == m_foundedSafeCounts) {
			val = swapMine(x, y);	//更新值
		}
		else {
			m_gameover = true;
			cout << "You failed!" << endl;
		}
	}
	if (!m_gameover) {
		//不是雷，则更新计数。
		m_foundedSafeCounts++;
		if (val == SAFE_CELL) {//若不是雷，且周边没有雷。则需对其进行unfold操作
			unfold(x, y);
		}
	}
	print();
	return true;
}

void MineSweeper::show() {
	for (int i = 0; i <= m_rows; ++i)
	{
		for (int j = 0; j <= m_cols; ++j) {
			if (j == 0) {
				cout << i << "\t";
			}
			else if (i == 0) {
				cout << j << "  ";
			}
			else {
				int tmp = m_grid[i][j];
				if (tmp == MINE_CELL) {
					cout << "!  ";
				}
				else {
					cout << tmp << "  ";
				}
			}
		}
		cout << endl;
	}
}
//打印地图
void MineSweeper::print() {
	for (int i = 0; i <= m_rows; ++i)
	{
		for (int j = 0; j <= m_cols; ++j) {
			if (j==0) {
				cout << i << "\t";
			}
			else if (i == 0) {
				cout << j << "  ";
			}
			else if (m_status[i][j]) {
				int tmp = m_grid[i][j];
				if (tmp == MINE_CELL) {
					cout << "!  ";
				}
				else {
					cout << tmp << "  ";
				}
			}else{
					cout << "@  ";
			}
		}
		cout << endl ;
	}
}

bool MineSweeper::checkOver() {
	if (m_foundedSafeCounts == m_safeCells) {
		m_gameover = true;
		cout << "Win!!" << endl;
	}
	return m_gameover;
}

/*
	地雷的随机生成函数
*/
void MineSweeper::shuffle() {
	int counts = m_mines;
	srand(time(0));
	while (counts) {
		int i = rand() % m_rows +1;
		int j = rand() % m_cols +1;
		if (m_grid[i][j] == SAFE_CELL) {
			m_grid[i][j] = MINE_CELL;
			counts--;
		}
	}

}

void MineSweeper::envValConfig() {
	for (int i = 1; i <= m_rows; ++i)
		for (int j = 1; j <= m_cols; ++j) {
			if (m_grid[i][j]== SAFE_CELL)
				m_grid[i][j] = round(i,j);
		}
}

/*
	round函数返回制定格子周围一圈内的地雷数量
*/
inline int MineSweeper::round( int i, int j) {
	int m_rows = m_grid.size(), m_cols = m_grid[0].size();//行和列
	int result{ 0 };
	for (int x = -1; x <= 1; x++)
		for (int y = -1; y <= 1; y++)
			result += (m_grid[i + x][j + y] == MINE_CELL) ? 1 : 0;
	return result;
}

/*
	unfold函数将状态为SAFE_CELL的格子四周的所有格子全部打开
*/
void MineSweeper::unfold(int i, int j) {
	if (i <1 || i > m_rows || j <1 || j > m_cols) return;
	if (m_grid[i][j] != SAFE_CELL) return;
	for(int x = -1 ; x <=1 ; x++)
		for (int y = -1; y <= 1; y++) {
			if (x == 0 && y == 0) continue;	//跳过中心位置
			int tmpx = i + x, tmpy = j + y;
			if (!m_status[tmpx][tmpy])
			{
				m_foundedSafeCounts++;
				m_status[tmpx][tmpy] = true;
				if (m_grid[tmpx][tmpy] == SAFE_CELL)
					unfold(tmpx, tmpy);
			}
		}
}

/*
 如果第一个点开的就是雷，则对其进行一下交换，同时需要重新更新这两个位置四周的计数
*/
int  MineSweeper::swapMine(int x, int y) {
	//寻找一个不是雷的cell
	while (1) {
		int i = rand() % m_rows + 1;
		int j = rand() % m_cols + 1;
		if (m_grid[i][j] != MINE_CELL) {
			m_grid[i][j] = m_grid[x][y];//将地雷放入找到的cell位置，
			m_grid[x][y] = round(x,y);//刷新原位置的数据
			for (int a = -1; a <= 1; a++)
				for (int b = -1; b <= 1; b++) {
					if (a == 0 && b == 0) continue;
					m_grid[i+a][j+b] +=(m_grid[i + a][j + b] == MINE_CELL)? 0 : 1;
					m_grid[x+a][y+b] -= (m_grid[x + a][y + b] == MINE_CELL) ? 0 : 1;
				}
			return m_grid[x][y];
		}
	}
}

