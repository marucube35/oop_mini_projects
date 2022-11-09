#pragma once
#include "MySimpleCSVFileLogger.h"

class A {
private:
	MySimpleLogger* logger;
public:
	A() {
		logger = MySimpleCSVFileLogger::createInstance();
		logger->write("Begin of A::A()");
		logger->write("Middle of A::A()");
		logger->write("End of A::A()");
	}
	void fooA() {
		logger->write("Begin of A::fooA()");
		logger->write("Middle of A::fooA()");
		logger->write("Another logged message in A::fooA()");
		logger->write("End of A::fooA()");
	}
};
class B {
private:
	MySimpleLogger* logger;
public:
	B() {
		logger = MySimpleCSVFileLogger::createInstance();
	}
	void fooB() {
		logger->write("A simple logged message in B::fooB()");
	}
};