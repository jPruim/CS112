/*
 * Application.h
 *
 *  Created on: Oct 4, 2017
 *      Author: jrp27
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "VecTester.h"
#include "Matrix.h"


class Application {
public:
	Application();
	void runApplication();


private:
	bool wantRun;
	void makeMenu();
	void quit();
	void printMat(const Matrix<double>& m) const;
	void requestedAdd() const;
	void requestedSub()const;
	void requestedTrans()const;
	void checkFile(const std::__cxx11::string& response) const;
};

#endif /* APPLICATION_H_ */
