#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"
#include "falseFSM.h"

using namespace std;

void falseFSM::assignValue(genericEvent* ev) {
	switch (ev->getKey()) {
	case 'A':
		ev->setEvValue(EV_A);
		break;
	case 'L':
		ev->setEvValue(EV_L);
		break;
	case 'S':
		ev->setEvValue(EV_S);
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