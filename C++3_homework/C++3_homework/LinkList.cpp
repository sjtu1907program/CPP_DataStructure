#include "LinkList.h"

LinkList::LinkList(int v[], int size)
{
	// v[] = {1, 2, 3,  4, 3}
	shared_ptr<ListNode> p = m_head;
	for (int i = 0; i < size; i++)
	{
		shared_ptr<ListNode> s = make_shared<ListNode>();
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
	shared_ptr<ListNode> p = m_head->next;

	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}

void LinkList::erase(int x)
{
	shared_ptr<ListNode> r = m_head;
	shared_ptr<ListNode> p = r->next;
	while (p != NULL)
	{
		if (p->val == x)
		{
			r->next = p->next;
			p = p->next;
		}
		else
		{
			r = p;
			p = p->next;
		}
	}
}

void LinkList::insert(shared_ptr<ListNode> node, int v)
{
	shared_ptr<ListNode> m = make_shared<ListNode>();
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

shared_ptr<ListNode> LinkList::find(int x)
{
	shared_ptr<ListNode> p = m_head->next;
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
	shared_ptr<ListNode> p = m.m_head->next;
	while (p != NULL)
	{
		os << p->val << "  ";
		p = p->next;
	}
	return os;
	// TODO: 在此处插入 return 语句
}