/*
 * List.cpp
 *
 *  Created on: Oct 10, 2017
 *      Author: jrp27
 */

#include "List.h"
#include <cassert>
#include <iostream>
using namespace std;

List::List() {
	mySize = 0;
	myFirst = myLast = NULL;

}

void List::makeListCopy(const List& original) {
	myFirst = myLast = NULL; //  set pointers
	mySize = 0; //   and size to 'empty' values
	if (original.getSize() > 0) {
		//  if there are nodes to copy:
		Node* oPtr = original.myFirst; //  start at the first node
		while (oPtr != NULL) {
			//  while there are more nodes:
			append(oPtr->myItem); //   append the item in that node
			oPtr = oPtr->myNext; //   advance to next node
		}
	}
}

List::List(const List& original) {
	makeListCopy(original);
}
List::~List(){
	delete myFirst; // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}
List::Node::Node(){
	myItem = Item();
	myNext = NULL;
}
List::Node::Node(Item it, Node* next){
	myItem = it;
	myNext = next;
}
List::Node::~Node(){
//	   cout << "~Node() is deallocating the node containing item "
//	             << myItem << endl;
	delete myNext;
	myNext = NULL;
}
unsigned List::getSize() const{
	return mySize;
}
Item List::getFirst() const{
	if (myFirst != NULL) {
		return myFirst->myItem;
	} else {
		throw underflow_error("Called get First on an empty list");
	}
}
Item List::getLast() const{
	if (myLast != NULL) {
		return myLast->myItem;
	} else {
		throw underflow_error("Called get Last on an empty list");
	}
}
void List::Node::setPtr(Node* ptr){
	//myNext = ptr;
}
void List::append(const Item it){
	Node* nodePtr = new Node(it,NULL);
	mySize ++;
	if (myFirst == NULL){
		myFirst = myLast = nodePtr;
	}else{
		myLast->myNext = nodePtr;
		myLast = nodePtr;
	}
}
List& List::operator=(const List& original) {
	if(myFirst != original.myFirst){
		delete myFirst;
		this->makeListCopy(original);
	}
	return *this;
}




