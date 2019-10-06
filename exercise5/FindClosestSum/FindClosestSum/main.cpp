#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

list<pair<int, int>> FindClosestSum(vector<int> A, vector<int> B, int sum);
int BinarySearch(vector<int> array, int length, int key);

list<pair<int, int>> FindClosestSum(vector<int> A, vector<int> B, int sum)
{
	list<pair<int, int>> result{ NULL };
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int tempSum = 0;
	for (int i = 0; i < A.size(); i++)
	{
		int delta = sum - A[i];
		int bValue = BinarySearch(B, B.size(), delta);
		if (bValue != -1)
		{
			if (A[i] + bValue > tempSum)
			{
				tempSum = A[i] + bValue;
				result.clear();
				result.push_back(pair<int,int>(A[i], bValue));
			}
			else if (A[i] + bValue == tempSum)
			{
				result.push_back(pair<int,int>(A[i], bValue));
			}
		}
	}
	return result;
}

int BinarySearch(vector<int> array, int length, int key)
{
	int low = 0;
	int high = length - 1;
	int mid = 0;
	int result = -1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (array[mid] == key) 
		{
			return array[mid];
		}
		else if (array[mid] < key)
		{
			if (array[mid] > result)
			{
				result = array[mid];
			}
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return result;
}

int main()
{
	vector<int> A{ 2000, 5000, 3000, 1000 };
	vector<int> B{ 3000, 4000, 7000 };

	//list<pair<int, int>> result = FindClosestSum(A, B, 5000);
	list<pair<int, int>> result = FindClosestSum(A, B, 7500);
	if (result.size() != 0)
	{
		for (auto i = result.begin(); i != result.end(); i++)
		{
			cout << i->first << "," << i->second << endl;
		}
	}
	else
	{
		cout << "no result" << endl;
	}

	return 0;
}