#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"
#include "falseFSM.h"

using namespace std;

void falseFSM::assignValue(genericEvent* ev) {
	switch (ev->getKey()) {
	case 'a':
		ev->setEvValue(EV_A);
		break;
	case 'l':
		ev->setEvValue(EV_L);
		break;
	case 's':
		ev->setEvValue(EV_S);
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