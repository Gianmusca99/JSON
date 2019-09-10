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
typedef enum { QUOTES, COMMA, COLON, C_BRACE, _EOF, INVALID_CHAR} objectEvents;

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
		//Event "				Event ,						Event :					Event }					Invalid char		Event EOF
		{{STRING,TX(end)},		{FIN,TX(error)},			{FIN,TX(error)},		{FIN,TX(nothing)},		{FIN,TX(error)},	{FIN,TX(error)}		},	//State INIT_OBJ
		{{FIN,TX(error)},		{FIN,TX(error)},			{VALUE,TX(end)},		{STRING,TX(end)},		{FIN,TX(error)},	{FIN,TX(error)}		},	//State STRING
		{{FIN,TX(error)},		{MEMBER,TX(nothing)},		{FIN,TX(error)},		{FIN,TX(nothing)},		{FIN,TX(error)},	{FIN,TX(error)}		},	//State VALUE
		{{STRING,TX(end)},		{FIN,TX(error)},			{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},	{FIN,TX(error)}		}	//State MEMBER
	};

	void assignValue(genericEvent* ev);

};

#endif // OBJECTFSM_H