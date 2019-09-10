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
enum numberStates : stateType { INIT, CERO, INTEGER, FRACTION, EXPONENT, FINIT };
typedef enum { DIGIT, CERO, MINUS, PLUS, POINT, EXP, END_CHAR, INVALID } numberEvents;
/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class numberFSM;

class numberFSM : public genericFSM
{
public:

	numberFSM() : genericFSM(&numberTable[0][0], 5, 8, INIT, (assignType)& assignValue) {}

private:

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&numberFSM::x))

	const fsmCell numberTable[5][8] = {
		//		DIGIT						CERO						MINUS						PLUS						POINT						EXP						END_CHAR			INVALID
		{ {INTEGER, TX(nothing)},	{CERO, TX(nothing)},		{INTEGER, TX(nothing)},		{FINIT, TX(error)},			{FINIT, TX(error)},			{FINIT, TX(error)},			{FINIT, TX(error)},	{FINIT, TX(error)}	},	//INIT
		{ {FINIT, TX(error)},		{FINIT, TX(error)},			{FINIT, TX(error)},			{FINIT, TX(error)},			{FRACTION, TX(nothing)},	{EXPONENT, TX(nothing)},	{FINIT, TX(end)},	{FINIT, TX(error)}	},	//CERO
		{ {INTEGER, TX(nothing)},	{INTEGER, TX(nothing)},		{FINIT, TX(error)},			{FINIT, TX(error)},			{FRACTION, TX(nothing)},	{EXPONENT, TX(nothing)},	{FINIT, TX(end)},	{FINIT, TX(error)}	},	//INTEGER
		{ {FRACTION, TX(nothing)},	{INTEGER, TX(nothing)},		{FRACTION, TX(error)},		{FINIT, TX(error)},			{FINIT, TX(error)},			{EXPONENT, TX(nothing)},	{FINIT, TX(end)},	{FINIT, TX(error)}	},	//FRACTION
		{ {EXPONENT, TX(nothing)},	{INTEGER, TX(nothing)},		{EXPONENT, TX(nothing)},	{EXPONENT, TX(nothing)},	{FINIT, TX(error)},			{FINIT, TX(error)},			{FINIT, TX(end)},	{FINIT, TX(error)}	},	//EXPONENT
	};

	void assignValue(genericEvent* ev);

};

#endif // NUMBERFSM_H