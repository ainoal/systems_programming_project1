/*******************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
 * readwrite.h
 * Aino Liukkonen
 * 13.4.2021
 */
/*******************************************************************/

struct Node {
	char string[200];
	struct Node *pNext;
};

typedef struct Node NODE;

NODE *readFile(char *fileName);
void reverseLines(NODE **pStart);
FILE *openFile(NODE *pStart, char *fileName);
void write(FILE *outputFile, NODE *pStart);
void freeNodes(NODE *pStart);

/*******************************************************************/
/* eof */
