#include "Utilizator.h"
#include <iostream>
using namespace std;

Utilizator::Utilizator() {
	/* Subprogramul creeaza o instanta noua de tipul Utilizator
		 Input:-
		 Preconditii:-
		 Output:o instanta de tipul Utilizator
		 Postconditii:-
		 Error:-
	 */
	this->nume = "";
	this->parola = "";
	this->purchases = NULL;
}

Utilizator::Utilizator(string n, string p, CosDeCumparaturi* c) {
	/* Subprogramul creeaza o instanta noua de tipul Utilizator
			 Input:n,p,c
			 Preconditii:n reprezinta numele utilizatorului
							  p reprezinta parola utilizatorului
							  c reprezinta Cosul de cumparaturi al utilizatorului
			 Output:o instanta de tipul Utilizator
			 Postconditii:-
			 Error:-
		 */
	this->nume = n;
	this->parola = p;
	this->purchases = c;
}

Utilizator::Utilizator(const Utilizator* u) {
	/* Subprogramul creeaza o instanta noua de tipul Utilizator
			 Input:u
			 Preconditii: u reprezinta o instanta de tipul Utilizator
			 Output:o instanta de tipul Utilizator
			 Postconditii:-
			 Error:-
		 */
	this->nume = u->nume;
	this->parola = u->parola;
	this->purchases = u->purchases;
}

Utilizator::~Utilizator() {
	/* Subprogramul distruge un obiect de tipul Utilizator
			 Input:-
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
		 */
	if (this->purchases != NULL) {
		delete this->purchases;
		this->purchases = NULL;
	}
}

string Utilizator::getNume() {
	/* Subprogramul returneaza numele utilizatorului curent
		 Input:-
		 Preconditii:-
		 Output:numele utilizatorului curent
		 Postconditii:-
		 Error:-
	 */
	return this->nume;
}

void Utilizator::setNume(string n) {
	/* Subprogramul modifica numele utilizatorului curent
		 Input:n
		 Preconditii:n reprezinta noul nume al utilizatorului curent
		 Output:instanta curenta modificata
		 Postconditii: -
		 Error:-
	 */
	this->nume = n;
}

string Utilizator::getParola() {
	/* Subprogramul returneaza parola utilizatorului curent
		 Input:-
		 Preconditii:-
		 Output:parola utilizatorului curent
		 Postconditii:-
		 Error:-
	 */
	return this->parola;
}

void Utilizator::setParola(string p) {
	/* Subprogramul modifica parola utilizatorului curent
		 Input:p
		 Preconditii:p reprezinta noua parola a utilizatorului curent
		 Output:instanta curenta modificata
		 Postconditii: -
		 Error:-
	 */
	this->parola = p;
}

CosDeCumparaturi* Utilizator::getPurchases() {
	/* Subprogramul returneaza continutul cosului de cumparaturi al utilizatorului curent
		 Input:-
		 Preconditii:-
		 Output:continutul cosului de cumparaturi al utilizatorului curent
		 Postconditii:-
		 Error:-
	 */
	return this->purchases;
}

void Utilizator::setPurchases(CosDeCumparaturi* c) {
	/* Subprogramul modifica continutul cosului de cumparaturi al utilizatorului curent
		 Input:c
		 Preconditii:c reprezinta noul cos de cumparaturi al utilizatorului curent
		 Output:instanta curenta modificata
		 Postconditii: -
		 Error:-
	 */
	if (this->purchases != NULL) {
		delete this->purchases;
		this->purchases = NULL;
	}
	this->purchases = c;
}

string Utilizator::toString() {
	/* Subprogramul converteste informatia utila din instanta curenta in informatie afisabila
		 Input:-
		 Preconditii:-
		 Output:informatia utila sub forma de string
		 Postconditii:-
		 Error:-
	 */
	string s = "";
	s = "Numele utilizatorului: " + this->nume + "; Cosul de cumparaturi: " + this->purchases->toString();
	return s;
}

bool Utilizator::compare(const Utilizator* u) {
	/* Subprogramul compara daca informatia obiectului u de tipul Utilizator coincide sau nu cu instanta obiectului curent
		 Input:u
		 Preconditii:u reprezinta o instanta de tipul Utilizator
		 Output:True sau False
		 Postconditii:subprogramul returneaza True daca cele doua instante de tipul Utilizator coincid, sau False in rest
		 Error:-*/
	return ((this->nume == u->nume) && (this->parola == u->parola) && (this->purchases = u->purchases));
}

ostream & operator<<(ostream & os, const Utilizator * u) {
	/* Subprogramul suprascrie operatorul de afisare pentru clasa Utilzator
			 Input:os-ostream, u-Utilizator
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
		 */
	os << "Numele utilizatorului: " << u->nume << '\n';
	os << "Cosul de cumparaturi: \n" << u->purchases << '\n';
	return os;
}
