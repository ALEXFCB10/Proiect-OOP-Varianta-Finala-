#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller() {
	/* Subprogramul creeaza o instanta noua de tipul Controller
			 Input:-
			 Preconditii:-
			 Output:o instanta de tipul Controller
			 Postconditii:-
			 Error:-
		 */
	this->d = new Database();
}

Controller::~Controller() {
	/* Subprogramul distruge un obiect de tipul Controller
		 Input:-
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
	if (this->d != NULL) {
		delete this->d;
		this->d = NULL;
	}
}

Utilizator** Controller::GetUsers() {
	/* Subprogramul returneaza lista de utilizatori din cadrul bazei de date curente
		 Input:-
		 Preconditii:-
		 Output: lista de utilizatori curenta
		 Postconditii:-
		 Error:-
	 */
	return this->d->getUsers();
}

int Controller::GetSizeUsers() {
	/* Subprogramul returneaza numarul utilizatorilor din cadrul bazei de date curente
		 Input:-
		 Preconditii:-
		 Output: numarul de utilizatori din baza de date curenta
		 Postconditii:-
		 Error:-
	 */
	return this->d->getSizeUsers();
}

void Controller::Add(Utilizator* u) {
	/* Subprogramul adauga un element de tipul Utilizator in lista de utilizatori
			 Input:u
			 Preconditii:u este un obiect de tipul Utilizator
			 Output:lista de utilizatori modificata
			 Postconditii:-
			 Error:-*/
	this->d->add(u);
}

Autobuz** Controller::GetBusses() {
	/* Subprogramul returneaza lista de autobuze din cadrul bazei de date curente
		 Input:-
		 Preconditii:-
		 Output: lista de autobuze curenta
		 Postconditii:-
		 Error:-
	 */
	return this->d->getBusses();
}

int Controller::GetSizeBusses() {
	/* Subprogramul returneaza numarul autobuzelor din cadrul bazei de date curente
		 Input:-
		 Preconditii:-
		 Output: numarul de autobuze din baza de date curenta
		 Postconditii:-
		 Error:-
	 */
	return this->d->getSizeBusses();
}

void Controller::Add(Autobuz* a) {
	/* Subprogramul adauga un element de tipul Autobuz in lista de autobuze
			 Input:a
			 Preconditii:a este un obiect de tipul Autobuz
			 Output:lista de autobuze modificata
			 Postconditii:-
			 Error:-*/
	this->d->add(a);
}

