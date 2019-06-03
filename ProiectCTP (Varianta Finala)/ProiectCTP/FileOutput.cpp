#include "FileOutput.h"
#include <fstream>
string FileOutput::getFilename() {
/*  Subprogramul returneaza numele fisierului in care se introduce informatia
	Input:-
	Preconditii:-
	Output:numele fisierului in care se introduce informatia
	Postconditii:-
	Error:*/
	return this->filename;
}

void FileOutput::setFileName(string f) {
/*  Subprogramul modifica numele fisierului in care se introduce informatia
	Input:f
	Preconditii:f reprezinta noul nume al fisierului in care se introduce informatia
	Output:instanta curenta modificata
	Postconditii:-
	Error:-*/
	this->filename = f;
}

void FileOutput::Write(CTP* ctp) {
	ofstream file;
	file.open("Users.txt");
	if (file) {
		for (int i = 0; i < ctp->getController()->GetSizeUsers(); i++) {
			file << ctp->getController()->GetUsers()[i]->getNume() +','+ ctp->getController()->GetUsers()[i]->getParola() + '\n';
		}
	}
}