#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&trueFSM::x))

enum trueStates : stateType { S_T, S_R, S_U, S_E, FINIT };
typedef enum { EV_R, EV_U, EV_E, OTHER, END_CHAR } trueEvents;

class trueFSM;

using namespace std;

class trueFSM : public genericFSM
{

private:
	const fsmCell fsmTable[4][5] = {
		//		'R'						'U'						'E'						OTHER				END_CHAR
		{ {S_R, TX(nothing)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_T
		{ {FINIT, TX(error)},	{S_U, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_R
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{S_E, TX(nothing)},		{FINIT, TX(error)},		{FINIT, TX(error)}	},	//S_U
		{ {FINIT, TX(error)},	{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(error)},		{FINIT, TX(end)}	},	//S_E
	};

	void error(genericEvent* ev)
	{
		ev->setKey(NULL);
	}

	void end(genericEvent* ev)
	{
		ev->setKey(NULL);
	}

public:
	trueFSM() :genericFSM(&fsmTable[0][0], 4, 5, S_T) {}

};