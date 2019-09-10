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
enum arrayStates : stateType { INIT_ARRAY, VALUE, MEMBER, FIN };
typedef enum { O_BRACKET, COMMA, _EOF, INVALID_CHAR } arrayEvents;

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class arrayFSM;

class arrayFSM : public genericFSM
{

	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&arrayFSM::x))

	const fsmCell fsmTable[5][6] = {
		//Event ]				Event ,						Event EOF				Invalid char	
		{{FIN,TX(nothing)},		{FIN,TX(error)},			{FIN,TX(error)},		{FIN,TX(error)},		},	//State INIT_ARRAY
		{{FIN,TX(nothing)},		{MEMBER,TX(nothing)},		{FIN,TX(error)},		{FIN,TX(error)},		},	//State VALUE
		{{FIN,TX(error)},		{MEMBER,TX(nothing)},		{FIN,TX(error)},		{FIN,TX(error)},		}	//State MEMBER

	};

	void assignValue(genericEvent* ev);
};

#endif
