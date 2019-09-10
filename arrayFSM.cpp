/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include"arrayFSM.h"

/*******************************************************************************
 * PRIVATE METHODS
 ******************************************************************************/

void arrayFSM::assignValue(genericEvent* ev)
{
	switch (ev->getKey())
	{
	case ']':
		ev->setEvValue(FIN);
		break;

	case ',':
		ev->setEvValue(MEMBER);
		break;

	default:
		ev->setEvValue(INVALID_CHAR);
		break;
	}
}