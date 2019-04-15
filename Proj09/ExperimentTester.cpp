/*
 * ExperimentTester.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jrp27
 */

#include "ExperimentTester.h"
/* run tests
 * @param: none
 * return:
 * goal: to call the tests and add some formating
 * creator: Jason Pruim
 */
void ExperimentTester:: runTests() {
	cout<< "Testing Experiment"<<endl;
	testReadFrom();
	cout<< "All Tests Passed"<<endl;
}
/* test read from
 * @param: none
 * return:
 * goal: to test the read from function.
 * creator: Jason Pruim
 */
void ExperimentTester::testReadFrom(){
	cout<< "-testing read From"<<endl;
	Experiment e;
	cout<< "Expecting height of 3 and 2 duplicates"<<endl;
	e.readFrom("Tree1");

	cout<< "Passed!"<<endl;

}

