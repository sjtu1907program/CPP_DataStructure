#include "LinkList.h"

void TestLinkList();

int main() {
	TestLinkList();
	return 0;
}

void TestLinkList()
{
	int v[] = { 1, 2, 3, 4, 3 };
	LinkList lst(v, 4);
	// 1 -> 2 -> 3 -> 4 -> 3 
	cout << lst;
	lst.remove(3);
	cout << lst.length() << endl;
	cout << lst;
	lst.insert(nullptr, 10);
	auto node = lst.find(2);
	lst.insert(node, 8);
	cout << lst;
}