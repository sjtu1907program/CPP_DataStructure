#pragma once
#include<iostream>
#include<vector>
using namespace std;

class minesPlace
{
private:
	int num;
	int mines_num;
	vector<vector<int>> array;
	vector<vector<bool>> _array;
public:
	minesPlace(int n, int m);
	void input();
private:
	void buryMines();
	void showAll();
	void zero(int p, int q);
	bool judge();
};