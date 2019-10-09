//给两个数组：
//{ 2000，5000，3000，1000 }，
//{ 3000， 4000， 7000 }
//输入目标数，如5000，则返回：
//{ 2000 ，3000 }，{ 1000，4000 }
////两组中恰好有和等于输入，则只返回所有和恰好等于的组合
//如7500则返回：
//{ 3000，4000 }
////返回所有最大接近组合
//如9000则返回：
//{ 1000， 7000 }
//如2000则可返回异常；
//
//P.S.  :两重for循环之类没有效率的算法算错，期望算法复杂度小于等于O(nlogn)

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class TwoSum {
public :
	TwoSum(vector<int>& data1, vector<int>& data2, int sum)
	{
		 sort(data1.begin(), data1.end());   //O(N log N)
		 sort(data2.begin(), data2.end());
		 
		 if (data1[0] + data2[0] > sum)
		 {
			 cout << "Target is too small! "<<endl;
			 return;
		 }

		 for (int i{}; i < data1.size(); i++)
		 {
			 int target = sum - data1[i];
			 if (binary_search(data2.begin(),data2.end(), target))
			 {
				 cout << "{" << data1[i] << "," << target << "}" << endl;
				 count++;
				 continue;
			 }
		 }
		 
		 if (count == 0)
		 {
			 int min_difference{INT32_MAX};
			 int d1value{};
			 int d2value{};
			 for (int i{}; i < data1.size(); i++)
			 {
				 int target = abs(sum - data1[i] - data2[
					 ++lower_bound(data2.begin(), data2.end(), target)  - data2.begin()]);
				 if (target < min_difference)
				 {
					 min_difference = target;
					 d1value = data1[i];
					 d2value = data2[++lower_bound(data2.begin(), data2.end(), target)  - data2.begin()];
				 }
			 }
			 cout << "{" << d1value << "," << d2value << "}" << endl;
		 }
	}
private:
	int count{};
};