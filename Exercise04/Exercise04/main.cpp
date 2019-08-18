#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

string templateString(string input);
string templateString(string input, string test);
void test(string input, string result);

int main() {
	test("abc", "abc");
	test("aaaa", "a");
	test("abaaaabaaa", "abaaa");
	test("abccabcc", "abcc");
	test("abccd", "abccd");
	return 0;
}

string templateString(string input)
{
	if (input == "")
		return "";
	return templateString(input, input.substr(0, 1));
}

string templateString(string input, string test)
{
	if (test.size() == input.size())
		return input;

	if (input.size() % test.size() != 0
		|| input[test.size()] != test[0])
		return templateString(input, test + input[test.size()]);

	for (int i = 1; i < input.size(); i++) {
		if (input[i] != test[i % test.size()])
			return templateString(input, test + input[test.size()]);
	}

	return test;
}

void test(string input, string expected)
{
	cout << "input:" << input << endl;
	string result = templateString(input);
	cout << "result:" << result << endl;
	cout << "expected:" << expected << endl << endl;
	assert(result == expected);
}
