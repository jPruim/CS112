/*
 * Application.h
 *
 *  Created on: Sep 15, 2017
 *      Author: Jason Pruim
 *  Makes, edits, and searches through a play list via terminal/console.
 */
#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <string>
using namespace std;

class Application {
public:
	Application();
	string makeInterface();
	void titleResponse(const string& response);
	void makeMenu();
	void requestedSearchByArtist();
	void requestedSearchByYear();
	void requestedSearchByTitle();
	void requestedAddSong();
	void makeStarterPlayList();
	void savePlayList();
	void loadPlayList();
};

#endif /* APPLICATION_H_ */
