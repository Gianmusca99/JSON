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
#define OX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&objectFSM::x))

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class objectFSM;

class objectFSM : public genericFSM
{
	public:
	
	objectFSM() : genericFSM(&objectTable[0][0], 5, 6, INIT_OBJ, OX(assignValue)) {}

	private:

	const fsmCell objectTable[5][6] = {
		//Event "				Event ,						Event :					Event }					Invalid char		Event EOF
		{{STRING,OX(end)},		{FIN,OX(error)},			{FIN,OX(error)},		{FIN,OX(nothing)},		{FIN,OX(error)},	{FIN,OX(error)}		},	//State INIT_OBJ
		{{FIN,OX(error)},		{FIN,OX(error)},			{VALUE,OX(end)},		{STRING,OX(end)},		{FIN,OX(error)},	{FIN,OX(error)}		},	//State STRING
		{{FIN,OX(error)},		{MEMBER,OX(nothing)},		{FIN,OX(error)},		{FIN,OX(nothing)},		{FIN,OX(error)},	{FIN,OX(error)}		},	//State VALUE
		{{STRING,OX(end)},		{FIN,OX(error)},			{FIN,OX(error)},		{FIN,OX(error)},		{FIN,OX(error)},	{FIN,OX(error)}		}	//State MEMBER
	};

	void assignValue(genericEvent* ev);
	enum objStates : stateType { INIT_OBJ, STRING, VALUE, MEMBER, FIN };
	typedef enum { QUOTES, COMMA, COLON, C_BRACE, _EOF, INVALID_CHAR } objectEvents;

};

#endif // OBJECTFSM_H