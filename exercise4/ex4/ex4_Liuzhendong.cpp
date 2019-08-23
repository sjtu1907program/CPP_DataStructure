#include <iostream>
#include <string>
#include <vector>
using namespace std;
void getNext(string &str, int m, vector<int> &next) {
	next[1] = 0;
	int k = 0;
	for (int i = 2; i <= m; i++) {
		while (k > 0 && str[k] != str[i - 1])
			k = next[k];
		if (str[k] == str[i - 1])
			k++;
		next[i] = k;
	}
	return;
}
string PatternMatch(string s)
{
	if (s.empty()) {
		return "";
	}
	int len = s.length();
	vector<int> next(len + 1, 0);
	getNext(s, len, next);
	return s.substr(0, len - next[len]);
}
void Test()
{	//case senstive
	string s1 = "eabceabc";//s1
	string s2 = "aaaa";//a
	string s3 = "abaaaabaaa";//abaaa
	string s4 = "abccd";//abccd
	cout << PatternMatch(s1) << endl;
	cout << PatternMatch(s2) << endl;
	cout << PatternMatch(s3) << endl;
	cout << PatternMatch(s4) << endl;
}
int main() {
	Test();
	return 0;
}