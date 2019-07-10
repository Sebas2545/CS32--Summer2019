#include "LinkedList.h"

LinkedList::LinkedList() {
	head = 0;
	items = 0;
}

LinkedList::LinkedList(const LinkedList& prev) {
	items = prev.items; // assigns correct num of items

	Node* ptrPrev = prev.head; // traversal pointer (values for new list)

	head = new Node(ptrPrev->value, 0); //creates first node
	ptrPrev = ptrPrev->next;

	Node* ptr = head; // traversal pointer(new list itself)
	while(ptrPrev != 0) {
		ptr->next =  new Node(ptrPrev->value, 0);
		ptr = ptr->next;
		ptrPrev = ptrPrev->next;
	}

}

LinkedList::~LinkedList() {
	Node* ptr = head;
	Node* next = ptr->next;

	while(ptr != 0) {
		delete ptr;
		ptr = next;

		if(next != 0)
			next = next->next;
	}
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs) {
	//deallocates memory if list is already filled
	if(items > 0) {
		Node* garbage = head;
		Node* next = head->next;

		while(next != 0) {
			delete garbage;
			garbage = next;
			next = next->next;
		}
		head = 0; //prevents dangling pointers
	}


	items = rhs.items; // assigns correct num of items

	Node* ptrRhs = rhs.head; // traversal pointer

	head = new Node(ptrRhs->value, head); //creates first node
	ptrRhs = ptrRhs->next;

	Node* ptr = head; // traversal  pointer
	while(ptrRhs != 0) {
		ptr->next =  new Node(ptrRhs->value, 0);
		ptr = ptr->next;
		ptrRhs = ptrRhs->next;
	}

	return rhs;
}

void LinkedList::insertToFront(const ItemType& val) {
	head = new Node(val, head);
	++items;
}

void LinkedList::printList() {
	Node* ptr = head;
	while(ptr != 0) {
		std::cout << ptr->value << std::endl;
		ptr = ptr->next;
	}
}

bool LinkedList::get(int i, ItemType& item) const {
	int pos = 1;
	Node* ptr = head;

	//if i is larger than the size of the list, return false
	if(i > items)
		return false;

	//traverse the list, until you hit
	while(ptr != 0) {
		if(i == pos)
			item = ptr->value;
		ptr = ptr->next;
		++pos;
	}

	return true;
}

Node* LinkedList::reverse(Node* ptr, Node* next) {
	Node* temp = next->next;
	next->next = ptr;

	if(temp != 0)
		return reverse(next, temp);

	head = next;
	return 0;
}

void LinkedList::reverseList() {
	//returns if reversal is trivial
	if(items == 0 || items == 1)
		return;

	Node* temp = head;
	reverse(head, head->next);

	//assigns what was the first node
	//what is now the last node
	//to point to the null pointer
	temp->next = 0;
}

void LinkedList::printReverse() const {
	LinkedList temp(*this);
	temp.reverseList();
	temp.printList();
}

void LinkedList::append(const LinkedList& other) {
	Node* otherPtr = other.head;
	Node* ptr = head;

	//if list is empty
	if(ptr == 0) {
		head = new Node(otherPtr->value, head);
		ptr = head;
		otherPtr = otherPtr->next;
	}

	//traverses the list until pointing at the last node
	while(ptr->next != 0)
		ptr = ptr->next;

	items += other.items;

	while(otherPtr != 0) {
		ptr->next =  new Node(otherPtr->value, 0);
		ptr = ptr->next;
		otherPtr = otherPtr->next;
	}

}

void LinkedList::swap(LinkedList& other) {
	Node* temp = head;
	head = other.head;
	other.head = temp;

	int intTemp = items;
	items = other.items;
	other.items = intTemp;
}







