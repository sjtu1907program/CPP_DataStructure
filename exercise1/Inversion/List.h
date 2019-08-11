#pragma once
#include <iostream>
#include <malloc.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


struct LinkList {
	ListNode* m_head{ nullptr };

	LinkList(int v[], int size) {
		// v[] = {1, 2, 3,  4, 3}
		ListNode* s{0};
		for (int i{ size - 1 }; i > -1; i--)
		{
			if (!m_head)
			{
				m_head = new ListNode(v[i]);
			}
			else
			{
				s->next = m_head->next;
				s->val = v[i];
				m_head->next = s;
			}
		}
	}
	~LinkList()
	{
		remove(m_head);
	}

	void remove(ListNode* pNode)
	{
		if (!pNode)
			return;
		remove(pNode->next);
		delete pNode;
	}
	int size()
	{
		int count{};
		ListNode* s = m_head;
		while (s->next != nullptr)
		{
			count++;
			s->next = s->next->next;
		}
		return count;
	}



	void erase(int x);
	

	//after the given node
	void insert(ListNode* node, int v)
	{
		ListNode* source = m_head;
		ListNode* target{ nullptr };
		while (source->next != nullptr)
		{
			if (source != node)
			{
				source->val = source->next->val;
				source->next = source->next->next;
			}
			else
			{
				target->val = v;
				target->next = source->next->next;
				source->next = target;
			}
		}
		if (node == nullptr)
		{
			target->val = v;
			target->next = nullptr;
			node->next = target;
		}
	}

	// return fist node that has value x 
	ListNode* find(int x)
	{

		ListNode* f = m_head;
		while (f->next != nullptr)
		{
			if (f->val == x)
			{
				return f;
			}
			else
			{
				f->val = f->next->val;
				f->next = f->next->next;
			}
		}
		if (f->val == x)
		{
			return f;
		}
	}

};

std::ostream& operator<< (std::ostream& os, const LinkList& lst);
