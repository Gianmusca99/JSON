#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"
#include "numberFSM.h"

using namespace std;

void numberFSM::assignValue(genericEvent* ev) {
	if (('1' <= (ev->getKey())) && ((ev->getKey()) <= '9'))
	{
		ev->setEvValue(DIGIT);
	}
	else {
		switch(ev->getKey()){
		case '0':
			ev->setEvValue(CERO);
			break;
		case '-':
			ev->setEvValue(MINUS);
			break;
		case '+':
			ev->setEvValue(PLUS);
			break;
		case '.':
			ev->setEvValue(POINT);
			break;
		case 'e': case 'E':
			ev->setEvValue(EXP);
			break;
		case ',': case ']': case'}':
			ev->setEvValue(END_CHAR);
			fsetpos(ev->getFilePointer(), ev->getPosition());
			break;
		default:
			ev->setEvValue(INVALID);
			break;
		}
	}
}