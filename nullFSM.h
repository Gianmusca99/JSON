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
#define NX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&nullFSM::x))

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class nullFSM;

class nullFSM : public genericFSM
{
public:

	nullFSM() : genericFSM(&nullTable[0][0], 4, 4, S_N, NX(assignValue)) {}

private:

	enum nullStates : stateType { S_N, S_U, S_L, S_LL, FINIT };
	typedef enum { EV_U, EV_L, OTHER, END_CHAR } nullEvents;

	const fsmCell nullTable[4][4] = {
		//		'U'							'L'					  OTHER					END_CHAR
		{ {S_U, NX(nothing)},		{FINIT, NX(error)},		{FINIT, NX(error)},		{FINIT, NX(error)}	},	//S_N
		{ {FINIT, NX(error)},		{S_L, NX(nothing)},		{FINIT, NX(error)},		{FINIT, NX(error)}	},	//S_U
		{ {FINIT, NX(error)},		{S_LL, NX(nothing)},	{FINIT, NX(error)},		{FINIT, NX(error)}	},	//S_L
		{ {FINIT, NX(error)},		{FINIT, NX(error)},		{FINIT, NX(error)},		{FINIT, NX(end)}	},	//S_LL
	};

	void assignValue(genericEvent* ev);

};

#endif // NULLFSM_H