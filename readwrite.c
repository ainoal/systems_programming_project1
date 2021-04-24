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
NODE *readFile(char *fileName) {
	NODE *pStart = NULL, *pEnd = NULL, *ptr;
	FILE *inputFile;
	char *buffer;
	size_t bufferSize = 0;
	ssize_t lineLen;

	/* Open the input file b*/
	if ((inputFile = fopen(fileName, "r")) == NULL) {
		perror("Error at opening file\n"); // ??
		exit(1);
	}

	/* Read the file line by line */
	while ((lineLen = getline(&buffer, &bufferSize, inputFile)) > 0) {
		if ((ptr = (NODE*)malloc(sizeof(NODE))) == NULL) {
			perror("malloc failed\n");
			exit(1);	
		}

		/* Allocate memory for new ptr->string */
		if ((ptr->string = malloc (strlen (buffer) + 1)) == NULL) {
		    perror ("malloc failed\n");
			exit(1);
		}

		strcpy (ptr->string, buffer);  // Copy the line into a list NODE

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

FILE *openFile(NODE *pStart, char *fileName) { 
	FILE *outputFile;

	/* Open the output file */
	if ((outputFile = fopen(fileName, "w")) == NULL) {
		printf("Error at writing to a file.\n");
		exit(1);
	}

	return outputFile;
}

void write(FILE *outputFile, NODE *pStart) {
	NODE *ptr = pStart;

	/* Write into output file */
	while (ptr != NULL) {
		fprintf(outputFile, "%s", ptr->string);
		ptr = ptr->pNext;
	}
}

void freeNodes(NODE *pStart) {
	NODE *ptr = pStart;

	while (ptr != NULL) {
		pStart = ptr->pNext;
		free(ptr);
		ptr = pStart;
	}
}

/*******************************************************************/
/* eof */
