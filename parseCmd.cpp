#include "parseCmd.h"
#include <iostream>

using namespace std;

int parseCmd(int argc, char* argv[], char** userData)
{
	int r = true;

	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i] != '.')
		{
			i++;
		}

		if (!strcmp(".json", argv[1] + i))
		{ 
			*(userData) = argv[1];
		}

		else
		{
			r = ERRCODE;
		}
	}
	
	else
		r = ERRCODE;

	return r;

}