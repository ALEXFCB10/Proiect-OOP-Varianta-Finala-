#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class Exception {
protected:
	const char* message;
public:
	Exception(const char* m);
	const char* getMessage();
};



#endif /* EXCEPTION_H_ */
#pragma once
