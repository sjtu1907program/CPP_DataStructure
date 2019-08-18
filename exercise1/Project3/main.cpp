#include <iostream>
#include "SweepingBombs.h"
using namespace std;

int main()
{
	/*cout << __DATE__ << endl; 
	cout << __TIME__ << endl;
	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	cout << __FUNCTION__ << endl;
	*/
	int n{}, m{};
	scanf_s("%d %d", &n, &m);
	cout << endl;
	SweepingBombs* s = new SweepingBombs(n,m);
	return 0;
}