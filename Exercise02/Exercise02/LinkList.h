#pragma once
#include<vector>
#include<iostream>

using namespace std;

class ListNode {
public:
	ListNode(const int v) : value(v), next(nullptr) {}
	ListNode(const int v, ListNode* p) : value(v), next(p) {}
	const int getValue() { return value; };
	void setValue(int v) { value = v; };
	ListNode* getNext() const { return next; };
	void setNext(ListNode* where) { next = where; };
	//~Node() { delete next; };
private:
	int value;
	ListNode* next;
};

class LinkList {
public:
	LinkList() :size(0), head(nullptr) {}; //default: empty List
	LinkList(const vector<int>& v); //create a List from a vector
	LinkList(int* array, int array_size); //create a List from an array
	int length() const { return size; };
	bool insert(ListNode* np, int pos);//insert node into pos of the List
	bool insert(int value, int pos); //insert value into pos of the List
	int find(int value); //find the first value and get its pos
	int remove(int value); //remove all the Node s of the value and return the number of Node s removed
	bool split(int pos, LinkList& new_list); //split after the Node at the pos and let the rest be new_list
	void combine(LinkList& append_list); //add append_list to the end of the List
	void printAll(); //print all the members of the List in order
	friend ostream& operator<<(ostream& os, const LinkList& l);
	//const List& operator=(const List&) = delete;
	const LinkList& operator=(const LinkList& another) {
		this->~LinkList(); //get rid of the old List
		//another is an empty List
		if (another.size == 0) {
			*this = LinkList();
			return *this;
		}
		ListNode* nowA = another.head; //the headA is the first nowA
		head = new ListNode(another.head->getValue()); //create a head with the value
		ListNode* now = nullptr;
		ListNode* prev = head; //the head is the first prev
		nowA = nowA->getNext(); //get the next nowA
		while (nowA != nullptr) { //until the end of another
			now = new ListNode(nowA->getValue()); //copy the now Node
			prev->setNext(now); //chain now to prev
			prev = now; //the next prev is the now now
			nowA = nowA->getNext(); //get the next nowA
		}
		size = another.size;
		return *this; //get a new List
	}
	~LinkList() {
		size = 0;
		ListNode* now = head; //the first now is head
		if (head) {
			now = now->getNext();
			delete head;
		}
		while (now != nullptr) {
			ListNode* temp = now; //store where now is
			now = now->getNext(); //get the next
			delete temp; //delete the previous now
		}
		head = nullptr;
	}
private:
	ListNode* head; //Head of the list.
	int size; //The current size(length) of the list.
};
