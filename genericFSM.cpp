#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

genericFSM::genericFSM(void)
{
	FSMTable = NULL;
	assignValue = NULL;
	lineCount = 0;
	colCount = 0;
	state = NULL;
}

genericFSM::genericFSM(const fsmCell* table, uint lines, uint cols, stateType initState, assignType newAssignValue)
{
	FSMTable = table;
	lineCount = lines;
	colCount = cols;
	state = initState;
	assignValue = newAssignValue;
}

void genericFSM::cycle(eventGenerator* generator)
{
	genericEvent* ev;
	int value;

	while (state != END && state != ERROR)
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

void genericFSM::end(genericEvent* ev)
{
	state = END;
	return;
}

void genericFSM::error(genericEvent* ev)
{
	state = ERROR;
	return;
}


void genericFSM::setFSMTable(const fsmCell* newTable)
{
	FSMTable = newTable;
}