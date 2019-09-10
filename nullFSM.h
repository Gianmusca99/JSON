#ifndef NULLFSM_H
#define NULLFSM_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 *******************************************************************************/
enum nullStates : stateType { S_N, S_U, S_L, S_LL, FINIT };
typedef enum { EV_U, EV_L, OTHER, END_CHAR } nullEvents;
/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class nullFSM;

class nullFSM : public genericFSM
{
public:

	nullFSM() : genericFSM(&nullTable[0][0], 4, 4, S_N, (assignType)& assignValue) {}

private:

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&nullFSM::x))

	const fsmCell nullTable[4][4] = {
		//		'U'							'L'					  OTHER					END_CHAR
		{ {S_U, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_N
		{ {FINIT, TX(error)},		{S_L, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_U
		{ {FINIT, TX(error)},		{S_LL, TX(nothing)},	{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_L
		{ {FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(end)}	},	//S_LL
	};

	void assignValue(genericEvent* ev);

};

#endif // NULLFSM_H