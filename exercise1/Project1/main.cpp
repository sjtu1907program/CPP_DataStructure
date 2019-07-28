#include <iostream>

using namespace std;

int ReverseNum(int num);

void test(int num) {
	auto result = ReverseNum(num);
	if (result == std::numeric_limits<int>::max()) {
		cout << "Cannot reverse  " << num << ",   overflow error!" << endl;
	}
	else {
		cout << num << " -> " << result << endl;
	}
}

int main() {
	test(123);
	test(-1234);
	test(123456789);
	test(-123456789);
	test(1234567899);
	test(-1234567899);
	system("pause");
}

int ReverseNum(int num) {

	long long  result = 0;
	int min = std::numeric_limits<int>::min();
	int max = std::numeric_limits<int>::max();
	while (num != 0) {
		try {
			result *= 10;
			result += num % 10;
			if (result > max || result < min)
				throw overflow_error("throw a overflow_error exception\n");
			num /= 10;
		}
		catch (overflow_error e) {
			//cout << "overflow!!" << endl;
			return std::numeric_limits<int>::max();
		}
	}
	return result;
}