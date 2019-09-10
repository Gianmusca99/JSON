/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "objectFSM.h"

/*******************************************************************************
* PRIVATE METHODS
******************************************************************************/

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
		ev->setEvValue(INVALID_CHAR);
		break;
	}
}
