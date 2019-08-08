#pragma once
#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};

struct LinkList {
	ListNode* m_head{ nullptr };
	LinkList(int v[], int size) {
		// v[] = {1, 2, 3,  4, 3}
		//m_head->next=&(ListNode (v[0]));
		
		m_head = new ListNode(size);//指向的第一个为空  值为size大小  
		ListNode* temp{ m_head };
		for (int i{ 0 }; i <size; i++) {
			temp->next = new ListNode(v[i]);
			temp = temp->next;
		}
		
	}
	~LinkList()
	{

		ListNode*temp{ m_head->next};
		for (; temp!= nullptr;) {
			ListNode*temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
	
	
	}
	int size()
	{
		int count = 0;
		for (ListNode*temp{ m_head->next }; temp  != nullptr; temp = temp->next) {
			count++;
		}
		return count;
	}



	void erase(int x)
	{
		ListNode * temp2{ nullptr };
		for (ListNode*temp{ m_head}; temp->next!= nullptr; ) {
			if (temp->next->val == x) {
				temp2 = temp->next;
				temp->next = temp2->next;
				delete temp2;
			}
			else {
				temp = temp->next;
			}
		}
		
	}

	void insert(ListNode* node, int v)
	{
		ListNode*insertOne{ m_head };
		if (node == nullptr) {//插入队尾
			for (; insertOne->next!= nullptr; insertOne = insertOne->next) {// 循环到末尾
			}
			insertOne->next = new ListNode(v);
		}
		else {//只考虑传入的是合法node 
			for (; insertOne->next!=node; insertOne = insertOne->next) {//循环到下一个为node
			}
			insertOne->next = new ListNode(v);
			insertOne->next->next = node;
		}

	}

	// return fist node that has value x 
	ListNode* find(int x) {
		ListNode*target{ m_head->next };
		for (; target->val != x; target = target->next) {//循环到下一个为node
		}
		return target;
	
	};
	
};
std::ostream& operator<< (std::ostream& os, LinkList& lst) {
	ListNode * temp = lst.m_head->next;
    for (; temp->next != nullptr;temp=temp->next) {//最后一个元素为止
		
		os << temp->val<<"->";
	}
	os << temp->val<<std::endl;
	return os;
};
