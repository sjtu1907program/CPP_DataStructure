#include <iostream>
#include <string>
using namespace std;

string PatternMatch(string s)
{
	int n = s.size();
	for (int i = 1; i < n/2 + 1; i++)
	{
		if (n % i == 0)
		{
			int c = n / i;
			string t{};			
			string res = s.substr(0, i);
			for (int j = 0; j < c; j++)
			{
				t += res;	
			}
			if (t == s)
			{
				return res;
			}
		}
	}
	return s;
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

int main()
{
	Test();
	return 0;
}