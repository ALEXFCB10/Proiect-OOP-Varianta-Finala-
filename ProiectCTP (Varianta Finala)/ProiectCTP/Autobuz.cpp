#include "Autobuz.h"
#include <iostream>
#include <stdio.h>
using namespace std;
Autobuz::Autobuz() {
	/* Subprogramul creeaza o instanta noua de tipul Autobuz
		 Input:-
		 Preconditii:-
		 Output:o instanta de tipul Autobuz
		 Postconditii:-
		 Error:-
	 */
	this->linie = new Linie();
	this->numar = 0;
	this->orar;
}

Autobuz::Autobuz(Linie* l, int nr, vector <int> o) {
	/* Subprogramul creeaza o instanta noua de tipul Autobuz
		 Input:l,o
		 Preconditii:l reprezinta linia pe care circula autobuzul curent
						  o reprezinta orarul autobuzului curent
		 Output:o instanta de tipul Autobuz
		 Postconditii:-
		 Error:-
	 */
	this->linie = l;
	this->numar = nr;
	this->orar = o;

}


Autobuz::~Autobuz() {
	/* Subprogramul distruge un obiect de tipul Autobuz
		 Input:-
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
	if (this->linie != NULL) {
		delete this->linie;
		this->linie = NULL;
	}
}

Linie* Autobuz::getLinie() {
	/* Subprogramul returneaza linia autobuzului curent
		 Input:-
		 Preconditii:-
		 Output: linia autobuzului curent
		 Postconditii:-
		 Error:-
	 */
	return this->linie;
}

void Autobuz::setLinie(Linie* l) {
	/* Subprogramul modifica linia autobuzului curent
		 Input:l
		 Preconditii:l reprezinta noua linie a autobuzului curent
		 Output: instanta curenta modificata
		 Postconditii:-
		 Error:-
	 */
	this->linie = l;
}
int Autobuz::getNumar() {
	return this->numar;
}
vector <int> Autobuz::getOrar() {
	/* Subprogramul returneaza orarul autobuzului curent
		 Input:-
		 Preconditii:-
		 Output: orarul autobuzului curent
		 Postconditii:-
		 Error:-
	 */
	return this->orar;
}



Autobuz& Autobuz::operator =(const Autobuz& a) {
	/* Subprogramul atribuie informatiile autobuzului a autobuzului curent
		 Input:a
		 Preconditii:a reprezinta un obiect de tipul Autobuz
		 Output:instanta curenta de tipul Autobuz modificata
		 Postconditii:-
		 Error:-
	 */
	if (this != &a) {
		this->linie = a.linie;
		this->numar = a.numar;
		this->orar = a.orar;
	}
	else
		cout << "Autobuzul dat coincide cu instanta curenta";
	return *this;
}

ostream& operator<<(ostream& os, const Autobuz* a) {
	/* Subprogramul suprascrie operatorul de afisare pentru clasa Autobuz
		 Input:os-ostream, a-Autobuz
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
	os << "\nLinia autobuzului: " << "            Numarul autobuzului: " << a->numar << "\n>>\n" << a->linie << "\n>>";
	os << "\n                                     Orarul autobuzului: \n\n                    ";
	vector<string>statii = a->linie->getStatii();
	for (int i = 0; i < statii.size(); i++)cout << statii[i] << "     ";
	cout << "\n\n";
	int eroare_timp = 4;
	for (int i = 0; i < a->orar.size(); i++) {
		cout << "                    ";
		for (int j = 0; j < a->linie->getNrStatii(); j++) {
			if (a->orar[i] + j * eroare_timp < 10) {
				os << "Ora" << ":0" << a->orar[i] + j * eroare_timp;
				for (int k = 0; k < statii[j].size() - 1; k++)cout << ' ';
			}
			else {
				os << "Ora" << ':' << a->orar[i] + j * eroare_timp;
				for (int k = 0; k < statii[j].size() - 1; k++)cout << ' ';
			}
		}
		cout << endl;
	}
	cout << "\n\n\n";
	return os;
}