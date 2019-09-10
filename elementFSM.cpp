#include "elementFSM.h"
#include "arrayFSM.h"
#include "objectFSM.h"
#include "valueFSM.h"
#include "stringFSM.h"
#include "numberFSM.h"
#include "trueFSM.h"
#include "falseFSM.h"
#include "nullFSM.h"


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
		stackLevel++;
		stackFSM[stackLevel] = new stringFSM();
		break;
	case OBJECT:
		stackLevel++;
		stackFSM[stackLevel] = new objectFSM();
		break;
	case ARRAY:
		stackLevel++;
		stackFSM[stackLevel] = new arrayFSM();
		break;
	case TRUE:
		stackLevel++;
		stackFSM[stackLevel] = new trueFSM();
		break;
	case FALSE:
		stackLevel++;
		stackFSM[stackLevel] = new falseFSM();
		break;
	case NUL:
		stackLevel++;
		stackFSM[stackLevel] = new nullFSM();
		break;
	case NUMBER:
		stackLevel++;
		stackFSM[stackLevel] = new numberFSM();
		break;
	}
}
