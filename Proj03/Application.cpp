/*
 * Application.cpp
 *
 *  Created on: Sep 29, 2017
 *      Author: Jason Pruim and Casey Purtill
 */

#include "Application.h"
#include "VecTester.h"
#include <iostream>     // cout, cerr, ...
#include <fstream>      // ifstream, ofstream, ...
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // range_error, ...
using namespace std;
/* Default Constructor
 * @param:
 * return:
 * goal: to set default values for myDimension and moreVec,
 * has new lines to "clear terminal"
 */
Application::Application(){
	cout<<"\n\n\n\n\n\n\n\n\n\n"<<endl;
	myDimension = 0; moreVec = true;
}
/* runApplication
 * @param:
 * return:
 * goal:to call other methods in sequence to make an application through terminal
 */
void Application::runApplication(){
	makeMenu();
	while(myDimension == 0){
		requestDimension();
		if(myDimension ==0){
			cout<<"Please input a non-zero dimension"<<endl;
		}
	}
	requestStartingPoint();
	myLocation= myStartPoint;
	wantMove();
	while (moreVec){
		requestMove();
		wantMove();
	}
	quit();

}
/* requestDimension
 * @param:
 * return:
 * goal: uses cout and cin to request the dimension from the user
 */
void Application::requestDimension(){
	cout<<"Please enter the dimension of your vectors (non-zero):"<<flush;
	cin>>myDimension;
	cout<<"\n"<<flush;
}
/* requestStartingPoint
 * @param:
 * return:
 * goal:to Request a starting point/vector with size of myDimension
 */
void Application::requestStartingPoint(){
	myStartPoint.setSize(myDimension);
	for(unsigned i = 0; i<myDimension;i++){
		cout<<"Enter a value for term # "<<i+1<<" of your starting point: "<<flush;
		cin>>myStartPoint[i];
		cout<<endl;
	}
}
/* requestMove
 * @param:
 * return:
 * goal:requests a move or adding vector of size dimension
 */
void Application::requestMove(){
	Vec move(myDimension);
	for(unsigned i = 0; i<myDimension;i++){
		cout<<"Enter a value for term # "<<i+1<<" of your moving array: "<<flush;
		cin>>move[i];
		cout<<endl;
	}
	myLocation = myLocation + move;
	cout<<"Your location is: "<<flush;
	printVec(myLocation);
}
/* wantMove
 * @param:
 * return:
 * goal:make sure the user wants to move again
 */
void Application::wantMove(){
	char input;
	cout<<"Do you want to move ('n'to stop, any other char to continue)?"<<flush;
	cin>>input;
	cout<<endl;
	if(input == 'n'){
		moreVec = false;
	}
}
/* quit
 * @param:
 * return:
 * goal:exit application after printing an ending message to console
 */
void Application::quit() const{
	cout<< "Thanks for using my Vector adder"<<endl;
	cout<<"Your starting point was: "<<flush;
	printVec(myStartPoint);
	cout<<"Your ending point was: "<<flush;
	printVec(myLocation);
}
/* printVec
 * @param:const Vec& v
 * return:
 * goal: to print Vec in standard format
 */
void Application::printVec(const Vec& v)const{
	cout<<'('<<flush;
	for(unsigned i = 0; i<myDimension; i++){
		cout<<v[i]<<flush;
		if(i+1 !=myDimension){
				cout<<", "<<flush;
		}
	}
	cout<<')'<<endl;
}
/* makeMenu
 * @param:
 * return:
 * goal:to cout a welcome message
 */
void Application::makeMenu() const{
	cout<<"Welcome to Vector Adder. \n Please choose the number of dimensions. "
			<<"\n Then enter a starting point, and start adding"<<endl;
}
