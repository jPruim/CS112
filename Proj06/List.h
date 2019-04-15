/*
 * List.h
 *
 *  Created on: Oct 10, 2017
 *      Author: Jason Pruim
 */


#ifndef LIST_H_
#define LIST_H_
#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;
template<class Item>
class List {
public:
	List();
	~List();
	List(const List<Item>& original);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item it);
	List<Item>& operator=(const List<Item>& original);
	bool operator!=(const List<Item>& l2) const;
	bool operator==(const List<Item>& l2) const;
	void writeTo(ostream & out, const string& str)const;
	void writeTo(const string& filename) const;
	void readFrom(istream& in);
	void readFrom(const string& filename);
	int getIndexOf(const Item & it) const;
	Item remove(int index);
	void insert(const Item & it, int index);
	void prepend(const Item& it);
	bool insertBefore(const Item& them, const Item& me);
	bool insertAfter(const Item& them, const Item& me);
	ostream& operator<<(ostream& os);



private:
	struct Node{
		Item myItem;
		Node* myNext;
		Node();
		Node(Item it, Node* next);
		~Node();
		void setPtr(Node* ptr);

		friend class ListTester;
	};
	unsigned mySize;
	Node* myFirst;
	Node* myLast;

	void makeListCopy(const List<Item>& original);

	friend class ListTester;
};




