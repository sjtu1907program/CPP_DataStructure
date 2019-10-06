#include<iostream>
#include<vector>
using namespace std;

void Sort(vector<int> & arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j-1])
				swap(arr[j], arr[j-1]);
			else
				break;
		}
	}
}

void MaxSum(int target)
{
	int sum = 0;
	int aa, bb;
	aa = bb = 0;
	vector<int> a, b;
	vector<int> arr1 = { 2000,5000,3000,1000 };
	vector<int> arr2 = { 3000,4000,7000 };
	Sort(arr1);
	Sort(arr2);
	if (target >= *(arr1.end() - 1) + *(arr2.end() - 1))
	{
		aa = *(arr1.end() - 1);
		bb = *(arr2.end() - 1);
		goto end;
	}
	if (target < *arr1.begin() + *arr2.begin())
	{
		goto end;
	}
	for (vector<int>::iterator iter = arr2.begin(); iter != arr2.end() && *iter < target; iter++)
	{
		int mid;
		int low = 0;
		int high = arr1.size() - 1;
		while(low <= high)
		{
			mid = (low + high) / 2;
			if (arr1[mid] == target - *iter)
			{
				a.push_back(arr1[mid]);
				b.push_back(*iter);
				sum = arr1[mid] + *iter;
				break;
			}
			if (low == high)
			{
				if (arr1[mid] < target - *iter && arr1[mid] + *iter > sum)
				{
					aa = arr1[mid];
					bb = *iter;
					sum = arr1[mid] + *iter;
				}
				break;
			}
			if (arr1[mid] < target - *iter && arr1[mid + 1] > target - *iter && arr1[mid] + *iter > sum)
			{
				aa = arr1[mid];
				bb = *iter;
				sum = arr1[mid] + *iter;
			}
			else
			{
				if (arr1[mid + 1] <= target - *iter)
					low = mid + 1;
				else
					high = mid - 1;
			}

		}
	}
	end:
	if (a.size() == 0 && aa == 0)
		cout << "error";
	else
	{
		if (sum == target)
		{
			for (int i = 0; i < a.size(); i++)
			{
				cout << "{" << a[i] << "," << b[i] << "}" << endl;
			}
		}
		else
			cout << "{" << aa << "," << bb << "}" << endl;
	}
}

int main()
{
	int target;
	cout << "ÇëÊäÈë£º";
	cin >> target;
	MaxSum(target);
}
