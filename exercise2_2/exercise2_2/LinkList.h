#pragma once
#include<iostream>

class ListNode {
public:
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next() {}
};

class LinkList {
private:
	ListNode* m_head{ nullptr };
public:
	LinkList(int v[], int size);
	LinkList(std::initializer_list<int> l);
	LinkList(const LinkList&other);
	LinkList& operator =(const LinkList&other);
	~LinkList();
	int size();
	void erase(int x);
	void Remove(ListNode* node);
	ListNode* Clone(ListNode* node);
	void insert(ListNode* node, int v);
	ListNode* find(int x);
	ListNode* getHead();
};
std::ostream& operator<< (std::ostream& os, LinkList& lst);

