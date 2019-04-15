/* main.cpp tests the classes in our project.
* Student Name: Jason Pruim
* Date: September 12
* Begun by: Joel Adams, for CS 112 at Calvin College.
*/

#include "SongTester.h"
//#include <iostream>
//#include <cassert>
#include "Song.h"
//#include <string>
//#include <fstream>
#include "PlayListTester.h"
#include "PlayList.h"

using namespace std;
int main() {
	SongTester sTester;
	sTester.runTests();
    PlayListTester plTester;
    plTester.runTests();
}
