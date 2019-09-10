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
	if (('0' <= (ev->getKey()) && (ev->getKey()) <= '9') || ev->getKey() == '-')
	{
		ev->setEvValue(OTHER);
		fsetpos(ev->getFilePointer(), ev->getPosition());
	}
	else {
		switch (ev->getKey())
		{
		case ']':
			ev->setEvValue(O_BRACKET);
			break;

		case ',':
			ev->setEvValue(COMMA);
			break;

		case '{': case '[': case '"': case 't': case 'f': case 'n':
			ev->setEvValue(OTHER);
			fsetpos(ev->getFilePointer(), ev->getPosition());
			break;
		default:
			ev->setEvValue(INVALID_CHAR);
			break;
		}
	}
}

void arrayFSM::nextFSM(genericFSM** stackFSM, uint& stackLevel)
{
	switch (getState())
	{
	case VALUE:
		stackLevel++;
		stackFSM[stackLevel] = new valueFSM();
		break;
	}
}