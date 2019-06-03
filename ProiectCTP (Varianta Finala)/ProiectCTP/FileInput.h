#include "FileOperations.h"

class FileInput:public FileOperations {
private:
	string filename;
public:
	FileInput() { this->filename = "Busses.txt"; }
	~FileInput() {};

	string getFilename();
	void setFilename(string);

	void Read(CTP*);

	void Write(CTP*) {};

};