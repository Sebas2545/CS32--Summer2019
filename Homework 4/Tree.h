/*
 * GUIDE:
 * -Left is lower/smaller
 * -Default left
 *
 */

#ifndef TREE_H_
#define TREE_H_


#include <iostream>
#include <string>
typedef std::string IType;


struct WordNode {
   IType m_data;
   WordNode *m_left;
   WordNode *m_right;

   // You may add additional data members and member functions
   // in WordNode
   int attemptedAdd;

   WordNode(IType data, WordNode* left, WordNode* right) {
	   m_data = data;
	   m_left = left;
	   m_right = right;
	   attemptedAdd = 1; // starts at one, as it should only be created when being added for the first time
   }
};

class WordTree {
private:
	WordNode *root;

	WordNode* findItem(WordNode* currNode, IType item);
	int distinctWordsHelper(WordNode* currNode, int num) const;
	void freeTree(WordNode* currNode);
public:

    WordTree() : root(nullptr) {};
    // copy constructor
    WordTree(const WordTree& rhs);
    // assignment operator
    const WordTree& operator=(const WordTree& rhs);

    void add(IType v);

    int distinctWords() const {int num = 0; distinctWordsHelper(root, num); return num;};

    // Returns the total number of words inserted, including
    // duplicate values
    int totalWords() const;
    // Prints the LinkedList
    friend std::ostream& operator<<(std::ostream &out, const WordTree& rhs);

    ~WordTree() {freeTree(root);};
};


#endif /* TREE_H_ */
