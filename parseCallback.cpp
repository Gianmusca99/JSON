/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "parseCallback.h"

using namespace std;

/*******************************************************************************
* CONSTANT AND MACRO DEFINITIONS USING #DEFINE
******************************************************************************/
#define YES 1
#define NO 0

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef enum { NO_ERR, ERR_ARCH, ERR_CLAVE, ERR_VALOR, ERR_NULL} errType;

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static void showErrs(errType error);


/*******************************************************************************
 *******************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
int parseCallback(char* key, char* value, void* userData)
{
	char** data = (char**)userData;	//Crea un nuevo puntero para utilizar userData

	int parseOk = YES; //Devuelve por default error
	errType error = NO_ERR;

	if (key != NULL)
	{
		if (!strcmp(ARCHIVO, key))
		{
			int i = 0;
			while (value[i] != '.')	
			{
				
			}

			if (!strcmp(".json", value + i))
			{

				*(data) = value;

				if (data == NULL)
				{
					parseOk = NO;
					error = ERR_ARCH;
				}

				*(userData) = *(data);
			}

			else 
			{
				parseOk = NO;
				error = ERR_VALOR;
			}

		}

		else
		{
			parseOk = NO;
			error = ERR_CLAVE;
		}
	}

	else
	{
		parseOk = NO;
		error = ERR_NULL;
	}

	showErrs(error);
	cout << (char*)userData << endl;
	
	return parseOk;
}


/*******************************************************************************
 *******************************************************************************
						LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
static void showErrs(errType error) 
{
	switch (error)
	{
	case ERR_CLAVE:
		cout << "\nClave invalida";
		break;

	case ERR_VALOR:
		cout << "\nExtension de archivo invalida";
		break;

	case ERR_ARCH:
		cout << "\nNo se pudo abrir el archivo";
		break;

	case ERR_NULL:
		cout << "Clave NULL";
		break;

	case NO_ERR:
		break;

	default:
		"Error desconocido";
		break;
	}

	return;
}