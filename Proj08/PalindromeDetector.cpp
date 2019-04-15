/*
 * PalindromeDetector.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: jrp27
 */

#include "PalindromeDetector.h"
/* Palindrome Constructor
 * @param: input filename, output filename
 * return:
 * goal: to set instance variables for input and output files
 * creator: Jason Pruim
 */
PalindromeDetector::PalindromeDetector(const string& inFile,
		const string& outFile) {
	myInputFile = inFile;
	myOutputFile = outFile;

}
/* Palindrome dectect Palindromes
 * @param: none
 * return:
 * goal: to return the same text as a file with *** after each line containing letters if is a palindrome
 * creator: Jason Pruim
 */
void PalindromeDetector::detectPalindromes() {
	ifstream fin(myInputFile.c_str());
	ofstream fout(myOutputFile.c_str());
	string line;
	while(!fin.eof()){
		getline(fin, line);
		if(isPalindrome(line)){
			line = line+ "***";
		}
		line = line + "\n";
		fout<<line;
	}
	fout.close();
	fin.close();
}
/* Palindrome isPalindrome
 * @param: string
 * return: boolean
 * goal: to check if the line is a palindrome only taking non-case sensitive letters into account
 * no letters doesn't qualify as a palindrome
 * creator: Jason Pruim
 */
bool PalindromeDetector::isPalindrome(string stringIn) const {
	ArrayQueue<char> q(1);
	Stack<char> s(1);
	if(stringIn.length() == 0){
		return false;
	}
	char ch,ch1,ch2;
	for(unsigned i = 0; i <stringIn.length();i++){
		ch = stringIn[i];
		if(isalpha(ch)){
			ch = tolower(ch);
			try {
				s.push(ch);
				q.append(ch);
			} catch (StackException& se) {
				s.setCapacity(s.getCapacity() * 2);
				q.setCapacity(q.getCapacity() * 2);
				s.push(ch);
				q.append(ch);
			}
		}
	}
	if(q.isEmpty()){
		return false;
	}
	while(!q.isEmpty()){
		ch1 = s.pop();
		ch2 = q.remove();
		if(ch1 != ch2){
			return false;
		}
	}
	return true;
}
