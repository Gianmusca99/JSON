#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"
#include "nullFSM.h"


void nullFSM::assignValue(genericEvent* ev) {
	switch (ev->getKey) {
	case 'U':
		ev->setEvValue(EV_U);
		break;
	case 'L':
		ev->setEvValue(EV_L);
		break;
	case ',': case ']': case'}':
		ev->setEvValue(END_CHAR);
		break;
	default:
		ev->setEvValue(OTHER);
		break;
	}
}