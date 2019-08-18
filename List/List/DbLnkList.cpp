#include "DbLnkList.h"
#include <new>

namespace myClassLibrary {
	DbLinkList::DbLinkList() {
		m_size = 0;
		m_head = m_tail = nullptr;
	}
	
	DbLinkList::DbLinkList(std::initializer_list<int> l) {
		m_size = l.size();
		if (m_size == 0) {
			m_head = m_tail = nullptr;
			return;
		}
		const int * i = l.begin();
		m_head = new DbListNode(*i++);
		DbListNode * curNode = m_head;
		for( ; i < l.end(); ++i ){
			curNode->SetNext(new DbListNode(*i, curNode));
			curNode = curNode->GetNext();
		}
		m_tail = curNode;
	}

	DbLinkList::DbLinkList(int v[], int size) {
		m_size = size;
		if (m_size == 0) {
			m_head = m_tail = nullptr;
			return;
		}
		m_head = new DbListNode(v[0]);
		DbListNode * curNode = m_head;
		for (int i = 1; i < m_size; i++) {
			curNode->SetNext(new DbListNode(v[i], curNode));
			curNode = curNode->GetNext();
		}
		m_tail = curNode;
	}

	DbLinkList::DbLinkList(const DbLinkList & dbList) {
		m_size = dbList.size();
		if (m_size == 0) {
			m_head = m_tail = nullptr;
			return;
		}
		m_head = new DbListNode(dbList.head()->GetVal()) ;
		DbListNode * curNode = m_head;
		DbListNode * otherNode = dbList.head()->GetNext();
		for (int i = 1; i < m_size; i++) {
			curNode->SetNext(new DbListNode(otherNode->GetVal(), curNode));
			curNode = curNode->GetNext();
			otherNode = otherNode->GetNext();
		}
		m_tail = curNode ;
	}

	DbLinkList::DbLinkList(DbLinkList && dblist) {
		m_size = dblist.size();
		m_head = dblist.m_head;
		dblist.m_head = nullptr;
		m_tail = dblist.m_tail;
		dblist.m_tail = nullptr;
	}
	
	DbLinkList & DbLinkList::operator=(const DbLinkList & dblist) {
		this->clear();
		m_size = dblist.size();
		if (m_size == 0) {
			m_head = m_tail = nullptr;
			return *this;
		}
		m_head = new DbListNode(dblist.head()->GetVal());
		DbListNode * curNode = m_head;
		DbListNode * otherNode = dblist.head()->GetNext();
		for (int i = 1; i < m_size; i++) {
			curNode->SetNext(new DbListNode(otherNode->GetVal(), curNode));
			curNode = curNode->GetNext();
			otherNode = otherNode->GetNext();
		}
		m_tail = curNode;
		return *this;
	}

	DbLinkList & DbLinkList::operator=(DbLinkList && dblist) {
		this->clear();
		m_size = dblist.size();
		m_head = dblist.m_head;
		dblist.m_head = nullptr;
		m_tail = dblist.m_tail;
		dblist.m_tail = nullptr;
		return *this;
	}

	DbLinkList::~DbLinkList() {
		this->clear();
	}


	/*
		erase the first element that has the value x
	*/
	void DbLinkList::erase(int x) {
		std::cout << "try erasing " << x << "..." << std::endl;
		DbListNode * curNode = m_head;
		while (curNode != nullptr && curNode->GetVal() != x)
			curNode = curNode->GetNext();
		if (curNode != nullptr) {
			if (!curNode->GetNext() ) m_tail = curNode->GetPre();
			curNode->GetPre()->SetNext(curNode->GetNext());
			delete curNode;
			this->m_size -= 1;
		}
		else {
			std::cout << "the list has no the val needed been deleted." << std::endl;
		}
	}
	/*
		insert the value in the front of the list
	*/
	void DbLinkList::insert_front(int v) {
		m_head->SetPre(new DbListNode(v, nullptr, m_head));
		m_head = m_head->GetPre();
		m_size++;
	}

	/*
	insert the value in the tail of the list
	*/
	void DbLinkList::insert_back(int v) {
		m_tail->SetNext(new DbListNode(v, m_tail));
		m_tail = m_tail->GetNext();
		m_size++;
	}
	/*
	insert a value in the back of node
	*/
	void DbLinkList::insert(DbListNode* node, int v) {
		std::cout << "try to insert the " << v << " in the behind of " << node->GetVal() << " ..." << std::endl;
		//DbListNode * tmp = node->next;
		node->SetNext(new DbListNode(v, node, node->GetNext()));
		m_size++;
	}


	//@return: the first element that has the value x;
	DbListNode* DbLinkList::find(int x) {
		DbListNode * curNode = m_head;
		while (curNode != nullptr && curNode->GetVal() != x)
			curNode = curNode->GetNext();
		return curNode;
	}

	void DbLinkList::clear() {
		while (m_head) {
			DbListNode * cur = m_head;
			m_head = m_head->GetNext();
			delete cur;
			m_size--;
		}
	}
	std::ostream& operator<<(std::ostream& _cout, DbLinkList& list) {

		DbListNode * cur = list.head();
		_cout << "size:" << list.size() << ", contents:[";
		if (cur != nullptr)
		{
			_cout << cur->GetVal();
			while (cur->GetNext() != nullptr) {
				cur = cur->GetNext();
				_cout << "," << cur->GetVal();
			}
		}
		_cout << "]";
		return _cout;
	}
}

namespace myStructLibrary {
	/*
	params:	int v[] , int m_size :  an int array
*/
	DbLinkList::DbLinkList(int v[], int size) {
		m_size = size;
		if (m_size == 0) return;
		m_head = new DbListNode(v[0]);
		DbListNode * curNode = m_head;
		for (int i = 1; i < m_size; i++) {
			curNode->next = new DbListNode(v[i], curNode);
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
		std::cout << "try erasing " << x << "..." << std::endl;
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
		m_head->pre = new DbListNode(v, nullptr, m_head);
		m_head = m_head->pre;
		m_size++;
	}

	/*
	insert the value in the tail of the list
	*/
	void DbLinkList::insert_back(int v) {
		m_tail->next = new DbListNode(v, m_tail);
		m_tail = m_tail->next;
		m_size++;
	}
	/*
	insert a value in the back of node
	*/
	void DbLinkList::insert(DbListNode* node, int v) {
		std::cout << "try to insert the " << v << " in the behind of " << node->val << " ..." << std::endl;
		//DbListNode * tmp = node->next;
		node->next = new DbListNode(v, node, node->next);
		m_size++;
	}


	//@return: the first element that has the value x;
	DbListNode* DbLinkList::find(int x) {
		DbListNode * curNode = m_head;
		while (curNode != nullptr && curNode->val != x)
			curNode = curNode->next;
		return curNode;
	}


	std::ostream& operator<<(std::ostream& _cout, const DbLinkList& list) {

		DbListNode * cur = list.m_head;
		_cout << "size:" << list.m_size << ", contents:[";
		_cout << cur->val;
		while (cur->next != nullptr) {
			cur = cur->next;
			_cout << "," << cur->val;
		}
		_cout << "]";
		return _cout;
	}

}
