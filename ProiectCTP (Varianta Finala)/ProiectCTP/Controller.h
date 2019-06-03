#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Database.h"
#include "Autobuz.h"
class Controller {
private:
	Database* d;
public:
	Controller();
	~Controller();

	Utilizator** GetUsers();
	int GetSizeUsers();
	void Add(Utilizator*);

	Autobuz** GetBusses();
	int GetSizeBusses();
	void Add(Autobuz*);

	void GetBussesReady();

	bool verifyUserName(string);
	bool verifyLogin(string, string);


	bool FindAutobuz(int,Autobuz**,int);
	int FiltrareAutobuz(int);

	int SearchUser(Utilizator*);
	bool SearchStation(string);

	Autobuz** SugestiiOptime(string,string,string);
	int LungimeSugestiiOptime(string, string, string);

	Database* getDatabase();

};




#endif 