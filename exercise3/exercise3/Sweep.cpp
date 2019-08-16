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
		density = 0.3f;
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
			int check = rand() % (maxCount - i*col-n) + 1;//1~µ±Ç°Öµ¡£
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
	*((*(m_status.begin() + y - 1)).begin() + x - 1) = true;
	if (*((*(m_grid.begin() + y - 1)).begin() + x - 1)==-1) {
		cout << "youLose";
		return false;
	}
	return true;
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
					cout << "¡î";
				}
			}
			else {
				cout << "¡ö";
			}
		}
		cout << endl;
	}
	/*for (int i = 0; i < maxCount; i++) {
		int temp = *((*(m_grid.begin() + i / col)).begin() + i % col);
		if()
	}*/
}