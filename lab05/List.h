/*
 * List.h
 *
 *  Created on: Oct 10, 2017
 *      Author: jrp27
 */

#ifndef LIST_H_
#define LIST_H_

typedef double Item;
class List {
public:
	List();
	~List();
	List(const List& original);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item it);
	List& operator=(const List& original);

private:
	struct Node{
		Item myItem;
		Node* myNext;
		Node();
		Node(Item it, Node* next);
		~Node();
		void setPtr(Node* ptr);
	};
	unsigned mySize;
	Node* myFirst;
	Node* myLast;

	void makeListCopy(const List& original);

	friend class ListTester;
};

#endif /* LIST_H_ */