template<class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = myLast = NULL;

}
template<class Item>
void List<Item>::makeListCopy(const List<Item>& original) {
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
template<class Item>
List<Item>::List(const List<Item>& original) {
	makeListCopy(original);
}
template<class Item>
List<Item>::~List(){
	delete myFirst; // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}
template<class Item>
List<Item>::Node::Node(){
	myItem = Item();
	myNext = NULL;
}
template<class Item>
List<Item>::Node::Node(Item it, Node* next){
	myItem = it;
	myNext = next;
}
template<class Item>
List<Item>::Node::~Node(){
//	   cout << "~Node() is deallocating the node containing item "
//	             << myItem << endl;
	delete myNext;
	myNext = NULL;
}
template<class Item>
unsigned List<Item>::getSize() const{
	return mySize;
}
template<class Item>
Item List<Item>::getFirst() const{
	if (myFirst != NULL) {
		return myFirst->myItem;
	} else {
		throw underflow_error("Called get First on an empty list");
	}
}
template<class Item>
Item List<Item>::getLast() const{
	if (myLast != NULL) {
		return myLast->myItem;
	} else {
		throw underflow_error("Called get Last on an empty list");
	}
}
template<class Item>
void List<Item>::Node::setPtr(Node* ptr){
	//myNext = ptr;
}
template<class Item>
void List<Item>::append(const Item it){
	Node* nodePtr = new Node(it,NULL);
	mySize ++;
	if (myFirst == NULL){
		myFirst = myLast = nodePtr;
	}else{
		myLast->myNext = nodePtr;
		myLast = nodePtr;
	}
}
template<class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {
	if(myFirst != original.myFirst){
		delete myFirst;
		this->makeListCopy(original);
	}
	return *this;
}
/* operator!=
 * @param:const list &
 * return: bool
 * goal: to determine if the list is different from this
 * creator: Jason Pruim
 */
template<class Item>
bool List<Item>::operator!=(const List<Item>& l2) const{
	if (mySize != l2.mySize)
	{
		//cout<<"Different Sized"<<flush;
		return true;
	}
	else if(!mySize){
		//cout<<"Size is 0"<< flush;
		return false;
	}
	Node * ptr = myFirst;
	Node * ptrl2 = l2.myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		if (ptr->myItem == ptrl2->myItem) {
			ptr = ptr->myNext;
			ptrl2 = ptrl2->myNext;
		}else{
//			cout<<ptr->myItem<<"\t"<<ptrl2->myItem<<flush;
//			cout<<"Returned true in for loop"<<flush;
			return true;
		}
	}
	//cout<<"failed test"<<flush;
	return false;
}
/* operator==
 * @param:const list &
 * return: bool
 * goal: to determine if the list is the same as this (by Node item values, NOT node pointers
 */
template<class Item>
bool List<Item>::operator==(const List<Item>& l2) const{
	//Quicker way of doing it
//	if(l2!=*this){return false;}
//	return true;
    //if both lists are empty
    if (mySize == 0 and l2.mySize == 0) {
        return true;
    }

    // if one list is empty or  if both lists have different sizes
    else if (mySize != l2.mySize){
        return false;
    }

    else {
        Node* ptr1= myFirst;
        Node* ptr2 =l2.myFirst;

        while(ptr1) {
            if(ptr1-> myItem != ptr2->myItem) {
                return false;
            }
            ptr1 = ptr1->myNext;
            ptr2 = ptr2->myNext;

    }
    return true;
    }

}
/* write to stream
 * @param:ostream&
 * return:
 * goal: write out values separated by tabs
 * creator: Jason Pruim
 */
template<class Item>
void List<Item>::writeTo(ostream& out, const string& str) const{
	Node* ptr = myFirst;
	for( unsigned i= 0; i < mySize; i++){
		out<< ptr->myItem<<flush;
		if(i + 1 != mySize){
			out<< str <<flush;
		}
		ptr= ptr->myNext;
	}
}
/* write to file
 * @param:const string&
 * return:
 * goal: write out values separated by new lines
 */
template<class Item>
void List<Item>::writeTo(const string& filename) const{
	ofstream fout(filename.c_str());
	assert(fout.is_open());
	Node* ptr = myFirst;
	for( unsigned i= 0; i < mySize; i++){
		fout<< ptr->myItem<<flush;
		if(i + 1 != mySize){
			fout<< "\n"<<flush;
		}
		ptr= ptr->myNext;
	}
	fout.close();
}

/* readFrom stream
 * @param:const istream&
 * return:
 * goal: read values separated by tabs, terminate at end of line
 * creator: Jason Pruim
 */
template<class Item>
void List<Item>::readFrom( istream& in) {
	unsigned numVal;
	string line;
	getline(in, line);
	istringstream iss(line);

	while (iss >> numVal) {
		in >> numVal;
		this->append(numVal);
	}
}

/* readFrom file
 * @param:const string&
 * return:
 * goal: read from file until end
 * creator: Jason Pruim
 */
template<class Item>
void List<Item>::readFrom(const string& filename){
	ifstream fin(filename.c_str());
	delete myFirst;
	myFirst =myLast= NULL;
	mySize = 0;
	Item a;
	while(!fin.eof()){
		fin>> a;
		this->append(a);
	}
	fin.close();
}
/* getIndexOf
 * @param:const Item&
 * return: int
 * goal: return index of the first occurrence of the param. -1 if it doesn't show up
 * creator: Jason Pruim
 */
template<class Item>
int List<Item>::getIndexOf(const Item& it) const{
	Node * ptr = myFirst;
	for(unsigned i = 0; i < mySize; i++){
		if(ptr->myItem == it){
			return i;
		}
		ptr = ptr->myNext;
	}
	return -1;
}


/* remove
 * @param: int index
 * return: Item
 * goal: to remove what ever Item is at index and return it
 * negative indices are equivalent to 0, to big indices return the last Item;
 * creator: Jason Pruim
 */
template<class Item>
Item List<Item>::remove(int index) {
	Node * ptr = myFirst;
	Item value;
	if(mySize == 0){
		//removing from empty list
		throw underflow_error("No item to remove");
	}
	else if(mySize ==1){
		//removing last item
		value = myFirst->myItem;
		myFirst->myNext = NULL;
		myFirst = myLast = NULL;

	} else if(index <= 0){
		//min index
		value = myFirst->myItem;
		myFirst = myFirst->myNext;
		ptr->myNext = NULL;
	}else if (index >= int(mySize-1)){
		//max index
//		for(unsigned i = 0; i < mySize; i++){
//			if(i == mySize-1){
//				value = myLast->myItem;
//				ptr->myNext = NULL;
//				//myLast->myNext = NULL;
//				delete myLast;
//			}
//			ptr = ptr->myNext;
//		}
		for (unsigned i = 0; i < mySize - 2; i++) {
			ptr = ptr->myNext;
		}
		//cout<<ptr->myItem<<endl;
		value = myLast->myItem;
		assert(myLast !=ptr);
		assert(ptr->myNext == myLast);
		myLast = ptr;
		//cout<<myLast->myItem<<endl;

		//cout<<myLast->myItem<<endl;
		ptr = ptr->myNext;
		myLast->myNext = NULL;
		//cout<<myLast->myItem<<endl;

	}
	else{	//index in middle
		Node * prevPtr = myFirst;
		for (unsigned i = 0; i < mySize; i++) {
			if (int(i) == index) {
				value = ptr->myItem;
				prevPtr->myNext = ptr->myNext;
				ptr->myNext = NULL;
				break;
			}
			prevPtr = ptr;
			ptr = ptr->myNext;
		}
	}
	//Things to always do
	delete ptr;
	mySize --;
	return value;
}
/* Insert
 * @param:const Item&, int index
 * return:
 * goal: insert Item at index
 * creator: Daniel
 */
template<class Item>
void List<Item>::insert(const Item& it, int index){
	Node* ptr = new Node(it, NULL);
	if(mySize == 0){
		//size of zero
		myFirst = myLast = ptr;
	}else if (index <=0){
		//min index
		ptr->myNext= myFirst;
		myFirst = ptr;
	}else if (index >= int(mySize)){
		//max
		myLast->myNext = ptr;
		myLast= ptr;
	}else{
		//middle index
		Node* afterPtr = myFirst;
		Node* prevPtr =myFirst;
		for(int i = 1; i< int(mySize); i ++){
			afterPtr = afterPtr->myNext;
			if(i == index){
				ptr->myNext = afterPtr;
				prevPtr->myNext = ptr;
				break;
			}
			prevPtr = afterPtr;
		}
	}
	mySize++;
}
/* prepend
 * @param:const Item& it
 * return:
 * goal: insert Item at beginning
 * creator: Daniel
 */
template<class Item>
void List<Item>::prepend(const Item& it){
    if(mySize !=0){

    Node* ptr = new Node(it, NULL);
    ptr->myNext = myFirst;
    myFirst = ptr;
    }
    else{


        Node* ptr = new Node(it, NULL);
        ptr->myNext = myFirst;
        myFirst = ptr;
        myLast = ptr;
    }
    mySize++;
}
/* InsertBefore
 * @param:const Item& them, const Item& me
 * return:
 * goal: insert me before them
 * creator: Jason
 */
template<class Item>
bool List<Item>::insertBefore(const Item& them, const Item& me){
	if (mySize == 0){
		return false;
	}
	Node* ptr = new Node(me, NULL);
	if(myFirst->myItem == them){
		ptr->myNext = myFirst;
		myFirst = ptr;
		mySize++;
		return true;
	}
	Node* afterPtr = myFirst;
	Node* prevPtr =myFirst;
	for(int i = 1; i< int(mySize); i ++){
		afterPtr = afterPtr->myNext;
		if(afterPtr->myItem == them){
			ptr->myNext = afterPtr;
			prevPtr->myNext = ptr;
			mySize++;
			return true;
		}
		prevPtr = afterPtr;
	}
	//cout<<"end of loop"<<flush;
	return false;
}
/* InsertAfter
 * @param:const Item& them, const Item& me
 * return:
 * goal: insert me after them
 * creator: Jason
 */
template<class Item>
bool List<Item>::insertAfter(const Item& them, const Item& me){
	if (mySize == 0){
		return false;
	}
	Node* ptr = new Node(me, NULL);
	if(myLast->myItem == them){
		myLast = myLast->myNext = ptr;
		mySize++;
		return true;
	}
	Node* afterPtr = myFirst;
	for(int i = 0; i< int(mySize); i ++){
		if(afterPtr->myItem == them){
			ptr->myNext = afterPtr->myNext;
			afterPtr->myNext = ptr;
			mySize++;
			return true;
		}
		afterPtr = afterPtr->myNext;
	}
	return false;
}

/* ostream& operator<<
 * @param:ostream&, List<Item>
 * return:
 * goal: write list items to ostream&
 * creator: Jason
 */
template<class Item>
ostream& operator<<(ostream& os, List<Item> l){
	l.writeTo(os, "=>");
    return os;
}
/*
 *
 * Code attempts below
 *
 *
 */

//Item List::remove(int index) {
//	Node * ptr = myFirst;
//	Item value;
//	if(mySize == 0){
//		throw underflow_error("No item to remvoe");
//	}
//	if(mySize ==1){
//		value = myFirst->myItem;
//		myFirst->myNext = NULL;
//		myFirst = myLast = NULL;
//		delete ptr;
//		mySize = 0;
//		return value;
//	}
//	if(index <= 0){
//		value = myFirst->myItem;
//		myFirst = myFirst->myNext;
//		ptr->myNext = NULL;
//		delete ptr;
//		mySize -=1;
//		return value;
//	}
//	else if (index >= mySize-1){
//		index = mySize-1;
//		for(unsigned i = 0; i < mySize; i++){
//			if(i == mySize-1){
//				value = myLast->myItem;
//				ptr->myNext = NULL;
//				myLast->myNext = NULL;
//				delete myLast;
//				myLast = ptr;
//				mySize -=1;
//				return value;
//			}
//			ptr = ptr->myNext;
//		}
//	}
//	Node * prevPtr = myFirst;
//	for(unsigned i = 0; i < mySize; i++){
//		if(i ==index){
//			//cout<<prevPtr->myItem<<endl;
//			//cout<<ptr->myItem<< endl;
//			value = ptr->myItem;
//			prevPtr->myNext = ptr->myNext;
//			ptr->myNext = NULL;
//			delete ptr;
//			mySize -=1;
//			return value;
//		}
//		prevPtr = ptr;
//		ptr = ptr->myNext;
//	}
//}
//void List::readFrom(const string& filename){
	/*
	 * Fun yolo method of doing this operator
	 */
//	ifstream fin(filename.c_str());
//	List list0;
//	list0.readFrom(fin);
//	fin.close();
//	list0.writeTo("extra.txt");
//	ifstream fin2("extra.txt");
//	this->readFrom(fin2);
//	fin2.close();
	//more normal way
//	ifstream fin(filename.c_str());
//	Item a;
//	unsigned n = 0;
//	char x = fin.peek();
//	bool more = false;
//	if(x != '\n'){ more = true;}
//	while(( fin.peek( ) != '\n' ) || ( fin.peek( ) != '\r' )){
//		fin>>a;
//		this->append(a);
//		if(x != '\n'){ more = true;}
//		else{ more = false;}
//		if(n >10){
//			//more = false;
//			cout<<"breaked"<<endl;
//			break;
//		}
////		n++;
//	ifstream fin(filename.c_str());
//	this->readFrom(fin);
//}

//void List::readFrom(istream& in){
//	delete myFirst;
//	myFirst =myLast= NULL;
//	mySize = 0;
//	char ch;
////	in >> noskipws;
//	Item a;
//	int i = 0;
//	while(in.peek()){
//		ch = in.peek();
//	//	cout<<ch;
//		if(ch =='ÿ'){
//			if(!in.get(ch)){
//				break;
//			}else{
//				in.putback(ch);
//			}
//		}
//		i++;
//		if (i>10){break;}
//		in>> a;
//	//	cout <<a;
//		this->append(a);
//
//	}
//
//}
//template<class Item>
//ostream& List<Item>::operator>>(ostream& os){
//	Node* ptr = myFirst;
//	for( unsigned i= 0; i < mySize; i++){
//		os<< ptr->myItem<<flush;
//		if(i + 1 != mySize){
//			os<< "=>"<<flush;
//		}
//		ptr= ptr->myNext;
//	}
//    return os;
//}



#endif /* LIST_H_ */
