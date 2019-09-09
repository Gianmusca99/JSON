#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&stringFSM::x))

enum stringStates : stateType { INIT, INS_STRING, CTRL_CHAR, FINISH};
typedef enum { VALID_CHAR, BACKSLASH, UNVALID_CHAR, QUOTES } stringEvents;

class stringFSM;

class stringFSM : public genericFSM
{
	private:

		const fsmCell stringTable[3][4] =
		{	//   Event validChar,				Event '\',				Event unvalidChar,			Event '"'
			{{INS_STRING, TX(nothing)},		{CTRL_CHAR, TX(nothing)},	{FINISH, TX(error)},	{FINISH, TX(end)}},				//State INIT
			{{INS_STRING, TX(nothing)},		{CTRL_CHAR, TX(nothing)},	{FINISH, TX(error)},	{FINISH, TX(end)}},				//State INS_STRING
			{{INS_STRING, TX(nothing)},		{INS_STRING, TX(nothing)},	{FINISH, TX(error)},	{INS_STRING, TX(nothing)}}		 //State CTRL_CHAR
		};

		void nothing(genericEvent* ev)
		{
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
};