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

genericFSM::genericFSM(const fsmCell* table, uint lines, uint cols, stateType initState, void (genericFSM::* newAssignValue)(genericEvent* ev))
{
	FSMTable = table;
	lineCount = lines;
	colCount = cols;
	state = initState;
	assignValue = newAssignValue;
}

void genericFSM::cycle(eventGenerator* generator)
{
	int value;

	while (state != END && state != ERROR)
	{
		generator->getNextEvent();
		(this->*assignValue)(generator->getCurrentEvent());
		value = (generator->getCurrentEvent())->getEvValue();

		FSMTable[state * colCount + value].action;
		state = FSMTable[state*colCount + value].nextState;
		generator->setLastEvent(generator->getCurrentEvent());
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