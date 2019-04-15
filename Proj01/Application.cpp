/*
 * Application.cpp
 *
 *  Created on: Sep 15, 2017
 *      Author: Jason Pruim
 *  Makes, edits, and searches through a play list via terminal/console.
 */

#include "Application.h"
#include <string>
#include <iostream>
#include "PlayList.h"
#include "Song.h"
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Application::Application() {
	// TODO Auto-generated constructor stub
//    makeStarterPlayList();
//    string myPlaylist = "ActivePlaylist.txt";
}
/* Make Interface
 * @param:
 * return: string of interface text
 * Goal is to provide an intuitive message for users of the app.
 */
string Application::makeInterface(){
	string text = "Welcome to Play List Manager \n Play list Loaded. Will auto save /n Please enter:  \n 1: to search in the play list for songs by an artist \n 2: to search in play list by year \n 3: to search play list by title\n 4: to add a song to the play list \n 5: to load basic play list example \n q: to end program";
	//5: to save a play list \n 6: to load a play list \n
	return text;
}
/* Title Response
 * @param:const string& user input
 * return:
 * Goal is to inte1rpret user inputs as commands.
 * Calls methods when applicable and otherwise returns an polite error message and requests a new input.
 */
void Application::titleResponse(const string& response){
	if(response == "1") {
	   // statement(s) will execute if the boolean expression is true
		requestedSearchByArtist();
	}
	else if (response == "2"){
		requestedSearchByYear();
	}
	else if (response == "3"){
		requestedSearchByTitle();
	}
	else if (response == "4"){
		requestedAddSong();
	}
	else if (response == "5"){
		makeStarterPlayList();
		makeMenu();
	}
//	else if (response =="5"){
//		savePlayList();
//	}
//	else if (response =="6"){
//		//loadPlayList();
//	}
	else if (response == "q"){
	    cout << string( 100, '\n' );
	    cout<< "Thanks for running the Play List App"<<endl;
	}
	else {
	  // statement(s) will execute all other boolean expressions are false
		string input;
		cout <<"Please enter a number 1 to 5 without any spaces or q to quit."<< endl;
		cin >> input;
		titleResponse(input);
		//makeMenu();
	}
}
/* Makes Menu
 * @param:
 * return:
 * Goal is request text from makeInterface() method and then wait for user input to continue. Calls title response method after user input.
 *
 */
void Application::makeMenu(){
	cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<< endl;
	string text = makeInterface();
    //cout << "Play list Loaded. Will auto save"<< endl;
	cout << text << endl;
	string response;
	cin >> response;
	titleResponse(response);
}
/* Requested Search by Year
 * @param:
 * return:
 * Goal is to find all songs with the year requested inside of active playlist.
 * Shortened years such as "19" will show all songs from 1900's and all years that end or contain 19: like 2019 and 1190
 * uses console to communicate with user.
 */
void Application::requestedSearchByYear(){
	cout<< "What year do you wish to search for?"<<endl;
	string year;
	cin>> year;
	string stall;
	PlayList pList("ActivePlaylist.txt");
	vector<Song> searchResult = pList.searchByYear(year);
	unsigned numberOfResults = searchResult.size();
	if (numberOfResults != 0) {
		cout<<"Songs found:"<<endl;
		for (unsigned i = 0; i < numberOfResults; ++i) {
			cout << searchResult[i].getTitle() << endl;
		}
		cout<< "Enter anything to return to main Menu"<<endl;
		cin >> stall;
		makeMenu();
	} else {
		cout << "Sorry no songs match that year" << endl;
		cout<< "Enter anything to return to main Menu"<<endl;
		cin >> stall;
		makeMenu();
	}
}
/* Requested Search by Artist
 * @param:
 * return:
 * Goal is to find all songs with a requested artist. Songs come from active play list.
 * uses console to communicate with user. Typing in part of an artist's name will give all artists that contain that phrase
 */
void Application::requestedSearchByArtist(){
	cout<< "What Artist do you wish to search for?"<<endl;
	string artist;
	cin>> artist;
	string stall;
	PlayList pList("ActivePlaylist.txt");
	vector<Song> searchResult = pList.searchByArtist(artist);
	unsigned numberOfResults = searchResult.size();
	if (numberOfResults != 0) {
		cout<<"Songs found:"<<endl;
		for (unsigned i = 0; i < numberOfResults; ++i) {
			cout << searchResult[i].getTitle() << endl;
		}
		cout<< "Enter anything to return to main Menu"<<endl;
		cin >> stall;
		makeMenu();
	} else {
		cout << "Sorry no songs match that artist" << endl;
		cout<< "Enter anything to return to main Menu"<<endl;
		cin >> stall;
		makeMenu();
	}
}
/* Requested Search by Title
 * @param:
 * return:
 * Goal is to find all songs with a requested phrase inside of its title. Songs come from active play list.
 * uses console to communicate with user.
 */
