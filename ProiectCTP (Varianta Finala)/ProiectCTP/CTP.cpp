#include "CTP.H"
#include <iostream>
#include <ctime>
#include <string>
#include "Exception.h"
#include "FileOperations.h"
#include "FileInput.h"
#include "FileOutput.h"
#include <fstream>
#include <conio.h>
using namespace std;

CTP::CTP() {
	/* Subprogramul creeaza o instanta noua de tipul CTP
				 Input:-
				 Preconditii:-
				 Output:o instanta de tipul CTP
				 Postconditii:-
				 Error:-
			 */
	this->c = new Controller();
}

CTP::~CTP() {
	/* Subprogramul distruge un obiect de tipul CTP
			 Input:-
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
		 */
	if (this->c != NULL) {
		delete this->c;
		this->c = NULL;
	}
}

int CTP::Login_SignIn() {
	/*  Subprogramul realizeaza legatura dintre aplicatia principala si un utilizator, permitandu-i autentificarea
		Input:-
		Preconditii:-
		Output:true sau false
		Postconditii:Subprogramul returneaza true daca autentificarea a fost facut cu succes sau false, in rest
		Error:-*/
	int op;
	bool ok = true;
	while (ok)
	{
		cout << "1.Login / 2.Sign in / 3.Foloseste aplicatia ca vizitator\nOptiunea dumneavoastra este: ";
		cin >> op;
		if (op == 1)
		{
			string nume, parola="";
			cout << "Introduceti numele de utilizator: ";
			char s[25]; char pass[30] = { 0 };
			cin.ignore();
			cin.getline(s, 25);
			nume = s;
			int nrTries = 0;
			while ((this->c->verifyUserName(nume) == 0) && (nrTries < 2))
			{
				cout << "Nume de utilizator incorect...\n";
				cout << "Introduceti numele de utilizator: ";
				cin.getline(s, 25);
				nume = s;
				nrTries++;
			}
			if (nrTries < 2)
			{
				cout << "Introduceti parola: ";
				for (int i = 0; i < 30; i++) {
					pass[i] = _getch(); _putch('*');
					if (pass[i] == 13) break;
					parola += pass[i];
				}
				cout << endl;
			}
			while ((this->c->verifyLogin(nume, parola) == 0) && (nrTries < 2))
			{
				cout << "Parola incorecta...\n";
				cout << "Introduceti parola: ";
				for (int i = 0; i < 30; i++) {
					pass[i] = _getch(); _putch('*');
					if (pass[i] == 13) break;
					parola += pass[i];
				}
				cout << endl;
				nrTries++;
			}
			if (nrTries < 2)
			{
				cout << "\nLogarea a avut loc cu succes! \n";
				ok = false;
				return 1;
			}
		}
		else
			if (op == 2)
			{
				cout << "Introduceti numele de utilizator: ";
				string nume, parola;
				char s[25]; char pass[30] = { 0 };
				cin.ignore();
				cin.getline(s, 25);
				nume = s;
				
				while (this->c->verifyUserName(nume))
				{
					cout << "Nume de utilizator deja existent...\nIntroduceti altul: ";
					
					cin.getline(s, 25);
					nume = s;
				}
				cout << "Introduceti parola: ";
				for (int i = 0; i < 30; i++) {
					pass[i] = _getch(); _putch('*');
					if (pass[i] == 13) break;
					parola += pass[i];
				}
				cout << endl;
				CosDeCumparaturi* cos = new CosDeCumparaturi();
				Utilizator* u = new Utilizator(nume, parola, cos);
				this->c->Add(u);
				cout << "\nCont inregistrat cu succes! \n";
				ok = false;
				return 2;
			}
			else
				if (op == 3)return 3;
				else cout << "Optiune inexistenta...\n";
	}
}

