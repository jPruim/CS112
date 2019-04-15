/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:
 * Date:
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template <class Item>

class BST {
public:
	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;
	void insert(const Item& item);
	bool contains(const Item& item) const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

	unsigned getHeight();

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void nodeInsert(const Item& item);
            bool nodeContains(const Item& item)const;

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            unsigned getHeight();
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};
template <class Item>

BST<Item>::BST(){
	myRoot = NULL;
	myNumItems = 0;
}
template <class Item>

BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}
template <class Item>

BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

template <class Item>

BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}
template <class Item>

bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}
template <class Item>

unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}
template <class Item>

void BST<Item>::insert(const Item& item){
	if (isEmpty()){
		myRoot = new Node(item);
	}else{
		myRoot->nodeInsert(item);
	}
	myNumItems ++;
}
template<class Item>
void BST<Item>::Node::nodeInsert(const Item& item){
	if(item < myItem){
		if (myLeft == NULL){
			myLeft = new Node(item);
		}else{
			myLeft->nodeInsert(item);
		}
	}else if(item > myItem){
		if (myRight == NULL){
			myRight = new Node(item);
		}else{
			myRight->nodeInsert(item);
		}
	}else if(item == myItem){
		throw (invalid_argument("Item already in BST"));
	}

}
template<class Item>

bool BST<Item>::contains(const Item& item)const{
	if (isEmpty()){
		return false;
	}else{
		return myRoot->nodeContains(item);
	}
}
template<class Item>
bool BST<Item>::Node::nodeContains(const Item& item) const{
	if(myItem == item){
		return true;
	}
	else if(item < myItem){
		if (myLeft == NULL){
			return false;
		}else{
			return myLeft->nodeContains(item);
		}
	}
	else{
		if (myRight == NULL){
			return false;
		}else{
			return myRight->nodeContains(item);
		}
	}
}

template<class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}
template <class Item>

void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}
template <class Item>

void BST<Item>::Node::processItem() {
		cout << ' ' << myItem << flush;
}
template <class Item>

void BST<Item>::traversePostorder(){
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}
template <class Item>

void BST<Item>::Node::traversePostorder() {

	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}
template <class Item>

void BST<Item>::traverseInorder(){
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}
template <class Item>
void BST<Item>::Node::traverseInorder(){
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}

}
/* BST get height
 * @param: none
 * return: unsigned
 * goal: to return the height of a tree, uses recursion
 * creator: Jason Pruim
 */
template <class Item>
unsigned BST<Item>::getHeight(){
	if ( !isEmpty() ) {
		return myRoot->getHeight();
	}
	else {
		return 0;
	}
}
/* Node get height
 * @param: none
 * return: unsigned
 * goal: to return the maximum height of a all branches attached a node, uses recursion
 * creator: Jason Pruim
 */
template <class Item>
unsigned BST<Item>::Node::getHeight(){
	unsigned left = 0;
	unsigned right = 0;
	if (myLeft != NULL) {
		left = myLeft->getHeight();
	}
	if (myRight != NULL) {
		right = myRight->getHeight();
	}
	return max(left, right)+1;

}

#endif /*BST_H_*/

