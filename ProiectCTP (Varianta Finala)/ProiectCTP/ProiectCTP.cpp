#include "Tests.h"
#include "CTP.h"
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;
int main() 
{
	/*test_Linie();
	test_Autobuz();
	test_Bilet();
	test_CosDeCumparaturi();
	test_Utilizator();
	test_Database();
	test_Controller();	*/
	CTP* ctp = new CTP();
	ctp->Run();
	return 0;
}
