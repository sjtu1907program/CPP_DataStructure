#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

string templateString(const string& input);
string templateString(const string& input, int length);
int findNext(const string& input, int length);

void test(const string& input, const string& result);

int main() {
	test("abc", "abc");
	test("aaaa", "a");
	test("abaaaabaaa", "abaaa");
	test("abccabcc", "abcc");
	test("abccd", "abccd");
	return 0;
}

string templateString(const string& input)
{
	if (input == "")
		return "";
	return templateString(input, findNext(input, 1));
}

string templateString(const string& input, int length)
{
	const int size = input.size();

	if (length == size)
		return input;

	for (int i = length + 1; i < size; i++) {
		if (input[i] != input[i % length])
			return templateString(input, findNext(input, length + 1));
	}

	return input.substr(0, length);
}

int findNext(const string& input, int length) {
	const char first = input[0];
	const int size = input.size();

	while (length < input.length()) {
		if (size % length == 0
			&& input[length] == first) {
			break;
		}
		length++;
	}
	return length;
}

void test(const string& input, const string& expected)
{
	cout << "input:" << input << endl;
	string result = templateString(input);
	cout << "result:" << result << endl;
	cout << "expected:" << expected << endl << endl;
	assert(result == expected);
}
