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
#define FX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&falseFSM::x))

 /*******************************************************************************
* CLASS PROTOTYPE
******************************************************************************/
class falseFSM;

class falseFSM : public genericFSM
{
public:

	falseFSM() : genericFSM(&falseTable[0][0], 5, 6, S_F, FX(assignValue)) {}

private:

	enum falseStates : stateType { S_F, S_A, S_L, S_S, S_E};
	typedef enum { EV_A, EV_L, EV_S, EV_E, OTHER, END_CHAR } falseEvents;

	const fsmCell falseTable[5][6] = {
		//		'A'						'L'						'S'						'E'					OTHER					END_CHAR
		{ {S_A, FX(nothing)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)}	},	//S_F
		{ {ERROR, FX(error)},		{S_L, FX(nothing)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)}	},	//S_A
		{ {ERROR, FX(error)},		{ERROR, FX(error)},		{S_S, FX(nothing)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)}	},	//S_L
		{ {ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{S_E, FX(nothing)},		{ERROR, FX(error)},		{ERROR, FX(error)}	},	//S_S
		{ {ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{ERROR, FX(error)},		{END, FX(end)}		},	//S_E
	};

	void assignValue(genericEvent* ev);

};

#endif // FALSEFSM_H