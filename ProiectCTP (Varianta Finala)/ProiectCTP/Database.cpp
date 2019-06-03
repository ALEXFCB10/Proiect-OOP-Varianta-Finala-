#include "Database.h"
#include <iostream>
using namespace std;

Database::Database() {
	/* Subprogramul creeaza o instanta noua de tipul Database
				 Input:-
				 Preconditii:-
				 Output:o instanta de tipul Database
				 Postconditii:-
				 Error:-
			 */
	this->size_users = 0;
	this->size_busses = 0;
	this->users = new Utilizator * [MAX];
	this->busses = new Autobuz * [MAX];
}

Database::~Database() {
	/* Subprogramul distruge un obiect de tipul Database
			 Input:-
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
		 */
	if (this->users != NULL) {
		delete[] this->users;
		this->users = NULL;
	}
	if (this->busses != NULL) {
		delete[] this->busses;
		this->busses = NULL;
	}
}

Utilizator** Database::getUsers() {
	/* Subprogramul returneaza lista de utilizatori din cadrul bazei de date curente
		 Input:-
		 Preconditii:-
		 Output: lista de utilizatori curenta
		 Postconditii:-
		 Error:-
	 */
	return this->users;
}

int Database::getSizeUsers() {
	/* Subprogramul returneaza numarul utilizatorilor din cadrul bazei de date curente
		 Input:-
		 Preconditii:-
		 Output: numarul de utilizatori din baza de date curenta
		 Postconditii:-
		 Error:-
	 */
	return this->size_users;
}

void Database::add(Utilizator* u) {
	/* Subprogramul adauga un element de tipul Utilizator in lista de utilizatori
			 Input:u
			 Preconditii:u este un obiect de tipul Utilizator
			 Output:lista de utilizatori modificata
			 Postconditii:-
			 Error:-*/
	if (this->size_users == MAX) {
		Utilizator** uaux = new Utilizator * [2 * MAX];
		for (int i = 0; i < this->size_users; i++) uaux[i] = this->users[i];
		delete[] this->users;
		this->users = uaux;
	}
	this->users[size_users++] = u;
}

Autobuz** Database::getBusses() {
	/* Subprogramul returneaza lista de autobuze din cadrul bazei de date curente
		 Input:-
		 Preconditii:-
		 Output: lista de autobuze curenta
		 Postconditii:-
		 Error:-
	 */
	return this->busses;
}

int Database::getSizeBusses() {
	/* Subprogramul returneaza numarul autobuzelor din cadrul bazei de date curente
		 Input:-
		 Preconditii:-
		 Output: numarul de autobuze din baza de date curenta
		 Postconditii:-
		 Error:-
	 */
	return this->size_busses;
}
void Database::add(Autobuz * a) {
	/* Subprogramul adauga un element de tipul Autobuz in lista de autobuze
			 Input:a
			 Preconditii:a este un obiect de tipul Autobuz
			 Output:lista de autobuze modificata
			 Postconditii:-
			 Error:-*/
	if (this->size_busses == MAX) {
		Autobuz** aaux = new Autobuz * [2 * MAX];
		for (int i = 0; i < this->size_busses; i++) aaux[i] = this->busses[i];
		delete[] this->busses;
		this->busses = aaux;
	}
	this->busses[size_busses++] = a;
}

ostream& operator<<(ostream & os, const Database * d) {
	/* Subprogramul suprascrie operatorul de afisare pentru clasa Database
				 Input:os-ostream, d-Database
				 Preconditii:-
				 Output:-
				 Postconditii:-
				 Error:-
			 */
	os << "Utilizatori: \n";
	for (int i = 0; i < d->size_users; i++) os << d->users[i] << ';';
	os << "Autobuze: \n";
	for (int j = 0; j < d->size_busses; j++) os << d->busses[j] << ';';
	return os;
}
