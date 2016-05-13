#pragma once

#include "PlayerOptions.h"
#include "Serialisable.h"
#include "Visitable.h"
#include <memory>
#include <string>

class Player;

class Option
	:public Visitable
	,public Serialisable
{
public:
	using Pointer = std::shared_ptr < Option > ; //from <memory>

protected:
	Pointer m_pointer{ this };
	PlayerOptions m_chosenOption;
	std::string m_outputText;
	
public:
	Option(PlayerOptions chosenOption, const std::string& outputText, const unsigned int serialisableId)
		:m_chosenOption(chosenOption)
		, m_outputText(outputText)
		, Serialisable{ serialisableId }
	{

	}
	
	const std::string& GetOuputText() const
	{
		return m_outputText;
	}

	virtual void Evaluate(Player& player) = 0;

	virtual void OnSave(std::ofstream& file) {}
	virtual void OnLoad(std::ifstream& file) {}


	Pointer GetPointer() const { return m_pointer; }
};