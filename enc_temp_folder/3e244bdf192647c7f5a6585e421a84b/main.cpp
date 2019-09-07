/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "parseCallback.h"
#include "parseCmdLine.h"

using namespace std;

static void printHelpText();

int main(int argc, char** argv)
{
	FILE* userData = NULL;
	int ok = parseCmdLine(argc, argv, parseCallback, userData);
	if (ok == ERRCODE || ok == 0)
	{
		printHelpText();
		return 0;
	}

	fclose(userData);
	return 0;
}


static void printHelpText() {
	cout << "\n****************************** HELP TEXT ******************************\n\n";
	cout << "Valid keys: -archivo ""nombre del archivo\n"" ";

	return;
}