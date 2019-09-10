#ifndef VALUEFSM_H
#define VALUEFSM_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"	

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum valueStates : stateType { INIT_VALUE, STRING, NUMBER, OBJECT, ARRAY, TRUE, FALSE, NUL, FIN };
typedef enum { QUOTES, INTEGER, O_BRACES, O_BRACKETS, O_TRUE, O_FALSE, O_NULL, INVALID_CHAR } valueEvents;

class valueFSM : public genericFSM //Despues de doble punto o de corchete va una value
{
	public:
	
	valueFSM() : genericFSM(&valueTable[0][0], 1, 9, INIT_VALUE, (assignType) &assignValue) {}

	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&valueFSM::x))

	const fsmCell valueTable[8][9] = {
		//Event "				Event INT				Event {					Event [					Event "True"			Event "False"			Event "NULL"			Event invalid
		{{STRING,TX(nothing)},	{NUMBER,TX(nothing)},	{OBJECT,TX(nothing)},	{ARRAY,TX(nothing)},	{TRUE,TX(nothing)},		{FALSE,TX(nothing)},	{NUL,TX(nothing)},	{FIN,TX(error)}		},	//State INIT_VALUE
		{{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)}		},	//State STRING
		{{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)}		},	//State NUMBER
		{{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)}		},	//State OBJECT
		{{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)}		},	//State ARRAY
		{{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)}		},	//State TRUE
		{{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)}		},	//State FALSE
		{{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)}		},	//State NULL

	};

	void assignValue(genericEvent* ev);
};

#endif // VALUEFSM_H