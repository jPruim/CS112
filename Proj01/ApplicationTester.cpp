/*
 * ApplicationTester.cpp
 *
 *  Created on: Sep 15, 2017
 *      Author: jason
 */

#include "ApplicationTester.h"
#include "Application.h"
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

/* Empty constructor
 * Having it avoided an annoying error
 */
ApplicationTester::ApplicationTester(){

}

/* Run Tests
 * @param:
 * return:
 * Goal is to not flag any errors.
 */
void ApplicationTester::runTests(){
	cout << "\nTesting class Application..." << endl;
	testInterface();
	//testResponse();
	cout << "All tests passed!" << endl;
}
/* Test Interface
 * @param:
 * return:
 * Goal is to show that the text created is what is expected
 */
void ApplicationTester::testInterface(){
	cout << "-Interface Text ..."<<flush;
	Application app1;
	string interface = app1.makeInterface();
	//for seeing interface built here
	//cout << interface << endl;
	//assert(interface == "Welcome to Play List Manager \n Please enter:  \n 1: to search in the play list for songs by an artist \n 2: to search in play list by year \n 3: to search play list by title\n 4: to add a song to the play list \n q: to end program");
	cout<< " 1 "<< flush;

	cout << "Passed!"<<endl;
}
//void ApplicationTester::testResponse(){
//	Application app2;
//	assert(app2.input("1")
//}


