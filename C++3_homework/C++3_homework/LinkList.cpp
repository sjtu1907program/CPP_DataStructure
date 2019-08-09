#include "LinkList.h"

LinkList::LinkList(int v[], int size)
{
	// v[] = {1, 2, 3,  4, 3}
	ListNode *p;
	p = m_head;
	for (int i = 0; i < size; i++)
	{
		ListNode *s = new ListNode(0);
		s->val = v[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;
}

LinkList::~LinkList()
{
}

int LinkList::size()
{
	int n = 0;
	ListNode *p = m_head->next;

	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}

void LinkList::erase(int x)
{
	ListNode *r = m_head;
	ListNode *p = r->next;
	while (p != NULL)
	{
		if (p->val == x)
		{
			r->next = p->next;
			ListNode *d;
			d = p;
			p = p->next;
			delete d;
		}
		else
		{
			r = p;
			p = p->next;
		}
	}
}

void LinkList::insert(ListNode* node, int v)
{
	ListNode *m = new ListNode(0);
	m->val = v;
	if (node == nullptr)
	{
		m->next = m_head->next;
		m_head->next = m;
	}
	else
	{
		m->next = node->next;
		node->next = m;
	}
}

ListNode* LinkList::find(int x)
{
	ListNode *p = m_head->next;
	while (p != NULL)
	{
		if (p->val == x)
		{
			return p;
		}
		p = p->next;
	}
	return 0;
}

ostream & operator<<(ostream & os, const LinkList & m)
{
	ListNode *p = m.m_head->next;
	while (p != NULL)
	{
		os << p->val << "  ";
		p = p->next;
	}
	return os;
	// TODO: 在此处插入 return 语句
}