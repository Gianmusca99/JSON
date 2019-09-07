#ifndef GENERICFSM_H
#define GENERICFSM_H


#include "eventHandling.h"
#include "types.h"

class genericFSM;
using stateTypes = uint;

struct fsmCell
{
	stateTypes nextState;
	void (genericFSM::* action) (genericEvent*);
};

class genericFSM 
{
	public:

	genericFSM(const fsmCell* const table, const uint rows, const uint cols, stateTypes initState);
	void cycle(genericEvent* ev);
	genericEvent* getEvent();


	private:
	stateTypes state;
	const uint rowCount;
	const uint colCount;
	const fsmCell* const FSMTable;

};

#endif // GENERICFSM_H