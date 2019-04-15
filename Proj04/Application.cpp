/*
 * Application.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: jrp27
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
 * goal: to set default values for wantRun,
 * has new lines to "clear terminal"
 */
Application::Application(){
	cout<<"\n\n\n\n\n\n\n\n\n\n"<<endl;
	cout<<"Welcome to Matrix Operations!"<<endl;
	wantRun = true;
}
/* runApplication
 * goal:to call other methods in sequence to make an application through terminal
 */
void Application::runApplication(){
	wantRun = true;
	while(wantRun){
		makeMenu();
	}
}
/* quit
 * goal:exit application after printing an ending message to console
 */
void Application::quit(){
	cout<< "Thanks for using Matrix Operations"<<endl;
	wantRun = false;
}
/* printMat
 * @param:const Matrix<double>& m
 * return:
 * goal: to print Matrix in standard format
 */
void Application::printMat(const Matrix<double>& m)const{
	m.writeTo(cout);
}
/* makeMenu
 * @param:
 * return:
 * goal:to cout a menu message wait for response
 */
void Application::makeMenu(){

	cout<<"Do you wish to:"<<endl;
	cout<<"\t 1: add Matrices"<<endl;
	cout<<"\t 2: subtract Matrices"<<endl;
	cout<<"\t 3: transpose a Matrix"<<endl;
	cout<<"\t q: quit Matrix Operations"<<endl;
	char response;
	cin>> response;
	if (response == '1'){
		requestedAdd();
	}else if(response == '2'){
		this->requestedSub();
	}else if (response == '3'){
		this->requestedTrans();
	}else if (response == 'q'){
		this->quit();
	}else{
		cout<< "Invalid response"<<endl;
		makeMenu();
	}
}
/* check File
 * @param: const string& response
 * return:
 * goal:to throw range_error if file can't be opened
 */
void Application::checkFile(const string& response) const {
	ifstream file(response.c_str());
	if(file.is_open()){
		file.close();
	}else{
		throw range_error("Invalid file, did you include .txt?");
	}

}
/* requestedAdd
 * @param:
 * return:
 * goal:use console to request file names and add the matrices that are held in the files.
 * prints result to console
 */
void Application::requestedAdd()const{
	string response, response2, stall;
	Matrix<double> m1, m2, m3;
	cout<<"What file is your first Matrix in?"<<endl;
	cin>>response;
	try{
		checkFile(response);
	}catch(range_error& re){
		cout<<re.what()<<endl;
		return;
	}
	m1.readFrom(response);
	cout<<"What file is your second Matrix in?"<<endl;
	cin>>response2;
	try{
		checkFile(response2);
	}catch(range_error& re){
		cout<<re.what()<<endl;
		return;
	}
	m2.readFrom(response2);
	try{
		m3 = m1 + m2;
	}catch (invalid_argument& err){
		cout<<err.what()<<endl;
		return;
	}
	cout<<"Your sum is:"<<endl;
	printMat(m3);
	cout<<"type anything to return to Menu"<<endl;
	cin>>stall;
}
/* requestedSub
 * @param:
 * return:
 * goal:use console to request file names and subtract the matrices that are held in the files.
 * prints result to console
 */
void Application::requestedSub()const{
	string response, response2, stall;
	Matrix<double> m1, m2, m3;
	cout<<"What file is your first Matrix in?"<<endl;
	cin>>response;
	try{
		checkFile(response);
	}catch(range_error& re){
		cout<<re.what()<<endl;
		return;
	}
	m1.readFrom(response);
	cout<<"What file is your second Matrix in?"<<endl;
	cin>>response2;
	try{
		checkFile(response2);
	}catch(range_error& re){
		cout<<re.what()<<endl;
		return;
	}
	m2.readFrom(response2);
	try{
		m3 = m1 - m2;
	}catch (invalid_argument& err){
		cout<<err.what()<<endl;
		return;
	}
	cout<<"Your Difference is:"<<endl;
	printMat(m3);
	cout<<"type anything to return to Menu"<<endl;
	cin>>stall;
}
/* requestedTrans
 * @param:
 * return:
 * goal:use console to request a file name and transpose the Matrix held within
 * prints result to console
 */
void Application::requestedTrans()const{
	string response, stall;
	cout<<"What file is your Matrix in?"<<endl;
	cin>>response;
	try{
		checkFile(response);
	}catch(range_error& re){
		cout<<re.what()<<endl;
		return;
	}
	Matrix<double> m1, m2;
	m1.readFrom(response);
	m2 = m1.getTranspose();
	cout<<"Your transposed Matrix is:"<<endl;
	printMat(m2);
	cout<<"type anything to return to Menu"<<endl;
	cin>>stall;
}
