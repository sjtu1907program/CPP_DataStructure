#pragma once
#include <vector>

class SweepingBombs {
public:
	static void play();
private:
	enum BlockStatus
	{
		boom = -1,
		nothing = 0
	};
	int Row() const { return m_grid.size(); }
	int Col() const { return m_grid[0].size(); }
	SweepingBombs(int row, int col);
	bool isValidPos(int row, int col) const;
	void putBombs();
	void calculateBlocks(int row, int col);
	void choose(int row, int col);
	void seedFill(int row, int col);
	void _print() const;
	void print() const;
	bool win() const;
	bool isOver;
	std::vector<std::vector<int> > m_grid;
	std::vector<std::vector<bool> > m_status;
};