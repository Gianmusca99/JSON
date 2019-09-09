#include "stringFSM.h"

void stringFSM::error(genericEvent* ev)
{
	ev->setKey(NULL);
}

void stringFSM::end(genericEvent* ev)
{
	ev->setKey(NULL);
}