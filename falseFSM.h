#ifndef FALSEFSM_H
#define FALSEFSM_H

/*******************************************************************************
* INCLUDE HEADER FILES
******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

 /*******************************************************************************
* ENUMERATIONS AND STRUCTURES AND TYPEDEFS
*******************************************************************************/
enum falseStates : stateType { S_F, S_A, S_L, S_S, S_E, FINIT };
typedef enum { EV_A, EV_L, EV_S, EV_E, OTHER, END_CHAR } falseEvents;
 /*******************************************************************************
* CLASS PROTOTYPE
******************************************************************************/
class falseFSM;

class falseFSM : public genericFSM
{
public:

	falseFSM() : genericFSM(&falseTable[0][0], 5, 6, S_F, (assignType)& assignValue) {}

private:

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&falseFSM::x))

	const fsmCell falseTable[5][6] = {
		//		'A'						'L'						'S'						'E'					OTHER					END_CHAR
		{ {S_A, TX(nothing)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_F
		{ {FINIT, TX(error)},	{S_L, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_A
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{S_S, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_L
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{S_E, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_S
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(end)}	},	//S_E
	};

	void assignValue(genericEvent* ev);

};

#endif // FALSEFSM_H