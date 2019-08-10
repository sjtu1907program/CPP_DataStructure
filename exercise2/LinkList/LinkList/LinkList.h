#pragma once
#include<iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct LinkList {
	LinkList(int v[], int size)
	{
		m_head = new ListNode(0);
		ListNode *p = m_head;
		for (int i = 0; i < size; i++)
		{
			p->next = new ListNode(v[i]);
			p = p->next;
		}
		p->next = nullptr;
	}

	~LinkList()
	{
		ListNode *p, *q;
		p = m_head;
		while (p)
		{
			q = p;
			p = p->next;
			delete(q);
		}
		m_head = NULL;
	}

	int size()
	{
		ListNode *p = m_head;
		int size = 0;
		while (p->next)
		{
			p = p->next;
			size++;
		}
		return size;
	}

	void erase(int x)
	{
		ListNode *p, *q;
		p = m_head;
		while (p->next != nullptr)
		{
			if (p->next->val == x)
			{
				q = p->next;
				p->next = q->next;
				delete(q);
			}
			else
			{
				p = p->next;
			}
		}
	}

	void insert(ListNode* node, int v)
	{
		ListNode *p, *q;
		p = m_head;
		q = new ListNode(0);
		if (node == NULL)
		{
			while (p->next != nullptr)
			{
				p = p->next;
			}
			q->val = v;
			q->next = nullptr;
			p->next = q;

		}
		else
		{
			q->val = v;
			q->next = node->next;
			node->next = q;
		}
	}

	//return first node that has value x
	ListNode* find(int x)
	{
		ListNode *p = m_head;
		while (p->val != x)
		{
			p = p->next;
		}
		return p;
	}

	ListNode* m_head{ nullptr };
};

std::ostream& operator<<(std::ostream& os, LinkList& lst)
{
	ListNode *p = lst.m_head->next;
	if (p == NULL)
	{
		os << "LinkList is empty.";
	}
	else
	{
		os << p->val;
		p = p->next;
		while (p != NULL)
		{
			os << "->" << p->val;
			p = p->next;
		}
	}
	return os;
}
