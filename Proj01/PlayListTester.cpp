/* PlayListTester.cpp defines the PlayList test-methods.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "PlayListTester.h"
#include <iostream>
using namespace std;
/* Test PlayList class
 * @param:
 * return:
 * Goal is to not flag any errors. Calls other methods that test.
 */
void PlayListTester::runTests() {
	cout << "\nTesting class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	testSearchByYear();
	testSearchByTitle();
	cout << "All tests passed!" << endl;
}
/* Test building constructors
 * @param:
 * return:
 * Goal is to not flag any errors.
 */
void PlayListTester::testConstructors() {
	cout << "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert(pList.getNumSongs() == 4);
	cout << " 0 " << flush;

	cout << " Passed!" << endl;
}
/* Test Searching by Artist
 * @param:
 * return:
 * Goal is to not flag any errors. Checks for multiple songs with the same artist.
 */
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
/* Test Searching by Year
 * @param:
 * return:
 * Goal is to not flag any errors. Checks for multiple songs with the same year.
 * Shortened years such as "19" will show all songs from 1900's and all years that end or contain 19 like 2019 and 1190
 */
void PlayListTester::testSearchByYear() {
	cout << "- searchByYear()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByYear("2011");
	assert(searchResult.size() == 0);
	cout << " 0 " << flush;

	// case of 1
	searchResult = pList.searchByYear("2012");
	assert(searchResult.size() == 1);
	assert(searchResult[0].getTitle() == "Call Me Maybe");
	cout << " 1 " << flush;

	// case of 2
	searchResult = pList.searchByYear("1967");
	assert(searchResult.size() == 2);
	assert(searchResult[0].getTitle() == "Let It Be");
	assert(searchResult[1].getTitle() == "Penny Lane");
	cout << " 2 " << flush;

	//case of shortened dates
	searchResult = pList.searchByYear("19");
	assert(searchResult.size() == 3);
	assert(searchResult[0].getTitle() == "Let It Be");
	assert(searchResult[1].getTitle() == "Let It Be");
	assert(searchResult[2].getTitle() == "Penny Lane");
	cout << " 3 " << flush;
	cout << " Passed!" << endl;
}
void PlayListTester::testSearchByTitle() {
	cout << "- searchByTitle()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByTitle("2011");
	assert(searchResult.size() == 0);
	cout << " 0 " << flush;

	// case of 1 (complete or incomplete title
	searchResult = pList.searchByTitle("Call");
	assert(searchResult.size() == 1);
	assert(searchResult[0].getTitle() == "Call Me Maybe");
	searchResult = pList.searchByTitle("Call Me Maybe");
	assert(searchResult.size() == 1);
	assert(searchResult[0].getTitle() == "Call Me Maybe");
	cout << " 1 " << flush;

	// case of 2
	searchResult = pList.searchByTitle("Let");
	assert(searchResult.size() == 2);
	assert(searchResult[0].getTitle() == "Let It Be");
	assert(searchResult[1].getTitle() == "Let It Be");
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}
