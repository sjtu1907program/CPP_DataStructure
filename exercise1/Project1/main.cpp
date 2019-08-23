#include<iostream>
#include<string>
using namespace std;

bool CheckPattern(string pat,string rest)//判断剩下的部分是否可以由pat循环组成
{
	if (pat == rest)return true;//递归终点
	else if (pat == rest.substr(0, pat.length()))//比较第一段是否一样
		return CheckPattern(pat, rest.substr(pat.length()));//递归比较剩下的一段是否由pat组成
	else return false;//第一段即不一样，返回false
}

string FindPattern(string str)
{
	for (int i = 1; i < str.length() / 2; i++)
	{
		if (str[i] == str[0])
		{
			if (CheckPattern(str.substr(0, i), str.substr(i)))
				return str.substr(0, i);
		}
	}
	return str;
}

int main()
{
	string a;
	cin >> a;
	cout << FindPattern(a);

	system("pause");
	return 0;
}