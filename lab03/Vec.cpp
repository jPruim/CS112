/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Jason Pruim
 * Date: Sept 26, 2017
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */
 
#include "Vec.h"
#include <stdexcept>

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}
Vec::Vec(unsigned size){
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

void Vec::makeCopyOf(const Vec& original) {
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

Vec::Vec(const Vec& original) {
	makeCopyOf(original);
}
Vec::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}
Vec& Vec::operator=(const Vec& original) {
	if (this != &(original)) {
		delete[] myArray;
		makeCopyOf(original);

	}
	return *this;
}
unsigned Vec::getSize() const{
	return mySize;
}
void Vec::setItem(unsigned index, const Item& it){
	if (mySize > index) {
		myArray[index] = it;
	}
	else{
		throw range_error("invalid index");
	}
}
Item Vec::getItem(unsigned index) const{
	if (mySize > index) {
		return myArray[index];
	}
	else{
		throw range_error("invalid index");
	}
}
void Vec::setSize(unsigned newSize){
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
bool Vec::operator==(const Vec& v2) {
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
void Vec::writeTo(ostream& out) const {
	//out << mySize<<endl;
	for(unsigned i = 0; i < mySize; i++){
		out<< myArray[i]<<endl;
	}
}
void Vec::readFrom(istream& in) {
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
