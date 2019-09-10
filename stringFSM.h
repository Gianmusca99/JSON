#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

#define SX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&stringFSM::x))

class stringFSM : public genericFSM
{
	public:

		stringFSM() : genericFSM(&stringTable[0][0], 3, 4, INS_STRING, SX(assignValue)){}

	private:
		enum stringStates : stateType { INIT, INS_STRING, CTRL_CHAR, FINISH };
		typedef enum { VALID_CHAR, BACKSLASH, QUOTES, _EOF } stringEvents;

		const fsmCell stringTable[3][4] =
		{	//   Event validChar,				Event '\\',				Event '"',						Event EOF
			{{INS_STRING, SX(nothing)},		{CTRL_CHAR, SX(nothing)},	{FINISH, SX(end)},			{FINISH, SX(error)}},		//State INIT
			{{INS_STRING, SX(nothing)},		{CTRL_CHAR, SX(nothing)},	{FINISH, SX(end)},			{FINISH, SX(error)}},		//State INS_STRING
			{{INS_STRING, SX(nothing)},		{INS_STRING, SX(nothing)},	{INS_STRING, SX(nothing)},	{FINISH, SX(error)}}		//State CTRL_CHAR
		};

		void error(genericEvent* ev);
		void end(genericEvent* ev);
		void assignValue(genericEvent* ev);
};


