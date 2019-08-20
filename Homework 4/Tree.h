/*
 *
 * GUIDE:
 * -Left is lower/smaller
 * -Default left
 *
 *
 *
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
	WordNode* helpAdd(WordNode* currNode, IType item);
public:
	// default constructor
    WordTree() : root(nullptr) {};
    // copy constructor
    WordTree(const WordTree& rhs);
    // assignment operator
    const WordTree& operator=(const WordTree& rhs);
    // Inserts v into the WordTree
    void add(IType v);
    // Returns the number of distinct words / nodes
    int distinctWords() const;

    // Returns the total number of words inserted, including
    // duplicate values
    int totalWords() const;
    // Prints the LinkedList
    friend std::ostream& operator<<(std::ostream &out, const WordTree& rhs);
    // Destroys all the dynamically allocated memory in the
    // tree
    ~WordTree();
};


#endif /* TREE_H_ */
