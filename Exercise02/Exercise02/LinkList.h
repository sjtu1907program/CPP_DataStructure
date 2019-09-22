#pragma once
#include<vector>
#include<iostream>
#include<memory>

using namespace std;

class ListNode {
public:
	ListNode(const int v) : value(v), next(nullptr) {}
	ListNode(const int v, shared_ptr<ListNode> p) : value(v), next(p) {}
	const int getValue() { return value; };
	void setValue(int v) { value = v; };
	shared_ptr<ListNode> getNext() const { return next; };
	void setNext(shared_ptr<ListNode> where) { next = where; };
	//~Node() { delete next; };
private:
	int value;
	shared_ptr<ListNode> next;
};

class LinkList {
public:
	LinkList() :size(0), head(nullptr) {}; //default: empty List
	LinkList(std::initializer_list<int> l);
	LinkList(const vector<int>& v); //create a List from a vector
	LinkList(int* array, int array_size); //create a List from an array
	LinkList(const LinkList& another);
	LinkList& operator=(const LinkList& another);
	int length() const { return size; };
	bool insert(shared_ptr<ListNode> np, int pos);//insert node into pos of the List
	bool insert(int value, int pos); //insert value into pos of the List
	int find(int value); //find the first value and get its pos
	int remove(int value); //remove all the Node s of the value and return the number of Node s removed
	bool split(int pos, LinkList& new_list); //split after the Node at the pos and let the rest be new_list
	void combine(LinkList& append_list); //add append_list to the end of the List
	void printAll(); //print all the members of the List in order
	friend ostream& operator<<(ostream& os, const LinkList& l);
	//const List& operator=(const List&) = delete;
	~LinkList();
private:
	shared_ptr<ListNode> head; //Head of the list.
	int size; //The current size(length) of the list.
};
