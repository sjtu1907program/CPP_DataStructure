#include "TwoSumBestMatch.h"

void Cout(vector<int> data1, vector<int> data2, int input)
{
	cout << input << ":" << endl;
	TwoSum(data1, data2, input);
	cout << endl;
}


void TestTwoSum()
{
	vector<int> data1 = { 2000,5000,3000,1000,4000 };
	vector<int> data2 = { 4000,3000, 7000 };

	Cout(data1, data2, 9000);
	Cout(data1, data2, 7500);
	Cout(data1, data2, 2000);
	Cout(data1, data2,7000);
}


int main()
{	
	TestTwoSum();
	return 0;
}