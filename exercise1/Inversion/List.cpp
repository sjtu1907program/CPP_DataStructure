#include "List.h"
#include <iostream>



void LinkList::erase(int x)
{
	ListNode* e = m_head;
	while (e->next != nullptr)
	{
		if (e->val == x)
		{
			e->val = e->next->val;
			e->next = e->next->next;
		}
	}
	if (e->val == x)
	{
		e = nullptr;
	}
}

std::ostream& operator<< (std::ostream& os, const LinkList& lst)
{
	ListNode* output = lst.m_head;
	while(output->next != nullptr)
	{

		os << output->val << "->" << "\t";
		os << std::endl;
	}
	os << output->val ;
	return os;
}