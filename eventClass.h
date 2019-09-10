#pragma once

class genericEvent;
class eventGenerator;

#define END -99
#define ERROR -39


/***************************************************************
*						GENERIC EVENT
***************************************************************/
class genericEvent {

	public:
		genericEvent(int initEvValue, short initKey);
		int getEvValue();
		short getKey();
		void setEvValue(int);
		void setKey(short);

	private:
		int evValue;
		short key;
};

/***************************************************************
*						EVENT GENERATOR
***************************************************************/
class eventGenerator {

	public:
		eventGenerator(int initLineCount, FILE* initFile);

		//GETTERS
		genericEvent* getLastEvent(void);
		genericEvent* getCurrentEvent(void);
		void getNextEvent(void);
		int getLineCount();

		//SETTERS
		void setLineCount(int);
		void setLastEvent(genericEvent*);
		void setFilePointer(FILE*);

	private:
		genericEvent* lastEvent;
		genericEvent* currentEvent;
		int lineCount;
		FILE* file;

};