#include "LinkList.h"

LinkList::LinkList(const vector<int>& v) //create a List from a vector
	: size(int(v.size())), head(nullptr) //default: empty List
{
	ListNode* prev = nullptr;
	ListNode* now = nullptr;
	if (size) { //if not empty vector
		head = new ListNode(v[0]); //do the head
		prev = head; //the first prev is head
	}
	for (int i = 1; i < size; i++) { //do the body
		now = new ListNode(v[i]); //add the now Node
		prev->setNext(now); //chain now to prev
		prev = now; //prev pointer points to now
	}
}


LinkList::LinkList(int* array, int array_size) //create a List from an array
	: size(array_size), head(nullptr) //default: empty List
{
	ListNode* prev = nullptr;
	ListNode* now = nullptr;
	if (size) { //if not empty array
		head = new ListNode(*array); //do the head
		prev = head; //the first prev is head
	}
	for (int i = 1; i < size; i++) { //do the body
		now = new ListNode(*(array + i)); //add the now Node
		prev->setNext(now); //chain now to prev 
		prev = now; //prev pointer points to now
	}
}

bool LinkList::insert(ListNode* np, int pos) { //insert value into pos of the List
	if (pos<0 || pos >size || !np) return false; //check if the pos is valid
	np->setNext(nullptr);
	if (pos == 0) { //insert at the head
		head = np; //make np as the new head and chain the previous head to it
	}
	else { //insert pos at the middle or the end
		ListNode* prev = head; //the first prev is the head
		ListNode* next = nullptr;
		for (int i = 0; i < pos - 1; i++) { //get the prev point to the Node before the pos
			prev = prev->getNext();
		}
		next = prev->getNext(); //get the pos now and let it be the next
		prev->setNext(np); //chain the prev, np and the next
	}
	size++;
	return true;
}

bool LinkList::insert(int value, int pos) { //insert value into pos of the List
	if (pos<0 || pos >size) return false; //check if the pos is valid
	if (pos == 0) { //insert at the head
		head = new ListNode(value, head); //create a new Node as the new head and chain the previous head to it
	}
	else { //insert pos at the middle or the end
		ListNode* prev = head; //the first prev is the head
		ListNode* next = nullptr;
		for (int i = 0; i < pos - 1; i++) { //get the prev point to the Node before the pos
			prev = prev->getNext();
		}
		next = prev->getNext(); //get the pos now and let it be the next
		prev->setNext(new ListNode(value, next)); //create a new Node and chain the prev, it and the next
	}
	size++;
	return true;
}

int LinkList::find(int value) { //find the first value and get its pos
	if (!size) return -1; //empty List, not found
	int pos = 0; //store the now pos
	ListNode* now = head; //the first now is head
	for (int i = 0; i < size; i++) { //check the Nodes one by one
		if (now->getValue() == value) { //find it
			return pos;
		}
		now = now->getNext(); //get the next
		pos++;
	}
	return -1; //not found
}

int LinkList::remove(int value) { //remove all the Node s of the value and return the number of Node s removed
	if (size == 0) { return 0; } // the list is empty
	int removed = 0;
	while (head->getValue() == value) {// check the head
		ListNode* temp = head; //store where the removed Node is
		head = head->getNext(); //get a new head
		delete temp; //get rid of the removed Node
		removed++;
		if (head == nullptr) { //now the List is empty
			size -= removed; //set the new size
			return removed;
		}
	}
	ListNode* prev = head; //the first prev is head
	ListNode* now = nullptr;
	ListNode* next = nullptr;
	now = prev->getNext(); // get now
	while (now != nullptr) { // still not the end
		if (now->getValue() == value) {
			next = now->getNext(); // get the next of the next
			prev->setNext(next); // skip now(chain next to prev)
			delete now; //get rid of the now Node
			now = next; //the new now is the previous next
			removed++;
		}
		else prev = now; // let the prev pointer point to now
		now = prev->getNext(); // get the next
	}
	size -= removed; //set the new size
	return removed;
}

bool LinkList::split(int pos, LinkList& new_list) { //split after the Node at the pos and let the rest be new_list
	if (pos<0 || pos >size - 1) return false; //check if pos is valid
	if (pos == size - 1) { //split at the end
		new_list = LinkList(); //new_list is an empty list
	}
	else {
		ListNode* now = head; //the first now is head
		for (int i = 0; i < pos; i++) { //get to the pos
			now = now->getNext();
		}
		new_list.~LinkList();
		new_list.head = now->getNext(); //let the rest of the List be new_list
		new_list.size = size - (pos + 1); //set the size of new_list
		now->setNext(nullptr); //let the now Node be the end of the List
	}
	size = pos + 1; //set the new size
	return true;
}

void LinkList::combine(LinkList& append_list) { //add append_list to the end of the List
	if (!append_list.size) { //append_list is empty
		return; //do nothing
	}
	if (!size) { //this List is empty
		*this = append_list; //copy append_list
		return;
	}
	ListNode* prev = head; //the first prev is head
	ListNode* nowA = append_list.head; //the first nowA is headA
	ListNode* now = nullptr;
	while (prev->getNext() != nullptr) { //get to the end of the List
		prev = prev->getNext();
	}
	while (nowA != nullptr) { //until end of the append_list
		now = new ListNode(nowA->getValue()); //copy the Node
		prev->setNext(now); //chain now to prev
		prev = now; //the next prev is the now now
		nowA = nowA->getNext(); //get the next Node of append_list
	}
	size += append_list.size; //set the new size
}

ostream& operator<<(ostream& os, const LinkList& l) {
	if (!l.size) { //empty List
		os << endl;
		return os;
	}
	ListNode* now = l.head; //the first now is the head
	while ((now->getNext()) != nullptr) { //until the end
		os << now->getValue() << " <- "; //print the value of the now Node
		now = now->getNext(); //get the next Node
	}
	os << now->getValue() << endl; //print the value of the last Node
	return os;
}

void LinkList::printAll() { //print all the members of the List in order
	cout << this;
}

