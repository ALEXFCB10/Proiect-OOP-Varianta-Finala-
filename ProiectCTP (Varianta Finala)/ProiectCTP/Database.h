#ifndef DATABASE_H_
#define DATABASE_H_
#include "Autobuz.h"
#include "Utilizator.h"
const int MAX = 10;
class Database {
private:
	Utilizator** users;
	Autobuz** busses;
	int size_users;
	int size_busses;
public:
	Database();
	~Database();

	Utilizator** getUsers();
	int getSizeUsers();
	void add(Utilizator*);

	Autobuz** getBusses();
	int getSizeBusses();
	void add(Autobuz*);

	friend ostream& operator<<(ostream&, const Database*);
};




#endif