#include "CosDeCumparaturi.h"
#include <iostream>
using namespace std;

CosDeCumparaturi::CosDeCumparaturi() {
	/* 		Subprogramul creeaza o instanta noua de tipul CosDeCumparaturi
				 Input:-
				 Preconditii:-
				 Output:o instanta de tipul CosDeCumparaturi
				 Postconditii:-
				 Error:-
			 */
	this->bilete = new Bilet*[100];
	this->nr_bilete = 0;
	this->suma = 0;
}

CosDeCumparaturi::CosDeCumparaturi(Bilet** b, int n) {
	/* 		Subprogramul creeaza o instanta noua de tipul CosDeCumparaturi
				 Input:b,n,s
				 Preconditii:b reprezinta o lista de bilete
								  n reprezinta numarul biletelor
								  s reprezinta suma biletelor
				 Output:o instanta de tipul CosDeCumparaturi
				 Postconditii:-
				 Error:-
			 */
	this->nr_bilete = n;
	this->bilete = new Bilet * [n];
	for (int i = 0; i < n; i++) this->bilete[i] = b[i];
	for (int i = 0; i < n; i++) {
		if (this->bilete[i]->getTip()=="u") this->bilete[i]->setPret(5);
		else if (this->bilete[i]->getTip() == "m") this->bilete[i]->setPret(10);	
		this->suma += this->bilete[i]->getPret();
	}

}

CosDeCumparaturi::CosDeCumparaturi(const CosDeCumparaturi * c) {
	/* 		Subprogramul creeaza o instanta noua de tipul CosDeCumparaturi
					 Input:c
					 Preconditii:c reprezinta o instanta de tipul CosDeCumparaturi
					 Output:o instanta de tipul CosDeCumparaturi
					 Postconditii:-
					 Error:-
				 */
	this->nr_bilete = c->nr_bilete;
	if (this->bilete != NULL) {
		delete[] this->bilete;
		this->bilete = NULL;
	}
	this->bilete = new Bilet * [c->nr_bilete];
	for (int i = 0; i < c->nr_bilete; i++) this->bilete[i] = c->bilete[i];
	this->suma = c->suma;
}

CosDeCumparaturi::~CosDeCumparaturi() {
	/* Subprogramul distruge un obiect de tipul CosDeCumparaturi
			 Input:-
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
		 */
	if (this->bilete != NULL) {
		delete[] this->bilete;
		this->bilete = NULL;
	}
}

Bilet** CosDeCumparaturi::getBilete() {
	/* Subprogramul returneaza  biletele din cosul de cumparaturi curent
		 Input:-
		 Preconditii:-
		 Output: biletele din cosul de cumparaturi curent
		 Postconditii:-
		 Error:-
	 */
	return this->bilete;
}

void CosDeCumparaturi::setBilete(Bilet * *b) {
	/* Subprogramul modifica biletele din cosul de cumparaturi curent
		 Input:b
		 Preconditii:b reprezinta noile bilete din cosul de cumparaturi
		 Output: instanta curenta modificata
		 Postconditii:-
		 Error:-
	 */
	if (this->bilete != NULL) {
		delete[] this->bilete;
		this->bilete = NULL;
	}
	this->bilete = new Bilet * [this->nr_bilete];
	for (int i = 0; i < this->nr_bilete; i++) this->bilete[i] = b[i];
}

int CosDeCumparaturi::getNrBilete() {
	/* Subprogramul returneaza numarul de bilete din cosul de cumparaturi curent
		 Input:-
		 Preconditii:-
		 Output: numarul biletelor
		 Postconditii:-
		 Error:-
	 */
	return this->nr_bilete;
}

void CosDeCumparaturi::setNrBilete(int n) {
	/* Subprogramul modifica numarul de bilete din cosul de cumparaturi curent
		 Input:n
		 Preconditii:n reprezinta numarul de bilete din cosul de cumparaturi
		 Output: instanta curenta modificata
		 Postconditii:-
		 Error:-
	 */
	this->nr_bilete = n;
}

int CosDeCumparaturi::getSuma() {
	/* Subprogramul returneaza suma preturilor biletelor din cosul de cumparaturi curent
			 Input:-
			 Preconditii:-
			 Output: suma preturilor biletelor
			 Postconditii:-
			 Error:-
		 */
	return this->suma;
}

