#include"SweepingBombs.h"

int main() {
	cout << "请输入行 列 炸弹数" << endl;
	int row=0, col, bombs;
	cin >> row >> col >> bombs;
	SweepingBombs gameTest=SweepingBombs(row, col, bombs);
	cout << "请输入点击的坐标  输入-1 -1退出  或者踩到雷 自动结束" << endl;
	cin >> row >> col;//就是x y坐标 不声明新变量了；
	while (row != -1&&gameTest.getStatus()) {
		gameTest.Play(row, col);
	
			cout << "请输入点击的坐标  输入-1 -1退出  或者踩到雷 自动结束" << endl;
			cin >> row >> col;//就是x y坐标 不声明新变量了；
		
	}

	
}