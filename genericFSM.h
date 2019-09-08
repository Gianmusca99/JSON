#ifndef GENERICFSM_H
#define GENERICFSM_H

#include "eventClass.h"
#include "types.h"

class genericFSM;
using stateType = uint;

struct fsmCell
{
	stateType nextState;
	void (genericFSM::* action) (genericEvent*);
};

class genericFSM 
{
	public:

	genericFSM(const fsmCell* const table, const uint rows, const uint cols, stateType initState);
	void cycle(genericEvent* ev);

	private:
	stateType state;
	const uint rowCount;
	const uint colCount;
	fsmCell* const FSMTable;

};

#endif // GENERICFSM_H