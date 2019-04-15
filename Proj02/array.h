/* array.h declares "C style" array operations.
 * Name: Jason Pruim
 * Date: Sept 23, 2017
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

void initialize(double *a, unsigned size);

void print(double *a, unsigned size);

double average(double *a, unsigned size);

double sum(double *a, unsigned size);

void read(istream& in, double *a, unsigned size);

void fill (const string& fileName, double *&a, int &numValues);

void resize(double *&a, int oldSize, int newSize);

void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3);
