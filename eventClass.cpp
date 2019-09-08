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
	lastEvent = new genericEvent;
	lineCount = initLineCount;
}

genericEvent* eventGenerator::getLastEvent(void) {
	return lastEvent;
}

int eventGenerator::getLineCount(void) {
	return lineCount;
}

genericEvent eventGenerator::getNextEvent(FILE* file) {
	short c;
	genericEvent currentEvent;
	if ((c = fgetc(file)) != EOF) 
	{
		if (c == ' ' || c == '\t')
		{
			currentEvent.setType(NO_EVENT);
			currentEvent.setKey(NULL);
		}
		else
		{
			currentEvent.setType(EV_CHAR);
			currentEvent.setKey(c);
		}
	}
	else 
	{
		currentEvent.setType(EV_QUIT);
		currentEvent.setKey(NULL);
	}
	
	return currentEvent;
}


void eventGenerator::setLineCount(int newLineCount) {
	lineCount = newLineCount;
}

void eventGenerator::setLastEvent(genericEvent* event)
{
	lastEvent->setKey(event->getKey());
	lastEvent->setType(event->getType());
}