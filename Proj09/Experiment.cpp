/*
 * Experiment.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: jrp27
 */

#include "Experiment.h"
#include "fstream"
#include "iostream"
/*does nothing
 */
Experiment::Experiment() {
	// TODO Auto-generated constructor stub

}
/* read from all
 * @param: none
 * return:
 * goal: to read 10 files and then find the height and number of repeated values
 * creator: Jason Pruim
 */
void Experiment::readFromAll() {
	string file = "/home/cs/112/proj/09/randomInts01";
	readFrom("/home/cs/112/proj/09/randomInts01");
	readFrom("/home/cs/112/proj/09/randomInts02");
	readFrom("/home/cs/112/proj/09/randomInts03");
	readFrom("/home/cs/112/proj/09/randomInts04");
	readFrom("/home/cs/112/proj/09/randomInts05");
	readFrom("/home/cs/112/proj/09/randomInts06");
	readFrom("/home/cs/112/proj/09/randomInts07");
	readFrom("/home/cs/112/proj/09/randomInts08");
	readFrom("/home/cs/112/proj/09/randomInts09");
	readFrom("/home/cs/112/proj/09/randomInts10");
}
/* read from all
 * @param: const string&
 * return:
 * goal: to read from a file and then output the number of duplicates and the height of the tree
 * creator: Jason Pruim
 */
void Experiment::readFrom(const string& oriName) {
	string Name = oriName + ".txt";
	ifstream fin(Name.c_str());
	if (!fin.is_open()) {
		//cout<< ": failed to open file"<<endl;
		cerr << Name << ": failed to open file";
	}
	assert(fin.is_open());
	BST<long int> myBST;
	long int val, peeked;
	long int duplicates = 0;
	while (!fin.eof()) {
		peeked = fin.peek();
//		fin >> val;
		if (!isspace(peeked)&& !fin.eof()) {
			try {
				fin>>val;
				myBST.insert(val);
			} catch (invalid_argument& ia) {
				duplicates++;
			}
		}else{
			peeked = fin.get();
		}
	}
	cout << "File: " << Name << endl;
	cout << "Number of duplicates: " << duplicates << endl;
	cout << "Height of Tree: " << myBST.getHeight() << endl;
	fin.close();
}

