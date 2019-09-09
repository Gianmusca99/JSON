#include "elementFSM.h"
#include "arrayFSM.h"
#include "objectFSM.h"
#include "valueFSM.h"
#include "stringFSM.h"

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
		break;
	case ARRAY:
		break;
	case TRUE:
		break;
	case FALSE:
		break;
	case NUMBER:
		break;
	}
}
