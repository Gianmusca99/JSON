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
enum elementStates : stateType { INIT_ELEMENT, STRING, OBJECT, ARRAY, TRUE, FALSE, NUMBER};
typedef enum { QUOTES, O_BRACE, O_BRACKETS, O_TRUE, O_FALSE, O_NUMBER, _EOF } elementEvents;

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class elementFSM;

class elementFSM : public genericFSM
{
public:

	elementFSM() : genericFSM(&elementTable[0][0], 1, 8, INIT_ELEMENT, (assignType)& assignValue) {}
	void setStackLevel(uint);
	uint getStackLevel(void);

private:

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&elementFSM::x))

	const fsmCell elementTable[1][8] = {
		//Event "					Event {						Event [					Event true			Event false				Event number			Event ','						Event EOF
		{{STRING,TX(nextFSM)},	{OBJECT,TX(nextFSM)},		{ARRAY,TX(nextFSM)},	{TRUE,TX(nextFSM)},		{FALSE,TX(nextFSM)},	{NUMBER,TX(nextFSM)},	{INIT_ELEMENT, TX(nothing)},	{END, TX(end)}}		//State INIT_ELEMENT
	};

	void nextFSM(genericEvent* ev);
	void end(genericEvent* ev);
	void assignValue(genericEvent* ev);
	
	genericFSM* stackFSM[100];
	uint stackLevel;

};

#endif // ELEMENTFSM_H