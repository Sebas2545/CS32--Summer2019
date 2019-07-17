#include "BballRoster.h"

//TODO -- add assignment operator

BballRoster::BballRoster() {
	size = 0;

	dummy.next = &dummy;
	dummy.prev = &dummy;
}

BballRoster::BballRoster(const BballRoster& copy) {
	size = copy.size;

	dummy.next = &dummy;
	dummy.prev = &dummy;

	Node* ptrCopy = copy.dummy.next; //traverses copy
	Node* ptr = &dummy;

	while(ptr != &(copy.dummy)) {
		Node* temp = new Node(ptrCopy->firstName, ptrCopy->lastName, ptrCopy->value, ptr, ptr->next);
		ptr->next->prev = temp;
		ptr->next = temp;

		ptr = ptr->next;
	}
}

BballRoster::~BballRoster() {
	Node* ptr = dummy.next;
	Node* garbage;

	while(ptr != &dummy) {
		garbage = ptr;
		ptr = ptr->next;
		delete garbage;
	}
}

bool BballRoster::rosterEmpty() const {
	if(size) //true if size is non-zero (roster is not empty)
		return false;
	return true;
}

int BballRoster::howManyPlayers() const {
	return size;
}

bool BballRoster::signPlayer(const std::string& firstName, const std::string& lastName, const SomeType& value) {
	Node* ptr = dummy.next;

	if(ptr == &dummy) {
		Node* temp = new Node(firstName, lastName, value, &dummy, &dummy);
		dummy.next = temp;
		dummy.prev = temp;
		return true;
	}



	while(ptr != &dummy) {
		//already exists
		if((ptr->firstName == firstName) && (ptr->lastName ==lastName))
			return false;

		//if it is in a potential correct position
		if((lastName >= ptr->lastName) && (lastName <= ptr->next->lastName)) {

			//if last names don't match
			//but the position is correct
			if((lastName > ptr->lastName) && (lastName < ptr->next->lastName)) {
				Node* temp = new Node(firstName, lastName, value, ptr->next, ptr);
				temp->next->prev = temp;
				ptr->next = temp;
				++size;

				return true;
			}

			//if last name is the same, wait until first names are in correct position
			if((lastName == ptr->lastName) && (lastName == ptr->next->lastName))
				if((firstName >= ptr->firstName) && (firstName <= ptr->next->firstName)) {

					Node* temp = new Node(firstName, lastName, value, ptr, ptr->next);
					ptr->next->prev = temp;
					ptr->next = temp;
					++size;

					return true;
				}
		}

		ptr = ptr->next;
	}

	throw std::logic_error("Fully traversed list");
}

bool BballRoster::resignPlayer(const std::string& firstName, const std::string& lastName, const SomeType& value) {
	Node* ptr = dummy.next;

	while(ptr != &dummy) {
		if((ptr->firstName == firstName) && (ptr->lastName ==lastName)) {
			ptr->value = value;
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

bool BballRoster::signOrResign(const std::string& firstName, const std::string& lastName, const SomeType& value) {
	Node* ptr = dummy.next;

	if(ptr == &dummy) {
		Node* temp = new Node(firstName, lastName, value, &dummy, &dummy);
		dummy.next = temp;
		dummy.prev = temp;
		return true;
	}



	while(ptr != &dummy) {
		//already exists
		if((ptr->firstName == firstName) && (ptr->lastName ==lastName)) {
			ptr->value = value;
			return true;
		}

		//if it is in a potential correct position
		if((lastName >= ptr->lastName) && (lastName <= ptr->next->lastName)) {

			//if last names don't match
			//but the position is correct
			if((lastName > ptr->lastName) && (lastName < ptr->next->lastName)) {
				Node* temp = new Node(firstName, lastName, value, ptr->next, ptr);
				temp->next->prev = temp;
				ptr->next = temp;
				++size;

				return true;
			}

			//if last name is the same, wait until first names are in correct position
			if((lastName == ptr->lastName) && (lastName == ptr->next->lastName))
				if((firstName >= ptr->firstName) && (firstName <= ptr->next->firstName)) {

					Node* temp = new Node(firstName, lastName, value, ptr, ptr->next);
					ptr->next->prev = temp;
					ptr->next = temp;
					++size;

					return true;
				}
		}

		ptr = ptr->next;
	}

	throw std::logic_error("Fully traversed list");



	return true;
}

bool BballRoster::renouncePlayer(const std::string& firstName, const std::string& lastName) {
	Node* ptr = dummy.next;

	while(ptr != &dummy) {
		if((ptr->firstName == firstName) && (ptr->lastName ==lastName)) {
			Node* garbage = ptr;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;

			delete garbage;

			return true;
		}
		ptr = ptr->next;
	}

	return false;
}

bool BballRoster::playerOnRoster(const std::string& firstName, const std::string& lastName) const {
	Node* ptr = dummy.next;

	while(ptr != &dummy) {
		if((ptr->firstName == firstName) && (ptr->lastName ==lastName))
			return true;

		ptr = ptr->next;
	}
	return false;
}

bool BballRoster::lookupPlayer(const std::string& firstName, const std::string& lastName, SomeType& value) const {
	Node* ptr = dummy.next;

	while(ptr != &dummy) {
		if((ptr->firstName == firstName) && (ptr->lastName ==lastName)) {
			value = ptr->value;
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

bool BballRoster::choosePlayer(int i, std::string& firstName, std::string& lastName, SomeType& value) const {
	if(i >= size)
		return false;

	Node* ptr = dummy.next;

	for(int j = 0; j < i; ++j)
		ptr = ptr->next;

	firstName = ptr->firstName;
	lastName = ptr->lastName;
	value = ptr->value;

	return true;
}

void BballRoster::swapRoster(BballRoster& other) {
	int temp = size;
	size = other.size;
	other.size = temp;

	Node* ptrTemp = other.dummy.next;
	other.dummy.next = dummy.next;
	dummy.next = ptrTemp;

	ptrTemp = other.dummy.prev;
	other.dummy.prev = dummy.prev;
	dummy.prev = ptrTemp;
}

//don't forget to delete the original list in bbJoined before adding to it
bool joinRosters(const BballRoster& bbOne, const BballRoster& bbTwo, BballRoster& bbJoined) {


	return false;
}

//careful of aliasing, bbOne and bbResult are the same list
void checkRoster(const std::string& fsearch, const std::string& lsearch, const BballRoster& bbOne, BballRoster& bbResult) {

}
