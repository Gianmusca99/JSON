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
enum valueStates : stateType { INIT_VALUE, STRING, NUMBER, OBJECT, ARRAY, TRUE, FALSE, _NULL, FIN };
typedef enum { QUOTES, INTEGER, O_BRACES, O_BRACKETS, O_TRUE, O_FALSE, O_NULL, INVALID_CHAR } valueEvents;

class valueFSM : public genericFSM //Despues de doble punto o de corchete va una value
{
	public:
	
	valueFSM() : genericFSM(&valueTable[0][0], 1, 9, INIT_VALUE, (assignType) &assignValue) {}

	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&valueFSM::x))

	const fsmCell valueTable[1][9] = {
		//Event "			Event INT			Event {				Event [				Event "True"		Event "False"		Event "NULL"		Event invalid
		{{STRING,TX(end)},	{NUMBER,TX(end)},	{OBJECT,TX(end)},	{ARRAY,TX(end)},	{TRUE,TX(end)},		{FALSE,TX(end)},	{_NULL,TX(end)},	{FIN,TX(error)}},	//State INIT_VALUE

	};

	void assignValue(genericEvent* ev);
};

#endif // VALUEFSM_H