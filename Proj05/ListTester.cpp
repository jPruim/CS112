/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin College.
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testInEquality();
	testEquality();

	testReadFromFile();
	testWriteToFile();
	testReadFromStream();
	testWriteToStream();

	testGetIndexOf();
	testRemove();
	testPrepend();
	testInsert();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<double> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert( aNode.myItem == double());
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, NULL);
	List<double>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	//cout<<aList.myFirst->myNext<< flush;
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}
/* test operator!=
 * @param:
 * return:
 * goal: to determine if operator != works
 * creator: Jason Pruim
 */
void ListTester::testInEquality(){
	cout << "Testing !=... " << flush;

	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11.append(44);

	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	// tests with different terms
	assert(list11 != list9);
	cout << " 0a " << flush;
	List<double> list10;
	assert(list9 != list10);
	//tests with different sizes (empty size)
	cout << " 0b " << flush;
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	//tests throwing of false;
	if (list8 != list9) {
		throw logic_error("Should have failed an assertion");
	}
	cout<< " 1a " <<flush;
	//tests that self is not different from self
	assert(!(list8!=list8));
	if (list8 != list8) {
		throw logic_error("Should have failed an assertion");
	}
	cout << " 1b " << flush;

	List<double> list2,list3;
	if (list2 != list3) {
		throw logic_error("Should have failed an assertion");
	}
	cout << " 2 " << flush;

	cout<< "Passed!"<<endl;
}
/* test operator==
 * @param:
 * return:
 * goal: to determine if operator == works
 * creator: Daniel Chang
 */
void ListTester::testEquality(){
	//uses the inequality operator in its definition
	//tests for inequality also effect the equality test because
	//this operation just returns the opposite of the inequality operator
	cout << "Testing ==... " << flush;
	//empty case
	List<double> list10, list0;
	assert(list10 == list0);
	cout << " 0 " << flush;
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	//two equal lists
	List<double> list9(list11);
	assert( list9 == list11);
	cout << " 1 "<<flush;
	//false test
	assert(!(list0 == list9));
	//tests by Daniel
    //cout << " Testing equality operator " << endl;
    List<double> list1, list2, list3;
    list1.append(11);
    list1.append(22);
    list1.append(33);
    list2.append(11);
    list2.append(22);
    list2.append(33);
    //two non-empty lists
    assert(list1 ==list2);
    cout << " 2 " << flush;

    //non-empty list with empty list
    assert(!(list1 ==list3));
    cout << " 3 " << flush;

    //
	cout<< "Passed!"<<endl;
}
/* test writeTo file
 * @param:
 * return:
 * goal: to determine if write to file works
 * creator: Daniel Chang
 */
void ListTester::testWriteToFile() {
	cout << "Testing writeTo(file)... " << flush;
	// read a list whose values we know
	List<double> list0, list1;
	list0.readFrom("List2.txt");
	// now write it to a file via a filename
	list0.writeTo("List2Copy.txt");
	// now, read what we just wrote into a different List
	list1.readFrom("List2Copy.txt");
	// and test it

	assert(list0 == list1);
	cout << "Passed!" << endl;
}
/* test writeTo stream
 * @param:
 * return:
 * goal: to determine if write to stream  works
 * creator: Jason Pruim
 */
void ListTester::testWriteToStream() {
	cout << "Testing writeTo(ostream)... " << flush;
	// read a list whose values we know
	List<double> list0, list1;
	ifstream fin("List1.txt");
	list0.readFrom(fin);
	fin.close();
	// now write it to a file via a stream
	ofstream fout("List1Copy.txt");
	list0.writeTo(fout);
	fout.close();
	// now, read what we just wrote into a different List
	ifstream fin2("List1Copy.txt");
	list1.readFrom(fin2);
	fin2.close();
	// and test it
	assert(list0 == list1);
	cout << "Passed!" << endl;
}
/* test readFrom stream
 * @param:
 * return:
 * goal: to determine if read from stream works
 * creator: Daniel Chang
 */
void ListTester::testReadFromStream() {
	cout << "Testing readFrom(istream)... " << flush;
	ifstream fin("List1.txt");
	assert( fin.is_open() );
	List<double> list0;
	list0.readFrom(fin);
	fin.close();
	List<double>::Node * ptr = list0.myFirst;
	//cout<< list0.mySize<<endl;
	assert(list0.mySize ==3);
//	cout<<list0.myFirst->myItem<<endl;
//	cout<<list0.myFirst->myNext->myItem<<endl;
//	cout<<list0.myFirst->myNext->myNext->myItem<<endl;
	for(unsigned i = 0; i < list0.mySize; i++){
		assert(ptr->myItem == (i+1)*11);
		ptr = ptr->myNext;
	}

	assert(list0.myFirst->myItem == 11);
	assert(list0.myFirst->myNext->myItem == 22);
	assert(list0.myFirst->myNext->myNext->myItem == 33);
	//checking that read deletes old nodes and doesn't read from other lines
	ifstream fin2("extra.txt");
	list0.readFrom(fin2);
	assert(list0.myFirst->myItem == 11);
	assert(list0.myFirst->myNext->myItem == 22);
	assert(list0.myFirst->myNext->myNext->myItem == 33);
	fin2.close();
	cout << "Passed!" << endl;
}
/* test readFrom file
 * @param:
 * return:
 * goal: to determine if read from file works
 * creator: Jason Pruim
 */
