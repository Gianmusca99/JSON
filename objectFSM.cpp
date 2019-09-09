/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "objectFSM.h"

/*******************************************************************************
* PRIVATE METHODS
******************************************************************************/

void objectFSM::error(genericEvent* ev)
{
	ev->setKey(NULL);
	return;
}

void objectFSM::end(genericEvent* ev)
{
	ev->setKey(NULL);
	return;
}

void objectFSM::assignValue(genericEvent* ev)
{
	switch (ev->getKey())
	{
	case '"':
		ev->setEvValue(QUOTES);
		break;
	case ',':
		ev->setEvValue(COMMA);
		break;
	case ':':
		ev->setEvValue(COLON);
		break;
	case EOF:
		ev->setEvValue(_EOF);
		break;
	case '}':
		ev->setEvValue(C_BRACE);
		break;
	default:
		ev->setEvValue(UNVALID_CHAR);
		break;
	}
}
