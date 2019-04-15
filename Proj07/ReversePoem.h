/*
 * ReversePoem.h
 *
 *  Created on: Nov 1, 2017
 *      Author: jrp27
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include "StackTester.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "Stack.h"

using namespace std;


class ReversePoem {
public:
	ReversePoem(string fileName);
	const string& getTitle() const;
	const string& getAuthor() const;
	const string& getBody() const;
	const string& getBodyReversed()const;

private:
	string myTitle;
	string myAuthor;
	string myBody;
	string myBodyReversed;


	friend class ReversePoemTester;

};

#endif /* REVERSEPOEM_H_ */
