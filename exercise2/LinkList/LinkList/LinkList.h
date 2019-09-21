#pragma once
#include<iostream>
#include<memory>
using namespace std;

struct ListNode {
	int val;
	shared_ptr<ListNode> next = make_shared<ListNode>();;
	ListNode() : val(0), next(nullptr) {}
};

struct LinkList {
	shared_ptr<ListNode> m_head = make_shared<ListNode>();

	LinkList(int v[], int size);
	~LinkList();

	int size();
	void erase(int x);
	void insert(shared_ptr<ListNode> node, int v);
	shared_ptr<ListNode> find(int x);
};

std::ostream& operator<<(std::ostream& os, LinkList& lst);
