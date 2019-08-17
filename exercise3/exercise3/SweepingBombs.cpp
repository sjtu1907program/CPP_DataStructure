#include "SweepingBombs.h"
SweepingBombs::SweepingBombs(int row,int col,int bombs)//数组初始化 调用产生雷的方法
{
	gameStatus = true;
	m_grid.resize(row, vector<int>(col, 0));
	m_status.resize(row, vector<bool>(col, false));
	SetBombs(row, col, bombs);
	
}

void SweepingBombs::SetBombs(int row,int col,int bombs) {
	int tempNumber = RandomNumber();
	for (int i = 0; i < bombs; i++) {
		if (m_grid[tempNumber /col][tempNumber%col] != -1) {
			m_grid[tempNumber /col][tempNumber%col] =-1;//炸弹为-1
			for (int j = tempNumber / col - 1; j != tempNumber / col+2; j++) {
				for (int k = tempNumber % col - 1; k != tempNumber % col + 2; k++) {
					if (j < 0 || j>=row || k<0 || k>=col|| m_grid[j][k] == -1) {//越界或者当前为炸弹
						continue;
					}
					else {
						m_grid[j][k] += 1;
					}
				}
			}
		}
		else {
			i--;
			tempNumber = RandomNumber();
		}
	}
};
void SweepingBombs::Show_Status() {
	for (int i = 0; i < m_grid.size(); i++) {
		for (int j = 0; j < m_grid[i].size(); j++) {
			if (m_status[i][j]) {
				if (m_grid[i][j] == -1) {//已经被点开的炸弹
					cout << "* ";
				}
				else {
					cout << m_grid[i][j] << " ";//
				}
			}
			else {
				cout << "? ";
			}
		}
		cout << " " << endl;
	}
}
void SweepingBombs::ScanLineSeedFill(int x, int y) {
	int pRight, pLeft;//左右边界
	stack<Point> stk;
	stk.push(Point{ x,y });
	while (!stk.empty()) {
		Point p = stk.top();
		stk.pop();
		pLeft = FindLeft(p.x, p.y);
		pRight = FindRight(p.x, p.y);
		if (p.x >= 1) {//是否为边界
			SearchLineNewSeed(stk, pLeft, pRight, p.x - 1);
		}
		if (p.x < (m_grid.size()-1)) {//是否为边界
			SearchLineNewSeed(stk, pLeft, pRight, p.x + 1);
		}
		
	}
};
int  SweepingBombs::FindLeft(int x, int y) {//进来的一定==0 返回的是0的边界 最后一个0的位置 但是要把旁边的1 status 置真 当前点已经为真
	y--;
	while (y != -1 && m_grid[x][y] == 0&&!m_status[x][y]) {//点不为0或者 越界
		m_status[x][y] = true;//如果是连通的0 或者0旁边第一个不为0的 都可见
		y--;
	
	}
	if (y != -1) {
		m_status[x][y] = true;//0旁边的数字;
	}
	return( (y==-1)?y+1:y);//越界了就返回边界 否则返回自己
};
int SweepingBombs::FindRight(int x, int y) {
	y++;
	while (y != m_status[0].size()&&m_grid[x][y] == 0&&!m_status[x][y] ) {//防止越界 以及确保当前点为0 当出来不为0
		m_status[x][y] = true;
		y++;
	}
	if (y != m_status[0].size()) {
		m_status[x][y] = true;
	}
	return( (y==m_status[0].size())?y-1:y);//
};
void SweepingBombs::SearchLineNewSeed(stack<Point>& stk, int yLeft, int yRight,int row) {  //扫描线 扫描上下两条 把每个区间的最右入栈
	int yL = yLeft + 1;
	if (row >= 1) {//往上看 上面是否为0 当前是否为1  是1就打开本身 
		for (int L = yLeft, R = yRight; L <= R; L++) {
			if (m_grid[row - 1][L] == 0&&m_status[row-1][L]) {
				if (m_grid[row][L] != 0) {
					m_status[row][L] = true;
				}
			}
		}
	}
	if (row < m_grid.size()-1) {
		for (int L = yLeft, R = yRight; L <= R; L++) {
			if ( m_grid[row +1][L] == 0 && m_status[row +1][L]) {
				if ( m_grid[row][L] != 0) {
					m_status[row][L] = true;
				}
			}
		}

	}//往下看 下面是否为0 如果是就打开本身  上下都判断是为了不遗漏情况？ 和普通的扫描线不同
	for ( int yR = yRight + 1; yL < yR; yL++) {//在区间内 找到0 X的情况 把X 入栈
		if (m_grid[row][yL] != 0) {
			if (m_grid[row][yL - 1] == 0&&!m_status[row][yL - 1]) {
				m_status[row][yL - 1] = true;
				stk.push(Point{ row,yL - 1 });//置入栈之前把自己置为真
			}
		}
	}
	if (m_grid[row][yL - 1] == 0&&!m_status[row][yL - 1]) {//区间边界 区间右
		m_status[row][yL - 1] = true;
		stk.push(Point{ row,yL - 1 });
	}
};
void SweepingBombs::Play(int x, int y) {//输入坐标
	//输入不合法
	if (x<0 || x>=m_status.size() || y<0 || y>=m_status[0].size()) {
		cout << "WrongNumber";
	}
	if (m_status[x][y]) {//如果已经被点开过了
		cout << "You have opened it" << endl;
	}
	m_status[x][y] = true;
	if (m_grid[x][y] == -1) {//如果 是炸弹
		gameStatus = false;
		cout << "GameOver" << endl;
	}
	else if (m_grid[x][y] >= 1) {//如果是1以及以上
	}
	else {//点开的是0
		ScanLineSeedFill(x, y);
	}
	Show_Status();
};




