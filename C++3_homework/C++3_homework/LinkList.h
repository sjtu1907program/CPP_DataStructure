#pragma once
#include<iostream>;
#include<memory>;
using namespace std;

struct ListNode {
	int val;
	shared_ptr<ListNode> next = make_shared<ListNode>();
	//ListNode(int x) : val(x), next(nullptr) {}
	ListNode() : val(0), next(nullptr) {}
};

struct LinkList {
	int listSize;
	shared_ptr<ListNode> m_head = make_shared<ListNode>();

	LinkList(int v[], int size);

	~LinkList();

	int size();

	void erase(int x);

	void insert(shared_ptr<ListNode> node, int v);

	// return fist node that has value x 
	shared_ptr<ListNode> find(int x);
};

ostream& operator<<(ostream& os, const LinkList& m);