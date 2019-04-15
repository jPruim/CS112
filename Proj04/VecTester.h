/* VecTester.h provides unit tests for Vec, a simple vector class.
 * Student Name: Jason Pruim
 * Date: Sept 26, 2017
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */
 
#ifndef VECTESTER_H_
#define VECTESTER_H_

#include "Vec.h"

class VecTester {
public:
	void runTests() const;
	void testDefaultConstructor() const;
	void testExplicitConstructor() const;
	void testDestructor() const;
	void testGetSize() const;
	void testSetItem() const;
	void testGetItem() const;
	void testSetSize() const;
	void testCopyConstructor() const;
	void testAssignment() const;
	void testEquality() const;
	void testWriteToStream() const;
	void testReadFromStream() const;
	void testSubscript() const;
	void testInequality() const;
	void testAddition() const;
	void testSubtraction() const;
	void testDotProduct() const;
	void testWriteToFile() const;
	void testReadFromFile() const;
	//void testReadSubscript(const Vec& v) const;

};

#endif /*VECTESTER_H_*/
