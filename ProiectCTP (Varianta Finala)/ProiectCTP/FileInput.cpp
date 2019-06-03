#include "FileInput.h"
#include <fstream>
#include <stdlib.h>
#include "Exception.h"
string FileInput::getFilename() {
/*  Subprogramul returneaza numele fisierului de unde se extrage informatia
	Input:-
	Preconditii:-
	Output:numele fisierului curent de unde se extrage informatia
	Postconditii:-
	Error:-*/
	return this->filename;
}

void FileInput::setFilename(string f) {
/*  Subprogramul modifica numele fisierului de unde se extrage informatia
	Input:f
	Preconditii:f reprezinta noul nume al fisierului de unde se extrage informatia
	Output:-
	Postconditii:-
	Error:-*/
	this->filename = f;
}

void FileInput::Read(CTP* ctp) {
	/*  Subprogramul extrage informatiile referitoare la autobuzele din cadrul companiei CTP
		Input:ctp
		Preconditii:ctp reprezinta instanta curenta de tipul CTP
		Output:Extragere informatiilor din ctp
		Postconditii:-
		Error:-*/
	ifstream file;
	string line;
	vector<int> orar{ 0,15,30,45 };
	vector<int> orar2{ 0,12,24,36,48 };
	vector <int> orar3{3, 22, 41 };
	bool ok=true;
	int numar_autobuz, orar_option;
	file.open(this->filename);
	std::string::size_type sz;
	if (file) {
		while (getline(file, line)) {
			int j = 0;
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ',') {
					j = j + 1;
				}
			}
			if (j == 4) {
				int k = 0;
				Linie* l = new Linie();
			
				vector<string> statii;
				string s1 = "";
				for (int i = 0; i < line.length(); i++) {
					if (line[i] != ',') {
						s1 += line[i];
					}
					if (line[i] == ',') {
						k += 1;
						if (k == 1) {
							int nr_linie = std::stoi(s1, &sz);
							l->setNumar(nr_linie);
						}
						else if (k == 2) {
							string s2 = s1;

							while (s2 != "") {
								std::size_t found = s2.find('~');
								char a[40];
								std::size_t length = s2.copy(a, found);
								a[length] = '\0';
								statii.push_back(a);
								s2.erase(0, length + 1);
							}

							l->setStatii(statii);

						}
						else if (k == 3) {
							l->setTip(s1);
						}
						else if (k == 4) {
							numar_autobuz = std::stoi(s1, &sz);
							if (statii.size() == 4) {
								orar_option = rand() % 2;
								
								if (orar_option == 0) {
									Autobuz* bus = new Autobuz(l, numar_autobuz, orar);
									ctp->getController()->Add(bus);
								}
								else {

									Autobuz* bus = new Autobuz(l, numar_autobuz, orar2);
									ctp->getController()->Add(bus);
								}
							}
							if (statii.size() == 5) {
								Autobuz* bus = new Autobuz(l, numar_autobuz, orar3);
								ctp->getController()->Add(bus);
							}
							else if (statii.size()<4) {
								Autobuz* bus = new Autobuz(l, numar_autobuz, orar);
								ctp->getController()->Add(bus);
							}
						}
						s1 = "";
					}
				}
			}
		}
	}
}

