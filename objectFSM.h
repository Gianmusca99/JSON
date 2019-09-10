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
	
	objectFSM() : genericFSM(&objectTable[0][0], 3, 6, INIT_OBJ, OX(assignValue)) {}

	private:

	const fsmCell objectTable[3][6] = {
		//Event "				Event ,						Event :					Event }					Invalid char		Event EOF
		{{STRING,OX(end)},		{ERROR,OX(error)},			{ERROR,OX(error)},		{END,OX(end)},		{ERROR,OX(error)},	{ERROR,OX(error)}		},	//State INIT_OBJ
		{{ERROR,OX(error)},		{ERROR,OX(error)},			{VALUE,OX(end)},		{STRING,OX(end)},	{ERROR,OX(error)},	{ERROR,OX(error)}		},	//State STRING
		{{ERROR,OX(error)},		{INIT_OBJ,OX(nothing)},		{ERROR,OX(error)},		{END,OX(end)},		{ERROR,OX(error)},	{ERROR,OX(error)}		},	//State VALUE
	};

	void assignValue(genericEvent* ev);
	void nextFSM(genericFSM** stackFSM, uint& stackLevel);
	enum objStates : stateType { INIT_OBJ, STRING, VALUE };
	typedef enum { QUOTES, COMMA, COLON, C_BRACE, _EOF, INVALID_CHAR } objectEvents;


};

#endif // OBJECTFSM_H