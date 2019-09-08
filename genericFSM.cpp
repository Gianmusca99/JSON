#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"


using stateTypes = uint;

genericFSM::genericFSM(const fsmCell* const table, const uint rows, const uint cols, stateTypes initState) :
	FSMTable(table), rowCount(rows), colCount(cols), state(initState) { 
}

void genericFSM::cycle(genericEvent* ev)
{
	if (ev != nullptr)
	{

	}

	return;
}

