/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "parseCallback.h"
#include "parseCmdLine.h"
#include "eventClass.h"
#include "elementFSM.h"

using namespace std;

static void printHelpText();

int main(int argc, char** argv)
{
	FILE* userData = NULL;

	int isValid = parseCmdLine(argc, argv, parseCallback, userData);
	if (isValid == ERRCODE ||  isValid == 0)
	{
		printHelpText();
		return 0;
	}

	eventGenerator generator(1, userData);
	elementFSM element;

	while (element.getState() != EOF) {
		element.cycle(&generator);
		element.returnFSM(generator.getCurrentEvent());
	}
	printf("LLEGO A TERMINAR");

	fclose(userData);
	return 0;
}


static void printHelpText() {
	cout << "\n****************************** HELP TEXT ******************************\n\n";
	cout << "Valid keys: -archivo ""nombre del archivo\n"" ";

	return;
}

