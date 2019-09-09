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
enum valueStates : stateType { INIT_VALUE, STRING, NUMBER, OBJECT, ARRAY, TRUE, FALSE, _NULL};
typedef enum { QUOTES, INTEGER, O_BRACES, O_BRACKETS, O_TRUE, O_FALSE, O_NULL, _EOF, INVALID_CHAR } valueEvents;

class valueFSM : public genericFSM //Despues de doble punto o de corchete va una value
{
	public:
	
	valueFSM() : genericFSM(&valueTable[0][0], 1, 9, INIT_VALUE, (assignType) &assignValue) {}

	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&valueFSM::x))

	const fsmCell valueTable[1][9] = {
		//Event "			Event INT			Event {				Event [				Event "True"		Event "False"		Event "NULL"		Event EOF			Event invalid
		{{STRING,TX(end)},	{NUMBER,TX(end)},	{OBJECT,TX(end)},	{ARRAY,TX(end)},	{TRUE,TX(end)},		{FALSE,TX(end)},	{_NULL,TX(end)},	{END,TX(error)},	{END,TX(error)}},	//State INIT_VALUE

	};

	void error(genericEvent* ev);
	void end(genericEvent* ev);
	void assignValue(genericEvent* ev);
};

#endif // !VALUEFSM_H