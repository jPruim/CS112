/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 * 
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "ArrayQueue.h"
#include <cstring>      // memcpy()
#include "QueueException.h"

template<class Item>
 
class ArrayQueue {
public:
	ArrayQueue( int capacity);
	ArrayQueue(const ArrayQueue& original);
	virtual ~ArrayQueue();
	ArrayQueue& operator=(const ArrayQueue& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;
	unsigned getFirst() const;
	unsigned getLast() const;
	void append( const Item& it);
	Item remove();
	void setCapacity(unsigned newCapcity);


protected:
//	virtual void makeCopyOf(const ArrayQueue& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirstIndex; // index of oldest item (if any)
	unsigned myLastIndex;  // index of newest item (if any)
	Item*    myArrayPtr;   // dynamic array of items
	void makeCopyOf(const ArrayQueue& original);

	friend class ArrayQueueTester;
};






template<class Item>
ArrayQueue<Item>::ArrayQueue(int capacity){
	if(capacity <=0){
		throw QueueException("Queue(int)", "Non positive capacity");
	}
	mySize = 0;
	myArrayPtr = new Item[capacity];
	myCapacity = capacity;
	myFirstIndex = 0;
	myLastIndex =  myCapacity-1;

}

template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}
template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}
template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}

template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}
template<class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}
template<class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}
template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}
template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}
template<class Item>
unsigned ArrayQueue<Item>::getFirst() const{
	if(isEmpty()){
		throw EmptyQueueException("getFirst()");
	}
	return myArrayPtr[myFirstIndex];
}
template<class Item>
unsigned ArrayQueue<Item>::getLast() const{
	if(isEmpty()){
		throw EmptyQueueException("getLast()");
	}
	return myArrayPtr[myLastIndex];
}
template<class Item>
void ArrayQueue<Item>::append(const Item& it){
	if(isFull()){
		throw FullQueueException("append()");
	}
	myLastIndex = (myLastIndex+1) % myCapacity;
	mySize++;
	myArrayPtr[myLastIndex] = it;
}
template<class Item>
Item ArrayQueue<Item>::remove(){
	if(isEmpty()){
		throw EmptyQueueException("remove()");
	}
	Item value = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex+1) % myCapacity;
	--mySize;
	return value;
}
template<class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity){
	if(newCapacity==0 || newCapacity< getSize()){
		throw QueueException("setCapaciy","New Capacity is too small");
	}
	Item* temp = new Item[newCapacity];
	if (mySize != 0) {
		for (unsigned i = 0; i < getSize(); i++) {
			temp[i] = myArrayPtr[ (myFirstIndex + i ) % myCapacity];
		}
	}
	myFirstIndex = 0;
	myLastIndex = getSize()-1;
	delete [] myArrayPtr;
	myArrayPtr = temp;
	myCapacity = newCapacity;
}

#endif /*ARRAY_QUEUE_H_*/
