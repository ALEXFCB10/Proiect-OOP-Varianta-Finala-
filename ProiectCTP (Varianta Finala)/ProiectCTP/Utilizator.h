#ifndef UTILIZATOR_H_
#define UTILIZATOR_H_
#include <string>
#include <cstring>
#include "CosDeCumparaturi.h"
using namespace std;
class Utilizator {
private:
	string nume;
	string parola;
	CosDeCumparaturi* purchases;
public:
	Utilizator();
	Utilizator(string, string, CosDeCumparaturi*);
	Utilizator(const Utilizator*);
	~Utilizator();

	string getNume();
	void setNume(string);
	string getParola();
	void setParola(string);
	CosDeCumparaturi* getPurchases();
	void setPurchases(CosDeCumparaturi*);

	string toString();
	bool compare(const Utilizator*);

	friend ostream& operator<<(ostream&, const Utilizator*);

};




#endif