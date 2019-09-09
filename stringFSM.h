#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&stringFSM::x))

enum stringStates : stateType { INIT, INS_STRING, CTRL_CHAR, FINISH };
typedef enum { VALID_CHAR, BACKSLASH, QUOTES, _EOF } stringEvents;

class stringFSM : public genericFSM
{
	public:

		stringFSM() : genericFSM(&stringTable[0][0], 3, 4, INS_STRING, (assignType)& assignValue){}

	private:

		const fsmCell stringTable[3][4] =
		{	//   Event validChar,				Event '\\',				Event '"',						Event EOF
			{{INS_STRING, TX(nothing)},		{CTRL_CHAR, TX(nothing)},	{FINISH, TX(end)},			{FINISH, TX(error)}},		//State INIT
			{{INS_STRING, TX(nothing)},		{CTRL_CHAR, TX(nothing)},	{FINISH, TX(end)},			{FINISH, TX(error)}},		//State INS_STRING
			{{INS_STRING, TX(nothing)},		{INS_STRING, TX(nothing)},	{INS_STRING, TX(nothing)},	{FINISH, TX(error)}}		//State CTRL_CHAR
		};

		void error(genericEvent* ev);
		void end(genericEvent* ev);
		void assignValue(genericEvent* ev);
};


