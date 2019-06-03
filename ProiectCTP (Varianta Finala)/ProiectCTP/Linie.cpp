#include "Linie.h"
#include <iostream>
using namespace std;
Linie::Linie() {
	/* Subprogramul creeaza o instanta noua de tipul Linie
		 Input:-
		 Preconditii:-
		 Output:o instanta de tipul Linie
		 Postconditii:-
		 Error:-
	 */
	this->numar = 0;
	this->statii;
	this->tip = "";
}

Linie::Linie(int n, vector<string> s, string t) {
	/* Subprogramul creeaza o instanta noua de tipul Linie
		 Input:n,s,t
		 Preconditii:n reprezinta numarul liniei
						  s reprezinta lista de statii corespunzatoare liniei numarul n
						  t reprezinta tipul de autobuz care circula pe linia curenta
		 Output:o instanta de tipul Linie
		 Postconditii:-
		 Error:-
	 */
	this->numar = n;
	this->statii = s;
	this->tip = t;
}

Linie::~Linie() {
	/* Subprogramul distruge un obiect de tipul Linie
		 Input:-
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
	 /*if (this->statii != NULL) {
		 delete[] this->statii;
		 this->statii = NULL;
	 }*/
}

int Linie::getNumar() {
	/* Subprogramul returneaza numarul liniei curente
		 Input:-
		 Preconditii:-
		 Output: numarul liniei curente
		 Postconditii:-
		 Error:-
	 */
	return this->numar;
}
void Linie::setNumar(int n) {
	/* Subprogramul modifica numarul liniei curente
		 Input:n
		 Preconditii:n reprezinta numarul noii linii
		 Output:instanta curenta modificata
		 Postconditii:-
		 Error:-
	 */
	this->numar = n;
}

vector<string> Linie::getStatii() {
	/* Subprogramul returneaza statiile liniei curente
		 Input:-
		 Preconditii:-
		 Output: statiile liniei curente
		 Postconditii:-
		 Error:-
	 */
	return this->statii;
}
void Linie::setStatii(vector<string> s) {
	/* Subprogramul modifica statiile liniei curente
		 Input:s
		 Preconditii:s reprezinta statiile noii linii
		 Output:instanta curenta modificata
		 Postconditii:-
		 Error:-
	 */

	this->statii = s;
}

int Linie::getNrStatii() {
	/*	Subprogramul returneaza numarul de statii al unei linii
		Input:-
		Preconditii:-
		Output:numarul de statii al unei linii
		Postconditii:-
		Error:-*/
	return this->statii.size();
}


string Linie::getTip() {
	/* Subprogramul returneaza tipul liniei curente
		 Input:-
		 Preconditii:-
		 Output: tipul liniei curente
		 Postconditii:-
		 Error:-
	 */
	return this->tip;
}

void Linie::setTip(string t) {
	/* Subprogramul modifica tipul liniei curente
		 Input:t
		 Preconditii:t reprezinta tipul noii linii
		 Output:instanta curenta modificata
		 Postconditii:-
		 Error:-
	 */
	this->tip = t;
}


bool Linie::compare(const Linie& l) {
	/* Subprogramul compara daca informatia obiectului l de tipul Linie coincide sau nu cu instanta obiectului curent
		 Input:l
		 Preconditii:l reprezinta o instanta de tipul Linie
		 Output:True sau False
		 Postconditii:subprogramul returneaza True daca cele doua instante de tipul Linie coincid, sau False in rest
		 Error:-*/
	return ((this->numar == l.numar));
}

Linie& Linie::operator =(const Linie& l) {
	/* Subprogramul atribuie informatiile liniei l liniei curente
		 Input:l
		 Preconditii:l reprezinta un obiect de tipul Linie
		 Output:instanta curenta de tipul Linie modificata
		 Postconditii:-
		 Error:-
	 */
	if (this != &l) {
		this->numar = l.numar;
		this->statii = l.statii;
		this->tip = l.tip;
	}
	else
		cout << "Linia data coincide cu instanta curenta !\n";
	return *this;
}

ostream& operator<<(ostream& os, const Linie* l) {
	/* Subprogramul suprascrie operatorul de afisare pentru clasa Linie
		 Input:os-ostream, l-Linie
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
	os << "Numarul liniei: " << l->numar << '\n';
	/*os << "Statiile liniei: ";
	for (int i = 0; i < l->statii.size(); i++) {
		os << l->statii[i] << ";";
	}
	*/
	os << "Tipul biletului: ";
	if (l->tip == "u")cout << "urban";
	else cout << "metropolitan";
	return os;
}