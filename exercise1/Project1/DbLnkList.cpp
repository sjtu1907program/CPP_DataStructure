#include "DbLnkList.h"
#include <new>
/*
	params:	int v[] , int m_size :  an int array
*/
DbLinkList::DbLinkList(int v[], int size) {
	m_size = size;
	if (m_size == 0) return;
	m_head = new DbListNode(v[0]);
	DbListNode * curNode = m_head;
	for (int i = 1 ; i < m_size; i++) {
		curNode->next = new DbListNode(v[i] , curNode);
		curNode = curNode->next;
	}
	m_tail = curNode;
}

DbLinkList::~DbLinkList() {
	while (m_head) {
		DbListNode * cur = m_head;
		m_head = m_head->next;
		delete cur;
	}
}

int DbLinkList::size() {
	return this->m_size;
}

/*
	erase the first element that has the value x
*/
void DbLinkList::erase(int x) {
	std::cout << "try erasing " <<x <<"..."<< std::endl;
	DbListNode * curNode = m_head;
	while (curNode != nullptr && curNode->val != x)
		curNode = curNode->next;
	if (curNode != nullptr) {
		if (!curNode->next) m_tail = curNode->pre;
		curNode->pre->next = curNode->next;
		delete curNode;
		this->m_size -= 1;
	}

}
/*
	insert the value in the front of the list
*/
void DbLinkList::insert_front(int v) {
	m_head->pre = new DbListNode(v,nullptr, m_head);
	m_head = m_head->pre;
	m_size++;
}

/*
insert the value in the tail of the list
*/
void DbLinkList::insert_back(int v) {
	m_tail->next = new DbListNode(v,m_tail);
	m_tail = m_tail->next;
	m_size++;
}
/*
insert a value in the back of node
*/
void DbLinkList::insert(DbListNode* node, int v) {
	std::cout << "try to insert the " << v << " in the behind of " << node->val << " ..." << std::endl;
	//DbListNode * tmp = node->next;
	node->next = new DbListNode(v,node, node->next);
	m_size++;
}


//@return: the first element that has the value x;
DbListNode* DbLinkList::find(int x) {
	DbListNode * curNode = m_head;
	while (curNode != nullptr && curNode->val != x)
		curNode = curNode->next;
	return curNode;
}


std::ostream& operator<<(std::ostream& _cout,const DbLinkList& list) {
	
	DbListNode * cur = list.m_head;
	_cout << "size:" << list.m_size <<", contents:[";
	_cout << cur->val ;
	while (cur->next != nullptr) {
		cur = cur->next;
		_cout << "," <<cur->val ;
	}
	_cout << "]";
	return _cout;
}