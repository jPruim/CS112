/* main.cpp tests the classes in our project.
* Student Name: Jason Pruim
* Date: September 12
* Begun by: Joel Adams, for CS 112 at Calvin College.
*/

#include "SongTester.h"
#include <iostream>
#include <cassert>
#include "Song.h"
//#include <string>
//#include <fstream>
#include "PlayListTester.h"
#include "PlayList.h"
#include "ApplicationTester.h"
#include "Application.h"
using namespace std;

/* main
 * @param:
 * return:
 * Tests various classes associated with the Play list app.
 * Then calls up the app.
 */
int main() {
	SongTester sTester;
	sTester.runTests();
    PlayListTester plTester;
    plTester.runTests();
    ApplicationTester appTest;
    appTest.runTests();
    cout << string( 100, '\n' );
    Application app;
    //app.makeStarterPlayList();
    app.makeMenu();
}

