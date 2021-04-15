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

/* Reading a file into a linked list */
NODE *read(char *name) {
	NODE *pStart = NULL, *pEnd = NULL, *ptr;
	FILE *inputFile;
	char line[200];
	char *tok;
	int i, t, lineCount = 0;	// is lineCount needed anywhere?

	/* Opening the file */
	if ((inputFile = fopen(name, "r")) == NULL) {
		perror("Error while reading the file"); // CORRECT THE ERROR HANDLING FOR THE PROJECT!
		exit(1);
	}

	printf("Luetaan inputFile '%s'\n", name); // For testing, get rid of this later

	/* Reading the first line of the file */
	/* GET RID OF THIS LATER!?)*/
	if ((fgets(line, 99, inputFile)) == NULL) { 
		perror("Error while reading the file");
		exit(1);
	}
	printf("jei");

	/* Reading the file line by line */
	while ((fgets(line, 99, inputFile)) != NULL && strlen(line) > 1) {
		if ((ptr = (NODE*)malloc(sizeof(NODE))) == NULL) {
			perror("Malloc error"); // Correct way to handle malloc error for the project?
			exit(1);
		}

		printf("line"); 				// TESTING :)

		tok = strtok(line, "\n");
		strcpy(ptr->string, tok);


		ptr->pNext = NULL;
		if (pStart == NULL) { 		// If the list is empty
			pStart = ptr;
			pEnd = ptr;
		}
		else { 						// If there are already nodes in the list
			pEnd->pNext = ptr;
			pEnd = ptr;
		}
		lineCount++;
	}
									// For testing purposes,
	printf("Tiedosto '%s' luettu, %d riviä.\n", name, lineCount); 	// unnecessary for the project
	
	fclose(inputFile);

	return pStart;	
}

/*******************************************************************/
/* eof */
