
#ifndef FILEOPERATIONS_H_
#define FILEOPERATIONS_H_
#include "CTP.h"


using namespace std;
class FileOperations {
public:
	virtual ~FileOperations() {};
	virtual void Read(CTP*)=0;
	virtual void Write(CTP*) = 0;
};


#endif