bool CTP::Achizitionare() {
	/*  Subprogramul faciliteaza achizitionarea unui bilet de catre un utilizator
		Input:-
		Preconditii:-
		Output:true sau false
		Postconditii:Subprogramul returneaza true daca achizitionarea poate fi facuta sau false, in rest
		Error:-*/
	time_t tme = time(NULL);
	tm timePtr;
	localtime_s(&timePtr, &tme);
	int nr_autobuz, nr_bilete;
	string zi = to_string(timePtr.tm_mday);
	string luna = to_string(timePtr.tm_mon + 1);
	string an = to_string(timePtr.tm_year + 1900);
	char s[25], t[50];
	string pornire, sosire, data;
	cout << "Introduceti statia de pornire: ";
	cin.ignore();
	cin.getline(s, 25);
	pornire = s;
	if (this->c->SearchStation(pornire) == false) throw Exception("Nu exista statia de pornire data !");
	cout << "Introduceti statia de sosire: ";
	cin.getline(t, 50);
	sosire = t;
	if (this->c->SearchStation(sosire) == false) throw Exception("Nu exista statia de sosire data !");
	cout << "Introduceti data( In format ZZ/LL/AAAA): ";
	cin >> data;

	if ((data.find("/") == -1) && (data.find(".") == -1)) {
		data = zi + '/' + luna + '/' + an;
	}
	cout << "Data aleasa: " << data<<endl;
	
	Bilet* b1 = new Bilet(data, 5, "u");
	Bilet* b2 = new Bilet(data, 10, "m");
	Autobuz** a = this->c->SugestiiOptime(pornire, sosire, data);
	if (this->c->LungimeSugestiiOptime(pornire, sosire, data) == 0) throw Exception("Nu exista autobuze pentru ruta dorita !");
	else {
		cout << "Sugestiile oferite de aplicatia CTP sunt: \n";
		for (int i = 0; i < this->c->LungimeSugestiiOptime(pornire, sosire, data); i++) {
			cout << a[i];
		}
	}
	int no_repeat = 0;
	int k = 0;
	Autobuz** BestSuggestionNoRepeat = new Autobuz * [this->c->GetSizeBusses()];
	for (int i = 0; i < this->c->LungimeSugestiiOptime(pornire,sosire,data); i++) {
		if (this->c->FindAutobuz(a[i]->getNumar(), BestSuggestionNoRepeat, k) == false) {
			BestSuggestionNoRepeat[k++] = a[i];
		}
	}
	cout << "Introduceti numarul de bilete dorite: "; cin >> nr_bilete;
	if (nr_bilete <= 0) throw Exception("Numar invalid de bilete !");

	bool ok = false;
	int contor_bilete = 0;
	for (int j = 0; j < nr_bilete; j++) {
		ok = false;
		cout << "Alegeti numarul autobuzului: "; cin >> nr_autobuz;
		for (int i = 0; i < k; i++) {
			if (BestSuggestionNoRepeat[i]->getNumar() == nr_autobuz) {
				ok = true;
				contor_bilete++;
				if (BestSuggestionNoRepeat[i]->getLinie()->getTip() == "u") this->c->GetUsers()[this->c->GetSizeUsers() - 1]->getPurchases()->addBilet(b1);
				if (BestSuggestionNoRepeat[i]->getLinie()->getTip() == "m") this->c->GetUsers()[this->c->GetSizeUsers() - 1]->getPurchases()->addBilet(b2);
			}


		}
		if (ok == false) cout << "Nu exista autobuzul cu numarul " << nr_autobuz << '\n';
		//cout << a[0];

	}
	if (contor_bilete==0) throw Exception("Eroare la procesarea biletelor. . .");

	cout << "In momentul de fata, cosul de cumparaturi contine urmatoarele tipuri de bilete:\n"; this->VizualizareCosDeCumparaturi(this->c->GetSizeUsers() - 1);
	cout << "Doriti sa continuati cu finalizarea platii ?\nRaspuns:";
	string raspuns;
	cin >> raspuns;
	if (raspuns == "da") return true;
	else return false;
}

void CTP::FinalizareaPlatii(bool optiune) {
/*  Subprogramul realizeaza finalizarea platii unui utilizator
	Input:-
	Preconditii:-
	Output:-
	Postconditii:-
	Error:-*/

	string CNP, bank_pass;
	char bank_p[30] = { 0 };
	CosDeCumparaturi* c = new CosDeCumparaturi();
	if (optiune == true) {
		cout << "Introduceti CNP-ul: "; cin >> CNP;
		if (CNP.size() != 13) throw Exception("CNP invalid !");
		else {
			cout << "Introduceti parola: "; 
			//cin >> bank_pass;
			for (int i = 0; i < 30; i++) {
				bank_p[i] = _getch(); _putch('*');
				if (bank_p[i] == 13) break;
				bank_pass += bank_p[i];
			}
			if (bank_pass.size() != 4) throw Exception("\nParola invalida !");
		}
		this->c->GetUsers()[this->c->GetSizeUsers() - 1]->setPurchases(c);
		cout << "\nAchizitia a fost efectuata cu succes !\n";
	}
	
	cout << "Continuati spre meniul principal apasand ENTER. . .\n";
	
	cin.get();
}


void CTP::AfisareOrarRute() {
	/*  Subprogramul afiseaza informatiile referitoare la autobuzele din baza de date curenta
		Input:-
		Preconditii:-
		Output:afisarea informatiilor despre autobuzele din baza de date curenta
		Postconditii:-
		Error:-*/
	for (int i = 0; i < this->c->GetSizeBusses(); i++) {
		cout << this->c->GetBusses()[i];
	}
}

void CTP::VizualizareCosDeCumparaturi(int i) {
	/*  Subprogramul permite verificarea si vizualizarea cosului de cumparaturi al unui utilizator
		Input:i
		Preconditii:i reprezinta numarul de ordine al utilizatorului in lista de utlizatori continuta in baza de date
		Output:cosul de cumparaturi al utilizatorului cu numarul de ordine i
		Postconditii:-
		Error:-*/
	cout << this->c->GetUsers()[i]->getPurchases();
}

