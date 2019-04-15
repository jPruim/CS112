/*
 * PalindromeTester.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: jrp27
 */

#include "PalindromeTester.h"
/* Palindrome Tester runTests
 * @param:
 * return:
 * goal: to call other functions to test PalindromeDetector class
 * creator: Jason Pruim
 */
void PalindromeTester::runTests() {
	cout<<"Testing Palindrome Detector"<<endl;
	testConstructor();
	testIsPalindrome();
	testDetectPalindromes();

	cout << "All tests passed!\n" << endl;


}
/* Palindrome Tester for Constructor
 * @param:
 * return:
 * goal: to check instance variables for input and output files
 * creator: Jason Pruim
 */
void PalindromeTester::testConstructor(){
	cout << "- testing constructor... " << flush;
	PalindromeDetector pd("Input","Output");
	assert(pd.myInputFile == "Input");
	assert(pd.myOutputFile == "Output");
	cout<< " 0 "<<flush;
	cout<<"Passed!"<<endl;
}

/* Palindrome Tester for isPalindrome
 * @param:
 * return:
 * goal: to check the varying cases for Palindromes of strings
 * creator: Jason Pruim
 */
void PalindromeTester::testIsPalindrome(){
	cout<<"- testing isPalindrome"<<flush;
	PalindromeDetector pd("Input","Output");
	//empty string
	assert(!pd.isPalindrome(""));
	cout<< " 0 "<<flush;
	//1 char strings
	assert(!pd.isPalindrome("1"));
	assert(pd.isPalindrome("a"));
	assert(!pd.isPalindrome("-"));
	cout<< " 1 "<<flush;
	//2 char strings
	assert(!pd.isPalindrome("1 "));
	assert(!pd.isPalindrome("ab"));
	assert(pd.isPalindrome("-a"));
	assert(!pd.isPalindrome("11"));
	assert(pd.isPalindrome("aa"));
	assert(!pd.isPalindrome("'-"));
	cout<< " 2 "<<flush;
	//longer strings
	assert(pd.isPalindrome("Madam, I'm Adam."));
	assert(pd.isPalindrome("A man, a plan, a canal, Panama!"));
	assert(pd.isPalindrome("racecar"));
	assert(pd.isPalindrome("race car"));
	assert(pd.isPalindrome("RaCe cAr"));
	assert(pd.isPalindrome("R-75723085820948ace03093*/-*/*-/9408293084car"));
	cout<< " 3 "<<flush;
	// non palindrome longer strings
	assert(!pd.isPalindrome("R-75723085820948ae0309328940-*/*-/*-++9*-/3084car"));
	assert(!pd.isPalindrome("I think therefore I am"));
	assert(!pd.isPalindrome("Why me?????"));
	assert(!pd.isPalindrome("To be or not to be?"));
	assert(!pd.isPalindrome("Is this the real life?"));
	cout<< "Passed!"<<endl;
}

/* Palindrome Tester for detect Palindromes
 * @param:
 * return:
 * goal: to check whether detect palindromes is outputing the right file by reading it and comparing to a test file.
 * creator: Jason Pruim
 */
void PalindromeTester::testDetectPalindromes(){
	cout<<"- testing detect Palindromes"<<flush;
	PalindromeDetector pd("drawnOnward.txt","Test.txt");
	pd.detectPalindromes();
	ifstream fin1 ("Test.txt");
	ifstream fin2 ("Copy.txt");
	assert(fin1.is_open());
	assert(fin2.is_open());
	string line1, line2;
	//int count = 0;
	while(!fin1.eof()){
		//cout<<count<<flush;
		getline(fin1,line1);
		getline(fin2,line2);
		for(unsigned i = 0; i < line2.length();i++){
			assert(line1[i] == line2[i]);
		}
		//count++;
	}
	cout<<" 0 "<<endl;
	fin1.close();
	fin2.close();
	cout<<"Passed!"<<endl;

}
