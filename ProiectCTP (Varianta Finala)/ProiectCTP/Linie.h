#ifndef LINIE_H_
#define LINIE_H_
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Linie {
private:
	int numar;
	vector <string> statii;
	string tip;
public:
	Linie();
	Linie(int, vector<string>, string);
	
	~Linie();

	int getNumar();
	void setNumar(int);
	vector<string> getStatii();
	void setStatii(vector<string>);
	int getNrStatii();
	string getTip();
	void setTip(string);

	bool compare(const Linie&);
	Linie& operator=(const Linie&);

	friend ostream& operator<<(ostream&, const Linie*);


};




#endif