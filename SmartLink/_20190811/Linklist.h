#pragma once
#include<iostream>
using namespace std;
using std::shared_ptr;
struct ListNode {
	int val;
	shared_ptr<ListNode> next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class LinkList
{
	shared_ptr<ListNode> m_head{ nullptr };
public:
	LinkList(LinkList&& other);
	LinkList& operator=(LinkList&& other);
	shared_ptr<ListNode> getHead()const {//如果 调用本身 有const
		return m_head;
	}
	void setHead(shared_ptr<ListNode> node) {
		m_head = node;
	}

	LinkList(int v[], int size);
	LinkList(std::initializer_list<int> l);
	LinkList(const LinkList& other);
	LinkList& operator = (const LinkList& other);

	~LinkList();

	int size();
	void erase(int x)
	{
		shared_ptr<ListNode>  temp2{ nullptr };
		for (shared_ptr<ListNode> temp{ m_head }; temp->next != nullptr; ) {
			if (temp->next->val == x) {
				temp2 = temp->next;
				temp->next=temp2->next;
				temp2.reset();
			}
			else {
				temp = temp->next;
			}
		}

	}

	void insert(shared_ptr<ListNode>  node, int v)
	{
		shared_ptr<ListNode> insertOne{ m_head };
		if (node == nullptr) {//插入队尾
			for (; insertOne->next != nullptr; insertOne = insertOne->next) {// 循环到末尾
			}
			insertOne->next=make_shared<ListNode>(v);
		}
		else {//只考虑传入的是合法node 
			for (; insertOne->next != node; insertOne = insertOne->next) {//循环到下一个为node
			}
			insertOne->next=make_shared<ListNode>(v);
			insertOne->next=node;
		}

	}

	// return fist node that has value x 
	shared_ptr<ListNode>  find(int x) {
		shared_ptr<ListNode> target{ m_head->next };
		for (; target->val != x; target = target->next) {//循环到下一个为node
		}
		return target;

	};


};
inline std::ostream& operator<< (std::ostream& os, LinkList& lst) {
	shared_ptr<ListNode>  temp = lst.getHead()->next;
	for (; temp->next != nullptr; temp = temp->next) {//最后一个元素为止

		os << temp->val << "->";
	}
	os << temp->val << std::endl;
	return os;
};





