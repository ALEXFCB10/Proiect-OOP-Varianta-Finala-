#ifndef BILET_H_
#define BILET_H_
#include <string>
#include <cstring>
using namespace std;
class Bilet {
private:
	string data;
	int pret;
	string tip;
public:
	Bilet();
	Bilet(string, int, string);
	Bilet(const Bilet*);
	~Bilet();

	string getData();
	void setData(string);
	int getPret();
	void setPret(int);
	string getTip();
	void setTip(string);

	string toString();
	bool compare(const Bilet*);
	Bilet& operator=(const Bilet&);

	friend ostream& operator<<(ostream&, const Bilet*);
};
#endif
