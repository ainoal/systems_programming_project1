/*******************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
 * readwrite.h
 * Aino Liukkonen
 * 13.4.2021
/*******************************************************************/

struct Node {
	char string[200];
	struct Node *pNext;
};

typedef struct Node NODE;

NODE *read(char *name);

//void write(solmu *pAlku, char *nimi);

/*******************************************************************/
/* eof */
