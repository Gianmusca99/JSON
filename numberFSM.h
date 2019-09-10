#ifndef NUMBERFSM_H
#define NUMBERFSM_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

 /*******************************************************************************
  * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
  ******************************************************************************/
#define NUMX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&numberFSM::x))

  /*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class numberFSM;

class numberFSM : public genericFSM
{
public:

	numberFSM() : genericFSM(&numberTable[0][0], 5, 8, INIT, NUMX(assignValue)) {}

private:

	enum numberStates : stateType { INIT, CERO, INTEGER, FRACTION, EXPONENT, FINIT };
	typedef enum { DIGIT, EV_CERO, MINUS, PLUS, POINT, EXP, END_CHAR, INVALID } numberEvents;

	const fsmCell numberTable[5][8] = {
		//		DIGIT							EV_CERO							MINUS							PLUS							POINT							EXP							END_CHAR				INVALID
		{ {INTEGER, NUMX(nothing)},		{CERO, NUMX(nothing)},			{INTEGER, NUMX(nothing)},		{FINIT, NUMX(error)},			{FINIT, NUMX(error)},			{FINIT, NUMX(error)},			{FINIT, NUMX(error)},	{FINIT, NUMX(error)}	},	//INIT
		{ {FINIT, NUMX(error)},			{FINIT, NUMX(error)},			{FINIT, NUMX(error)},			{FINIT, NUMX(error)},			{FRACTION, NUMX(nothing)},		{EXPONENT, NUMX(nothing)},		{FINIT, NUMX(end)},		{FINIT, NUMX(error)}	},	//CERO
		{ {INTEGER, NUMX(nothing)},		{INTEGER, NUMX(nothing)},		{FINIT, NUMX(error)},			{FINIT, NUMX(error)},			{FRACTION, NUMX(nothing)},		{EXPONENT, NUMX(nothing)},		{FINIT, NUMX(end)},		{FINIT, NUMX(error)}	},	//INTEGER
		{ {FRACTION, NUMX(nothing)},	{INTEGER, NUMX(nothing)},		{FRACTION, NUMX(error)},		{FINIT, NUMX(error)},			{FINIT, NUMX(error)},			{EXPONENT, NUMX(nothing)},		{FINIT, NUMX(end)},		{FINIT, NUMX(error)}	},	//FRACTION
		{ {EXPONENT, NUMX(nothing)},	{INTEGER, NUMX(nothing)},		{EXPONENT, NUMX(nothing)},		{EXPONENT, NUMX(nothing)},		{FINIT, NUMX(error)},			{FINIT, NUMX(error)},			{FINIT, NUMX(end)},		{FINIT, NUMX(error)}	},	//EXPONENT
	};

	void assignValue(genericEvent* ev);

};

#endif // NUMBERFSM_H