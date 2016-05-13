#pragma once

#include "Option.h"
#include "Room.h"

class Player;

class MoveOption: public Option
{
public:
	MoveOption(Room::JoiningDirections joiningDirection, PlayerOptions chosenOption, const std::string & outputText, const unsigned int serialisableId)
		: Option(chosenOption, outputText, serialisableId), m_directionToMove(joiningDirection)
	{

	}

	virtual void Evaluate( Player& player);

private:
	Room::JoiningDirections m_directionToMove;

};

