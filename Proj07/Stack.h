/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:
 * Date:
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>

template<class Item>
class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack& original);
	~Stack();
	Stack<Item>& operator=(const Stack<Item>& original);
	bool isEmpty() const;
	bool isFull() const;
	Item& peekTop() const;
	void  push(const Item& it);
	Item& pop();
	unsigned getSize() const;
	unsigned getCapacity() const;
	void setCapacity(unsigned newCapacity);
	
protected:
	void makeCopyOf(const Stack<Item>& original);
	
private:
	unsigned myCapacity;
	unsigned mySize;
	Item*    myArray;
	friend class StackTester;
};



///* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
// * Joel Adams, for CS 112 at Calvin College.
// * Student Name:
// * Date:
// */
//
//#include "Stack.h"
//#include <vector>
//#include "StackException.h"

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
template<class Item>
Stack<Item>::Stack(unsigned capacity) {
	if(capacity ==0){
		throw StackException("Stack(size)", "size must be positive!");
	}
   mySize = 0;
   myCapacity = capacity;
   myArray = new Item[capacity];
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template<class Item>
Stack<Item>::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
template<class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
template<class Item>
Stack<Item>::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
template<class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}
template<class Item>
bool Stack<Item>::isEmpty() const{
	return mySize ==0;
}
template<class Item>
bool Stack<Item>::isFull() const{
	return mySize == myCapacity;
}
template<class Item>
Item& Stack<Item>::peekTop() const{
    if ( isEmpty() ) {
       throw StackException("peekTop()", "stack is empty");
    } else {
       return myArray[mySize - 1];
    }
}
template<class Item>
void Stack<Item>::push(const Item& it){
//	if(mySize == myCapacity){
//		Item* temp = new Item[myCapacity*2];
//		for (unsigned i = 0; i < myCapacity; i++) {
//			temp[i] = myArray[i];
//		}
//		delete [] myArray;
//		myArray = temp;
//		myCapacity = myCapacity*2;
//	}
	if(mySize == myCapacity){
		throw StackException("push()", "Stack is full!");
	}
	else{
	myArray[mySize] = it;
	}
	mySize++;
}
template<class Item>
Item& Stack<Item>::pop(){
	if(mySize == 0){
		throw StackException ("pop()","called on Stack of size 0");
	}
	return myArray[--mySize];
}
template<class Item>
unsigned Stack<Item>::getSize() const{
	return mySize;
}
template<class Item>
unsigned Stack<Item>::getCapacity() const{
	return myCapacity;
}
template<class Item>
void Stack<Item>::setCapacity(unsigned newCapacity){
	if(newCapacity < mySize){
		throw StackException ("setCapacity", "Not allowed to decrease Capacity");
	}else if ( newCapacity == myCapacity){
		return;
	}
	Item * ptr = new Item[newCapacity];
	for(unsigned i = 0; i< mySize; i++){
		ptr[i] = myArray[i];
	}
	myCapacity = newCapacity;
	delete [] myArray;
	myArray = ptr;
}



#endif

