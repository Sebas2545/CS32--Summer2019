#ifndef BBALLROSTER_H_
#define BBALLROSTER_H_

#include <string>

typedef std::string SomeType;


class BballRoster {
private:

	struct Node {
		SomeType value;
		std::string firstName;
		std::string lastName;

		Node* next;
		Node* prev;

		Node() {
			firstName = "zzz";
			lastName = "zzz";
			value = "";
			next = 0;
			prev = 0;
		}

		Node(std::string fName, std::string lName, SomeType val, Node* nex, Node* pre) {
			firstName = fName;
			lastName = lName;
			value = val;
			next = nex;
			prev = pre;
		}
	};

	int size;
	Node dummy;// points to dummy node

public:
	// Create an empty BballRoster list
	BballRoster();

	// Copy Constructor
	BballRoster(const BballRoster&);

	// Deallocates the memory associated with a list
	~BballRoster();

	// Return true if the BballRoster list
	// is empty, otherwise false.
	bool rosterEmpty() const;

	// Return the number of players in
	// the BballRoster list.
	int howManyPlayers() const;

	// If the full name (both the first and last name) is not equal
	// to any full name currently in the list then add it and return
	// true. Elements should be added according to their last name.
	// Elements with the same last name should be added according to
	// their first names. Otherwise, make no change to the list and
	// return false (indicating that the name is already in the
	// list).
	bool signPlayer(const std::string& firstName, const std::string& lastName, const SomeType& value);

	// If the full name is equal to a full name currently in the
	// list, then make that full name no longer map to the value it
	// currently maps to, but instead map to the value of the third
	// parameter; return true in this case. Otherwise, make no
	// change to the list and return false.
	bool resignPlayer(const std::string& firstName, const std::string& lastName, const SomeType& value);

	// If full name is equal to a name currently in the list, then
	// make that full name no longer map to the value it currently
	// maps to, but instead map to the value of the third parameter;
	// return true in this case. If the full name is not equal to
	// any full name currently in the list then add it and return
	// true. In fact, this function always returns true.
	bool signOrResign(const std::string& firstName, const std::string& lastName, const SomeType& value);

	// If the full name is equal to a full name currently in the
	// list, remove the full name and value from the list and return
	// true. Otherwise, make no change to the list and return
	// false.
	bool renouncePlayer(const std::string& firstName, const std::string& lastName);

	// Return true if the full name is equal to a full name
	// currently in the list, otherwise false.
	bool playerOnRoster(const std::string& firstName, const std::string& lastName) const;

	// If the full name is equal to a full name currently in the
	// list, set value to the value in the list that that full name
	// maps to, and return true. Otherwise, make no change to the
	// value parameter of this function and return false.
	bool lookupPlayer(const std::string& firstName, const std::string& lastName, SomeType& value) const;

	// If 0 <= i < size(), copy into firstName, lastName and value
	// parameters the corresponding information of the element at
	// position i in the list and return true. Otherwise, leave the
	// parameters unchanged and return false. (See below for details
	// about this function.)
	bool choosePlayer(int i, std::string& firstName, std::string& lastName, SomeType& value) const;

	// Exchange the contents of this list with the other one.
	void swapRoster(BballRoster& other);
};


bool joinRosters(const BballRoster& bbOne, const BballRoster& bbTwo, BballRoster& bbJoined);

void checkRoster(const std::string& fsearch, const std::string& lsearch, const BballRoster& bbOne, BballRoster& bbResult);


#endif /* BBALLROSTER_H_ */
