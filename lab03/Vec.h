/* Student Name: Jason Pruim
 * Date: Sept 26, 2017
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2);
	void writeTo(ostream& out) const;
	void readFrom(istream& in);

private:
   unsigned mySize;
   Item *   myArray;

	void makeCopyOf(const Vec& original);

   friend class VecTester;
};


#endif /*VEC_H_*/
