#ifndef ELEMENTFSM_H
#define ELEMENTFSM_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

 /*******************************************************************************
  * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
  ******************************************************************************/
#define EX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&elementFSM::x))

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class elementFSM;

class elementFSM : public genericFSM
{
public:

	elementFSM() : genericFSM(&elementTable[0][0], 1, 10, INIT_ELEMENT, EX(assignValue)) {}

private:

	enum elementStates : stateType { INIT_ELEMENT, STRING, OBJECT, ARRAY, TRUE, FALSE, NUL, NUMBER };
	typedef enum { QUOTES, O_BRACES, O_BRACKETS, O_TRUE, O_FALSE, O_NUMBER,O_NULL, INVALID_CHAR, _EOF } elementEvents;

	const fsmCell elementTable[1][10] = {
		//Event "					Event {						Event [					Event true			Event false				Event null			Event number			Event ','						Event INVALID_CHAR		Event EOF			
		{{STRING,EX(nothing)},	{OBJECT,EX(nothing)},		{ARRAY,EX(nothing)},	{TRUE,EX(nothing)},		{FALSE,EX(nothing)},	{NUL,EX(nothing)},  {NUMBER,EX(nothing)},	{INIT_ELEMENT, EX(nothing)},	{ERROR, EX(error)},		{END, EX(end)}	}	//State INIT_ELEMENT
	};

	void nextFSM(genericFSM** stackFSM, uint& stackLevel);
	void assignValue(genericEvent* ev);

};

#endif // ELEMENTFSM_H