/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Jason Pruim
 * Date:
 */

#include "ArrayQueue.h"
#include <cstring>      // memcpy()
#include "QueueException.h"
using namespace std;


ArrayQueue::ArrayQueue(int capacity){
	if(capacity <=0){
		throw QueueException("Queue(int)", "Non positive capacity");
	}
	mySize = 0;
	myArrayPtr = new Item[capacity];
	myCapacity = capacity;
	myFirstIndex = 0;
	myLastIndex =  myCapacity-1;

}


ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

ArrayQueue::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}


ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

unsigned ArrayQueue::getSize() const {
	return mySize;
}
unsigned ArrayQueue::getFirst() const{
	if(isEmpty()){
		throw EmptyQueueException("getFirst()");
	}
	return myArrayPtr[myFirstIndex];
}
unsigned ArrayQueue::getLast() const{
	if(isEmpty()){
		throw EmptyQueueException("getLast()");
	}
	return myArrayPtr[myLastIndex];
}
void ArrayQueue::append(const Item& it){
	if(isFull()){
		throw FullQueueException("append()");
	}
	myLastIndex = (myLastIndex+1) % myCapacity;
	mySize++;
	myArrayPtr[myLastIndex] = it;
}

Item ArrayQueue::remove(){
	if(isEmpty()){
		throw EmptyQueueException("remove()");
	}
	Item value = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex+1) % myCapacity;
	--mySize;
	return value;
}