void Controller::GetBussesReady() {
/*  Subprogramul incarca in baza de date informatiile corespunzatoare autobuzelor din cadrul companiei CTP
	Input:-
	Preconditii:-
	Output:lista de autobuze modificata
	Postconditii:-
	Error:-*/
	vector<string> linii1{ "Bucium","Miraslau","Alexandru Vlahuta","Napoca" };
	vector<string> linii1b{ "Napoca","Alexandru Vlahuta","Miraslau","Bucium" };
	
	vector<string> linii2{ "Dacia","Napoca","Piata Avram Iancu","Piata Marasti","Somes"};
	vector<string> linii2b{"Somes","Piata Marasti","Piata Avram Iancu","Napoca","Dacia"};

	vector<string> linii3{ "Piata Marasti","Iulius Mall","Miraslau","Piata Avram Iancu"};
	vector<string> linii3b{"Piata Avram Iancu","Miraslau","Iulius Mall","Piata Marasti"};

	vector<string> linii4{ "Calea Turzii","Alexandru Vlahuta","Gheorghe Dima","Minerva"};
	vector<string> linii4b{"Minerva","Gheorghe Dima","Alexandru Vlahuta","Calea Turzii"};

	vector<string> linii5{ "Manastur","Sora","Napoca","Dacia" };
	vector<string> linii5b{"Dacia","Napoca","Sora","Manastur"};

	vector<string> linii6{ "Iulius Mall","Siretului","Vivo!","Sora","Miraslau" };
	vector<string> linii6b{"Miraslau","Sora","Vivo!","Siretului","Iulius Mall"};

	vector<string> linii7{ "Vivo!","Minerva","Izlazului","Manastur" };
	vector<string> linii7b{"Manastur","Izlazului","Minerva","Vivo!"};

	Linie* l1 = new Linie(24, linii1, "u");
	Linie* l1b = new Linie(240, linii1b, "u");
	Linie* l2 = new Linie(25, linii2, "u");
	Linie* l2b = new Linie(250, linii2b, "u");
	Linie* l3 = new Linie(26, linii3, "u");
	Linie* l3b = new Linie(260, linii3b, "u");
	Linie* l4 = new Linie(27, linii4, "u");
	Linie* l4b = new Linie(270, linii4b, "u");
	Linie* l5 = new Linie(28, linii5, "u");
	Linie* l5b = new Linie(280, linii5b, "u");
	Linie* l6 = new Linie(29, linii6, "u");
	Linie* l6b = new Linie(290, linii6b, "u");
	Linie* l7 = new Linie(30, linii7, "u");
	Linie* l7b = new Linie(300, linii7b, "u");
	vector<int> orar{ 0,15,30,45 };
	vector<int> orar2{ 0,12,24,36,48 };
	vector <int> orar3 {0,23,44};

	Autobuz* a1 = new Autobuz(l1, 100, orar2);
	Autobuz* a1b = new Autobuz(l1b, 101, orar2);	
	Autobuz* a2 = new Autobuz(l2, 200, orar3);
	Autobuz* a2b = new Autobuz(l2b, 201, orar3);
	Autobuz* a3 = new Autobuz(l3, 300, orar2);
	Autobuz* a3b = new Autobuz(l3b, 301, orar2);
	Autobuz* a4 = new Autobuz(l4, 400, orar3);
	Autobuz* a4b = new Autobuz(l4b, 401, orar3);
	Autobuz* a5 = new Autobuz(l5, 500, orar3);
	Autobuz* a5b = new Autobuz(l5b, 501, orar3);
	Autobuz* a6 = new Autobuz(l6, 600, orar3);
	Autobuz* a6b = new Autobuz(l6b, 601, orar3);
	Autobuz* a7 = new Autobuz(l7, 700, orar);
	Autobuz* a7b = new Autobuz(l7b, 701, orar);

	this->Add(a1); this->Add(a1b); this->Add(a2); this->Add(a2b); this->Add(a3); this->Add(a3b); this->Add(a4); this->Add(a4b); this->Add(a5); this->Add(a5b); this->Add(a6); this->Add(a6b); this->Add(a7); this->Add(a7b);
	
	
}


bool Controller::verifyUserName(string nume) {
/*  Subprogramul verifica daca un client se gaseste in lista de utilizatori
	Input:nume
	Preconditii:nume reprezinta numele utilizatorului cautat
	Output:true sau false
	Postconditii:Subprogramul returneaza true daca utilizatorul exista deja in baza de date sau false, in rest
	Error:-*/
	for (int i = 0; i < this->d->getSizeUsers(); i++) {
		if (this->d->getUsers()[i]->getNume() == nume) return true;
	}
	return false;
}

bool Controller::verifyLogin(string nume, string parola) {
/*  Subprogramul verifica daca autentificarea utilizatorului curent a fost cu succes sau nu
	Input:nume,parola
	Preconditii:nume si parola reprezinta datele utilizatorului curent
	Output:true sau false
	Postconditii:Subprogramul returneaza true daca autentificarea a fost cu succes sau false, in rest
	Error:-*/
	for (int i = 0; i < this->d->getSizeUsers(); i++) {
		if ((this->d->getUsers()[i]->getNume()==nume)&&(this->d->getUsers()[i]->getParola()==parola)) return true;
	}
	return false;
}

Database* Controller::getDatabase() {
/*	Subprogramul colecteaza baza de date curenta
	Input:-
	Preconditii:-
	Output:baza de date curenta
	Postconditii:-
	Error:-*/
	return this->d;
}


bool Controller::FindAutobuz(int nr, Autobuz** autobuz, int size) {
/*	Subprogramul cauta un autobuz in lista de autobuze
	Input:nr,autobuz,size
	Preconditii:nr reprezinta numarul autobuzului
				autobuz reprezinta lista de autobuze data
				size reprezinta numarul de autobuze din lista autobuz
	Output:true sau false
	Postconditii:subprogramul returneaza true daca autobuzul cu numarul nr a fost gasit sau false, in rest
	Error:-*/
	for (int i = 0; i < size; i++) {
		if (autobuz[i]->getNumar() == nr) return true;
	}
	return false;
}



