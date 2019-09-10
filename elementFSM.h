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

	elementFSM() : genericFSM(&elementTable[0][0], 1, 9, INIT_ELEMENT, EX(assignValue)) {
		stackLevel = 0;
	}
	void setStackLevel(uint);
	uint getStackLevel(void);
	void returnFSM(genericEvent* ev);

private:

	enum elementStates : stateType { INIT_ELEMENT, STRING, NUMBER, OBJECT, ARRAY, TRUE, FALSE, NUL, FINIT };
	typedef enum { QUOTES, O_BRACES, O_BRACKETS, O_TRUE, O_FALSE, O_NUMBER, INVALID_CHAR, _EOF } elementEvents;

	const fsmCell elementTable[1][9] = {
		//Event "					Event {						Event [					Event true			Event false				Event number			Event ','						Event INVALID_CHAR		Event EOF			
		{{STRING,EX(nextFSM)},	{OBJECT,EX(nextFSM)},		{ARRAY,EX(nextFSM)},	{TRUE,EX(nextFSM)},		{FALSE,EX(nextFSM)},	{NUMBER,EX(nextFSM)},	{INIT_ELEMENT, EX(nothing)},	{FINIT, EX(error)},		{FINIT, EX(end)}}		//State INIT_ELEMENT
	};

	void nextFSM(genericEvent* ev);
	void assignValue(genericEvent* ev);
	
	genericFSM* stackFSM[100];
	uint stackLevel;

};

#endif // ELEMENTFSM_H