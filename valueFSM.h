#ifndef VALUEFSM_H
#define VALUEFSM_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"	

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum valueStates : stateType { INIT_VAL, IN, END};
typedef enum { QUOTES, INTEGER, CLY_BRACKET, SQR_BRACKET, TR, FL, NU, _EOF, UNVALID_CHAR } valuetEvents;

class valueFSM : public genericFSM //Despues de doble punto o de corchete va una value
{
	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&objectFSM::x))

	const fsmCell fsmTable[3][9] = {
		//Event "			Event INT			Event {				Event [				Event "True"		Event "False"		Event "NULL"		Event EOF			Event unvalid
		{{IN,TX(string)},	{IN,TX(number)},	{IN,TX(object)},	{IN,TX(array_)},	{IN,TX(true_)},		{IN,TX(false_)},	{IN,TX(null)},		{END,TX(error)},	{END,TX(error)}},		//State INIT_VAL
		{{END,TX(error)},	{END,TX(error)},	{END,TX(error)},,	{END,TX(error)},	{END,TX(error)},	{END,TX(error)},	{END,TX(error)},	{END,TX(error)},	{END,TX(error)}},	//State IN
	};

	void string(genericEvent* ev);
	void number(genericEvent* ev);
	void object(genericEvent* ev);
	void array_(genericEvent* ev);
	void true_(genericEvent* ev);
	void false_(genericEvent* ev);
	void null(genericEvent* ev);
	void error(genericEvent* ev);
	void nothing(genericEvent* ev);
	void end(genericEvent* ev);
};

#endif // !VALUEFSM_H