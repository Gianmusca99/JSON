#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&falseFSM::x))

enum falseStates : stateType { S_F, S_A, S_L, S_S, S_E, FINIT };
typedef enum { EV_A, EV_L, EV_S, EV_E, OTHER, END_CHAR } falseEvents;

class falseFSM;

using namespace std;

class falseFSM : public genericFSM
{

private:

	const fsmCell fsmTable[5][6] = {
		//		'A'						'L'						'S'						'E'					OTHER					END_CHAR
		{ {S_A, TX(nothing)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_F
		{ {FINIT, TX(error)},	{S_L, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_A
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{S_S, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_L
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{S_E, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_S
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(end)}	},	//S_E
	};


public:
	falseFSM() :genericFSM(&fsmTable[0][0], 5, 6, S_F) {}

};