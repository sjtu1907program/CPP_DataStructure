#include "Linklist.h"

void Remove(shared_ptr<ListNode>  head) {
	if (!head) {
		return;
	}

	Remove(head->next);
	head.reset();//从后往前删
}
shared_ptr<ListNode>  clone(shared_ptr<ListNode>  head) {
	if (!head) {
		return nullptr;
	}
	shared_ptr<ListNode>  temp = make_shared<ListNode>(head->val);
	temp->next=(clone(head->next));
	return temp;
}

LinkList::LinkList(int v[], int size) {
	// v[] = {1, 2, 3,  4, 3}
	//m_head->next=&(ListNode (v[0]));
	if (size == 0) {
		return;
	}
	m_head = make_shared<ListNode>(size);//指向的第一个为空  值为size大小  
	shared_ptr<ListNode>  temp{ m_head };
	for (int i{ 0 }; i <size; i++) {
		temp->next=make_shared<ListNode>(v[i]);
		temp = temp->next;
	}

}
LinkList::LinkList(std::initializer_list<int> l) {
	if (l.size() == 0) {
		return;
	}
	m_head = make_shared<ListNode>(l.size());//指向的第一个为空  值为size大小  
	shared_ptr<ListNode> temp{ m_head };
	for (auto i= l.begin(); i < l.end(); i++) {
		temp->next=make_shared<ListNode>(*i);
		temp = temp->next;
	}
}
LinkList::LinkList(const LinkList& other) {
	this->setHead(clone(other.getHead()));
}
LinkList::LinkList(LinkList&& other) {
	m_head = other.getHead();
	other.setHead(nullptr);
}
LinkList& LinkList::operator = (const LinkList& other) {
	if (this==&other) {
		return *this;
	}
	Remove(this->getHead());
	this->setHead(clone(other.getHead()));
	return *this;
}
LinkList& LinkList::operator=(LinkList&& other) {
	if (m_head == other.getHead()) {
		return *this;
	}
	m_head.reset();
	m_head = other.getHead();
	other.setHead(nullptr);
	return *this;
}

LinkList::~LinkList() 
	{
	shared_ptr<ListNode>temp{ m_head };
		for (; temp != nullptr;) {
			shared_ptr<ListNode>temp2 = temp;
			temp = temp->next;
			temp2.reset();
		}
	}
int LinkList::size() 
	{
		int count = 0;
		for (shared_ptr<ListNode>temp{ m_head->next }; temp != nullptr; temp = temp->next) {
			count++;
		}
		return count;
	}