int Controller::FiltrareAutobuz(int nr) {
/*	Subprogramul filtreaza autobuzele dupa numarul lor
	Input:nr
	Preconditii:nr reprezinta numarul autobuzului dat
	Output:pozitia autobuzului in lista de autobuze curente
	Postconditii:-
	Error:-*/
	int verify_existence = 0;
	for (int i = 0; i < this->GetSizeBusses(); i++) {
		if (this->GetBusses()[i]->getNumar() == nr) {
			verify_existence = 1;
			return i;
		}
		
	}
	if (verify_existence == 0) return -1;
}

int Controller::SearchUser(Utilizator* u) {
/*	Subprogramul cauta un utilizator in lista de utilizatori
	Input:u
	Preconditii:u reprezinta Utilizatorul cautat
	Output:pozitia utilizatorului sau -1 daca acesta nu exista
	Postconditii:-
	Error:-*/
	for (int i = 0; i < this->GetSizeUsers(); i++) {
		if (this->GetUsers()[i]->compare(u) == true)
			return i;
	}
	return -1;
}


bool Controller::SearchStation(string statie) {
/*	Subprogramul cauta o statie in lista de statii curenta
	Input:statie
	Preconditii:statie reprezinta numele statiei curente
	Output:true sau false
	Postconditii:Subprogramul returneaza true daca exista statia cu numele statie sau false, in rest
	Error:-*/
	for (int i = 0; i < this->GetSizeBusses(); i++) {
		vector<string> b=this->GetBusses()[i]->getLinie()->getStatii();
		if (find(b.begin(), b.end(), statie) != b.end()) return true;
	}
	return false;
}





Autobuz** Controller::SugestiiOptime(string po, string so, string da) {
/*	Subprogramul returneaza lista de sugestii optime ale autobuzelor pentru un utilizator
	Input:p,s,d
	Preconditii:p reprezinta statia de pornire
				s reprezinta statia de sosire
				d reprezinta data de cautare a autobuzelor
	Output:lista cu cele mai bune autobuze pentru utilizatorul curent
	Postconditii:-
	Error:-*/
	Autobuz** autobuze_pornire = new Autobuz * [this->GetSizeBusses()];
	Autobuz** autobuze_sosire = new Autobuz * [this->GetSizeBusses()];
	Autobuz** porniri_sosiri = new Autobuz * [this->GetSizeBusses()];
	Autobuz** schimbari = new Autobuz * [this->GetSizeBusses()];
	Autobuz** bestSuggestion = new Autobuz * [this->GetSizeBusses()];
	int k = 0, l = 0, m = 0, n = 0,pos=0,f=0;
	for (int i = 0; i < this->GetSizeBusses(); i++) {
		vector<string> b = this->GetBusses()[i]->getLinie()->getStatii();
		bool ok = false;
		if ((find(b.begin(), b.end(), po) != b.end())&&(b[b.size()-1]!=po)) {
			for (int j = 0; j<b.size(); j++) {
				if ((b[j] == po)) ok = false;
				if ((b[j] == so)) ok = true;
			}
			if (ok == true) {
				porniri_sosiri[m++] = this->GetBusses()[i];
				bestSuggestion[f++] = this->GetBusses()[i];
			}
			autobuze_pornire[k++] = this->GetBusses()[i];
		}
		if ((find(b.begin(), b.end(), so) != b.end())&&(b[0]!=so)) {
			autobuze_sosire[l++] = this->GetBusses()[i];
		}
	}

	for (int i = 0; i < k; i++) {
		vector<string> b = this->GetBusses()[i]->getLinie()->getStatii();
		if (find(b.begin(), b.end(), so) == b.end())
			schimbari[n++] = autobuze_pornire[i];
	}

	for (int j = 0; j < n; j++) {
		vector<string> b = schimbari[j]->getLinie()->getStatii();
		for (int i = 0; i < b.size(); i++) {
			if (schimbari[j]->getLinie()->getStatii()[i] == po) {
				pos = i;
				
			}
		}
		//cout << "pozitie " << pos;
		for (int i = pos + 1; i < schimbari[j]->getLinie()->getStatii().size(); i++) {

			for (int d = 0; d < l; d++) {

				vector<string> sch = autobuze_sosire[d]->getLinie()->getStatii();
				
				if (find(sch.begin(), sch.end(), schimbari[j]->getLinie()->getStatii()[i]) != sch.end()) {
					bool ok1 = false;
					for (int t = 0; t < sch.size(); t++) {
						if (schimbari[j]->getLinie()->getStatii()[i] == sch[t]) ok1 = false;
						else if (sch[t] == so) ok1 = true;
						
						}
					if (ok1 == true) {
						if ((FindAutobuz(autobuze_sosire[d]->getNumar(), bestSuggestion, f) == false)){
						bestSuggestion[f++] = schimbari[j];
						bestSuggestion[f++] = autobuze_sosire[d];
					}
						
					}

				}



			}
		}

	}

	return bestSuggestion;
}

