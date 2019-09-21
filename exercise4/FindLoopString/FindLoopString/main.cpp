#include <iostream>
#include <string>
using namespace std;

string FindLoopString(string test);
bool FindLoopString(string test, int loopLength);

string FindLoopString(string test)
{
	string result{};
	int origLength = test.length();	//当前字符串长度
	int i = 1;
	while (i <= (origLength / 2))
	{
		if (test[0] == test[i])		//寻找与第一个相同的字符
		{
			int loopLength = i;		//循环字符数长度
			if (origLength%loopLength != 0)		//如果不是整数倍必不正确
			{
				break;
			}
			result = test.substr(0, i);
			if (FindLoopString(test, loopLength))
			{
				return result;
			}
		}
		i++;
	}
	return test;
}

bool FindLoopString(string test, int loopLength)	//判断后续字符串是否相同
{
	if (test.length() == loopLength)
	{
		return true;
	}
	if (test.substr(0, loopLength) == test.substr(loopLength, loopLength))
	{
		if (!FindLoopString(test.substr(loopLength), loopLength))
			return false;
	}
	else
	{
		return false;
	}
}

int main()
{
	while (true)
	{
		string test{};
		cin >> test;
		string result = FindLoopString(test);
		cout << test << " --> " << result << endl;
	}
	return 0;
}