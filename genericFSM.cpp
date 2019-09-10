#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

using namespace std;

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

void genericFSM::cycle(eventGenerator* generator, genericFSM** stackFSM, uint& stackLevel)
{
	int value;

	if(state != END && state != ERROR)
	{
		generator->getNextEvent();
		//TURBINA
		(this->*assignValue)(generator->getCurrentEvent());
		value = (generator->getCurrentEvent())->getEvValue();
		//ACA TENGO QUE LLAMAR A LA RUTINA DE LA FSM CON EL EVENTO CORRESPONDIENTE
		FSMTable[state * colCount + value].action;
		state = FSMTable[state*colCount + value].nextState;
		//TURBINA
		generator->setLastEvent(generator->getCurrentEvent());

		this->nextFSM(stackFSM, stackLevel);
	}
	else
	{
		returnFSM(stackFSM, stackLevel);
	}

	return;
}

void genericFSM::returnFSM(genericFSM** stackFSM, uint& stackLevel)
{
	if (state == END)
	{
		delete(stackFSM[stackLevel]);
		stackLevel--;
		printf("Todo piola hasta ac�");
	}
	else if (state == ERROR)
	{
		//identifyError();
		//displayError()

		cout << "Hubo un error en la linea:" << lineCount;

		for (uint i = stackLevel; i > 0; i--)
		{
			delete(stackFSM[i]);
		}
		stackLevel = 0;
		stackFSM[stackLevel]->setState(ERROR);
	}

	return;
}

stateType genericFSM::getState(void)
{
	return state;
}

void genericFSM::setState(stateType newState)
{
	state = newState;
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

void genericFSM::nextFSM(genericFSM** stackFSM, uint& stackLevel)
{
	return;
}