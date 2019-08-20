#include "Tree.h"

#include <iostream>
#include <string>
typedef std::string IType;



//TODO--Copy Constructor
WordTree::WordTree(const WordTree& rhs) {
	root = 0;
}

WordNode* WordTree::findItem(WordNode* currNode, IType item) {
	if(currNode == 0) // if you hit a dead end, return
		return 0;
	if(currNode->m_data == item) // if you find the value, return
		return currNode;
	if(item > currNode->m_left->m_data) // if item is greater than left, go right
		return findItem(currNode->m_right, item);

	return findItem(currNode->m_right, item); // else, go left
}

WordNode* WordTree::helpAdd(WordNode* currNode, IType item) {
	if(currNode == 0)
		throw(std::logic_error("Cannot Add"));
	if(item > currNode->m_left->m_data) { //checks left hand side
		if(currNode->m_right == 0) { //if right is empty, add new node
			currNode->m_right = new WordNode(item, 0, 0);
			return 0;
		}
		else if(currNode->m_right->m_data == item) { // if node with item already exists, increment add attempts
			++currNode->m_right->attemptedAdd;
			return 0;
		}
		else {
			return helpAdd(currNode->m_right, item);
		}
	}
	else {


	}
}

void WordTree::add(IType value) {
	if(root == 0) // if the tree is empty, add the root
		root = new WordNode(value, 0, 0);




}
