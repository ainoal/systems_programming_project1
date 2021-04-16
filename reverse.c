/*******************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
 * reverse.c
 * Aino Liukkonen
 * 13.4.2021
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "readwrite.h"

int main(void) { 
	NODE *pStart = NULL;
	char *name = "testfile.txt";	

	pStart = read(name);
	write(pStart, name);

	return 0;
}

/*******************************************************************/
/* eof */
