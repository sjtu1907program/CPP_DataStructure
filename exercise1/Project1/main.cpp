#include<iostream>
using namespace std;

int ReverseInt(int x);
//我觉得用longlong好像有点暴力作弊的感觉
//但如果纯用int来判断是否超过INT_MAX的话要写的步骤好像有点太夸张了，我放弃
int main()
{
	cout << ReverseInt(2)<<endl;
	cout << ReverseInt(1234)<<endl;
	cout << ReverseInt(1563847412) << endl;//一个正序小于INT_MAX而逆序略微大于INT_MAX的数
	cout << ReverseInt(1463847412) << endl;//一个正序小于INT_MAX而逆序略微小于INT_MAX的数
	system("PAUSE");
	return 0;
}

int ReverseInt(int x)
{
	long long ll_x = (long long)x;
	long long ll_revx = 0;
	while(ll_x!=0)
	{
		ll_revx = ll_revx * 10 + ll_x % 10;
		ll_x /= 10;
	}
	if (ll_revx > INT_MAX) {
		cout << "error!";
		return 0;
	}
	else
		return (int)ll_revx;


}