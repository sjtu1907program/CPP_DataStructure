#include<iostream>;
#include "LinkList.h"
using namespace std;

int main()
{
	int v[] = { 1, 2, 3, 4, 3 };
	LinkList list(v, 5);
	cout << "原链表为：" << list << endl;
	list.erase(3);
	cout << "（删除3）链表长度为：" << list.size() << endl;
	cout << "（删除3）链表为：" << list << endl;
	list.insert(nullptr, 10);
	cout << "（插入10）" << endl;
	auto node = list.find(2);
	list.insert(node, 8);
	cout << "（插入8）链表为：" << list << endl;
}