void Application::requestedSearchByTitle(){
	cout<< "What Title do you wish to search for?"<<endl;
	string title;
	cin>> title;
	string stall;
	PlayList pList("ActivePlaylist.txt");
	vector<Song> searchResult = pList.searchByTitle(title);
	unsigned numberOfResults = searchResult.size();
	if (numberOfResults != 0) {
		cout<<"Songs found:"<<endl;
		for (unsigned i = 0; i < numberOfResults; ++i) {
			cout << searchResult[i].getTitle() << endl;
		}
		cout<< "Enter anything to return to main Menu"<<endl;
		cin >> stall;
		makeMenu();
	} else {
		cout << "Sorry no songs contain that phrase" << endl;
		cout<< "Enter anything to return to main Menu"<<endl;
		cin >> stall;
		makeMenu();
	}
}
/* Requested Add song (to play list)
 * @param:
 * return:
 * Goal is to add song to play list. Asks user through terminal to input name, artist, and year.
 * uses console to communicate with user.
 */
void Application::requestedAddSong(){
	string myTitle;
	string myArtist;
	string yearImput;
	string stall;
	cout << "What is the song's name?"<<endl;
	getline(cin, stall);
	getline(cin, myTitle);
	//cin >> myTitle;
	cout << "What is the song's artist?"<<endl;
	getline(cin, myArtist);
	//cin >> myArtist;
	cout << "What is the year the song was created in?"<< endl;
	cin>> yearImput;
	unsigned int myYear = atoi(yearImput.c_str());
	// declare three songs
	Song s1(myTitle, myArtist, myYear);
	// write the three songs to an output file
	ofstream fout;
	fout.open( "ActivePlaylist.txt", ios::out | ios::app );
	assert(fout.is_open());
	s1.writeTo(fout);
	fout << '\n';
	fout.close();
	cout <<"Your song has been added to the active play list."<<endl;
	cout <<"Enter anything to return to the main Menu"<<endl;
	cin>> stall;
	makeMenu();
}
/* Makes a default playlist
 * @param:
 * return:
 * contains 4 songs that allow user to use various features of the app.
 */
void Application::makeStarterPlayList(){
	Song s1("Call Me Maybe", "Carly Rae Jepsen", 2012);
	Song s2("Let It Be", "The Beatles", 1967);
	Song s3("Let It Be", "Joan Baez", 1971);
	Song s4("Penny Lane", "The Beatles", 1967);
	// write the four songs to an output file
	ofstream fout("ActivePlaylist.txt");
	assert(fout.is_open());
	s1.writeTo(fout);
	fout << '\n';
	s2.writeTo(fout);
	fout << '\n';
	s3.writeTo(fout);
	fout << '\n';
	s4.writeTo(fout);
	fout << '\n';
	fout.close();
}
/*
 * more failures, going to stick with only 1 saved file. Can't pull off more
 *
 */
//void Application::savePlayList(){
//	ifstream inFile("ActivePlaylist.txt", ios::binary);
//	ofstream outFile("MyTestSave.txt", ios::binary);
//	char ch;
//	while (!inFile.eof())  // Though perhaps this condition is wrong
//	{
//		inFile.get(ch);
//		outFile <<ch;
//	}
//	inFile.close();
//	outFile.close();
//	string stall;
//	cout << "Your play list has been saved" << endl;
//	cout << "Enter anything to return to the main Menu" << endl;
//	cin >> stall;
//	makeMenu();
//}


/*
 * failed attempts for saving and loading
 */
//void Application::savePlayList(){
//	cout << "Where would you like to save this file (please include .txt ending)"<<endl;
//	string myLocation;
//	cin >> myLocation;
//    if (remove(myLocation.c_str( )) !=0){
//          //cout<<"Remove operation failed"<<endl;
//    }
//    else{
//        cout<<myLocation<<" has been overwritten."<<endl;
//    }
//    ifstream  src("ActivePlaylist.txt", ios::binary);
//    ofstream  dst(myLocation, ios::binary);
//    dst << src.rdbuf();
//    string stall;
//	cout <<"Your play list has been saved"<<endl;
//	cout <<"Enter anything to return to the main Menu"<<endl;
//	cin>> stall;
//	makeMenu();
//}
//void Application::loadPlayList(){
//	cout << "Where would you like to load from (please include .txt ending)"<<endl;
//	string myLocation;
//	cin >> myLocation;
//	//remove("ActivePlaylist.txt");
//    //ifstream  src(myLocation, ios::binary);
//    //ofstream  dst("ActivePlaylist.txt", ios::binary);
//    //dst << src.rdbuf();
//    string stall;
//	cout <<"Your play list has been loaded"<<endl;
//	cout <<"Enter anything to return to the main Menu"<<endl;
//	cin>> stall;
//	makeMenu();
//}
