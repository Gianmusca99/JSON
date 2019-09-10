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
#define AX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&arrayFSM::x))

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class arrayFSM;

class arrayFSM : public genericFSM
{	public:
	arrayFSM() : genericFSM(&arrayTable[0][0], 2, 4, VALUE, AX(assignValue)) {}

	private:
		enum arrayStates : stateType { INIT, VALUE };
		typedef enum { O_BRACKET, COMMA, OTHER, INVALID_CHAR } arrayEvents;

	const fsmCell arrayTable[2][4] = {
		//Event ]				Event ,					Event OTHER				Invalid char	
		{{END, AX(end)},	{ERROR, AX(error)},		{VALUE, AX(nothing)},	{ERROR, AX(error)},	},	//State INIT
		{{END, AX(end)},	{VALUE, AX(nothing)},	{ERROR, AX(error)},		{ERROR, AX(error)},	},	//State VALUE

	};

	void assignValue(genericEvent* ev);
	void nextFSM(genericFSM** stackFSM, uint& stackLevel);
};

#endif
