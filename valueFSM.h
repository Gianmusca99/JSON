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
#define VX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&valueFSM::x))

class valueFSM : public genericFSM //Despues de doble punto o de corchete va una value
{
	public:
	
	valueFSM() : genericFSM(&valueTable[0][0], 8, 9, INIT_VALUE, VX(assignValue)) {}

	private:

	enum valueStates : stateType { INIT_VALUE, STRING, NUMBER, OBJECT, ARRAY, TRUE, FALSE, NUL };
	typedef enum { QUOTES, INTEGER, O_BRACES, O_BRACKETS, O_TRUE, O_FALSE, O_NULL, INVALID_CHAR, END_CHAR } valueEvents;

	const fsmCell valueTable[8][9] = {
		//Event "				Event INT				Event {					Event [					Event "True"			Event "False"			Event "NULL"			Event invalid			Event END_CHAR
		{{STRING,VX(nothing)},	{NUMBER,VX(nothing)},	{OBJECT,VX(nothing)},	{ARRAY,VX(nothing)},	{TRUE,VX(nothing)},		{FALSE,VX(nothing)},	{NUL,VX(nothing)},		{ERROR,VX(error)},		{END,VX(end)}	},	//State INIT_VALUE
		{{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{END,VX(end)}	},	//State STRING
		{{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{END,VX(end)}	},	//State NUMBER
		{{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{END,VX(end)}	},	//State OBJECT
		{{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{END,VX(end)}	},	//State ARRAY
		{{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{END,VX(end)}	},	//State TRUE
		{{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{END,VX(end)}	},	//State FALSE
		{{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{ERROR,VX(error)},		{END,VX(end)}	},	//State NULL

	};

	void assignValue(genericEvent* ev);
	void nextFSM(genericFSM** stackFSM, uint& stackLevel) override;
};

#endif // VALUEFSM_H