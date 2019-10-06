#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

bool raiseSort(const int &p1, const int &p2)
{
	return p1 < p2;
}
bool downSort(const int &p1, const int &p2)
{
	return p1 > p2; 
}

list<pair<int,int>> MaxPairsSmallerThanX(vector<int> data1,vector<int> data2,int target) {
	list<pair<int, int>> result{ NULL };
	if (data1.size() == 0 || data2.size() == 0) {
		return result;
	}
	sort(data1.begin(), data1.end(), raiseSort);//升序
	sort(data2.begin(), data2.end(), downSort);//降序
	if (data1[0]+data2[data2.size()-1]>target) {//最小的相加
		return result;
	}
	
	for (int i = 0, j = 0; i != data1.size()-1 || j != data2.size()-1;) {
		int tempResult = data1[i] + data2[j];
		if (tempResult <= target) {
			if (result.size() == 0) {//第一次没有结果的时候
				result.push_back(pair<int, int>(data1[i], data2[j]));
			}
			else {
				int oldResult = result.begin()->first + result.begin()->second;
				if (tempResult == oldResult) {//这次结果和上次一样
					result.push_back( pair<int, int>(data1[i], data2[j]));
				}
				else {
					if (tempResult > oldResult) {
						result.clear();
						result.push_back( pair<int, int>(data1[i], data2[j]));
					}
				}
			}
			if(i!=data1.size()-1)
			i++;//数字小了 第一个升序数组+1;
			else {
				j++;
			}
		}
		else {
			if(j!=data2.size()-1)
			j++;//数字大了 第二个降序数组+1；
			else {
				i++;
			}
		}
	}
	return result;
}
int main() {
	list<pair<int, int>> results{NULL};
	vector<int> a{ 1000,2000,7000,3000 ,6000,};
    vector<int> b{ 3000,4000,2000,5000 };
	int target = 8000;
	
	
	results = MaxPairsSmallerThanX(a, b,target);
	if (results.size()!=0) {
		for (auto i = results.begin(); i !=results.end(); i++) {
			cout << i->first<<i->second << endl;
		}
	}
	else {
		cout << "no result" << endl;
	}
}