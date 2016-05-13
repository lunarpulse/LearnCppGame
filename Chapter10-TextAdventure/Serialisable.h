#pragma once
#include "SerialisationManager.h"

class Serialisable
{
	unsigned int m_id{ 0 };

public:
	explicit Serialisable(unsigned int id)
		:m_id{ id }
	{
		SerialisationManager::GetSingletonPtr()->RegisterSerialisable(this);
	};

	~Serialisable()
	{
		SerialisationManager* pSerialisationManager =
			SerialisationManager::GetSingletonPtr();
		if (pSerialisationManager)
		{
			pSerialisationManager->RegisterSerialisable(this);
		}

	};

	virtual void OnSave(std::ofstream& file) = 0;
	virtual void OnLoad(std::ifstream& file) = 0;

	unsigned int GetId() const { return m_id; }
};