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
	FILE *fp;	

	switch (argc) {
		case 1:
			// each line as nodes into a linked list
			//pStart = readStdin(); // this function into readwrite.c
			//reverseLines(&pStart);
			//write(stdout, pStart);
			//freeNodes(pStart);
			break;
		case 2:
			pStart = readFile(argv[1]);
			reverseLines(&pStart);
			write(stdout, pStart);
			freeNodes(pStart);
			break;
		case 3:
			pStart = readFile(argv[1]);
			reverseLines(&pStart);
			fp = openFile(pStart, argv[2]);
			write(fp, pStart);
			fclose(fp);
			freeNodes(pStart);
			break;
		default:
			printf("usage: reverse <input> <output>\n");
			exit(1);
	}

	return 0;
}

/*******************************************************************/
/* eof */
