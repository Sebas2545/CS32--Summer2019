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

void WordTree::add(IType v) {
	if(root == 0) // if the tree is empty, add the root
		root = new WordNode(v, 0, 0);

	WordNode* currNode = root;
	for(;;) {
		if(v == currNode->m_data)
			return;
		if(currNode->m_data > v) {
			if(currNode->m_left != 0) {
				currNode = currNode->m_left;
			}
			else {
				currNode->m_left = new WordNode(v, 0, 0);
				return;
			}
		}
		else if(currNode->m_data < v) {
			if(currNode->m_right != 0) {
				currNode = currNode->m_right;
			}
			else{
				currNode->m_right = new WordNode(v, 0, 0);
				return;
			}
		}
	}
}


const WordTree& WordTree::operator=(const WordTree& rhs) {

}

int WordTree::distinctWordsHelper(WordNode* currNode, int num) const {
	if(currNode == 0)
		return num;

	int num1 = distinctWordsHelper(currNode->m_left, num + 1);

	int num2 = distinctWordsHelper(currNode->m_right, num + 1);

	return num1 + num2;
}

void WordTree::freeTree(WordNode* currNode) {
	if(currNode == 0)
		return;

	freeTree(currNode->m_left);

	freeTree(currNode->m_right);

	delete currNode;
}

