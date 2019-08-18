#include"Sweep.h"

SweepingBombs::SweepingBombs(int row, int col) {
	this->col = col;
	this->row = row;
	srand(time(NULL));
	m_grid.resize(row);
	/*for (int i = 0; i < row; i++)
	{
		m_grid.push_back((vector<int>(col)));
	}*/
	vector<vector<int> >::iterator iRow;
	iRow = m_grid.begin();
	for (; iRow != m_grid.end(); iRow++)
	{
		(*iRow).resize(col);
	}

	m_status.resize(row);
	/*for (int i = 0; i < row; i++)
	{
		m_grid.push_back((vector<int>(col)));
	}*/
	vector<vector<bool> >::iterator bRow;
	bRow = m_status.begin();
	for (; bRow != m_status.end(); bRow++)
	{
		(*bRow).resize(col);
	}
}
void SweepingBombs::ResetLevel(int level) {
	float density;
	int maxCount = col * row;
	int mineCount;
	int noneMineCount;
	switch (level)
	{
	case DIFFICULT_LEVEL_EASY:
		density = 0.1f;
		break;
	case DIFFICULT_LEVEL_NORMAL:
		density = 0.4f;
		break;
	case DIFFICULT_LEVEL_HARD:
		density = 0.6f;
		break;
	default:
		break;
	}
	mineCount = density * maxCount;
	noneMineCount = maxCount - mineCount;
	//cout << mineCount;
	//vector<vector<int> >::iterator iRow;
	//vector<int>::iterator iCol;
	for (int i = 0; i < row; i++) {
		for (int n = 0; n < col; n++) {
			int check = rand() % (maxCount - i*col-n) + 1;//1~当前值。
			if (check <= mineCount) {
				*((*(m_grid.begin() + i)).begin() + n) = -1;
				mineCount--;
			}
			else {
				*((*(m_grid.begin() + i)).begin() + n) = 0;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int n = 0; n < col; n++) {
			vector<int>::iterator a= ((*(m_grid.begin() + i)).begin() + n);
			if (*a == 0) {
				if (i != 0) {
					if (*((*(m_grid.begin() + i - 1)).begin() + n) == -1) {
						(*a)++;
					}
				}
				if (n != 0) {
					if (*((*(m_grid.begin() + i )).begin() + n-1) == -1) {
						(*a)++;
					}
				}
				if (n != 0&&i!= 0) {
					if (*((*(m_grid.begin() + i - 1)).begin() + n-1) == -1) {
						(*a)++;
					}
				}
				if (i!=row-1) {
					if (*((*(m_grid.begin() + i + 1)).begin() + n) == -1) {
						(*a)++;
					}
				}

				if (n != col-1) {
					if (*((*(m_grid.begin() + i)).begin() + n + 1) == -1) {
						(*a)++;
					}
				}

				if (n != col - 1&& i != row - 1) {
					if (*((*(m_grid.begin() + i+1)).begin() + n + 1) == -1) {
						(*a)++;
					}
				}

				if (n != 0 && i != row - 1) {
					if (*((*(m_grid.begin() + i + 1)).begin() + n - 1) == -1) {
						(*a)++;
					}
				}
				if (n != col - 1 && i != 0) {
					if (*((*(m_grid.begin() + i - 1)).begin() + n + 1) == -1) {
						(*a)++;
					}
				}
			}
		}
	}


}

bool SweepingBombs::Play(int x, int y) {
	m_status[y - 1][x - 1]=true;
	//*((*(m_status.begin() + y - 1)).begin() + x - 1) = true;
	//if (*((*(m_grid.begin() + y - 1)).begin() + x - 1)==-1) {
	//if (m_grid[y - 1][x - 1] ==-1) {
	//	cout << "youLose";
	//	return false;
	//}
	//else 
	if (m_grid[y - 1][x - 1]==0) {
		FullFillOpen(y - 1, x - 1);
	}
	return true;
}


void SweepingBombs::FullFillOpen(int y, int x) {
	stack<int> fx;
	stack<int> fy;
	fx.push(x);
	fy.push(y);
	//第一个
	while (!fx.empty()) {
		int tempX = fx.top();
		fx.pop();
		int tempY = fy.top();
		fy.pop();
		int tLeft = FullFillLeft(tempY, tempX);
		tLeft = tempX - tLeft;
		int tRight = FullFillRight(tempY, tempX);
		tRight = tempX + tRight;

		if((tempY - 1)!=-1)
		{
			SetNewSeed(fx, fy, tLeft, tRight, tempY - 1);
		}
		if ((tempY + 1) < row) {
			SetNewSeed(fx, fy, tLeft, tRight, tempY + 1);
		}
	}
	for (int i = 0; i < row; i++) {
		for (int n = 0; n < col; n++) {
			if (m_grid[i][n] == 0 && m_status[i][n]) {
				//揭露周围一圈
				if (i != 0) {
					m_status[i - 1][n] = true;
				}
				if (n != 0) {
					m_status[i][n - 1] = true;
				}
				if (n != 0 && i != 0) {
					m_status[i - 1][n - 1] = true;
				}
				if (i != row - 1) {
					m_status[i + 1][n] = true;
				}

				if (n != col - 1) {
					m_status[i][n + 1] = true;
				}

				if (n != col - 1 && i != row - 1) {
					m_status[i + 1][n + 1] = true;
				}

				if (n != 0 && i != row - 1) {
					m_status[i + 1][n - 1] = true;
				}
				if (n != col - 1 && i != 0) {
					m_status[i - 1][n + 1] = true;
				}
			}
		}
	}
}

void SweepingBombs::SetNewSeed(stack<int> &fx, stack<int> &fy, int tLeft, int tRight, int y) {
	 int nowX = tLeft;
	 //y--;
	bool findNewSeed = false;
	while (nowX < tRight) {
		//findNewSeed = false;
		if ((m_grid[y][nowX] == 0&&m_grid[y][nowX+1] != 0)) {//被分割或到底
			if (!m_status[y][nowX]) {
				fy.push(y);
				fx.push(nowX);
			}
		}
		else {

		}

		nowX++;
	}
	if ((m_grid[y][tRight] == 0)) {
		if (!m_status[y][tRight]) {
			fy.push(y);
			fx.push(tRight);
		}
	}
}
int SweepingBombs::FullFillLeft(int y, int x) {
	int count = 0;
	while (x > -1) {
		if (m_grid[y][x] != 0) {
			break;
		}
		m_status[y][x] = true;
		count++;
		x--;
	}
	return count-1;
}
int SweepingBombs::FullFillRight(int y, int x) {
	int count = 0;
	while (x < col) {
		if (m_grid[y][x] != 0) {
			break;
		}
		m_status[y][x] = true;
		count++;
		x++;
	}
	return count-1;

}


void SweepingBombs::Print() {
	int maxCount = col * row;
	for (int i = 0; i < row; i++) {
		for (int n = 0; n < col; n++) {
			cout << "\t";
			int temp = *((*(m_grid.begin() + i)).begin() + n);
			if (*((*(m_status.begin() + i)).begin() + n)) {
				if(temp!=-1)
				cout << temp;
				else {
					cout << "☆";
				}
			}
			else {
				cout << "■";
			}
		}
		cout << endl;
	}
	/*for (int i = 0; i < maxCount; i++) {
		int temp = *((*(m_grid.begin() + i / col)).begin() + i % col);
		if()
	}*/
}