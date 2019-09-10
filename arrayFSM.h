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
	arrayFSM() : genericFSM(&arrayTable[0][0], 1, 9, INIT_ARRAY, AX(assignValue)) {}

	private:
		enum arrayStates : stateType { INIT_ARRAY, VALUE, MEMBER, FIN };
		typedef enum { O_BRACKET, COMMA, EOF_, INVALID_CHAR } arrayEvents;

	const fsmCell arrayTable[5][6] = {
		//Event ]				Event ,						Event EOF				Invalid char	
		{{FIN,AX(nothing)},		{FIN,AX(error)},			{FIN,AX(error)},		{FIN,AX(error)},		},	//State INIT_ARRAY
		{{FIN,AX(nothing)},		{MEMBER,AX(nothing)},		{FIN,AX(error)},		{FIN,AX(error)},		},	//State VALUE
		{{FIN,AX(error)},		{MEMBER,AX(nothing)},		{FIN,AX(error)},		{FIN,AX(error)},		}	//State MEMBER

	};

	void assignValue(genericEvent* ev);
	void nextFSM(genericFSM** stackFSM, uint& stackLevel);
};

#endif
