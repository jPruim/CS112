/* Student Name: Jason Pruim and Casey Purtill
 * Date: Sept 26, 2017
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

template<class Item>
class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2)const;
	bool operator!=(const Vec& v2)const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator[](unsigned index);
	const Item& operator[](unsigned index)const;
	void readFrom(string fileName);
	void writeTo(string fileName) const;
	Vec operator-(const Vec& v2) const;
	Item operator*(const Vec& v2) const;
	Vec operator+(const Vec& v2) const;


private:
   unsigned mySize;
   Item *   myArray;

	void makeCopyOf(const Vec& original);

   friend class VecTester;
};

/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Jason Pruim and Casey Purtill
 * Date: Sept 26, 2017
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"
#include <stdexcept>
#include <fstream>
#include <cassert>
template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}
template<class Item>
Vec<Item>::Vec(unsigned size){
	mySize = size;
	if(size > 0){
		myArray = new Item[size]();
//		cout<< myArray<<endl;
//		cout << myArray[0]<<endl;
//		for(unsigned i; i < size; ++i){
//			myArray[i] = 0;
//		}
	}
	else{
		myArray = NULL;
	}
}
template<class Item>
void Vec<Item>::makeCopyOf(const Vec<Item>& original) {
	mySize = original.mySize;
	if (mySize > 0) {
		myArray = new Item[mySize]();
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];
			//			cout << myArray[i]<< flush;
		}
	} else {
		myArray = NULL;
	}
}
template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	makeCopyOf(original);
}
template<class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}
template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if (this != &(original)) {
		delete[] myArray;
		makeCopyOf(original);

	}
	return *this;
}
template<class Item>
unsigned Vec<Item>::getSize() const{
	return mySize;
}
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it){
	if (mySize > index) {
		myArray[index] = it;
	}
	else{
		throw range_error("invalid index");
	}
}
template<class Item>
Item Vec<Item>::getItem(unsigned index) const{
	if (mySize > index) {
		return myArray[index];
	}
	else{
		throw range_error("invalid index");
	}
}
template<class Item>
void Vec<Item>::setSize(unsigned newSize){
//	Vec Temp(newSize);
//	for(unsigned i =0; i< mySize && i < newSize; i++){
//		Temp.myArray[i] = myArray[i];
//	}
//	*this = Temp;
	if (newSize == mySize){
		return;
	}
	if (newSize > 0) {
		Item* tempArray = new Item[newSize]();
		for (unsigned i = 0; i < mySize && i < newSize; i++) {
			tempArray[i] = myArray[i];
		}
		delete[] myArray;
		mySize = newSize;
		myArray = tempArray;
	}
	else{
		delete [] myArray;
		myArray = NULL;
		mySize = 0;
	}
}
template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
	if(mySize== v2.mySize){
		for(unsigned i = 0; i< mySize; i++){
			if (myArray[i] != v2.myArray[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}
//
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	//out << mySize<<endl;
	for(unsigned i = 0; i < mySize; i++){
		out<< myArray[i]<<endl;
	}
}
template<class Item>
void Vec<Item>::readFrom(istream& in) {
	//in >> mySize;
	//delete[] myArray;
	if (mySize > 0) {
		for (unsigned i = 0; i < mySize; i++) {
			in >> myArray[i];
		}
	} else {
		myArray = NULL;
	}
}

/* operator[]
 * @param:unsigned index
 * return: myArray[index]
 * goal: work [] with assignment
 */
template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if(index >=mySize){
		//cout << "Error thrown \n\n\n\n\n"<<endl;
		throw range_error("Index outside of Array");
	}
	//cout<<"First was called"<<endl;
//	Item &Address = &(myArray[index]);
	return myArray[index];
}
/* operator[] const
 * @param:unsigned index
 * return: myArray[index]
 * goal: work [] with retrieval
 */
template<class Item>
const Item& Vec<Item>::operator[](unsigned index)const{
	if(index >=mySize){
		//cout << "Other Error thrown \n\n\n\n\n "<<endl;
		throw range_error("Index outside of Array");
	}
	//cout<<"Second was called"<<endl;
	return myArray[index];
}
/* readFrom
 * @param: string fileName
 * return:
 * goal: to change myArray based on inputs from a file
 */
template<class Item>
void Vec<Item>::readFrom(string fileName){
    ifstream fin(fileName.c_str());
    assert( fin.is_open());
    fin>>mySize;
    delete[] myArray;
    myArray = new Item[mySize];
//    for(unsigned i = 0; i<mySize; i++){
//    	fin>>myArray[i];
//    }
//    fin.close();
    this->readFrom(fin);
}
/* writeTo
 * @param: string fileName
 * return:
 * goal: to write myArray to a file with same format needed for readFrom
 */
template<class Item>
void Vec<Item>::writeTo(string fileName) const{
	ofstream fout(fileName.c_str());
	assert(fout.is_open());
	fout<<mySize<<endl;
	this->writeTo(fout);
	fout.close();
}
/* operator!=
 * @param: const Vec& v2
 * return: bool
 * goal: to see if v2 and this are not the same
 */
template<class Item>
bool Vec<Item>::operator!=(const Vec& v2) const{
	bool a = *this==(v2);
	return !a;
}
/* oeprator-
 * @param: const Vec& v2
 * return: Vec
 * goal: to return a vector that is "this" minus v2
 */
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2) const{
	if(this->getSize() != v2.getSize()){
		throw invalid_argument("Different sized vectors");
	}
	Vec v7(mySize);
	for (unsigned i = 0; i<mySize; i++){
		v7.myArray[i] = this->myArray[i]-v2.myArray[i];
	}
	return (v7);
}
/* oeprator+
 * @param: const Vec& v2
 * return: Vec
 * goal: to return a vector that is "this" plus v2
 */
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) const{
	if(this->getSize() != v2.getSize()){
		throw invalid_argument("Different sized vectors");
	}
	Vec v7(mySize);
	for (unsigned i = 0; i<mySize; i++){
		v7.myArray[i] = this->myArray[i]+v2.myArray[i];
	}
	return (v7);
}
/* oeprator*
 * @param: const Vec& v2
 * return: Item
 * goal: to return a vector that is "this" dot producted with v2
 */
template<class Item>
Item Vec<Item>::operator*(const Vec<Item>& v2) const {
	if (v2.getSize() != this->getSize()) {
		throw invalid_argument("Arrays are not the same size");
	}
	Item dProd = 0;
	if (mySize != 0) {
		for (unsigned i = 0; i < this->getSize(); i++) {
			dProd += this->myArray[i] * v2.myArray[i];
		}
	}
	return dProd;
}

#endif /*VEC_H_*/
