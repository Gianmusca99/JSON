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
enum objStates : stateType { INIT_OBJ, STRING, VALUE, MEMBER, FIN};
typedef enum { QUOTES, COMMA, COLON, _EOF, UNVALID_CHAR, O_BRACE } objectEvents;

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class objectFSM;

class objectFSM : public genericFSM
{
	public:
	
	objectFSM() : genericFSM(&objectTable[0][0], 5, 6, INIT_OBJ, (assignType) &assignValue) {}

	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&objectFSM::x))

	const fsmCell objectTable[5][6] = {
		//Event "				Event ,						Event :					Event EOF				Invalid char		Event }
		{{STRING,TX(end)},		{FIN,TX(error)},			{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},	{FIN,TX(nothing)}	},	//State INIT_OBJ
		{{FIN,TX(error)},		{FIN,TX(error)},			{VALUE,TX(end)},		{FIN,TX(error)},		{FIN,TX(error)},	{STRING,TX(end)}	},	//State STRING
		{{FIN,TX(error)},		{MEMBER,TX(nothing)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},	{FIN,TX(nothing)}	},	//State VALUE
		{{STRING,TX(end)},		{FIN,TX(error)},			{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},	{FIN,TX(error)}		}	//State MEMBER
	};

	void error(genericEvent* ev);
	void end(genericEvent* ev);
	void assignValue(genericEvent* ev);

};

#endif // OBJECTFSM_H