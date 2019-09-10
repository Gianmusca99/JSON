#ifndef TRUEFSM_H
#define TRUEFSM_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 *******************************************************************************/
#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&trueFSM::x))

/*******************************************************************************
 * CLASS PROTOTYPE
 ******************************************************************************/
class trueFSM;

class trueFSM : public genericFSM
{
public:

	trueFSM() : genericFSM(&trueTable[0][0], 4, 6, S_T, TX(assignValue)) {}

private:

	enum trueStates : stateType { S_T, S_R, S_U, S_E };
	typedef enum { EV_R, EV_U, EV_E, OTHER, END_CHAR, _EOF } trueEvents;

	const fsmCell trueTable[4][6] = {
		//		'R'						'U'						'E'						OTHER					END_CHAR			_EOF
		{ {S_R, TX(nothing)},		{ERROR, TX(error)},		{ERROR, TX(error)},		{ERROR, TX(error)},		{ERROR, TX(error)},		{ERROR, TX(error)}	},	//S_T
		{ {ERROR, TX(error)},		{S_U, TX(nothing)},		{ERROR, TX(error)},		{ERROR, TX(error)},		{ERROR, TX(error)},		{ERROR, TX(error)}	},	//S_R
		{ {ERROR, TX(error)},		{ERROR, TX(error)},		{S_E, TX(nothing)},		{ERROR, TX(error)},		{ERROR, TX(error)},		{ERROR, TX(error)}	},	//S_U
		{ {ERROR, TX(error)},		{ERROR, TX(error)},		{ERROR, TX(error)},		{ERROR, TX(error)},		{END, TX(end)},			{END, TX(end)}		},	//S_E
	};

	void assignValue(genericEvent* ev);

};

#endif // TRUEFSM_H