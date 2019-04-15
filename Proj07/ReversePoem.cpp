/*
 * ReversePoem.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: jrp27
 */

#include "ReversePoem.h"
#include <cassert>
/* ReversePoem constructor
 * @param: filename
 * return:
 * goal: to go into poem.txt and find the poem file with the stated name. Open file
 * read from file and store the string of the file and the string of the file reversed by line
 * creator: Jason Pruim
 */
ReversePoem::ReversePoem(string fileName) {
	// TODO Auto-generated constructor stub
	fileName = "poems/"+fileName;
	ifstream fin (fileName.c_str());
	assert(fin.is_open());
	getline(fin,myTitle);
	getline(fin,myAuthor);
	string line;
	getline(fin,line);
	//getline(fin,line);
	Stack<string> myStack(1);
	bool first = true;
//	while(!fin.eof()){
	while(getline(fin,line)){
//		getline(fin,line);
//		if(line == "\n"){
//			break;
//		}
		if(!first){
			myBody = myBody + "\n"+line;
		}else{
			myBody = myBody + line;
		}
		first = false;
		try{
			myStack.push(line);
		}catch(StackException& se){
			myStack.setCapacity(myStack.getCapacity()*2);
			myStack.push(line);
		}
	}
	unsigned size = myStack.getSize();
	for(unsigned i = 0; i < size; i ++){
		line = myStack.pop();
		myBodyReversed = myBodyReversed +"\n" + line;
	}
}
/* get Title()
 * @param:
 * return: const strin& of myTitle
 * creator: Jason Pruim
 */
const string& ReversePoem::getTitle() const{
	return myTitle;
}
/* get Author()
 * @param:
 * return: const strin& of myAuthor
 * creator: Jason Pruim
 */
const string& ReversePoem::getAuthor() const{
	return myAuthor;
}
/* get Body()
 * @param:
 * return: const strin& of myBody
 * creator: Jason Pruim
 */
const string& ReversePoem::getBody()const {
	return myBody;
}
/* get getBodyReversed()
 * @param:
 * return: const strin& of myBodyReversed
 * creator: Jason Pruim
 */
const string& ReversePoem::getBodyReversed() const{
	return myBodyReversed;
}
