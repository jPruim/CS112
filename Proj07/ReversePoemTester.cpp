/*
 * ReversePoemTester.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: jrp27
 */

#include "ReversePoemTester.h"
#include <cassert>
/* run Tests()
 * @param:
 * return:
 * goal: to determine reverse poem class works
 * creator: Jason Pruim
 */
void ReversePoemTester::runTests() {
	cout << "Testing Reverse Poem class..." << endl;
	testConstructor();
	testFetchMethods();
	cout << "All Tests Passed!" << endl;
}
/* test constructor
 * @param:
 * return:
 * goal: to determine if the constructor works using friend class
 * creator: Jason Pruim
 */
void ReversePoemTester::testConstructor() {
	cout << "- Testing constructor... " << flush;
	ReversePoem rp("love.txt");
	assert(rp.myTitle == "Love?");
	cout << " 0 " << flush;
	assert(rp.myAuthor == "Anonymous");
	cout << " 1 " << flush;
	string a = "I don't love you anymore...";
	string b = "I don't love you anymore...\n"
			"I would be lying if I said\n"
			"That I still love you the way I always did.\n"
			"I'm sure\n"
			"Nothing was in vain.\n"
			"And I feel inside of me that\n"
			"You mean nothing to me\n"
			"I could never really say that\n"
			"Our time together matters.\n"
			"I feel more and more that\n"
			"I'm forgetting you...\n"
			"And I will never use the phrase\n"
			"I love you.\n"
			"I'm sorry but I must tell the truth.";
	for (unsigned i = 0; i < 15; i++) {
		assert(a[i] == rp.myBody[i]);
	}
	assert(b == rp.myBody);
//	cout<<b.length()<<endl;
//	cout<<rp.myBody.length()<<endl;
//	cout<<"this is 367-"<<rp.myBody[367]<<"-"<<endl;
//	cout<<"this is 368-"<<rp.myBody[367]<<"-"<<endl;

	for (unsigned i = 0; i < 366; i++) {
//		cout<<b[i]<<flush;
		assert(b[i] == rp.myBody[i]);
	}
	cout << " 2 " << flush;
	string c = "\nI'm sorry but I must tell the truth.\n"
			"I love you.\n"
			"And I will never use the phrase\n"
			"I feel more and more that\n";
	for (unsigned i = 0; i < 25; i++) {
		//cout<< c[i]<<rp.myBodyReversed[i]<<flush;
		assert(c[i] == rp.myBodyReversed[i]);
	}
	cout << " 3 " << flush;
	cout << "Passed!" << endl;

}
/* test fetch methods
 * @param:
 * return:
 * goal: to determine if the get_____() methods work
 * creator: Jason Pruim
 */
void ReversePoemTester::testFetchMethods() {
	cout << "- Testing Getters... " << flush;
	ReversePoem rp("love.txt");
	assert(rp.myTitle == "Love?");
	assert(rp.getTitle() == "Love?");
	assert(rp.myAuthor == "Anonymous");
	assert(rp.getAuthor() == "Anonymous");
	cout << " 0 " << flush;
	string a = "I don't love you anymore...";
	string b = "I don't love you anymore...\n"
			"I would be lying if I said\n"
			"That I still love you the way I always did.\n"
			"I'm sure\n"
			"Nothing was in vain.\n"
			"And I feel inside of me that\n"
			"You mean nothing to me\n"
			"I could never really say that\n"
			"Our time together matters.\n"
			"I feel more and more that\n"
			"I'm forgetting you...\n"
			"And I will never use the phrase\n"
			"I love you.\n"
			"I'm sorry but I must tell the truth.";
	for (unsigned i = 0; i < 15; i++) {
		assert(a[i] == rp.getBody()[i]);
	}
	cout << " 1 " << flush;
	string c = "\nI'm sorry but I must tell the truth.\n"
			"I love you.\n"
			"And I will never use the phrase\n"
			"I feel more and more that\n";
	for (unsigned i = 0; i < 25; i++) {
		//cout<< c[i]<<rp.myBodyReversed[i]<<flush;
		assert(c[i] == rp.getBodyReversed()[i]);
	}
	cout << " 2 " << flush;
	cout << "Passed!" << endl;

}
