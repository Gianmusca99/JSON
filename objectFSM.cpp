/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "objectFSM.h"

/*******************************************************************************
* PRIVATE METHODS
******************************************************************************/

void objectFSM::error(genericEvent* ev)
{
	ev->setType(EV_ERROR);
	ev->setKey(NULL);
	return;
}

void objectFSM::nothing(genericEvent* ev)
{
	return;
}

void objectFSM::end(genericEvent* ev)
{
	ev->setType(EV_QUIT);
	ev->setKey(NULL);
	return;
}