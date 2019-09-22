#include "Linklist.h"

void Remove(ListNode* head) {
	if (!head) {
		return;
	}

	Remove(head->getNext());
	delete head;//从后往前删
}
ListNode* clone(ListNode* head) {
	if (!head) {
		return nullptr;
	}
	ListNode* temp = new ListNode(head->getValue());
	temp->setNext(clone(head->getNext()));
	return temp;
}

LinkList::LinkList(int v[], int size) {
	// v[] = {1, 2, 3,  4, 3}
	//m_head->next=&(ListNode (v[0]));
	if (size == 0) {
		return;
	}
	m_head = new ListNode(size);//指向的第一个为空  值为size大小  
	ListNode* temp{ m_head };
	for (int i{ 0 }; i < size; i++) {
		temp->setNext(new ListNode(v[i]));
		temp = temp->getNext();
	}

}
LinkList::LinkList(std::initializer_list<int> l) {
	if (l.size() == 0) {
		return;
	}
	m_head = new ListNode(l.size());//指向的第一个为空  值为size大小  
	ListNode* temp{ m_head };
	for (auto i = l.begin(); i < l.end(); i++) {
		temp->setNext(new ListNode(*i));
		temp = temp->getNext();
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
	if (this == &other) {
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
	delete m_head;
	m_head = other.getHead();
	other.setHead(nullptr);
	return *this;
}

LinkList::~LinkList()
{
	ListNode*temp{ m_head };
	for (; temp != nullptr;) {
		ListNode*temp2 = temp;
		temp = temp->getNext();
		delete temp2;
	}
}
int LinkList::size()
{
	int count = 0;
	for (ListNode*temp{ m_head->getNext() }; temp != nullptr; temp = temp->getNext()) {
		count++;
	}
	return count;
}
