
//#include "BST_Tester.h"
#include "ExperimentTester.h"
int main() {
	BST_Tester bstt;
	bstt.runTests();
	ExperimentTester et;
	et.runTests();
	Experiment e;
	e.readFromAll();

}
