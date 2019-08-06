#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(nullptr) {}
};
struct LinkList {
	friend std::ostream& operator<< (std::ostream& os, LinkList& lst);
	ListNode* m_head{ nullptr };
	int len;
	LinkList(int v[],int size) {
		m_head = new ListNode(0);
		len = size;
		ListNode* tmp = m_head;
		for (int i = 0; i < len; i++) {
			tmp->next= new ListNode(v[i]);
			tmp = tmp->next;
		}
	}
	~LinkList()
	{
		ListNode *t = m_head;
		while (t!=nullptr)
		{
			ListNode *del = t;
			t = t->next;
			delete del;
		}
	}
	int size()
	{
		return len;
	}

	void erase(int x)
	{
		ListNode *d = find(x);
		while (d!=nullptr)
		{
			if (len == 0) return;
			--len;
			ListNode *del = d->next;
			if (del == nullptr) {
				ListNode *tmp = m_head;
				while (tmp->next->next!=nullptr)
				{
					tmp = tmp->next;
				}
				tmp->next = nullptr;
				return;
			}
			d->val = d->next->val;
			d->next = d->next->next;
			delete del;
			d = find(x);
		}
		
	}

	void insert(ListNode* node, int v)
	{
		if (node == nullptr) {
			ListNode *t = m_head;
			while (t->next!=nullptr)
			{
				t = t->next;
			}
			t->next = new ListNode(v);
			return;
		}
		ListNode *pos = node->next;
		node->next = new ListNode(v);
		node->next->next = pos;
		++len;
	}
	// return fist node that has value x 
	ListNode* find(int x);
};
ListNode* LinkList::find(int x) {
	ListNode *t = m_head;
	while (t!=nullptr)
	{
		if (t->val == x) return t;
		t = t->next;
	}
	return t;
}

std::ostream& operator<< (std::ostream& os, LinkList& lst) {
	ListNode *traverse = lst.m_head->next;
	while (traverse != nullptr)
	{
		std::cout << traverse->val << " ";
		traverse = traverse->next;
	}
	return os;
}
