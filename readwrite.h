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

NODE *readFile(char *name);
void reverseLines(NODE **pStart);
void writeFile(NODE *pStart, char *name);

/*******************************************************************/
/* eof */
