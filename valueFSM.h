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
enum valueStates : stateType { INIT_VALUE, STRING, NUMBER, OBJECT, ARRAY, TRUE, FALSE, _NULL, END};
typedef enum { QUOTES, INTEGER, O_BRACES, O_BRACKETS, O_TRUE, O_FALSE, O_NULL, _EOF, UNVALID_CHAR } valuetEvents;

class valueFSM : public genericFSM //Despues de doble punto o de corchete va una value
{
	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&valueFSM::x))

	const fsmCell fsmTable[3][9] = {
		//Event "			Event INT			Event {				Event [				Event "True"		Event "False"		Event "NULL"		Event EOF			Event unvalid
		{{STRING,TX(end)},	{NUMBER,TX(end)},	{OBJECT,TX(end)},	{ARRAY,TX(end)},	{TRUE,TX(end)},		{FALSE,TX(end)},	{_NULL,TX(end)},	{END,TX(error)},	{END,TX(error)}},	//State INIT_VALUE

	};

	void error(genericEvent* ev);
	void end(genericEvent* ev);
};

#endif // !VALUEFSM_H