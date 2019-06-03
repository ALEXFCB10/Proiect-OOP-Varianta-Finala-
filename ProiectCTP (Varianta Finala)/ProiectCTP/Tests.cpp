#include "Tests.h"
#include "Linie.h"
#include "Autobuz.h"
#include "Bilet.h"
#include "CosDeCumparaturi.h"
#include "Utilizator.h"
#include "Database.h"
#include <iostream>
#include <assert.h>
#include "Controller.h"
#include "FileOperations.h"
#include "FileInput.h"
using namespace std;
void test_Linie() {
	/* Subprogramul testeaza metodele clasei Linie
		 Input:-
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
	int nr = 4;
	vector<string> s = { "Piata Marasti","Dorobantilor","Campus","Iulius Mall","Bucium" };
	string t = "urban";
	Linie linie1 = Linie(nr, s, t);
	assert(linie1.getNumar() == 4);
	assert(linie1.getNrStatii() == 5);
	assert(linie1.getTip() == "urban");
	linie1.setNumar(5);
	assert(linie1.getNumar() == 5);
	linie1.setTip("metropolitan");
	assert(linie1.getTip() == "metropolitan");
	nr = 5;
	t = "metropolitan";
	vector <string> v = { "Vivo!","Unirii" };
	Linie linie2 = Linie(nr, v, t);
	assert(linie1.compare(linie2) == 1);
	cout << "\nTestele pentru clasa Linie au trecut";


}

void test_Autobuz() {
	/* Subprogramul testeaza metodele clasei Autobuz
		 Input:-
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
	 */
	int nr = 4;
	vector<string> s = { "Piata Marasti","Dorobantilor","Campus","Iulius Mall","Bucium" };
	string t = "urban";
	Linie* linie1 = new Linie(nr, s, t);
	vector <int> a = { 0,15,30,45 };
	
	Autobuz autobuz1 = Autobuz(linie1,nr,a);
	assert(autobuz1.getNumar() == 4);
	vector <int> ora = autobuz1.getOrar();
	assert(ora[0] == 0);
	nr = 5;
	t = "metropolitan";
	vector <string> v = { "Vivo!","Unirii" };
	Linie* linie2 =new Linie(nr, v, t);
	autobuz1.setLinie(linie2);


	cout << "\nTestele pentru clasa Autobuz au trecut";

}

void test_Bilet() {
	/* Subprogramul testeaza metodele clasei Bilet
			 Input:-
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
		 */
	string d = "01.06.2019";
	int p = 3;
	string t = "urban";
	Bilet bilet1 = Bilet(d, p, t);
	p = 5; 
	t = "metropolitan";
	Bilet bilet2 = Bilet(d, p, t);
	assert(bilet1.getPret() == 3);
	assert(bilet2.getData() == "01.06.2019");
	assert(bilet1.getTip() == "urban");
	bilet1.setPret(4);
	assert(bilet1.getPret() == 4);
	bilet2.setData("05.06.2019");
	assert(bilet2.getData() == "05.06.2019");
	bilet1.setTip("metropolitan");
	assert(bilet1.getTip() == "metropolitan");
	Bilet* bilet3 =new Bilet(d, p, t);
	assert(bilet1.compare(bilet3)==0);
	cout << "\nTestele pentru clasa Bilet au trecut";


}
void test_CosDeCumparaturi() {
	/* Subprogramul testeaza metodele clasei CosDeCumparaturi
		 Input:-
		 Preconditii:-
		 Output:-
		 Postconditii:-
		 Error:-
			 */
	string d = "01.06.2019";
	int p = 3;
	string t = "u";
	Bilet* bilet1 =new Bilet(d, p, t);
	p = 5;
	t = "m";
	int nr = 2;
	Bilet* bilet2 =new Bilet(d, p, t);
	Bilet** bilete=new Bilet*[nr];
	
	bilete[0] = bilet1;
	bilete[1] = bilet2;
	
	CosDeCumparaturi cos = CosDeCumparaturi(bilete, nr);
	
	assert(cos.getNrBilete() == 2);
	assert(cos.getSuma() == 15);
	cos.setNrBilete(3);
	cos.addBilet(bilet1);
	assert(cos.getSuma() == 20);
	assert(cos.getNrBilete() == 4);
	cos.setSuma(25);
	assert(cos.getSuma() == 25);
	cout << "\nTestele pentru clasa CosDeCumparaturi au trecut";

}

void test_Utilizator() {
	/* Subprogramul testeaza metodele clasei Utilizator
			 Input:-
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
*/
	string nume = "Vasile Alexandru";
	string parola = "4762a";
	string d = "01.06.2019";
	int p = 3;
	string t = "u";
	Bilet* bilet1 = new Bilet(d, p, t);
	p = 5;
	t = "m";
	int nr = 2;
	Bilet* bilet2 = new Bilet(d, p, t);
	Bilet** bilete = new Bilet * [nr];

	bilete[0] = bilet1;
	bilete[1] = bilet2;

	CosDeCumparaturi* cos =new CosDeCumparaturi(bilete, nr);
	Utilizator utiliz = Utilizator(nume, parola, cos);
	assert(utiliz.getNume() == "Vasile Alexandru");
	utiliz.setParola("4321b");
	assert(utiliz.getParola() == "4321b");
	nume = "Albert";
	parola = "aaaa";
	Utilizator* utiliz2 =new Utilizator(nume, parola, cos);
	assert(utiliz.compare(utiliz2) == 0);
	cout << "\nTestele pentru clasa Utilizator au trecut";
	


}

