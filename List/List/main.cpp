#include <iostream>
#include "DbLnkList.h"

#define LENGTHOF(x) (sizeof(x)/sizeof(x[0]))

using namespace std;
using namespace myClassLibrary;
void listTest() {
	myClassLibrary::DbLinkList testList{ {1,3,5,6,3} };
	myClassLibrary::DbLinkList another{ testList };
	myClassLibrary::DbLinkList another2;
	cout <<"testList:" << testList << endl;
	cout <<"another2:" << another2 << endl;
	testList.erase(5);
	cout <<"testList:" << testList << endl;
	testList.insert(testList.find(3),3);
	cout << "testList:"<< testList << endl;
	cout << "another:" << another << endl;
	cout << "another2:" << another2 << endl;
	another2 = testList;
	cout << "½«testList¸³¸øanother2ºó:"<<another2 << endl;
}

DbLinkList moveTest() {
	DbLinkList testList{ {1,3,5,6,3} };
	return testList;
}


int main() {
	DbLinkList listTest = moveTest();
	cout << "listTest:" << listTest << endl;
	//listTest();
	system("pause");
}
