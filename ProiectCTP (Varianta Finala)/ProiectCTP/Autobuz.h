#ifndef AUTOBUZ_H_
#define AUTOBUZ_H_
#include <string>
#include <cstring>
#include "Linie.h"
using namespace std;
class Autobuz {
private:
	Linie* linie;
	int numar;
	vector <int> orar;
public:
	Autobuz();
	Autobuz(Linie*,int, vector <int>);
	~Autobuz();

	Linie* getLinie();
	void setLinie(Linie*);
	int getNumar();
	vector <int> getOrar();

	

	Autobuz& operator=(const Autobuz&);

	friend ostream& operator<<(ostream&, const Autobuz*);
};
#endif