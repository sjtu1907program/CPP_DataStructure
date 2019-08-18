#pragma once
#include <vector>
using namespace std;
enum class Mode {
	EASY,
	NORMAL,
	HARD,
	CRAZY
};
class MineSweeper {

public:
	MineSweeper(int row = 8, int col =8, Mode mode = Mode::NORMAL);
	MineSweeper(int row, int col , int bombs);
	~MineSweeper(void);
	/*
		当踩到雷，爆炸
		当踩到没有雷的地方，以该位置为原点，进行发散式展开（一圈一圈向外扩散），直到扩散的圈有雷停止
	*/
	bool play(int x , int y);//踩位置
	
	void print();//打印地图
	void show();	//显示细节
	bool checkOver();	//检测函数
	//void funcTest();	//测试函数
private :
	const int SAFE_CELL = 0; //表示安全
	const int MINE_CELL = 9; //表示地雷
	vector<vector<int>> m_grid;
	vector<vector<bool>> m_status;
	int m_mines{0};			//炸弹计数
	int m_safeCells{0};			//炸弹计数
	int m_foundedSafeCounts{0};	//已找到的安全格数量
	
	int m_rows{0};
	int m_cols{0};
	bool m_gameover{false};

	void createMap(int row, int col);
	void shuffle();
	void knuth_shuffle();
	void envValConfig();
	void unfold(int x , int y);
	inline int round(int i, int j);
	int swapMine(int x, int y);
};