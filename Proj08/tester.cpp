/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin College.
 */

 #include "ArrayQueueTester.h"
#include "StackTester.h"
#include "PalindromeTester.h"
 int main() {
 	ArrayQueueTester aqt;
 	aqt.runTests();
 	StackTester st;
 	st.runTests();
 	PalindromeTester pdt;
 	pdt.runTests();

 }
 
 