void CosDeCumparaturi::setSuma(int s) {
	/* Subprogramul modifica suma preturilor biletelor din cosul de cumparaturi curent
			 Input:s
			 Preconditii:s reprezinta suma noilor bilete
			 Output: instanta curenta modificata
			 Postconditii:-
			 Error:-
		 */
	this->suma = s;
}

void CosDeCumparaturi::addBilet(Bilet* b) {
/*  Subprogramul adauga un bilet in lista de bilete existenta
	Input:b
	Preconditii:b reprezinta un obiect de tipul Bilet
	Output:lista de bilete modificata
	Postconditii:-
	Error:-*/
	this->bilete[this->nr_bilete++] = b;
	if (b->getTip() == "u") this->suma += 5;
	else if (b->getTip() == "m") this->suma += 10;
}


string CosDeCumparaturi::toString() {
	/* Subprogramul converteste informatia utila din instanta curenta in informatie afisabila
		 Input:-
		 Preconditii:-
		 Output:informatia utila sub forma de string
		 Postconditii:-
		 Error:-
	 */
	string s = "";
	s = "Biletele: ";
	for (int i = 0; i < this->nr_bilete; i++) s += this->bilete[i]->toString();
	s += "; Numarul de bilete: " + to_string(this->nr_bilete) + "; Suma totala a preturilor biletelor: " + to_string(this->suma);
	return s;
}

bool CosDeCumparaturi::compare(const CosDeCumparaturi * c) {
	/* Subprogramul compara daca informatia obiectului c de tipul CosDeCumparaturi coincide sau nu cu instanta obiectului curent
			 Input:c
			 Preconditii:c reprezinta o instanta de tipul CosDeCumparaturi
			 Output:True sau False
			 Postconditii:subprogramul returneaza True daca cele doua instante de tipul CosDeCumparaturi coincid, sau False in rest
			 Error:-*/
	if (this->nr_bilete != c->nr_bilete) return false;
	if (this->suma != c->suma) return false;
	for (int i = 0; i < this->nr_bilete; i++)
		if (this->bilete[i] != c->bilete[i]) return false;
	return true;
}

CosDeCumparaturi & CosDeCumparaturi::operator =(const CosDeCumparaturi & c) {
	/* Subprogramul atribuie informatiile cosului de cumparaturi c cosului curent
			 Input:c
			 Preconditii:c reprezinta un obiect de tipul CosDeCumparaturi
			 Output:instanta curenta de tipul CosDeCumparaturi modificata
			 Postconditii:-
			 Error:-
		 */
	if (this != &c) {
		delete[] this->bilete;
		this->bilete = NULL;
		this->bilete = new Bilet * [c.nr_bilete];
		for (int i = 0; i < c.nr_bilete; i++) this->bilete[i] = c.bilete[i];
		this->nr_bilete = c.nr_bilete;
		this->suma = c.suma;
	}
	else
		cout << "Cosul de cumparaturi dat coincide cu instanta curenta";
	return *this;
}

ostream& operator<<(ostream& os, const CosDeCumparaturi* c) {
	/* Subprogramul suprascrie operatorul de afisare pentru clasa CosDeCumparaturi
			 Input:os-ostream, b-CosDeCumparaturi
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
		 */
	if (c->nr_bilete == 0)cout << "\nMomentan, cosul de cumparaturi este gol !\n";
	else {
		os << "Biletele:\n>>\n";
		for (int j = 0; j < c->nr_bilete; j++)os << "Data biletului: " << c->bilete[j]->getData() << "        ";
		cout << endl;
		for (int j = 0; j < c->nr_bilete; j++)os << "Pretul biletului: " << c->bilete[j]->getPret() << "             ";
		cout << endl;
		for (int j = 0; j < c->nr_bilete; j++)os << "Tipul biletului: " << c->bilete[j]->getTip() << "              ";
		cout << "\n>>\n";
		os << "Numarul de bilete: " << c->nr_bilete;
		os << "\nSuma preturilor biletelor: " << c->suma << '\n';
		return os;
	}
}