#pragma once
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};

class LinkList {

	friend ostream& operator<<(ostream& os, LinkList& list);


public:
	LinkList(int v[], int size);
	LinkList(std::initializer_list<int> l);
	LinkList(const LinkList& other);
	LinkList& operator=(const LinkList& other);
	
	~LinkList();

	int size();
	void erase(int x);
	void insert(ListNode* node, int v);
	// return fist node that has value x 
	ListNode* find(int x);

private:

	
	static void DeleteList(ListNode* node);
	ListNode* CopyList(ListNode* node);

private:
	ListNode* m_head{ nullptr };

};

