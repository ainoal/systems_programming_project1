/*******************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
 * readwrite.c
 * Aino Liukkonen
 * 13.4.2021
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readwrite.h"

/* Function read() reads the contents of an input file and stores
each line of the file in a linked list */
NODE *readFile(char *name) {
	NODE *pStart = NULL, *pEnd = NULL, *ptr;
	FILE *inputFile;
	char line[200]; // !!!! "YOU MAY NOT ASSUME ANYTHING ABOUT HOW LONG A LINE SHOULD BE" !!!!!!!
	char *tok;

	/* Open the input file */
	if ((inputFile = fopen(name, "r")) == NULL) {
		perror("malloc failed"); 
		exit(1);
	}

	printf("Luetaan inputFile '%s'\n", name); // For testing, get rid of this later


	/* Read the file line by line */
	while ((fgets(line, 99, inputFile)) != NULL && strlen(line) > 1) {
		if ((ptr = (NODE*)malloc(sizeof(NODE))) == NULL) {
			perror("malloc failed");
			exit(1);
		}

		tok = strtok(line, "\n");
		strcpy(ptr->string, tok);	// Copy the line into a list NODE


		ptr->pNext = NULL;
		if (pStart == NULL) { 		// If the list is empty
			pStart = ptr;
			pEnd = ptr;
		}
		else { 						// If there are already nodes in the list
			pEnd->pNext = ptr;
			pEnd = ptr;
		}
	}

	fclose(inputFile);

	return pStart;	
}

/* Function to reverse the linked list and thereby reverse the order
of input lines. Reference: 
https://www.geeksforgeeks.org/reverse-a-linked-list/ */
void reverseLines(NODE **pStart) {
	NODE *pPrev = NULL, *pNext = NULL;
	NODE *ptr = *pStart;

	while(ptr != NULL) {
		pNext = ptr->pNext;		// Store the next node
		ptr->pNext = pPrev;		// Reverse the current node's pointer
		
		pPrev = ptr;			// Move the pointers one position
		ptr = pNext;			// ahead in the linked list
	}
	*pStart = pPrev;
}

void writeFile(NODE *pStart, char *name) { 
	FILE *outputFile;
	NODE *ptr = pStart;

	/* Open the output file */
	if ((outputFile = fopen(name, "w")) == NULL) {
		printf("Error at writing to a file.\n");
		exit(1);
	}
	
	/* Write into output file */
	//fprintf(outputFile, line); 
	while (ptr != NULL) {
		fprintf(outputFile, "%s\n", ptr->string);
		ptr = ptr->pNext;
	}

	fclose(outputFile);
}

/*******************************************************************/
/* eof */
