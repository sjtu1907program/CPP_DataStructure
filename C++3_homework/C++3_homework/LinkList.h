#pragma once
#include<iostream>;
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct LinkList {
	int listSize;
	ListNode * m_head = new ListNode(0);

	LinkList(int v[], int size);

	~LinkList();

	int size();

	void erase(int x);

	void insert(ListNode* node, int v);

	// return fist node that has value x 
	ListNode* find(int x);
};

ostream& operator<<(ostream& os, const LinkList& m);