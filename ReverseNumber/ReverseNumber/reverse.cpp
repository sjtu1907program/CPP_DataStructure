#include<iostream>
using namespace std;

int ReverseNumer(int n)
{
	int m, revn = 0;
	int k = n;
	//求回文
	while (k)
	{
		m = k % 10;
		revn = revn * 10 + m;
		k /= 10;
	}
	int result = revn;
	//检查是否溢出
	while (revn)
	{
		m = revn % 10;
		k = k * 10 + m;
		revn /= 10;
	}
	if (k == n)
		return result;
	else
		return std::numeric_limits<int>::max();
}

void test(int n)
{
	auto result = ReverseNumer(n);
	if (result == std::numeric_limits<int>::max())
	{
		cout << "Cannot reverse " << n << " overflow error " << endl;
	}
	else
	{
		cout << n << " -> " << result << endl;
	}
}

int main()
{
	test(123);
	test(-1234);
	test(1234567899);
	return 0;
}