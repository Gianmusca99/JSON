#ifndef GENERICFSM_H
#define GENERICFSM_H

#include "eventClass.h"
#include "types.h"

#define NO_VALUE -2
#define END -1

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

	genericFSM();
	genericFSM(const fsmCell* table, uint lines, uint cols, stateType initState);
	void setFSMTable(const fsmCell*);
	void cycle(eventGenerator* generator);
	void nothing(genericEvent* ev);
	stateType getState(void);


	private:
	stateType state;
	uint lineCount;
	uint colCount;
	const fsmCell* FSMTable;

};

#endif // GENERICFSM_H