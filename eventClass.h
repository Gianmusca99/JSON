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
		fpos_t* getPosition(void);
		void setEvValue(int);
		void setKey(short);
		void setPosition(fpos_t);
		FILE* getFilePointer(void);
		void setFilePointer(FILE*);

	private:
		int evValue;
		short key;
		FILE* file;
		fpos_t position;
		fpos_t* pPosition;
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
		FILE* getFilePointer(void);

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