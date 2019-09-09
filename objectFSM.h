#ifndef OBJECTFSM_H
#define OBJECTFSM_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum objStates : stateType { INIT_OBJ, STRING, VALUE, MEMBER};
typedef enum { QUOTES, COMMA, COLON, _EOF, UNVALID_CHAR, O_BRACE } objectEvents;

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class objectFSM;

class objectFSM : public genericFSM
{
	public:
	
	objectFSM() : genericFSM(&objectTable[0][0], 5, 6, INIT_OBJ) {}

	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&objectFSM::x))

	const fsmCell objectTable[5][6] = {
		//Event "				Event ,						Event :					Event EOF				Invalid char		Event }
		{{STRING,TX(end)},		{END,TX(error)},			{END,TX(error)},		{END,TX(error)},		{END,TX(error)},	{END,TX(nothing)}	},	//State INIT_OBJ
		{{END,TX(error)},		{END,TX(error)},			{VALUE,TX(end)},		{END,TX(error)},		{END,TX(error)},	{STRING,TX(end)}	},	//State STRING
		{{END,TX(error)},		{MEMBER,TX(nothing)},		{END,TX(error)},		{END,TX(error)},		{END,TX(error)},	{END,TX(nothing)}	},	//State VALUE
		{{STRING,TX(end)},		{END,TX(error)},			{END,TX(error)},		{END,TX(error)},		{END,TX(error)},	{END,TX(error)}		}	//State MEMBER
	};

	void error(genericEvent* ev);
	void end(genericEvent* ev);

};

#endif // OBJECTFSM_H