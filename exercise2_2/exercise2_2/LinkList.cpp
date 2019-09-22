#include"LinkList.h"
using std::make_shared;
using std::shared_ptr;

namespace TOOL {
	LinkList::LinkList(int v[], int size) {
		m_size = size;
		if (size > 0) {
			m_head = make_shared<ListNode>(ListNode(v[0]));
			shared_ptr<ListNode> temp = m_head;
			for (int i{ 1 }; i < size; i++) {
				temp->SetNext(make_shared<ListNode>(ListNode(v[i],nullptr)));
				temp = temp->GetNext();
			}
		}
	}



	LinkList::LinkList(LinkList&& other) {
		m_head = other.m_head;
		//other.m_head = nullptr;
	}



	LinkList::LinkList(std::initializer_list<int> l) {
		const int* i = l.begin();
		m_head = make_shared<ListNode>(ListNode(*i));
		shared_ptr<ListNode> temp = m_head;
		for (; i != l.end(); i++) {
			temp->SetNext(make_shared<ListNode>(ListNode(*i)));
			temp = temp->GetNext();
		}

	}

	LinkList& LinkList::operator =(LinkList&&other) {
		if (m_head == other.m_head) {
			return *this;
		}
		m_head = other.m_head;
		other.m_head = nullptr;
		return *this;
	}
	LinkList::LinkList(const LinkList&other) {

		m_head = Clone(other.m_head);
	}
	LinkList:: ~LinkList()
	{
		while (m_head) {
			//std::shared_ptr<ListNode> temp = m_head;
			m_head = m_head->GetNext();
			m_size--;
		}
	}
	LinkList& LinkList::operator =(const LinkList&other) {
		if (this == &other) {
			return *this;
		}
		Remove(m_head);
		m_head = Clone(other.m_head);
		return *this;
	}


	void LinkList::Remove(std::shared_ptr<ListNode> node) {
		if (!node) {
			return;
		}
		Remove(node->GetNext());
	}
	std::shared_ptr<ListNode> LinkList::Clone(std::shared_ptr<ListNode> node) {
		if (!node)return NULL;
		std::shared_ptr<ListNode> temp = make_shared<ListNode>(ListNode(node->GetVal()));
		temp->SetNext(Clone(node->GetNext()));
		return temp;
	}

	int LinkList::size()
	{
		return m_size;
	}

	void LinkList::erase(int x)
	{
		std::shared_ptr<ListNode> temp = m_head;
		std::shared_ptr<ListNode> temp2 = temp;
		for (; temp != nullptr;)
		{
			if (temp->GetVal() == x) {

				if (temp == m_head) {
					m_head = temp->GetNext();
				}
				else {
					temp2->SetNext(temp->GetNext());
				}
				temp2 = temp;
				temp = temp->GetNext();
				m_size--;
			}
			temp2 = temp;
			temp = temp == nullptr ? temp : temp->GetNext();
		}


	}

	void LinkList::insert(std::shared_ptr<ListNode> node, int v)
	{
		std::shared_ptr<ListNode>insertNew = make_shared<ListNode>(ListNode(v));
		if (node == nullptr) {
			node = m_head;
			while (node->GetNext() != nullptr) {
				node = node->GetNext();
			}
		}
		else {
			insertNew->SetNext(node->GetNext());
		}
		node->SetNext(insertNew);
		m_size++;
	}

	std::shared_ptr<ListNode> LinkList::find(int x) {
		shared_ptr<ListNode> temp = m_head;
		for (; temp != nullptr; temp = temp->GetNext())
		{
			if (temp->GetVal() == x) {
				return temp;
			}
		}
		return nullptr;
	};


	std::shared_ptr<ListNode> LinkList::getHead() {
		return m_head;
	}

	std::ostream& operator<< (std::ostream& os, LinkList& lst)
	{
		shared_ptr<ListNode> temp = lst.getHead();
		for (; temp->GetNext() != nullptr; temp = temp->GetNext()) {

			os << temp->GetVal() << " ";
		}
		os << temp->GetVal() << std::endl;
		return os;
	};
}
