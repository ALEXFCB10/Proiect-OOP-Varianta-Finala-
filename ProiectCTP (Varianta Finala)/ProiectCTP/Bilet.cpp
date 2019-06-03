#include "Bilet.h"
#include <iostream>
using namespace std;
Bilet::Bilet() {
	/* Subprogramul creeaza o instanta noua de tipul Bilet
			 Input:-
			 Preconditii:-
			 Output:o instanta de tipul Bilet
			 Postconditii:-
			 Error:-
		 */
	this->data = "";
	this->pret = 0;
	this->tip = "";
}

Bilet::Bilet(string d, int p, string t) {
	/* Subprogramul creeaza o instanta noua de tipul Bilet
			 Input:d,p,t
			 Preconditii:d reprezinta data biletului curent
							  p reprezinta pretul biletului curent
							  t reprezinta tipul biletului curent
			 Output:o instanta de tipul Bilet
			 Postconditii:-
			 Error:-
		 */
	this->data = d;
	this->pret = p;
	this->tip = t;
}

Bilet::Bilet(const Bilet* b) {
	/* Subprogramul creeaza o instanta noua de tipul Bilet
			 Input:b
			 Preconditii:b reprezinta o instanta de tipul Bilet
			 Output:o instanta de tipul Bilet
			 Postconditii:-
			 Error:-
		 */
	this->data = b->data;
	this->pret = b->pret;
	this->tip = b->tip;
}

Bilet::~Bilet() {
	/* Subprogramul distruge un obiect de tipul Bilet
		 Input:-
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
}

string Bilet::getData() {
	/* Subprogramul returneaza data biletului curent
		 Input:-
		 Preconditii:-
		 Output: data biletului curent
		 Postconditii:-
		 Error:-
	 */
	return this->data;
}

void Bilet::setData(string d) {
	/* Subprogramul modifica data biletului curent
			 Input:d
			 Preconditii:d reprezinta noua data a biletului curent
			 Output: -
			 Postconditii:-
			 Error:-
		 */
	this->data = d;
}

int Bilet::getPret() {
	/* Subprogramul returneaza pretul biletului curent
			 Input:-
			 Preconditii:-
			 Output: pretul biletului curent
			 Postconditii:-
			 Error:-
		 */
	return this->pret;
}

void Bilet::setPret(int p) {
	/* Subprogramul modifica pretul biletului curent
				 Input:p
				 Preconditii:p reprezinta noul pret al biletului curent
				 Output: -
				 Postconditii:-
				 Error:-
			 */
	this->pret = p;
}

string Bilet::getTip() {
	/* Subprogramul returneaza tipul biletului curent
			 Input:-
			 Preconditii:-
			 Output: tipul biletului curent
			 Postconditii:-
			 Error:-
		 */
	return this->tip;
}

void Bilet::setTip(string t) {
	/* Subprogramul modifica tipul biletului curent
		 Input:t
		 Preconditii:t reprezinta noul tip al biletului curent
		 Output: -
		 Postconditii:-
		 Error:-
	 */
	this->tip = t;
}

string Bilet::toString() {
	/* Subprogramul converteste informatia utila din instanta curenta in informatie afisabila
		 Input:-
		 Preconditii:-
		 Output:informatia utila sub forma de string
		 Postconditii:-
		 Error:-
	 */
	string s = "";
	s = "Data biletului: " + this->data + "; Pretul biletului: " + to_string(this->pret) + "; Tipul biletului: " + this->tip;
	return s;
}

bool Bilet::compare(const Bilet* b) {
	/* Subprogramul compara daca informatia obiectului b de tipul Bilet coincide sau nu cu instanta obiectului curent
			 Input:b
			 Preconditii:b reprezinta o instanta de tipul Bilet
			 Output:True sau False
			 Postconditii:subprogramul returneaza True daca cele doua instante de tipul Bilet coincid, sau False in rest
			 Error:-*/
	return ((this->data == b->data) && (this->pret == b->pret) && (this->tip == b->tip));
}

Bilet& Bilet::operator =(const Bilet& b) {
	/* Subprogramul atribuie informatiile biletului a biletului curent
		 Input:b
		 Preconditii:b reprezinta un obiect de tipul Bilet
		 Output:instanta curenta de tipul Bilet modificata
		 Postconditii:-
		 Error:-
	 */
	if (this != &b) {
		this->data = b.data;
		this->pret = b.pret;
		this->tip = b.tip;
	}
	else
		cout << "Biletul dat coincide cu instanta curenta";
	return *this;
}

ostream& operator<<(ostream& os, const Bilet* b) {
	/* Subprogramul suprascrie operatorul de afisare pentru clasa Bilet
			 Input:os-ostream, b-Bilet
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
		 */
	os << "Data biletului: " << b->data << '\n';
	os << "Pretul biletului: " << b->pret << " RON\n";
	os << "Tipul biletului: " << b->tip << '\n';
	return os;
}