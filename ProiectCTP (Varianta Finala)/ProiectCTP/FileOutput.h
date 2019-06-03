#include "FileOperations.h"

class FileOutput:public FileOperations {
private:
	string filename;
public:
	FileOutput() { this->filename = "Users.txt"; }
	~FileOutput() {};

	string getFilename();
	void setFileName(string);

	void Read(CTP*) {};

	void Write(CTP*) ;

};