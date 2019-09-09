#include "stringFSM.h"

void stringFSM::error(genericEvent* ev)
{
	ev->setKey(NULL);
}

void stringFSM::end(genericEvent* ev)
{
	ev->setKey(NULL);
}

void stringFSM::assignValue(genericEvent* ev)
{
	switch (ev->getKey())
	{
	case '"':
		ev->setEvValue(QUOTES);
		break;
	case '\\':
		ev->setEvValue(BACKSLASH);
		break;
	case EOF:
		ev->setEvValue(_EOF);
		break;
	default:
		ev->setEvValue(VALID_CHAR);
		break;
	}
}