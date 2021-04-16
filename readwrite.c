/*******************************************************************/
/* CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
 * readwrite.c
 * Aino Liukkonen
 * 13.4.2021
/*******************************************************************/

// Just dumping this here to see if I can get some inspo:
// https://www.geeksforgeeks.org/reverse-a-linked-list/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readwrite.h"

/* Function read() reads the contents of an input file and stores
each line of the file in a linked list */
NODE *read(char *name) {
	NODE *pStart = NULL, *pEnd = NULL, *ptr;
	FILE *inputFile;
	char line[200];
	char *tok;

	/* Opening the input file */
	if ((inputFile = fopen(name, "r")) == NULL) {
		perror("Error while reading the file"); // CORRECT THE ERROR HANDLING FOR THE PROJECT!
		exit(1);
	}

	printf("Luetaan inputFile '%s'\n", name); // For testing, get rid of this later


	/* Reading the file line by line */
	while ((fgets(line, 99, inputFile)) != NULL && strlen(line) > 1) {
		if ((ptr = (NODE*)malloc(sizeof(NODE))) == NULL) {
			perror("Malloc error while reading a file."); // Correct way to handle malloc error for the project?
			exit(1);
		}

		printf(line); 				// TESTING :)

		tok = strtok(line, "\n");
		strcpy(ptr->string, tok);	// Copying the line into a list NODE


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

void write(NODE *pStart, char *name) { 		// PASS FILE NAME AS AN ARGUMENT
	FILE *outputFile;
	NODE *ptr = pStart;

	/* Opening the output file */
	if ((outputFile = fopen("testfile2.txt", "w")) == NULL) {
		printf("Error at writing to a file.\n");
		exit(1);
	}
	
	/* Write into output file */
	//fprintf(outputFile, line); 
	while (ptr != NULL) {
		fprintf(outputFile, "%s", ptr->string);
		ptr = ptr->pNext;
	}

	fclose(outputFile);
	printf("Woop woop now let's try reverse :)\n");
}

/*******************************************************************/
/* eof */