void CTP::AfisareFiltrareAutobuz() {
	/*  Subprogramul filtreaza autobuzul dupa numarul dat
		Input:-
		Preconditii:-
		Output:autobuzul cu numarul nr
		Postconditii:-
		Error:-*/
	int nr;
	cout << "Dati numarul autobuzului dupa care doriti filtrarea: ";
	cin >> nr;
	if (this->c->FiltrareAutobuz(nr) != -1)
		cout << this->c->GetBusses()[this->c->FiltrareAutobuz(nr)];
	else
		cout << "Autobuzul numarul "<< nr<<" nu exista in cadrul companiei CTP !\n";
}

void CTP::AfisareaBiletelor() {
	/*	Subprogramul afiseaza biletele unui utilizator
		Input:-
		Preconditii:-
		Output:biletele unui utilizator
		Postconditii:-
		Error:-*/
	cout << "\nPret bilet traseu urban(u): 5 RON\nPret bilet traseu metropolitan(m): 10 RON\n";
}

void CTP::CautareUtilizator(Utilizator* u) {
	/*	Subprogramul cauta un utilizator in lista de utilizatori
		Input:u
		Preconditii:u reprezinta un obiect de tipul Utilzator
		Output:-
		Postconditii:-
		Error:-*/

	if (this->c->SearchUser(u) != -1) {
		cout << "Utilizatorul " << u->getNume() << " exista in baza de date existenta.\n";
	}
	else
		cout << "Utilizatorul " << u->getNume() << " nu exista in baza de date existenta.\n";
}

void CTP::printMenu(int logare) {
	/*	Subprogramul afiseaza meniul aplicatiei principale
		Input:-
		Preconditii:-
		Output:-
		Postconditii:-
		Error:-*/
	if (logare == 1) {
		cout << "\nOptiunile dumneavoastra sunt:\n1.Achizitionarea unui bilet\n2.Filtrare in functie de numarul autobuzului\n3.Vizualizarea pretului biletelor\n4.Afisarea orarului si a rutelor autobuzelor\n5.Afisarea situatiei curente\n6.Logout\n7.Exit\nIntroduceti optiunea dorita: ";
	}
	else {
		cout << "\nOptiunile dumneavoastra sunt:\n1.Filtrare in functie de numarul autobuzului\n2.Vizualizarea pretului biletelor\n3.Afisarea orarului si a rutelor autobuzelor\n4.Revenire la ecranul principal\n5.Exit\nIntroduceti optiunea dorita: ";
	}

}



Controller* CTP::getController() {
	return this->c;
}
void CTP::Menu() {
	/* Subprogramul construieste meniul pe care se bazeaza aplicatia principala
		 Input:-
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
	FileOperations* FI = new FileInput();
	FileOperations* FO = new FileOutput();
	FI->Read(this);
	cout << "Bine ati venit in CTP !\n";
	bool meniu = true;
	bool exit1 = true;
	bool exit2 = true;
	while (meniu) {
		int b = Login_SignIn();
		bool log_in = true;
		while (log_in) {
			if (b == 1)log_in = false;
			if (b == 2)b = Login_SignIn();
			if (b == 3)log_in = false;
			if ((b != 1) && (b != 3))log_in = false;
		}
		if ((b == 1) || (b == 3))printMenu(b);
		int opt;
		cin >> opt;
		if (b == 1) {
			while ((opt != 6) && (exit1)) {
				if (opt == 1) {
					try {
						bool optiune_achizitie=Achizitionare();
						FinalizareaPlatii(optiune_achizitie);
						cin.get();

					}
					catch (Exception& exc) {
						cout << exc.getMessage() << endl;
					}
				}
				else if (opt == 2) {
					AfisareFiltrareAutobuz();
				}
				else if (opt == 3) {
					AfisareaBiletelor();
				}
				else if (opt == 4) {
					AfisareOrarRute();
				}
				else if (opt == 5) {
					VizualizareCosDeCumparaturi(this->c->GetSizeUsers() - 1);
				}
				else if (opt == 6)cout << ' ';
				else if (opt == 7) {
					meniu = false;
					exit1 = false;
				}
				else cout << "\nOptiune inexistenta...\n";
				if (opt != 7) {
					printMenu(b);
					cin >> opt;
				}
			}
		}
		else
			if (b == 3) {
				while ((opt != 4) && (exit2)) {
					if (opt == 1) {
						AfisareFiltrareAutobuz();
					}
					else if (opt == 2) {
						AfisareaBiletelor();
					}
					else if (opt == 3) {
						AfisareOrarRute();
					}
					else if (opt == 4)cout << ' ';
					else if (opt == 5) {
						meniu = false;
						exit2 = false;
					}
					else cout << "\nOptiune inexistenta...\n";
					if (opt != 5) {
						printMenu(b);
						cin >> opt;
					}
				}
			}

	}
	FO->Write(this);
}

void CTP::Run() {
	/* Subprogramul ruleaza aplicatia principala
		 Input:-
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
	this->Menu();
}