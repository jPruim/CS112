/* array.cpp defines "C style" array operations
 * Name: Jason Pruim
 * Date: Sept 23, 2017
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include "array.h"
#include <stdlib.h>
#include <string>
#include <sstream>

void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}
 
void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

double average(double *a, unsigned size) {
	double avg = 0;
	for (unsigned i = 0; i < size; i++) {
		avg = avg + *a;
		if (i == size-1){
			avg = avg/size;
		}
		a++;
	}
	return avg;
}
double sum(double *a, unsigned size){
	double sum = 0;
	for (unsigned i = 0; i < size; i++) {
		sum = sum + *a;

		a++;
	}
	return sum;
}
/* Read (into array)
 * @param:istream& in, double *a, unsigned size
 * return:
 * take numbers from file and write into array
 */
void read(istream& in, double *a, unsigned size){
	string num;

	for(unsigned i = 0; i< size; ++i){
		getline(in, num);
//		istringstream sstream(num);
//		double x;
//		if (!(i >> x)){
//			x = 0;
//		}
//		cout <<x<<endl;
		double value = atof( num.c_str() );
		a[i] = value;
	}
//	cout << "finished read"<< endl;
}
/* fill (into array)
 * @param:const string& fileName, double *&a, int &numValues
 * return:
 * goal: is to make the array of a size as shown in a file. Then read from the file to create an array
 * with that many values in it.
 */
void fill (const string& fileName, double *&a, int &numValues){
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	string num;
	getline(fin,num);
	numValues = atoi(num.c_str());
	delete [] a;
	a = new double[numValues];
	read(fin, a, numValues);
	//print(a, numValues);
	fin.close();
	assert(!fin.is_open());

}
/* resize (an array)
 * @param:double *&a, int oldSize, int newSize
 * return:
 * goal: is to create a new array with the same pointer variable that is a different size.
 * Truncates data if the new size is smaller. Fills data as is able.
 */
void resize(double *&a, int oldSize, int newSize){
	double *a2 = new double[newSize];
	for(int i = 0; i<newSize; ++i){
		a2[i] = 0;
	}
//	unsigned int b = newSize;
//	print(a2,b);
	int dataSize = min(oldSize, newSize);
	assert(dataSize !=0);
	for (int i=0; i<dataSize; ++i){
		a2[i] = a[i];
	}
	delete [] a;
	a = new double[newSize];
	a = a2;
}
/* Concat (two arrays)
 * @param:double *a1, int size1, double *a2, int size2, double *&a3, int &size3
 * return:
 * goal: is to turn a3 into an array that has a1 followed by a2 in its data.
 * sizes must correspond to the same numbered arrays
 */void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3){
	int size4 = size1 +size2;
	resize(a3, size3, size4);
//	if (a3 != NULL){
//		delete [] a3;		//deletes via resize
//		a3 = NULL;
//	}
	size3 = size4;
	for(int i = 0; i < size1; ++i){
		a3[i] = a1[i];
	}
	for(int i = 0; i < size2; ++i){
		a3[i+size1] = a2[i];
	}
//	cout<< "Extra Tests"<<endl;
//	print(a1, size1);
//	print(a2, size2);
//	print(a3,size3);
}
