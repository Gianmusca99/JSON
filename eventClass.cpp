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
	file = NULL;
	position = NULL;
	pPosition = &position;
}


int genericEvent::getEvValue(void) 
{
	return evValue;
}

short genericEvent::getKey(void) 
{
	return key;
}

FILE* genericEvent::getFilePointer(void)
{
	return file;
}

fpos_t* genericEvent::getPosition(void)
{
	return pPosition;
}


void genericEvent::setPosition(fpos_t newPosition)
{
	position = newPosition;
}

void genericEvent::setFilePointer(FILE* newFile)
{
	file = newFile;
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
	currentEvent->setFilePointer(initFile);
	lineCount = initLineCount;
	file = initFile;
}

genericEvent* eventGenerator::getLastEvent(void) 
{
	return lastEvent;
}

genericEvent* eventGenerator::getCurrentEvent(void)
{
	return currentEvent;
}

int eventGenerator::getLineCount(void) 
{
	return lineCount;
}

FILE* eventGenerator::getFilePointer(void)
{
	return file;
}


void eventGenerator::getNextEvent() 
{
	fgetpos(file, currentEvent->getPosition());

	short c = fgetc(file);
	while (c == ' ' || c == '\t' || c == '\n')
	{
		if (c == '\n')
		{
			lineCount++;
		}

		c = fgetc(file);

	}

	currentEvent->setKey(c);

	return;
}


void eventGenerator::setLineCount(int newLineCount) 
{
	lineCount = newLineCount;
}

void eventGenerator::setLastEvent(genericEvent* event)
{
	*lastEvent = *event;
}

void eventGenerator::setFilePointer(FILE* newFile)
{
	file = newFile;
}