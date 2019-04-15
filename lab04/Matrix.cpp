/* Matrix.cpp defines Matrix class methods.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "Matrix.h"

Matrix::Matrix() {
	myRows = myColumns = 0;
}

Matrix::Matrix(unsigned rows, unsigned columns) {
         myRows = rows;
         myColumns = columns;
         myVec.setSize(rows);
         for (unsigned i = 0; i < rows; i++) {
             myVec[i].setSize(columns);
         }
}

unsigned Matrix::getRows() const{
	return myRows;
}

unsigned Matrix::getColumns() const{
	return myColumns;
}

Vec<Item>& Matrix::operator[](unsigned index){
	return myVec[index];
}

const Vec<Item>& Matrix::operator[](unsigned index)const{
	return myVec[index];
}

bool Matrix::operator==(const Matrix& m2) const {
     if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
          return false;
     } else {
          return myVec == m2.myVec;
     }
}
