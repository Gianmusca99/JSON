/*******************************************************************************
* INCLUDE HEADER FILES
******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"
#include "trueFSM.h"

/*******************************************************************************
 *					 CLASS FUNCTION DEFINITION
 ******************************************************************************/

using namespace std;

void trueFSM::assignValue(genericEvent* ev) {
	switch (ev->getKey()) {
	case 'r':
		ev->setEvValue(EV_R);
		break;
	case 'u':
		ev->setEvValue(EV_U);
		break;
	case 'e':
		ev->setEvValue(EV_E);
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
