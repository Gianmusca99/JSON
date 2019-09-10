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

	nullFSM() : genericFSM(&nullTable[0][0], 4, 5, S_N, NX(assignValue)) {}

private:

	enum nullStates : stateType { S_N, S_U, S_L, S_LL };
	typedef enum { EV_U, EV_L, OTHER, END_CHAR, _EOF } nullEvents;

	const fsmCell nullTable[4][5] = {
		//		'U'							'L'					  OTHER					END_CHAR					_EOF	
		{ {S_U, NX(nothing)},		{ERROR, NX(error)},		{ERROR, NX(error)},		{ERROR, NX(error)},		{ERROR, NX(error)}},	//S_N
		{ {ERROR, NX(error)},		{S_L, NX(nothing)},		{ERROR, NX(error)},		{ERROR, NX(error)},		{ERROR, NX(error)}},	//S_U
		{ {ERROR, NX(error)},		{S_LL, NX(nothing)},	{ERROR, NX(error)},		{ERROR, NX(error)},		{ERROR, NX(error)}},	//S_L
		{ {ERROR, NX(error)},		{ERROR, NX(error)},		{ERROR, NX(error)},		{END, NX(end)},			{END, NX(end)}},		//S_LL
	};

	void assignValue(genericEvent* ev);

};

#endif // NULLFSM_H