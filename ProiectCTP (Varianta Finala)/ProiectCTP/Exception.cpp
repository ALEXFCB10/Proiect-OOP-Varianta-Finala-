/*
 * Exception.cpp
 *
 *  Created on: May 14, 2019
 *      Author: Alex
 */
#include "Exception.h"

Exception::Exception(const char* s) {
	/* Subprogramul construieste un obiect de tipul Exception
		 Input:s
		 Preconditii:s reprezinta numele exceptiei
		 Output:un obiect de tipul Exceptie
		 Postconditii:-
		 Error:-
	 */
	message = s;
}

const char* Exception::getMessage() {
	/* Subprogramul returneaza mesajul exceptiei curente
		 Input:-
		 Preconditii:-
		 Output:exceptia curenta
		 Postconditii:-
		 Error:-
	 */
	return this->message;
}



