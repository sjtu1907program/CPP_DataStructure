#include <iostream>
#include "DbLnkList.h"

#define LENGTHOF(x) (sizeof(x)/sizeof(x[0]))

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
void listTest() {
	int test[] = { 5,3,9,2,7,2,6};
	DbLinkList testList{ test, LENGTHOF(test) };
	cout << testList << endl;
	testList.erase(9);
	cout << testList << endl;
	testList.insert(testList.find(7),3);
	cout << testList << endl;
}


int main() {
	listTest();
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