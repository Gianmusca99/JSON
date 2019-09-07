#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parseCallback.h"

#define YES 1
#define NO 0

int parseCallback(char* key, char* value, void* userData)
{
	* data = userdata;	//Crea un nuevo puntero para utilizar userData

	int parseOk = NO; //Devuelve por default error

