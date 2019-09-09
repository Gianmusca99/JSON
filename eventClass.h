#pragma once

class genericEvent;
class eventGenerator;

#define NO_VALUE -2
#define END -1


/***************************************************************
*						GENERIC EVENT
***************************************************************/
class genericEvent {

	public:
		genericEvent(int initEvValue, char initKey);
		int getEvValue();
		char getKey();
		void setEvValue(int);
		void setKey(char);

	private:
		int evValue;
		char key;
};

/***************************************************************
*						EVENT GENERATOR
***************************************************************/
class eventGenerator {

	public:
		eventGenerator(int initLineCount, FILE* initFile);

		//GETTERS
		genericEvent* getLastEvent(void);
		genericEvent* getNextEvent(void);
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