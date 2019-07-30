#include<iostream>
using namespace std;


int ReverseNumber(int number) {
	
	int result = 0;
	int flag=1;
	int testInt = std::numeric_limits<int>::max() / 10;
	if (number < 0)
		flag = -1;
		while (number != 0) {
			if (result > testInt || result == testInt && (number > 7 || number < -8))
				return std::numeric_limits<int>::max();
			result = result * 10 + number % 10;
			number /= 10;
		}
	return result*flag;
}

void test(int n) {
	auto result = ReverseNumber(n);
	if (result == std::numeric_limits<int>::max()) {
		cout << "Cannot reverse" << n << "overflow error" << endl;
	}
	else {
		cout << n << "->" << result << endl;
	}


}

int main() {
	cout << std::numeric_limits<int>::max() << endl;
	cout << "Hello World" << endl;
	test(123);
	test(-1234);
	test(1234567899);
	return 0;
}