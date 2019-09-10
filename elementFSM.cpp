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
		stackFSM[stackLevel] = new numberFSM();
		break;
	}
	if (getState() != END && getState() != ERROR)
	{
		setState(INIT_ELEMENT);
	}
}

void elementFSM::assignValue(genericEvent* ev)
{
	if (('0' <= (ev->getKey()) && (ev->getKey()) <= '9') || ev->getKey() == '-')
	{
		ev->setEvValue(O_NUMBER);
		fsetpos(ev->getFilePointer(), ev->getPosition());
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
			ev->setEvValue(O_TRUE);
			break;

		case 'f':
			ev->setEvValue(O_FALSE);
			break;

		case 'n':
			ev->setEvValue(O_NULL);
			break;

		case ',':
			ev->setEvValue(O_COMA);
			break;

		case EOF:
			ev->setEvValue(_EOF);
			break;

		default:
			ev->setEvValue(INVALID_CHAR);
			break;
		}
	}

	return;
}