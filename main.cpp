/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "parseCallback.h"
#include "parseCmdLine.h"
#include "arrayFSM.h"
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

	elementFSM masterFSM;
	while (masterFSM.getState() != END)
	{

	}




	//fclose(userData);
	return 0;
}


static void printHelpText() {
	cout << "\n****************************** HELP TEXT ******************************\n\n";
	cout << "Valid keys: -archivo ""nombre del archivo\n"" ";

	return;
}

