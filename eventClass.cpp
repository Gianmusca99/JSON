#include <iostream>
#include "eventClass.h"

using namespace std;

/***************************************************************
*						GENERIC EVENT
***************************************************************/
genericEvent::genericEvent(int initType = 0, char initKey = '\0') {
	type = initType;
	key = initKey;
}

int genericEvent::getType(void) {
	return type;
}

char genericEvent::getKey(void) {
	return key;
}

void genericEvent::setType(int newType) {
	type = newType;
}

void genericEvent::setKey(char newKey) {
	key = newKey;
}

/***************************************************************
*						EVENT GENERATOR
***************************************************************/
eventGenerator::eventGenerator(int initLineCount = 0) {
	currentEvent = new genericEvent();
	lineCount = initLineCount;
}

genericEvent* eventGenerator::getCurrentEvent(void) {
	return currentEvent;
}

int eventGenerator::getLineCount(void) {
	return lineCount;
}

void eventGenerator::setLineCount(int newLineCount) {
	lineCount = newLineCount;
}

genericEvent* eventGenerator::getNextEvent(FILE* file) {
	char c;
	if ((c = fgetc(file)) != EOF) {
		while (c != ' ') {
			currentEvent->setType(EV_CHAR);
			currentEvent->setKey(c);
			break;
		}
	}
	else {
		currentEvent->setType(EV_QUIT);
		currentEvent->setKey(c);
	}
	
	return currentEvent;
}
