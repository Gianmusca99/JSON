#ifndef GENERICFSM_H
#define GENERICFSM_H

#include "eventClass.h"
#include "types.h"

class genericFSM;
using stateType = uint;
using eventType = uint;

struct fsmCell
{
	stateType nextState;
	void (genericFSM::* action) (genericEvent*);
};

class genericFSM 
{
	public:

	genericFSM(const fsmCell* table, uint rows, uint cols, stateType initState);
	void cycle(eventGenerator* generator);
	stateType getState(void);

	private:
	stateType state;
	uint rowCount;
	uint colCount;
	const fsmCell* FSMTable;

};

#endif // GENERICFSM_H