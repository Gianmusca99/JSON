#pragma once

class genericEvent;
class eventGenerator;

enum events {EV_QUIT, EV_INIT, EV_CHAR, NO_EVENT};		//nose aca vamos agregando

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

		//GETTERS
		genericEvent* getLastEvent(void);
		int getLineCount();
		genericEvent getNextEvent(FILE* file);

		//SETTERS
		void setLineCount(int);
		void setLastEvent(genericEvent*);

	private:
		genericEvent* lastEvent;
		int lineCount;

};