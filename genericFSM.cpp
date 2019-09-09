#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

genericFSM::genericFSM(void)
{
	FSMTable = NULL;
	lineCount = 0;
	colCount = 0;
	state = NULL;
}

genericFSM::genericFSM(const fsmCell* table, uint lines, uint cols, stateType initState)
{
	FSMTable = table;
	lineCount = lines;
	colCount = cols;
	state = initState;
}

void genericFSM::cycle(eventGenerator* generator)
{
	genericEvent* ev;
	int value;

	while (state != END)
	{
		ev = generator->getNextEvent();
		(this->*assignValue)(ev);
		value = ev->getEvValue();

		if (value != NO_VALUE)
		{
			FSMTable[state * colCount + value].action;
			state = FSMTable[state*colCount + value].nextState;
			generator->setLastEvent(ev);
		}
	}
	return;
}

stateType genericFSM::getState(void)
{
	return state;
}

void genericFSM::nothing(genericEvent* ev)
{
	return;
}

void genericFSM::setFSMTable(const fsmCell* newTable)
{
	FSMTable = newTable;
}