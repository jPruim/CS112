/* PlayListTester.cpp defines the PlayList test-methods.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "PlayListTester.h"
#include <iostream>
using namespace std;

void PlayListTester::runTests() {
	cout << "\nTesting class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	cout << "All tests passed!" << endl;
}
void PlayListTester::testConstructors() {
	cout << "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert(pList.getNumSongs() == 4);
	cout << " 0 " << flush;

	cout << " Passed!" << endl;
}
void PlayListTester::testSearchByArtist() {
	cout << "- searchByArtist()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByArtist("Cream");
	assert(searchResult.size() == 0);
	cout << " 0 " << flush;

	// case of 1
	searchResult = pList.searchByArtist("Baez");
	assert(searchResult.size() == 1);
	assert(searchResult[0].getTitle() == "Let It Be");
	cout << " 1 " << flush;

	// case of 2
	searchResult = pList.searchByArtist("Beatles");
	assert(searchResult.size() == 2);
	assert(searchResult[0].getTitle() == "Let It Be");
	assert(searchResult[1].getTitle() == "Penny Lane");
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}
