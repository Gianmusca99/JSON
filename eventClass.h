#pragma once

class genericEvent;
class eventGenerator;

enum events {EV_QUIT, EV_INIT, EV_CHAR, EV_ERROR, NO_EVENT};		//nose aca vamos agregando

/***************************************************************
*						GENERIC EVENT
***************************************************************/
class genericEvent {

	public:
		genericEvent(int initType, int initEvValue, char initKey);
		int getType();
		int getEvValue();
		char getKey();
		void setType(int);
		void setEvValue(int);
		void setKey(char);

	private:
		int type;
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