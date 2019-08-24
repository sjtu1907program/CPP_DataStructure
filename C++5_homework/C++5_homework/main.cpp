#include<iostream>
#include<vector>
using namespace std;

vector<char> function(vector<char> str,int num = 1)
{
	int k = num;
	vector<char> result;
	for (int i = 0; i < num; i++)
		result.push_back(str[i]);
	if (str.size()%num != 0)
	{
		k++;
		result = function(str, k);
		return result;
	}
	for (int j = 0; j < num; j++)
	{
		for (int i = j; i < str.size(); i += num)
		{
			if (str[j] != str[i])
			{
				k++;
				result = function(str, k);
				return result;
			}
		}
	}
	return result;
}

int main()
{
	vector<char> result;
	vector<char> str1{ 'e','a','b','c' };
	vector<char> str2{ 'a','a','a','a' };
	vector<char> str3{ 'a','b','a','a','a','b','a','a' };
	vector<char> str4{ 'a','b','c','c','a','b','c','c' };
	vector<char> str5{ 'a','b','c','c','d' };
	vector<vector<char>> str{ str1,str2,str3,str4,str5 };
	for (int i = 0; i < str.size(); i++)
	{
		result = function(str[i]);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
		cout << endl;
	}
}