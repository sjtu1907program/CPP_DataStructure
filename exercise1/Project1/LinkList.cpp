#include"LinkList.h"
#include<iostream>
using namespace std;

LinkList::LinkList(int v[], int size) {
	// v[] = {1, 2, 3,  4, 3}
	m_head = new ListNode(v[size - 1]);
	for (int i = size - 2; i >= 0; i--)
		insert(m_head, v[i]);
}
LinkList::~LinkList()
{
	ListNode *tmp1, *tmp2 = m_head;
	while (tmp2)
	{
		tmp1 = tmp2;
		tmp2 = tmp2->next;
		delete tmp1;
	}
}


int LinkList::size()
{
	ListNode* tmp = m_head;
	int i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}


void LinkList::erase(int x)
{
	ListNode* tmp1 = m_head;
	if (m_head->val == x)
	{
		m_head = m_head->next;
		delete tmp1;
	}
	else {
		ListNode* tmp2 = m_head->next;
		while (tmp2->val != x)
		{
			if (tmp2->next == nullptr)
			{
				cout << "erase not found!"; return;
			}
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp1->next = tmp2->next;
		delete tmp2;
	}
}

void LinkList::insert(ListNode* node, int v)
{
	if (node) {
		//将当前节点的值放入新节点，v放入当前节点
		ListNode* tmp = node->next;
		node->next = new ListNode(node->val);
		node->next->next = tmp;
		node->val = v;
	}
	else {
		//node为空，插入尾部
		ListNode* tmp = m_head;
		while (tmp->next)	//找到尾部
			tmp = tmp->next;
		tmp->next = new ListNode(v);
	}
}

// return fist node that has value x 
ListNode* LinkList::find(int x) {
	ListNode* tmp = m_head;
	while (tmp->val != x)
	{
		if (tmp->next == nullptr)
		{
			cout << "not found!"; return nullptr;
		}
		tmp = tmp->next;
	}
	return tmp;
}

ostream& operator<<(ostream& os, LinkList& list)
{
	os << "{ ";
	ListNode* tmp = list.m_head;
	while (tmp)
	{
		os << tmp->val << ' ';
		tmp = tmp->next;
	}
	os << '}';
	return os;
}
