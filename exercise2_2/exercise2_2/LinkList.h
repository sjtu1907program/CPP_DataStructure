#pragma once
#include<iostream>

using std::shared_ptr;
namespace TOOL {
	/*class ListNode {
	public:
		int val;
		ListNode * next;
		ListNode(int x) :val(x), next() {}
	};*/
	class ListNode {
	private:
		int val;
		std::shared_ptr<ListNode> next;
	public:
		ListNode(int x,std::shared_ptr<ListNode> next = nullptr) : val(x), next(next) {}

		void SetVal(int v) { val = v; };
		int GetVal() const { return val; }
		void SetNext(std::shared_ptr<ListNode> n) { next = n; };
		std::shared_ptr<ListNode> GetNext() const { return next; }
	};

	struct LinkList {
	private:
		std::shared_ptr<ListNode>  m_head;// = std::make_shared<ListNode>(nullptr);
		int m_size;
		//ListNode* m_head{ nullptr };
	public:
		//LinkList();
		LinkList(std::initializer_list<int> l);
		LinkList(int v[], int size);
		LinkList(LinkList&& other);
		LinkList(const LinkList&other);
		~LinkList();
		LinkList& operator =(const LinkList&other);
		LinkList& operator =(LinkList&&other);
		int size();
		void erase(int x);
		void Remove(shared_ptr<ListNode> node);
		shared_ptr<ListNode> Clone(shared_ptr<ListNode> node);
		void insert(shared_ptr<ListNode> node, int v);
		shared_ptr<ListNode> find(int x);
		shared_ptr<ListNode> getHead();
	};
	std::ostream& operator<< (std::ostream& os, LinkList& lst);


}
