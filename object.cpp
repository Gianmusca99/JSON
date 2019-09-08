#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

enum objStates: stateTypes {Init};

class objectFSM;

class objectFSM : public genericFSM
{
	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&objectFSM::x))
		const fsmCell fsmTable[5][5] = {
			//		Event '{'		Event','		Event'
				{	{Init,TX(f)},	{Init,TX(f)},		{Init,TX(f)} 	}

		};

		void f(genericEvent* ev) {
			return;
		}
};