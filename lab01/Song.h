 /* Song.h declares a class for storing song information.
    * Student Name:
    * Date:
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Song {
	public:
	Song();
	Song(const string& , const string& , unsigned );
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	void readFrom(istream&);
	void writeTo(ostream&) const;
private:
	string   myTitle;
	string   myArtist;
	unsigned myYear;
};
#endif
