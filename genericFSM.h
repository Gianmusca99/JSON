#ifndef GENERICFSM_H
#define GENERICFSM_H

#include "eventClass.h"
#include "types.h"


class genericFSM;
using stateType = uint;
using eventType = uint;

//typedef void (genericFSM::*assignType) (genericEvent*);

struct fsmCell
{
	stateType nextState;
	void (genericFSM::*action) (genericEvent*);
};

class genericFSM 
{
	public:

	genericFSM();
	genericFSM(const fsmCell* table, uint lines, uint cols, stateType initState, void (genericFSM::* newAssignValue)(genericEvent* ev));
	void setFSMTable(const fsmCell*);
	void cycle(eventGenerator* generator, genericFSM** stackFSM, uint& stackLevel);
	void nothing(genericEvent* ev);
	void end(genericEvent* ev);
	void error(genericEvent* ev);
	stateType getState(void);
	void setState(stateType);
	void nextFSM(genericFSM** stackFSM, uint& stackLevel);
	void returnFSM(genericFSM** stackFSM, uint& stackLevel);


	private:
	stateType state;
	uint lineCount;
	uint colCount;
	const fsmCell* FSMTable;
	void (genericFSM::* assignValue)(genericEvent* ev);
	//assignType assignValue;

};

#endif // GENERICFSM_H