/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include"arrayFSM.h"
#include "valueFSM.h"

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

void arrayFSM::nextFSM(genericFSM** stackFSM, uint& stackLevel)
{
	switch (getState())
	{
	case INIT_ARRAY:
		break;
	case VALUE:
		stackLevel++;
		stackFSM[stackLevel] = new valueFSM();
		break;
	}
}