#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"


genericFSM::genericFSM(const fsmCell* table, uint rows, uint cols, stateType initState)
{
	FSMTable = table;
	rowCount = rows;
	colCount = cols;
	state = initState;
}

void genericFSM::cycle(eventGenerator* generator)
{
	genericEvent* ev;
	int value;

	while (generator->getLastEvent()->getType() != EV_QUIT)
	{
		ev = generator->getNextEvent();
		value = ev->getEvValue();

		if (ev->getType() != NO_EVENT)
		{
			FSMTable[state * colCount + value].action;
			state = FSMTable[state*colCount + value].nextState;
			generator->setLastEvent(ev);
		}
	}
	return;
}


