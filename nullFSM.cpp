/*******************************************************************************
* INCLUDE HEADER FILES
******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"
#include "nullFSM.h"

/*******************************************************************************
 *					 CLASS FUNCTION DEFINITION
 ******************************************************************************/
void nullFSM::assignValue(genericEvent* ev) {
	switch (ev->getKey()) {
	case 'u':
		ev->setEvValue(EV_U);
		break;
	case 'l':
		ev->setEvValue(EV_L);
		break;
	case ',': case ']': case'}':
		ev->setEvValue(END_CHAR);
		fsetpos(ev->getFilePointer(), ev->getPosition());
		break;
	case EOF:
		ev->setEvValue(_EOF);
		fsetpos(ev->getFilePointer(), ev->getPosition());
		break;
	default:
		ev->setEvValue(OTHER);
		break;
	}
}