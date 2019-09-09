#ifndef ARRAYTFSM_H
#define ARRAYTFSM_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

 /*******************************************************************************
  * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
  ******************************************************************************/
enum arrayStates : stateType { INIT_ARRAY, STRING, VALUE, MEMBER, END };
typedef enum { QUOTES, COMMA, COLON, _EOF, UNVALID_CHAR, O_BRACE } arrayEvents;

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class arrayFSM;

class arrayFSM : public genericFSM
{

private:

#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&arrayFSM::x))

	const fsmCell fsmTable[5][6] = {
		//Event "				Event ,						Event :					Event EOF				Invalid char		Event }
		{{STRING,TX(end)},		{END,TX(error)},			{END,TX(error)},		{END,TX(error)},		{END,TX(error)},	{END,TX(nothing)}	},	//State INIT_OBJ
		{{END,TX(error)},		{END,TX(error)},			{VALUE,TX(end)},		{END,TX(error)},		{END,TX(error)},	{STRING,TX(end)}	},	//State STRING
		{{END,TX(error)},		{MEMBER,TX(nothing)},		{END,TX(error)},		{END,TX(error)},		{END,TX(error)},	{END,TX(nothing)}	},	//State VALUE
		{{STRING,TX(end)},		{END,TX(error)},			{END,TX(error)},		{END,TX(error)},		{END,TX(error)},	{END,TX(error)}		}	//State MEMBER
	};

	void error(genericEvent* ev);
	void end(genericEvent* ev);

};

#endif
