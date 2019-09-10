#include "elementFSM.h"
#include "arrayFSM.h"
#include "objectFSM.h"
#include "valueFSM.h"
#include "stringFSM.h"
#include "numberFSM.h"
#include "trueFSM.h"
#include "falseFSM.h"
#include "nullFSM.h"


void elementFSM::nextFSM(genericFSM** stackFSM, uint &stackLevel)
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
		break;
	}
}

void elementFSM::assignValue(genericEvent* ev)
{
	if ('0' <= (ev->getKey()) || (ev->getKey()) <= '9' || ev->getKey() == '-')
	{
		ev->setEvValue(NUMBER);
	}

	else {
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
	}

	return;
}