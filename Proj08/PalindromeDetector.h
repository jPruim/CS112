/*
 * PalindromeDetector.h
 *
 *  Created on: Nov 15, 2017
 *      Author: jrp27
 */

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_

#include "ArrayQueue.h"
#include "Stack.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>


class PalindromeDetector {
public:
	PalindromeDetector(const string& inFile, const string& outFile);
	void detectPalindromes();
	bool isPalindrome(string str) const;
private:
	string myInputFile;
	string myOutputFile;

	friend class PalindromeTester;
};

#endif /* PALINDROMEDETECTOR_H_ */
