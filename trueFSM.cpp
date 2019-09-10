#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"
#include "trueFSM.h"


using namespace std;

void trueFSM::assignValue(genericEvent* ev) {
	switch (ev->getKey()) {
	case 'R':
		ev->setEvValue(EV_R);
		break;
	case 'U':
		ev->setEvValue(EV_U);
		break;
	case 'E':
		ev->setEvValue(EV_E);
		break;
	case ',': case ']': case'}':
		ev->setEvValue(END_CHAR);
		break;
	default:
		ev->setEvValue(OTHER);
		break;
	}
}
