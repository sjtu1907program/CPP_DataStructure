#include"LinkList.h"

LinkList::LinkList(int v[], int size)
{
	shared_ptr<ListNode> p = m_head;
	for (int i = 0; i < size; i++)
	{
		p->next = make_shared<ListNode>();
		p->next->val = v[i];
		p = p->next;
	}
	p->next = nullptr;
}

LinkList::~LinkList()
{
	shared_ptr<ListNode> p, q;
	p = m_head;
	while (p)
	{
		q = p;
		p = p->next;
	}
	m_head = NULL;
}

int LinkList::size()
{
	shared_ptr<ListNode> p = m_head;
	int size = 0;
	while (p->next)
	{
		p = p->next;
		size++;
	}
	return size;
}

void LinkList::erase(int x)
{
	shared_ptr<ListNode> p, q;
	p = m_head;
	while (p->next != nullptr)
	{
		if (p->next->val == x)
		{
			q = p->next;
			p->next = q->next;
		}
		else
		{
			p = p->next;
		}
	}
}

void LinkList::insert(shared_ptr<ListNode> node, int v)
{
	shared_ptr<ListNode> p, q;
	p = m_head;
	q = make_shared<ListNode>();
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
shared_ptr<ListNode> LinkList::find(int x)
{
	shared_ptr<ListNode> p = m_head;
	while (p->val != x)
	{
		p = p->next;
	}
	return p;
}

ostream& operator<<(ostream& os, LinkList& lst)
{
	shared_ptr<ListNode> p = lst.m_head->next;
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