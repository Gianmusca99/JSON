#include <iostream>
#include "genericFSM.h"
#include "eventClass.h"

enum objStates: stateType {INIT_OBJ, STRING, VALUE, MEMBER, OTHER_OBJ, END};

class objectFSM;

class objectFSM : public genericFSM
{
	private:

	#define TX(x)  (static_cast<void (genericFSM::*)(genericEvent*)>(&objectFSM::x))

		const fsmCell fsmTable[5][6] = {
				//		Event "					Event ,						Event :					Event EOF		Invalid char			Event }
				{{STRING,TX(string)},		{END,TX(error)},			{END,TX(error)},		{END,TX(error)},	{END,TX(error)},	{OTHER_OBJ,TX(nothing)}},		//State INIT_OBJ
				{{END,TX(error)},			{END,TX(error)},			{VALUE,TX(value)},		{END,TX(error)},	{END,TX(error)},	{STRING,TX(string)}},			//Sate STRING
				{{END,TX(error)},			{MEMBER,TX(f)},				{END,TX(error)},		{END,TX(error)},	{END,TX(error)},	{OTHER_OBJ,TX(nothing)}},		//State VALUE
				{{STRING,TX(string)},		{END,TX(error)},			{END,TX(error)},		{END,TX(error)},	{END,TX(error)},	{END,TX(error)}},				//State MEMBER
				{{END,TX(error)},			{INIT_OBJ,TX(nothing)},		{END,TX(error)},		{END,TX(end)},		{END,TX(error)},	{END,TX(error)}},				//State OTHER_OBJ
		};	

		void string(genericEvent* ev) 
		{

			return;
		}

		void value(genericEvent* ev)
		{
			return;
		}

		void error(genericEvent* ev)
		{
			return;
		}

		void nothing(genericEvent* ev)
		{
			return;
		}

		void end(genericEvent* ev)
		{
			return;
		}
};