void ListTester::testReadFromFile() {
	cout << "Testing readFrom(string)... " << flush;
	List<double> list0;
	list0.readFrom("List1.txt");
	assert(list0.myFirst->myItem == 11);
	assert(list0.myFirst->myNext->myItem == 22);
	assert(list0.myFirst->myNext->myNext->myItem == 33);
	assert(list0.mySize == 3);
	cout << " 0 "<< flush;
	//check that readFrom deletes old Nodes
	list0.readFrom("List1.txt");
	assert(list0.mySize == 3);
	cout<<" 1 "<< flush;
	//cout<< list0.mySize<<flush;
	//cout<<list0.mySize<<endl;
	assert(list0.mySize == 3);
	assert(list0.myFirst->myItem == 11);
	assert(list0.myFirst->myNext->myItem == 22);
	assert(list0.myFirst->myNext->myNext->myItem == 33);
	cout << "Passed!" << endl;
}
/* test getIndexOf
 * @param:
 * return:
 * goal: to determine if get index of works
 * creator: Jason Pruim
 */
void ListTester::testGetIndexOf(){
	cout << "Testing getIndexOf... " << flush;
	//initiallize list
	List<double> list0;
	ifstream fin("List1.txt");
	assert(fin.is_open());
	list0.readFrom(fin);

	//test included values
	for (int i = 0; i < int(list0.mySize); i ++){
		assert(list0.getIndexOf(11*(i+1))==i);
	}
	cout<< " 0 "<<flush;
	//test not in list value
	assert(list0.getIndexOf(2)==-1);
	cout << " 1 "<< flush;
	//test doubly included values;
	list0.append(11);
	assert(list0.getIndexOf(11)==0);
	cout << " 2 "<< flush;
	fin.close();
	cout<<"Passed!"<<endl;

}
/* test remove
 * @param:
 * return:
 * goal: to determine if remove works
 * creator: Jason Pruim
 */
void ListTester::testRemove(){
	cout << "Testing remove()... " << flush;
	//create lists
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11.append(44);

	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	list6.append(77);
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5.append(77);

	List<double> list4;
	list4.append(66);
	list4.append(77);
	//test Removing negative index
	double a;
	a = list9.remove(-2);
	assert(a==44);
	assert(list9.mySize ==3);
	cout << " 0 "<<flush;
	//test removing zero index
	a = list9.remove(0);
	assert(list9.mySize==2);
	assert(a==55);
	cout << " 1a "<<flush;
	//test case of two values
	a = list4.remove(1);
	assert(list4.mySize==1);
	assert(a==77);
	cout << " 1b "<<flush;
	//remove from 9 again
	a = list9.remove(1);
	assert(list9.mySize==1);
	assert(a==77);
	cout << " 1c "<<flush;
	//remove last Item from 9
	a = list9.remove(0);
	assert(list9.myFirst == NULL);
	assert(list9.myLast == NULL);
	assert(list9.mySize==0);
	assert(a==66);
	cout << " 1d "<<flush;
	//test removing internal index
	a = list6.remove(1);
	assert(list6.mySize ==3);
	assert(a==55);
	cout << " 2 "<< flush;
	//test removing end index
	a = list5.remove(3);
	assert(list5.mySize ==3);
	assert(a==77);
	cout<< " 3 "<< flush;
	//test removing bigger index
	a = list11.remove(10);
	assert(list11.mySize==3);
	assert(a==44);
	cout << " 4 "<< flush;
	cout<< "Passed!"<<endl;
}
/* test prepend
 * @param:
 * return:
 * goal: to determine if prepend works
 * creator: Daniel Chang
 */

void ListTester::testPrepend(){
//non-empty case

    cout << "Testing Prepend()... " << flush;
    List<double> list32;
    list32.append(11);
    list32.append(22);
    list32.append(33);
    list32.prepend(1,0);
    assert(list32.myFirst->myItem == 1);
    assert(list32.myFirst->myNext->myItem == 11);
    assert(list32.myFirst->myNext->myNext->myItem == 22);
    assert(list32.myFirst->myNext->myNext->myNext->myItem == 33);
    cout << " 1 " << flush;
    //Empty case
    List<double> list33;
    list33.prepend(1,0);
    assert(list33.myFirst->myItem == 1);
    assert(list33.myLast->myItem == 1);
    cout << " 2 " << flush;
    cout << " Prepend Passed! " << endl;

}
/* test append
 * @param:
 * return:
 * goal: to determine if insert works
 * creator: Daniel Chang
 */
void ListTester::testInsert() {
	cout << "Testing insert()... " << flush;
	// empty List
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	// insert to empty list
	aList.insert(11,-1);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	//cout<<aList.myFirst->myNext<< flush;
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// insert at end of a list containing 1 Item
	aList.insert(22,10);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// insert in the middle of a list containing 2 Items
	aList.insert(33,1);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext->myItem == 33 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}
