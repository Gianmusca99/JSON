/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "parseCmd.h"
#include "eventClass.h"
#include "elementFSM.h"

using namespace std;

static void printHelpText();

int main(int argc, char** argv)
{
	char* userData = NULL;

	int isValid = parseCmd(argc, argv, &userData);
	if (isValid == ERRCODE)
	{
		printHelpText();
		return 0;
	}

	cout << userData << endl;

	FILE* file = NULL;
	if (fopen_s(&file, userData, "r")) {
		return 0;
	}

	eventGenerator generator(1, file);
	elementFSM element;

	while (element.getState() != EOF) {
		element.cycle(&generator);
		element.returnFSM(generator.getCurrentEvent());
	}
	printf("LLEGO A TERMINAR");

	fclose(file);
	return 0;
}


static void printHelpText() {
	cout << "\n****************************** HELP TEXT ******************************\n\n";
	cout << "Por favor ingrese un archivo .json valido\n";

	return;
}

