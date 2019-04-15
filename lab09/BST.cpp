/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:
 * Date:
 */
 
#include "BST.h"

BST::BST(){
	myRoot = NULL;
	myNumItems = 0;
}
BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::insert(const Item& item){
	if (isEmpty()){
		myRoot = new Node(item);
	}else{
		myRoot->nodeInsert(item);
	}
	myNumItems ++;
}

void BST::Node::nodeInsert(const Item& item){
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

bool BST::contains(const Item& item)const{
	if (isEmpty()){
		return false;
	}else{
		return myRoot->nodeContains(item);
	}
}

bool BST::Node::nodeContains(const Item& item) const{
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


void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
		cout << ' ' << myItem << flush;
}
void BST::traversePostorder(){
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

void BST::Node::traversePostorder() {

	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}
void BST::traverseInorder(){
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}
void BST::Node::traverseInorder(){
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}

}

unsigned BST::getHeight(){
	if ( !isEmpty() ) {
		return myRoot->getHeight();
	}
	else {
		return 0;
	}
}




unsigned BST::Node::getHeight(){
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
