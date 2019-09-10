#ifndef TRUEFSM_H
#define TRUEFSM_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 *******************************************************************************/
#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&trueFSM::x))

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class trueFSM;

class trueFSM : public genericFSM
{
public:

	trueFSM() : genericFSM(&trueTable[0][0], 4, 5, S_T, TX(assignValue)) {}

private:

	enum trueStates : stateType { S_T, S_R, S_U, S_E, FINIT };
	typedef enum { EV_R, EV_U, EV_E, OTHER, END_CHAR } trueEvents;

	const fsmCell trueTable[4][5] = {
		//		'R'						'U'						'E'						OTHER				END_CHAR
		{ {S_R, TX(nothing)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_T
		{ {FINIT, TX(error)},	{S_U, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_R
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{S_E, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_U
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(end)}	},	//S_E
	};

	void assignValue(genericEvent* ev);

};

#endif // TRUEFSM_H