#pragma once
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};

struct LinkList {
public:
	LinkList(int v[], int size);
	~LinkList();

	int size();

	void erase(int x);

	void insert(ListNode* node, int v);

	// return fist node that has value x 
	ListNode* find(int x);
	ListNode* m_head{ nullptr };
};


ostream& operator<<(ostream& os, LinkList& list);