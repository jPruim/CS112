/* PlayList.cpp ...
 * ...
 */

#include "PlayList.h"
#include <fstream>      // ifstream
#include <cassert>      // assert()
#include <string>		//string
#include <iostream>
#include <sstream>
using namespace std;

/* PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a playlist file.
 */
PlayList::PlayList(const string& fileName) {
	// open a stream to the playlist file
	ifstream fin(fileName.c_str());
	assert(fin.is_open());

	// read each song and append it to mySongs
	Song s;
	string separator;
	while (true) {
		s.readFrom(fin);
		if (!fin) {
			break;
		}
		getline(fin, separator);
		mySongs.push_back(s);
	}

	// close the stream
	fin.close();
}
unsigned PlayList::getNumSongs() const {
	return mySongs.size();
}

/* Search by artist
 * @param: artist, a string.
 * Return: a vector containing all the Songs in mySongs by artist.
 */
vector<Song> PlayList::searchByArtist(const string& artist) const {
   vector<Song> v;

   for (unsigned i = 0; i < mySongs.size(); i++) {
      if ( mySongs[i].getArtist().find(artist) != string::npos ) {
         v.push_back( mySongs[i] );
      }
   }

   return v;
}
/* Search by Year
 * @param: Year, a string.
 * Return: a vector containing all the Songs in mySongs created in a year.
 */
vector<Song> PlayList::searchByYear(const string& year) const {
   vector<Song> v;

   for (unsigned i = 0; i < mySongs.size(); i++) {
	   double intYear = mySongs[i].getYear();
	   string strYear = static_cast<ostringstream*>( &(ostringstream() << intYear) )->str();
	   //string strYear = to_string(mySongs[i].getYear());
      if ( strYear.find(year) != string::npos ) {
         v.push_back( mySongs[i] );
      }
   }
   return v;
}
/* Search by Title
 * @param: Title, a string.
 * Return: a vector containing all the Songs in mySongs containing that title.
 */
vector<Song> PlayList::searchByTitle(const string& title) const {
   vector<Song> v;

   for (unsigned i = 0; i < mySongs.size(); i++) {
      if ( mySongs[i].getTitle().find(title) != string::npos ) {
         v.push_back( mySongs[i] );
      }
   }

   return v;
}
