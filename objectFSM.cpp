/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "objectFSM.h"
#include "stringFSM.h"
#include "valueFSM.h"


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

void objectFSM::nextFSM(genericFSM** stackFSM, uint& stackLevel)
{
	switch (getState())
	{
	case INIT_OBJ:
		break;
	case STRING:
		stackLevel++;
		stackFSM[stackLevel] = new stringFSM();
		break;
	case VALUE:
		stackLevel++;
		stackFSM[stackLevel] = new valueFSM();
		break;
	}
}