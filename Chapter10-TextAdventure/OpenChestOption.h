#pragma once

#include "Option.h"
#include "Chest.h"

class OpenChestOption
	:public Option
{
public:
	OpenChestOption(const std::string& outputText, const unsigned int serialisableId)
		:Option(PlayerOptions::OpenChest, outputText, serialisableId)
	{
	}

	void SetChest(Chest* pChest)
	{
		m_chest = pChest;
	}

	virtual void Evaluate(Player& player);
private:
	Chest* m_chest;
};
