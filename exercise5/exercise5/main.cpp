#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>
#include<math.h>
//#include<>
using namespace std;
void quickSort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x)
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] < x)
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1);
		quickSort(s, i + 1, r);
	}
}


 vector<pair<int, int>>  CountNumber(int a[],int aNum,int b[],int bNum,int target,int&resultFlag) {
	 vector<pair<int, int>> result(aNum > bNum ? aNum : bNum);
	 int flagA = 0;
	 int flagB = bNum - 1;
	 int minValue = abs(target - a[flagA] - b[flagB]);
	 resultFlag=0;

	 while (flagA != aNum && flagB != -1) {
		 int temp= abs(target - a[flagA] - b[flagB]);
		 
		 if (temp == minValue) {
			 result[resultFlag].first = a[flagA];
			 result[resultFlag].second = b[flagB];
			 resultFlag++;
			 //ÈÓ½øpair
		 }
		 else if(temp<minValue) {
			 minValue = temp;
			 resultFlag = 0;
			 result[resultFlag].first = a[flagA];
			 result[resultFlag].second = b[flagB];
			 resultFlag++;
		 }

		 if (a[flagA] + b[flagB]<target) {
			 flagA++;
		 }
		 else {
			 flagB--;
		 }
	 }


	 return result;
}


int main() {
	int a[]{ 3000,1000,5000,2000,1000,1200,2200,4200,7000,9000 };
	int b[]{ 1000,2000,3000,6000 };
	int target = 5600;
	int n = 10;

	int aCount = sizeof(a) / sizeof(int);
	int bCount = sizeof(b) / sizeof(int);
	quickSort(a, 0, (aCount -1));
	quickSort(b, 0, (bCount -1));

	for (int i = 0; i < aCount; i++) {
		cout << a[i];
	}
	int flag;
	vector<pair<int, int>> result = CountNumber(a, aCount,b,bCount,target, flag);
	cout << result.size()<<"  "<<flag<<endl;
	for (int i = 0; i < flag; i++) {
		cout << result[i].first << "  " << result[i].second << endl;
	}

	return 0;
}