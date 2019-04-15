/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name:Jason Pruim
 * Date: Oct 4, 2017
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include "Vec.h"


using namespace std;
template<class Item>
class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getRows() const;
	unsigned getColumns()const;
	Vec<Item>& operator[](unsigned index);
	const Vec<Item>& operator[](unsigned index) const;
	bool operator==(const Matrix& m2) const;
	bool operator!=(const Matrix& m2) const;
	void readFrom(istream& fin);
	void writeTo(string fileName) const;
	void readFrom(string fileName);
	void writeTo(ostream& fout)const;
	Matrix operator+(const Matrix& m2) const;
	Matrix operator-(const Matrix& m2) const;
	Matrix getTranspose();

private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
	typedef Item myItem;
	friend class MatrixTester;


};



template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}
template<class Item>
unsigned Matrix<Item>::getRows() const{
	return myRows;
}
template<class Item>
unsigned Matrix<Item>::getColumns() const{
	return myColumns;
}
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index){
	return myVec[index];
}
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index)const{
	if(index >=myRows){
		throw range_error("Index not in Matrix");
	}
	return myVec[index];
}
template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const {
     if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
          return false;
     } else {
          return myVec == m2.myVec;
     }
}
/* operator !=
 * @param: const Matrix& m2
 * return:
 * goal: to return true if the matrices are the same
 */
template<class Item>
bool Matrix<Item>::operator!=(const Matrix<Item>& m2) const {
	if(myVec!= m2.myVec){
		return true;
	}
	return false;
}
/* readFrom (istream)
 * @param: istream& fin
 * return:
 * goal: to make matrix from file with tab separated values, assumes correct dimensions
 */
template<class Item>
void Matrix<Item>::readFrom(istream& fin){
	for(unsigned i = 0; i < myRows; i++){
		for(unsigned j = 0; j < myColumns; j++){
			fin>>myVec[i][j];
		}
	}
}
/* readFrom (fileName)
 * @param: string fileName
 * return:
 * goal: to make matrix from file with tab separated values, reads in dimensions
 */
template<class Item>
void Matrix<Item>::readFrom(string fileName){
	ifstream fin(fileName.c_str());
	for (unsigned i = 0; i < myRows; i++) {
		delete [] &(myVec[i]);
	}
	fin>>myRows;
	fin>>myColumns;
	myVec.setSize(myRows);
	for (unsigned i = 0; i < myRows; i++) {
		myVec[i].setSize(myColumns);
	}
	this->readFrom(fin);
	fin.seekg(0, ios:: beg);
	fin.close();

}
/* writeTo(ostream) const
 * @param: ostream& fout
 * return:
 * goal: to write values of Matrix without number of columns or number of rows
 */
template<class Item>
void Matrix<Item>::writeTo(ostream& fout)const {
	for(unsigned i = 0; i < myRows; i++){
		for(unsigned j = 0; j < myColumns; j++){
			fout<<myVec[i][j];
			if (j!=myColumns-1){
				fout<<'\t';
			}else{
				fout<<endl;
			}
		}
	}
}
/* writeTo(fileName)
 * @param: const string& fileName
 * return:
 * goal: to write values of Matrix with number of columns and number of rows
 */
template<class Item>
void Matrix<Item>::writeTo( string fileName) const{
	ofstream fout(fileName.c_str());
	assert(fout.is_open());
	fout<<myRows<<endl;;
	fout<<myColumns<<endl;
	this->writeTo(fout);
	fout.close();
}
/* operator+
 * @param: const Matrix& m2
 * return:
 * goal: to return a matrix that is the sum of this and m2,
 * throws range errors if the matrices don't have the same dimensions
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator+(const Matrix<Item>& m2) const{
	if(myRows != m2.myRows){
		throw invalid_argument("Different sized Matrices");
	}
	if(myColumns != m2.myColumns){
		throw invalid_argument("Different sized Matrices");
	}
	Matrix result(myRows, myColumns);
	for (unsigned i = 0; i< myRows; i++){
		result.myVec[i] = myVec[i]+m2.myVec[i];
	}
	return (result);
}
/* operator-
 * @param: const Matrix& m2
 * return:Matrix
 * goal: to return a matrix that is the difference of this and m2,
 * throws range errors if the matrices don't have the same dimensions
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator-(const Matrix<Item>& m2) const{
	if(myRows != m2.myRows){
		throw invalid_argument("Different sized Matrices");
	}
	if(myColumns != m2.myColumns){
		throw invalid_argument("Different sized Matrices");
	}
	Matrix<Item> result(myRows, myColumns);
	for (unsigned i = 0; i< myRows; i++){
		result.myVec[i] = myVec[i] - m2.myVec[i];
	}
	return (result);
}
/* getTranspose
 * @param:
 * return:Matrix
 * goal: to return a matrix that is the difference of this and m2,
 * throws range errors if the matrices don't have the same dimensions
 */
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose(){
	Matrix tranMat(myColumns, myRows);
//	Vec<Vec< Item> > tranMat;
//	tranMat.setSize(myColumns);
//	for (unsigned i = 0; i< myColumns; i++){
//		tranMat[i].setSize(myRows);
//	}
	for (unsigned i = 0; i<myRows; i++){
		for (unsigned j = 0; j < myColumns; j++){
			tranMat[j][i] = myVec[i][j];
		}
	}
	return tranMat;
}
#endif

