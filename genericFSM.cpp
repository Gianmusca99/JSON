#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"


genericFSM::genericFSM(const fsmCell* const table, const uint rows, const uint cols, stateType initState) :
	FSMTable(table), rowCount(rows), colCount(cols), state(initState) { 
}

void genericFSM::cycle(genericEvent* ev)
{
	if (ev != nullptr)
	{

	}

	return;
}

