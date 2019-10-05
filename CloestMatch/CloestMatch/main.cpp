#include "CloestMatch.h"
#include <iostream>
/*
	最接近距离匹配。
	(输入两个数组，每一组中选取一个数值，返回和小于等于目标且最接近目标的结果)
	eg:
	输入：
			[2000,5000,1000,3000]
			[3000,4000,7000]
		目标：5000	---》返回：[1000,4000] [2000,3000]
		目标：7000	---》返回：[3000,4000]

	步骤：
		1.排序：
			1 2 3 5
			3 4 7
		
*/
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))
void test();
int main() {
	test();
	system("pause");
}


void test() {
	int  data1[]{ 5,4,7,8,1,5,6,7 };	//排序后： 1 4 5 5 6 7 7 8
	int  data2[]{ 4,5,7,1,3,67 };       //排序后： 1 3 4 5 7 67
	
	CloestMatch<int> data_group(data1, LENGTH(data1), data2 , LENGTH(data2));
	std::vector<std::pair<int, int>> result = std::vector<std::pair<int, int>>();
	data_group.Match(9 ,result);
	for (int i = 0; i < result.size(); i++)
	{
		std::pair<int, int> p = result[i];
		cout << "[" << p.first << "," << p.second << "], ";
	}

	cout << endl;
}