#include <iostream>
#include "DbLnkList.h"

#define LENGTHOF(x) (sizeof(x)/sizeof(x[0]))

using namespace std;

void listTest() {
	int test[] = { 5,3,9,2,7,2,6};
	DbLinkList testList{ test, LENGTHOF(test) };
	cout << testList << endl;
	testList.erase(9);
	cout << testList << endl;
	testList.insert(testList.find(7),3);
	cout << testList << endl;
}

int main() {
	listTest();
	system("pause");
}
