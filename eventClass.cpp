#include <iostream>
#include "eventClass.h"

using namespace std;

/***************************************************************
*						GENERIC EVENT
***************************************************************/
genericEvent::genericEvent(int initType = 0, int initEvValue = 0, char initKey = '\0') {
	type = initType;
	evValue = initEvValue;
	key = initKey;
}

int genericEvent::getType(void) {
	return type;
}

int genericEvent::getEvValue(void) {
	return evValue;
}

char genericEvent::getKey(void) {
	return key;
}

void genericEvent::setType(int newType) {
	type = newType;
}

void genericEvent::setEvValue(int newEvValue) {
	evValue = newEvValue;
}

void genericEvent::setKey(char newKey) {
	key = newKey;
}

/***************************************************************
*						EVENT GENERATOR
***************************************************************/
eventGenerator::eventGenerator(int initLineCount = 0, FILE* initFile = NULL) {
	lastEvent = new genericEvent;
	currentEvent = new genericEvent;
	lineCount = initLineCount;
	file = initFile;
}

genericEvent* eventGenerator::getLastEvent(void) {
	return lastEvent;
}

int eventGenerator::getLineCount(void) {
	return lineCount;
}

genericEvent* eventGenerator::getNextEvent() {
	short c;
	if ((c = fgetc(file)) != EOF) 
	{
		if (c == ' ' || c == '\t')
		{
			currentEvent->setType(NO_EVENT);
			currentEvent->setKey(NULL);
		}
		else
		{
			currentEvent->setType(EV_CHAR);
			currentEvent->setKey(c);
		}
	}
	else 
	{
		currentEvent->setType(EV_QUIT);
		currentEvent->setKey(NULL);
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

void eventGenerator::setFilePointer(FILE* newFile)
{
	file = newFile;
}