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

	numberFSM() : genericFSM(&numberTable[0][0], 5, 9, INIT, NUMX(assignValue)) {}

private:

	enum numberStates : stateType { INIT, CERO, INTEGER, FRACTION, EXPONENT};
	typedef enum { DIGIT, EV_CERO, MINUS, PLUS, POINT, EXP, END_CHAR, INVALID, _EOF} numberEvents;

	const fsmCell numberTable[5][9] = {
		//		DIGIT							EV_CERO							MINUS							PLUS							POINT							EXP							END_CHAR				INVALID					EOF
		{ {INTEGER, NUMX(nothing)},		{CERO, NUMX(nothing)},			{INTEGER, NUMX(nothing)},		{ERROR, NUMX(error)},			{ERROR, NUMX(error)},			{ERROR, NUMX(error)},			{END, NUMX(end)},		{ERROR, NUMX(error)},	{END, NUMX(end)}	},		//INIT
		{ {ERROR, NUMX(error)},			{ERROR, NUMX(error)},			{ERROR, NUMX(error)},			{ERROR, NUMX(error)},			{FRACTION, NUMX(nothing)},		{EXPONENT, NUMX(nothing)},		{END, NUMX(end)},		{ERROR, NUMX(error)},	{END, NUMX(end)}	},	//CERO
		{ {INTEGER, NUMX(nothing)},		{INTEGER, NUMX(nothing)},		{ERROR, NUMX(error)},			{ERROR, NUMX(error)},			{FRACTION, NUMX(nothing)},		{EXPONENT, NUMX(nothing)},		{END, NUMX(end)},		{ERROR, NUMX(error)},	{END, NUMX(end)}	},	//INTEGER
		{ {FRACTION, NUMX(nothing)},	{INTEGER, NUMX(nothing)},		{FRACTION, NUMX(error)},		{ERROR, NUMX(error)},			{ERROR, NUMX(error)},			{EXPONENT, NUMX(nothing)},		{END, NUMX(end)},		{ERROR, NUMX(error)},	{END, NUMX(end)}	},	//FRACTION
		{ {EXPONENT, NUMX(nothing)},	{INTEGER, NUMX(nothing)},		{EXPONENT, NUMX(nothing)},		{EXPONENT, NUMX(nothing)},		{ERROR, NUMX(error)},			{ERROR, NUMX(error)},			{END, NUMX(end)},		{ERROR, NUMX(error)},	{END, NUMX(end)}	},	//EXPONENT
	};

	void assignValue(genericEvent* ev);
};

#endif // NUMBERFSM_H