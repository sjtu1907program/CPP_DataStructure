#include"LinkList.h"
LinkList::LinkList(int v[], int size) {
	m_head = new ListNode(v[0]);
	ListNode* temp{ m_head };
	for (int i{ 1 }; i < size; i++) {
		temp->next = new ListNode(v[i]);
		temp = temp->next;
	}
}

LinkList::LinkList(std::initializer_list<int> l) {
	int* i =(int*)l.begin();
	m_head = new ListNode(*i);
	ListNode* temp{ m_head };
	for (; i != (int*)l.end(); i++) {
		temp->next = new ListNode(*i);
		temp = temp->next;
	}

}

LinkList::LinkList(const LinkList&other) {

	m_head = Clone(other.m_head);
}
LinkList& LinkList::operator =(const LinkList&other) {
	if (this == &other) {
		return *this;
	}
	Remove(m_head);
	m_head = Clone(other.m_head);
	return *this;
}


void LinkList::Remove(ListNode* node) {
	if (!node) {
		return;
	}
	Remove(node->next);
	delete node;
}
ListNode* LinkList::Clone(ListNode* node) {
	if (!node)return NULL;
	ListNode* temp = new ListNode(node->val);
	temp->next = Clone(node->next);
	return temp;
}

LinkList:: ~LinkList()
{
	ListNode*temp{ m_head->next };
	for (; temp != nullptr;) {
		ListNode*temp2 = temp;
		temp = temp->next;
		delete temp2;
	}
}
int LinkList::size()
{
	int count = 0;
	for (ListNode*temp{ m_head }; temp != nullptr; temp = temp->next) {
		count++;
	}
	return count;
}

void LinkList::erase(int x)
{
	ListNode * temp = m_head;
	ListNode * temp2 = temp;
	for (; temp != nullptr;)
	{
		if (temp->val == x) {

			if (temp == m_head) {
				m_head = temp->next;
			}
			else {
				temp2->next = temp->next;
			}
			temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
		temp2 = temp;
		temp = temp == nullptr ? temp : temp->next;
	}


}

void LinkList::insert(ListNode* node, int v)
{
	ListNode *insertNew = new ListNode(v);
	if (node == nullptr) {
		node = m_head;
		while (node->next != nullptr) {
			node = node->next;
		}
	}
	else {
		insertNew->next = node->next;
	}
	node->next = insertNew;
}

ListNode* LinkList::find(int x) {
	ListNode* temp = m_head;
	for (; temp != nullptr; temp = temp->next)
	{
		if (temp->val == x) {
			return temp;
		}
	}
	return nullptr;
};


ListNode* LinkList::getHead() {
	return m_head;
}

std::ostream& operator<< (std::ostream& os, LinkList& lst)
{
	ListNode * temp = lst.getHead();
	for (; temp->next != nullptr; temp = temp->next) {

		os << temp->val << " ";
	}
	os << temp->val << std::endl;
	return os;
};