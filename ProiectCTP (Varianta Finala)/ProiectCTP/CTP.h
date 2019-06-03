#ifndef CTP_H_
#define CTP_H_
#include "Controller.h"
class CTP {
private:
	Controller* c;
public:
	CTP();
	~CTP();



	int Login_SignIn();

	bool Achizitionare();
	void FinalizareaPlatii(bool);

	void AfisareOrarRute();
	void VizualizareCosDeCumparaturi(int);
	void AfisareFiltrareAutobuz();
	void AfisareaBiletelor();
	void CautareUtilizator(Utilizator*);

	Controller* getController();

	void printMenu(int);
	void Menu();
	void Run();
};




#endif