int Controller::LungimeSugestiiOptime(string po, string so, string da) {
	/*	Subprogramul returneaza lista de sugestii optime ale autobuzelor pentru un utilizator
		Input:p,s,d
		Preconditii:p reprezinta statia de pornire
					s reprezinta statia de sosire
					d reprezinta data de cautare a autobuzelor
		Output:lista cu cele mai bune autobuze pentru utilizatorul curent
		Postconditii:-
		Error:-*/
	Autobuz** autobuze_pornire = new Autobuz * [this->GetSizeBusses()];
	Autobuz** autobuze_sosire = new Autobuz * [this->GetSizeBusses()];
	Autobuz** porniri_sosiri = new Autobuz * [this->GetSizeBusses()];
	Autobuz** schimbari = new Autobuz * [this->GetSizeBusses()];
	Autobuz** bestSuggestion = new Autobuz * [this->GetSizeBusses()];
	int k = 0, l = 0, m = 0, n = 0, pos = 0, f = 0;
	for (int i = 0; i < this->GetSizeBusses(); i++) {
		vector<string> b = this->GetBusses()[i]->getLinie()->getStatii();
		bool ok = false;
		if ((find(b.begin(), b.end(), po) != b.end())&& (b[b.size() - 1] != po)) {
			for (int j = 0; j < b.size(); j++) {
				if ((b[j] == po)) ok = false;
				if ((b[j] == so)) ok = true;
			}
			if (ok == true) {
				porniri_sosiri[m++] = this->GetBusses()[i];
				bestSuggestion[f++] = this->GetBusses()[i];
			}
			autobuze_pornire[k++] = this->GetBusses()[i];
		}
		if ((find(b.begin(), b.end(), so) != b.end()) && (b[0] != so)) {
			autobuze_sosire[l++] = this->GetBusses()[i];
		}
	}

	for (int i = 0; i < k; i++) {
		vector<string> b = this->GetBusses()[i]->getLinie()->getStatii();
		if (find(b.begin(), b.end(), so) == b.end())
			schimbari[n++] = autobuze_pornire[i];
	}

	for (int j = 0; j < n; j++) {
		vector<string> b = schimbari[j]->getLinie()->getStatii();
		for (int i = 0; i < b.size(); i++) {
			if (schimbari[j]->getLinie()->getStatii()[i] == po) {
				pos = i;

			}
		}
	
		for (int i = pos + 1; i < schimbari[j]->getLinie()->getStatii().size(); i++) {

			for (int d = 0; d < l; d++) {

				vector<string> sch = autobuze_sosire[d]->getLinie()->getStatii();

				if (find(sch.begin(), sch.end(), schimbari[j]->getLinie()->getStatii()[i]) != sch.end()) {
					bool ok1 = false;
					for (int t = 0; t < sch.size(); t++) {
						if (schimbari[j]->getLinie()->getStatii()[i] == sch[t]) ok1 = false;
						else if (sch[t] == so) ok1 = true;

					}
					if (ok1 == true) {
						if (FindAutobuz(autobuze_sosire[d]->getNumar(), bestSuggestion, f) == false) {
							
							bestSuggestion[f++] = schimbari[j];
							bestSuggestion[f++] = autobuze_sosire[d];
						}
					}

				}



			}
		}

	}

	return f;
}
