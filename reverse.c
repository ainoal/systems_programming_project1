/*******************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
 * reverse.c
 * Aino Liukkonen
 * 13.4.2021
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "readwrite.h"

int main(int argc, char *argv[]) { 
	NODE *pStart = NULL;	

	switch (argc) {
		case 1:
			printf("1 arg, not working yet\n");
			break;
		case 2:
			printf("2 args, not working yet\n");
			break;
		case 3:
			pStart = readFile(argv[1]);
			reverseLines(&pStart);
			writeFile(pStart, argv[2]);
			break;
		default:
			printf("usage: reverse <input> <output>\n");
			exit(1);
	}

	return 0;
}

/*******************************************************************/
/* eof */
