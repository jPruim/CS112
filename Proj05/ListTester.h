/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin College.
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testInEquality();
	void testEquality();
	void testReadFromStream();
	void testWriteToStream();
	void testReadFromFile();
	void testWriteToFile();
	void testGetIndexOf();
	void testRemove();
	void testPrepend();
	void testInsert();

};

#endif /*LISTTESTER_H_*/
