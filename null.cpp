#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&nullFSM::x))

enum nullStates : stateType { S_N, S_U, S_L, S_LL, FINIT };
typedef enum { EV_U, EV_L, OTHER, END_CHAR } nullEvents;

class nullFSM;

using namespace std;

class nullFSM : public genericFSM
{

private:
	const fsmCell fsmTable[4][4] = {
		//		'U'							'L'					  OTHER					END_CHAR
		{ {S_U, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_N
		{ {FINIT, TX(error)},		{S_L, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_U
		{ {FINIT, TX(error)},		{S_LL, TX(nothing)},	{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_L
		{ {FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(end)}	},	//S_LL
	};

public:
	nullFSM() :genericFSM(&fsmTable[0][0], 4, 4, S_N) {}

};