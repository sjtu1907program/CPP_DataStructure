#include<iostream>
using namespace std;

// 123 -> 321
// -123 -> -321
// 1234567899 -> output error
int ReverseNumber(int n)
{
	long long result = 0;
	bool flag = false;
	if (n < 0)
	{
		n = -n;
		flag = true;
	}
	while (n > 0)
	{
		result = result * 10 + n % 10;
		n = n / 10;
	}
	result = flag ? -result : result;
	result = result > numeric_limits<int>::max() ? numeric_limits<int>::max() : result;
	return result;
}

void test(int n)
{
	auto result = ReverseNumber(n);
	if (result == numeric_limits<int>::max())
	{
		cout << "Cannot reverse " << n << "   overflow error" << endl;
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