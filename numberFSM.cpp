#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&numberFSM::x))
enum numberStates : stateType { INIT, CERO, INTEGER, FRACTION, EXPONENT, FINIT };
typedef enum { DIGIT, CERO, MINUS, PLUS, POINT, EXP, SPACE} numberEvents;

class numberFSM;

using namespace std;

class numberFSM : public genericFSM
{

private:
	const fsmCell fsmTable[5][7] = {
		//		DIGIT						CERO						MINUS						PLUS						POINT					EXP							SPACE
		{ {INTEGER, TX(nothing)},	{CERO, TX(nothing)},		{INTEGER, TX(nothing)},		{FINIT, TX(error)},			{FINIT, TX(error)},			{FINIT, TX(error)},			{FINIT, TX(error)}	},	//INIT
		{ {FINIT, TX(error)},		{FINIT, TX(error)},			{FINIT, TX(error)},			{FINIT, TX(error)},			{FRACTION, TX(nothing)},	{EXPONENT, TX(nothing)},	{FINIT, TX(end)}	},	//CERO
		{ {INTEGER, TX(nothing)},	{INTEGER, TX(nothing)},		{FINIT, TX(error)},			{FINIT, TX(error)},			{FRACTION, TX(nothing)},	{EXPONENT, TX(nothing)},	{FINIT, TX(end)}	},	//INTEGER
		{ {FRACTION, TX(nothing)},	{INTEGER, TX(nothing)},		{FRACTION, TX(error)},		{FINIT, TX(error)},			{FINIT, TX(error)},			{EXPONENT, TX(nothing)},	{FINIT, TX(end)}	},	//FRACTION
		{ {EXPONENT, TX(nothing)},	{INTEGER, TX(nothing)},		{EXPONENT, TX(nothing)},	{EXPONENT, TX(nothing)},	{FINIT, TX(error)},			{FINIT, TX(error)},			{FINIT, TX(end)}	},	//EXPONENT
	};

	void nothing(genericEvent* ev) {
		return;
	}

	void error(genericEvent* ev)
	{
		ev->setType(EV_ERROR);
		ev->setKey(NULL);
	}

	void end(genericEvent* ev)
	{
		ev->setType(EV_QUIT);
		ev->setKey(NULL);
	}

public:
	numberFSM() :genericFSM(&fsmTable[0][0], 5, 7, INIT) {}

};