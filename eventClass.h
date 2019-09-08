#pragma once

class genericEvent;
class eventGenerator;

enum events {EV_QUIT, EV_INIT, EV_CHAR};		//nose aca vamos agregando

/***************************************************************
*						GENERIC EVENT
***************************************************************/
class genericEvent {

	public:
		genericEvent(int initType, char initKey);
		int getType();
		char getKey();
		void setType(int);
		void setKey(char);

	private:
		int type;
		char key;
};

/***************************************************************
*						EVENT GENERATOR
***************************************************************/
class eventGenerator {

	public:
		eventGenerator(int initLineCount);
		genericEvent* getCurrentEvent(void);
		int getLineCount();
		genericEvent* getNextEvent(FILE* file);
		void setLineCount(int);

	private:
		genericEvent* currentEvent;
		int lineCount;

};