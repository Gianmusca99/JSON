#include <iostream>
#include <functional>
#include "genericFSM.h"
#include "eventClass.h"

using namespace std;
using namespace std::placeholders;

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
		(this->*assignValue)(generator->getCurrentEvent());
		value = (generator->getCurrentEvent())->getEvValue();

		auto f = bind(FSMTable[state * colCount + value].action, this, generator->getCurrentEvent());

		f();

		if (state != END && state != ERROR)
		{
			state = FSMTable[state * colCount + value].nextState;
		}
		
		generator->setLastEvent(generator->getCurrentEvent());

		this->nextFSM(stackFSM, stackLevel);
	}
	else
	{
		returnFSM(generator, stackFSM, stackLevel);
	}

	return;
}

void genericFSM::returnFSM(eventGenerator* gen, genericFSM** stackFSM, uint& stackLevel)
{
	if (state == END)
	{
		delete(stackFSM[stackLevel]);
		stackLevel--;
		printf("Todo piola hasta acá");
	}
	else if (state == ERROR)
	{
		identifyError(gen);

		for (uint i = stackLevel; i > 0; i--)
		{
			delete(stackFSM[i]);
		}
		stackLevel = 0;
		stackFSM[stackLevel]->setState(END);
	}

	return;
}

void genericFSM::identifyError(eventGenerator* gen)
{
	cout << "Error en la linea" << lineCount << endl;

	switch (gen->getCurrentEvent()->getKey())
	{
		case EOF:
			cout << "Falta cerrar un valor" << endl;
			break;
		case ',': case '}' : case ']':
			cout << "Ultimo valor incompleto" << endl;
			break;
		default:
			cout << "Caracter invalido en el bloque local" << endl;
			break;
	}

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