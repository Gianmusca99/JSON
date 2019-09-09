#include "valueFSM.h"


void valueFSM::assignValue(genericEvent* ev)
{
	if ('0'<= (ev->getKey()) || (ev->getKey()) <= '9' || ev->getKey()=='-')
	{
		ev->setEvValue(NUMBER);
	}

	switch (ev->getKey)
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
		ev->setEvValue(O_NULL);
		break;

		default:
		ev->setEvValue(INVALID_CHAR);
		break;
	}

	return;
}