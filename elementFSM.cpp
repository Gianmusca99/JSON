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
		stackFSM[stackLevel] = new stringFSM();
		stackLevel++;
		break;
	case OBJECT:
		stackFSM[stackLevel] = new objectFSM();
		stackLevel++;
		break;
	case ARRAY:
		stackFSM[stackLevel] = new arrayFSM();
		stackLevel++;
		break;
	case TRUE:
		stackFSM[stackLevel] = new trueFSM();
		stackLevel++;
		break;
	case FALSE:
		stackFSM[stackLevel] = new falseFSM();
		stackLevel++;
		break;
	case NUL:
		stackFSM[stackLevel] = new nullFSM();
		stackLevel++;
		break;
	case NUMBER:
		stackFSM[stackLevel] = new numberFSM();
		stackLevel++;
		break;
	}
}

void elementFSM::assignValue(genericEvent* ev)
{
	if ('0' <= (ev->getKey()) || (ev->getKey()) <= '9' || ev->getKey() == '-')
	{
		ev->setEvValue(NUMBER);
	}

	switch (ev->getKey())
	{
	case '"':
		ev->setEvValue(QUOTES);
		break;

	case '{':
		ev->setEvValue(O_BRACES);
		break;

	case '[':
		ev->setEvValue(O_BRACKETS);
		break;

	case 't':
		ev->setEvValue(TRUE);
		break;

	case 'f':
		ev->setEvValue(FALSE);
		break;

	case 'n':
		ev->setEvValue(NUL);
		break;

	default:
		ev->setEvValue(INVALID_CHAR);
		break;
	}

	return;
}

void elementFSM::returnFSM(genericEvent* ev)
{
	if (stackFSM[stackLevel]->getState() == END) {
		delete(stackFSM[stackLevel]);
		setStackLevel(stackLevel--);
		printf("Todo piola hasta ac�");
	}
	else if (stackFSM[stackLevel]->getState() == ERROR) {
		//identifyError();
		//displayError()
		for (uint i = stackLevel; i > 0; i--)
			delete(stackFSM[i]);
	}

	return;
}