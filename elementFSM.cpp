#include "elementFSM.h"
#include "arrayFSM.h"
#include "objectFSM.h"
#include "valueFSM.h"
#include "stringFSM.h"
#include "numberFSM.h"


void elementFSM::setStackLevel(uint newStack)
{
	stackLevel = newStack;
}

uint elementFSM::getStackLevel(void)
{
	return stackLevel;
}

void elementFSM::nextFSM(genericEvent* ev)
{
	switch (getState())
	{
	case INIT_ELEMENT:
		break;
	case STRING:
		stackFSM[stackLevel] = new stringFSM();
		break;
	case OBJECT:
		stackFSM[stackLevel] = new objectFSM();
		break;
	case ARRAY:
		stackFSM[stackLevel] = new arrayFSM();
		break;
	case TRUE:
		stackFSM[stackLevel] = new trueFSM();
		break;
	case FALSE:
		stackFSM[stackLevel] = new falseFSM();
		break;
	case NULL:
		stackFSM[stackLevel] = new nullFSM();
		break;
	case NUMBER:
		stackFSM[stackLevel] = new numberFSM();
		break;
	}
}
