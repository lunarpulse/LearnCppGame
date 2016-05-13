#pragma once

#include "Entity.h"
#include "EnemyFactory.h"
#include <memory>
#include "Serialisable.h"

class Enemy
	:public Entity
	, public Serialisable
{
public:

	using Pointer = std::shared_ptr < Enemy > ;

	Enemy(EnemyType type, unsigned int serialiasableId)
		:m_type{ type }
		, Serialisable{ serialiasableId }
	{

	}

	EnemyType GetType()const
	{
		return m_type;
	}

	bool isAlive() const
	{
		return m_alive;
	}

	void Kill()
	{
		m_alive = false;
	}

	virtual void OnSave(std::ofstream& file)
	{
		file << m_alive;
	}

	virtual void OnLoad(std::ifstream& file)
	{
		file >> m_alive;
	}
private:
	EnemyType m_type;
	bool m_alive{ true };
};
