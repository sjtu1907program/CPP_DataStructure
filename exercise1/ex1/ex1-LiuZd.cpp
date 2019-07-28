#include <iostream>
#include <limits>
using namespace std;
int ReverseNumber(int x) {
	int res{ 0 };
	if (x == numeric_limits<int>::min()) {
		res = numeric_limits<int>::max(); return res;
	}
	bool flag = (x > 0 ? 1 : 0);
	if (!flag) x = -x;
	while (x>0)
	{
		if (res > numeric_limits<int>::max() / 10) {
			res = numeric_limits<int>::max(); return res;
		}
		res *= 10;
		if (numeric_limits<int>::max() - res < x % 10) {
			res = numeric_limits<int>::max(); return res;
		}
		res += x % 10;
		x /= 10;
	}
	if (!flag) res = -res;
	return res;
}
void test(int x) {
	int result = ReverseNumber(x);
	if (result == numeric_limits<int>::max()) {
		cout << "Can Not Reverse " << x << " OverFlow Error" << endl;
	}
	else
	{
		cout << x << "--->" << result << endl;
	}
}
int main() {
	test(123);
	test(-1234);
	test(1234567899);
	test(2147483647);
	test(2147483642);
	test(2147483611);
	test(-2147483647);
	test(0);
	test(numeric_limits<int>::min());
	return 0;
}