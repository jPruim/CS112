/*
 * Application.h
 *Adds an arbitrary number of Vectors Together
 *  Created on: Sep 29, 2017
 *      Author: Jason Pruim and Casey Purtill
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "VecTester.h"


class Application {
public:
	Application();
	void runApplication();


private:
	unsigned myDimension;
	Vec myStartPoint;
	bool moreVec;
	Vec myLocation;
	void requestDimension();
	void requestStartingPoint();
	void requestMove();
	void wantMove();
	void quit()const;
	void printVec(const Vec& v)const;
	void makeMenu() const;
};

#endif /* APPLICATION_H_ */
