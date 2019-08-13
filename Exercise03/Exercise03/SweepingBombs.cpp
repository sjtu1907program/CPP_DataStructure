#include "SweepingBombs.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void SweepingBombs::play()
{
	cout << "Welcome to sweeping bombs!" << endl;
	while (true) {
		cout << "New Game" << endl;
		cout << "Please enter Row and Col: ";
		int r, c;
		cin >> r >> c;
		string s;
		std::getline(cin, s);
		SweepingBombs sb(r, c);
		sb.print();
		while (!sb.isOver) {
			cout << "Choose Row and Col: ";
			cin >> r >> c;
			std::getline(cin, s);
			sb.choose(r, c);
		}
	}
}

SweepingBombs::SweepingBombs(int row, int col)
{
	isOver = false;
	m_grid = vector<vector<int> >(row, vector<int>(col, 0));
	m_status = vector<vector<bool> >(row, vector<bool>(col, false));
	putBombs();
}

void SweepingBombs::choose(int row, int col)
{
	if (isValidPos(row, col)
		&& m_status[row][col] != true) {
		if (m_grid[row][col] == boom) {
			m_status = vector<vector<bool> >(Row(), vector<bool>(Col(), true));
			isOver = true;
		}
		else if (m_grid[row][col] == nothing) {
			seedFill(row, col);
		}
		else {
			m_status[row][col] = true;
		}
		print();

		if (isOver) {
			cout << "Game Over" << endl;
		}

		else if (win()) {
			isOver = true;
			cout << "You Win" << endl;
		}
	}
}

bool SweepingBombs::isValidPos(int row, int col) const
{
	return row >= 0 && row < Row()
		&& col >= 0 && col < Col();
}

void SweepingBombs::putBombs()
{
	const double ratio = 0.2;
	assert(ratio > 0 && ratio < 1);
	int blocks = Col() * Row();
	int num = ratio * blocks;
	while (num > 0) {
		int pos = rand() % blocks;
		int roww = pos / Col();
		int coll = pos % Col();
		if (m_grid[roww][coll] != boom) {
			m_grid[roww][coll] = boom;
			calculateBlocks(roww, coll);
			num--;
		}
	}
}

void SweepingBombs::calculateBlocks(int row, int col)
{
	const int rows[]{ -1, -1, -1, 0, 0, 1, 1, 1 };
	const int cols[]{ -1, 0, 1, -1, 1, -1, 0, 1 };
	for (int i = 0; i < 8; i++) {
		int r = rows[i] + row;
		int c = cols[i] + col;
		if (isValidPos(r, c)
			&& m_grid[r][c] != boom) {
			m_grid[r][c]++;
		}
	}
}

void SweepingBombs::_print() const
{
	for (int i = 0; i < Row(); i++) {
		for (int j = 0; j < Col(); j++) {
			if (m_grid[i][j] == boom) {
				cout << '*';
			}
			else if (m_grid[i][j] == nothing) {
				cout << ' ';
			}
			else {
				cout << m_grid[i][j];
			}

			if (j + 1 == Col()) {
				cout << endl;
			}
			else {
				cout << ' ';
			}
		}
	}
}

void SweepingBombs::print() const
{
	for (int i = 0; i < Row(); i++) {
		for (int j = 0; j < Col(); j++) {
			if (m_status[i][j]) {
				if (m_grid[i][j] == boom) {
					cout << '*';
				}
				else if (m_grid[i][j] == nothing) {
					cout << ' ';
				}
				else {
					cout << m_grid[i][j];
				}
			}
			else {
				cout << '#';
			}

			if (j + 1 == Col()) {
				cout << endl;
			}
			else {
				cout << ' ';
			}
		}
	}
}

bool SweepingBombs::win() const
{
	for (int i = 0; i < Row(); i++) {
		for (int j = 0; j < Col(); j++) {
			if (!m_status[i][j] && m_grid[i][j] != boom) {
				return false;
			}
		}
	}
	return true;
}

void SweepingBombs::seedFill(int row, int col)
{
	const int rows[]{ -1, 0, 0, 1 };
	const int cols[]{ 0, -1, 1, 0 };
	stack<int*> todo;
	todo.push(new int[2]{ row, col });
	m_status[row][col] = true;
	while (!todo.empty()) {
		int* now = todo.top();
		todo.pop();
		if (m_grid[now[0]][now[1]] == nothing) {
			for (int i = 0; i < 4; i++) {
				int r = rows[i] + now[0];
				int c = cols[i] + now[1];
				if (isValidPos(r, c)
					&& !m_status[r][c]) {
					todo.push(new int[2]{ r, c });
					m_status[r][c] = true;
				}
			}
		}
		delete[] now;
	}
}
