#ifndef GENERICFSM_H
#define GENERICFSM_H

#include "eventClass.h"
#include "types.h"

class genericFSM;
using stateType = uint;
using eventType = uint;

typedef void (genericFSM::*assignType) (genericEvent*);

struct fsmCell
{
	stateType nextState;
	void (genericFSM::*action) (genericEvent*);
};

class genericFSM 
{
	public:

	genericFSM();
	genericFSM(const fsmCell* table, uint lines, uint cols, stateType initState, assignType newAssignValue);
	void setFSMTable(const fsmCell*);
	void cycle(eventGenerator* generator);
	void nothing(genericEvent* ev);
	stateType getState(void);


	private:
	stateType state;
	uint lineCount;
	uint colCount;
	const fsmCell* FSMTable;
	assignType assignValue;

};

#endif // GENERICFSM_H