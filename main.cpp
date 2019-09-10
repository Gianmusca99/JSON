/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "parseCmd.h"
#include "eventClass.h"
#include "elementFSM.h"
#include "eventClass.h"
#include "falseFSM.h"
#include "genericFSM.h"
#include "nullFSM.h"
#include "numberFSM.h"
#include "objectFSM.h"
#include "stringFSM.h"
#include "trueFSM.h"
#include "valueFSM.h"
#include "arrayFSM.h"

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

	FILE* file = NULL;
	if (fopen_s(&file, userData, "r")) 
	{
		printHelpText();
		return 0;
	}

	eventGenerator generator(1, file);

	genericFSM* stackFSM[100];
	uint stackLevel = 0;

	elementFSM masterFSM;
	stackFSM[stackLevel] = &masterFSM;

	while (masterFSM.getState() != END)
	{
		stackFSM[stackLevel]->cycle(&generator, stackFSM, stackLevel);
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

