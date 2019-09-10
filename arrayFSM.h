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
enum arrayStates : stateType { INIT_ARRAY, STRING, VALUE, MEMBER, FIN };
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
		{{STRING,TX(end)},		{FIN,TX(error)},			{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},	{FIN,TX(nothing)}	},	//State INIT_OBJ
		{{FIN,TX(error)},		{FIN,TX(error)},			{VALUE,TX(end)},		{FIN,TX(error)},		{FIN,TX(error)},	{STRING,TX(end)}	},	//State STRING
		{{FIN,TX(error)},		{MEMBER,TX(nothing)},		{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},	{FIN,TX(nothing)}	},	//State VALUE
		{{STRING,TX(end)},		{FIN,TX(error)},			{FIN,TX(error)},		{FIN,TX(error)},		{FIN,TX(error)},	{FIN,TX(error)}		}	//State MEMBER
	};

};

#endif
