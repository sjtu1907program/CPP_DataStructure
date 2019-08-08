#include <iostream>
#include <limits>
#include <stack>

using namespace std;

stack<int> i2s(int i, int system);
int ReverseNumber(int num);

int main() {
	int cases[]{ 123, -123, 1234567899 };

	for (auto i : cases) {
		cout << i << " -> ";
		try {
			cout << ReverseNumber(i);
		}
		catch (exception e) {
			cout << e.what();
		}
		cout << endl;
	}

	return 0;
}

stack<int> i2s(int i, int system) {
	stack<int> result{};
	while (i != 0) {
		result.push(i % system);
		i /= system;
	}
	return result;
}

int ReverseNumber(int num) {
	const bool isNegative = num < 0 ? true : false;
	const int boarder = numeric_limits<int>().max();
	const int system = 10;

	if (isNegative) {
		num = -num;
	}

	stack<int> numS = i2s(num, system);
	stack<int> boarderS = i2s(boarder, system);

	if (numS.size() > boarderS.size())
		throw exception("ERROR: int overflow!");

	const bool isSafe = numS.size() < boarderS.size() ? true : false;

	int result = 0;
	int power = 1;
	while (!numS.empty()) {

		if (!isSafe) {
			// INT_MIN == -INT_MAX + 1
			if (numS.size() == 1 && isNegative) {
				if (numS.top() >= boarderS.top())
					throw exception("ERROR: int overflow!");
			}
			else {
				if (numS.top() > boarderS.top())
					throw exception("ERROR: int overflow!");
			}
		}

		result += numS.top() * power;
		power *= system;
		numS.pop();
		boarderS.pop();
	}

	if (isNegative)
		result = -result;

	return result;
}