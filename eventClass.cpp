#include <iostream>
#include "eventClass.h"

using namespace std;

/***************************************************************
*						GENERIC EVENT
***************************************************************/
genericEvent::genericEvent(int initEvValue = 0, short initKey = '\0') 
{
	evValue = initEvValue;
	key = initKey;
}


int genericEvent::getEvValue(void) 
{
	return evValue;
}

short genericEvent::getKey(void) 
{
	return key;
}


void genericEvent::setEvValue(int newEvValue) 
{
	evValue = newEvValue;
}

void genericEvent::setKey(short newKey) 
{
	key = newKey;
}

/***************************************************************
*						EVENT GENERATOR
***************************************************************/
eventGenerator::eventGenerator(int initLineCount = 0, FILE* initFile = NULL)
{
	lastEvent = new genericEvent;
	currentEvent = new genericEvent;
	lineCount = initLineCount;
	file = initFile;
}

genericEvent* eventGenerator::getLastEvent(void) 
{
	return lastEvent;
}

int eventGenerator::getLineCount(void) 
{
	return lineCount;
}

genericEvent* eventGenerator::getNextEvent() 
{
	short c;
	if ((c = fgetc(file)) != EOF) 
	{
		if (c == ' ' || c == '\t')
		{
			currentEvent->setKey(NULL);
		}
		else
		{
			currentEvent->setKey(c);
		}
	}
	else 
	{
		currentEvent->setKey(NULL);
	}
	
	return currentEvent;
}


void eventGenerator::setLineCount(int newLineCount) 
{
	lineCount = newLineCount;
}

void eventGenerator::setLastEvent(genericEvent* event)
{
	lastEvent->setKey(event->getKey());
	lastEvent->setEvValue(event->getEvValue());
}

void eventGenerator::setFilePointer(FILE* newFile)
{
	file = newFile;
}