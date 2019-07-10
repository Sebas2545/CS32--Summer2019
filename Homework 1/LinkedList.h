#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#include <iostream>
#include <string>

typedef std::string ItemType;

struct Node {
	ItemType value;
	Node* next;
	Node(ItemType val, Node* ptr) {
		next = ptr;
		value = val;
	}
};

class LinkedList {
private:
	int items;
	Node* head;

	//recursive implementation of list reversal
	Node* reverse(Node* ptr, Node* next);

public:
	//default constructor
	LinkedList();

	//copy constructor
	LinkedList(const LinkedList&);

	//destructor
	~LinkedList();

	//assignment operator
	const LinkedList& operator=(const LinkedList& rhs);

	//inserts value to front
	void insertToFront(const ItemType& val);

	//prints list
	void printList();

	//sets value  to  item at position i, returns true
	//if position i doesn't exist, returns false
	bool get(int i, ItemType& item) const;

	//reverses the order of the list
	void reverseList();

	//Prints the list in reverse order
	void printReverse() const;

	//Appends the values of other to the list
	void append(const LinkedList& other);

	//swaps two lists
	void swap(LinkedList& other);

	//returns the size of the list
	int size() const {return items;}

};

#endif /* LINKEDLIST_H_ */