void test_Database() {
	/* Subprogramul testeaza metodele clasei Database
			 Input:-
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
*/
	string nume = "Vasile Alexandru";
	string parola = "4762a";
	string d = "01.06.2019";
	int p = 3;
	string t = "u";
	Bilet* bilet1 = new Bilet(d, p, t);
	p = 5;
	t = "m";
	int nr = 2;
	Bilet* bilet2 = new Bilet(d, p, t);
	Bilet** bilete = new Bilet * [nr];

	bilete[0] = bilet1;
	bilete[1] = bilet2;

	CosDeCumparaturi* cos = new CosDeCumparaturi(bilete, nr);
	Utilizator* utiliz =new  Utilizator(nume, parola, cos);
	
	nume = "Albert";
	parola = "aaaa";
	Utilizator * utiliz2 = new Utilizator(nume, parola, cos);
	Database* data =new Database();
	data->add(utiliz);
	data->add(utiliz2);
	assert(data->getSizeUsers() == 2);
	 nr = 4;
	vector<string> s = { "Piata Marasti","Dorobantilor","Campus","Iulius Mall","Bucium" };
	 t = "u";
	Linie* linie1 = new Linie(nr, s, t);
	vector <int> a = { 0,15,30,45 };

	Autobuz* autobuz1 = new Autobuz(linie1, nr, a);
	data->add(autobuz1);
	assert(data->getSizeBusses() == 1);
	cout << "\nTestele pentru clasa Database au trecut";

}

void test_Controller() {
	/* Subprogramul testeaza metodele clasei Controller
			 Input:-
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
*/
	Controller* ctrl = new Controller();
	string nume = "Vasile Alexandru";
	string parola = "4762a";
	string d = "01.06.2019";
	int p = 3;
	string t = "u";
	Bilet* bilet1 = new Bilet(d, p, t);
	p = 5;
	t = "m";
	int nr = 2;
	Bilet* bilet2 = new Bilet(d, p, t);
	Bilet** bilete = new Bilet * [nr];

	bilete[0] = bilet1;
	bilete[1] = bilet2;

	CosDeCumparaturi* cos = new CosDeCumparaturi(bilete, nr);
	Utilizator* utiliz = new  Utilizator(nume, parola, cos);

	nume = "Albert";
	parola = "aaaa";
	Utilizator* utiliz2 = new Utilizator(nume, parola, cos);
	ctrl->Add(utiliz);
	ctrl->Add(utiliz2);
	nr = 4;
	vector<string> s = { "Piata Marasti","Dorobantilor","Campus","Iulius Mall","Bucium" };
	t = "u";
	Linie* linie1 = new Linie(nr, s, t);
	vector <int> a = { 0,15,30,45 };

	Autobuz* autobuz1 = new Autobuz(linie1, nr, a);
	nr = 21;
	vector<string> b = { "Andrei Muresanu","Ion Agarbiceanu","Trifoiului","Becas" };
	t = "u";
	Linie* linie2 = new Linie(nr, b, t);
	vector <int> o = { 2,17,32,48 };
	Autobuz* autobuz2 = new Autobuz(linie2, nr, o);

	ctrl->Add(autobuz1);
	ctrl->Add(autobuz2);
	assert(ctrl->GetSizeBusses() == 2);
	assert(ctrl->GetSizeUsers() == 2);
	assert(ctrl->verifyUserName("Vasile Alexandru") == true);
	assert(ctrl->verifyLogin("Albert", "aaa") == false);
	assert(ctrl->FindAutobuz(21, ctrl->GetBusses(), 2)==true);
	assert(ctrl->FiltrareAutobuz(21) == 1);
	assert(ctrl->SearchUser(utiliz2) == 1);
	assert(ctrl->SearchStation("Malinului") == false);
	FileInput* file = new FileInput();
	


	cout << "\nTestele pentru clasa Controller au trecut";

}
void test_citire() {
	/* Subprogramul testeaza citirea din fisier
			 Input:-
			 Preconditii:-
			 Output:-
			 Postconditii:-
			 Error:-
*/
	CTP* ctp = new CTP();
	FileInput* file = new FileInput();
	file->Read(ctp);
	
	Controller* ctrl = new Controller();
	ctrl = ctp->getController();
	assert(ctrl->GetSizeUsers() == 0);
	assert(ctrl->GetSizeBusses() == 15);
	assert(ctrl->verifyUserName("Ion")==false);
	assert(ctrl->SearchStation("Trifoiului") == false);
	assert(ctrl->verifyLogin("Andrei", "a") == false);
	assert(ctrl->FiltrareAutobuz(50) == -1);
	cout << "\nTestele pentru citirea din fisier au trecut";

}