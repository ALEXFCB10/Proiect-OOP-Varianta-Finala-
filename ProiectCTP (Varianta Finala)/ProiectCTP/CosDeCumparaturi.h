#ifndef COSDECUMPARATURI_H_
#define COSDECUMPARATURI_H_
#include "Bilet.h"
class CosDeCumparaturi {
private:
	Bilet** bilete;
	int nr_bilete;
	int suma;
public:
	CosDeCumparaturi();
	CosDeCumparaturi(Bilet**, int);
	CosDeCumparaturi(const CosDeCumparaturi*);
	~CosDeCumparaturi();

	Bilet** getBilete();
	void setBilete(Bilet**);
	int getNrBilete();
	void setNrBilete(int);
	int getSuma();
	void setSuma(int);

	void addBilet(Bilet*);

	string toString();
	bool compare(const CosDeCumparaturi*);
	CosDeCumparaturi& operator=(const CosDeCumparaturi&);

	friend ostream& operator<<(ostream&, const CosDeCumparaturi*);
};




#endif