#include<iostream>
#include"Linklist.h"

using namespace std;

void TestLinkList()
{
	int v[] = { 1, 2, 3, 4, 3 };
	LinkList lst(v, 5);
	cout << lst << endl;
	lst.erase(3);
	cout << lst.size() << endl;
	cout << lst << endl;
	lst.insert(nullptr, 10);
	auto node = lst.find(2);
	lst.insert(node, 8);
	cout << lst << endl;
}

int main()
{
	TestLinkList();
	return 0;
}