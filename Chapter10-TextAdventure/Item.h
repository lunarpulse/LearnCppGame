#pragma once
#include <string>
#include "SDBMHash.h"
#include "Serialisable.h"

class Item
	:public Serialisable
{
private:
	std::string m_name;
public:
	Item(const std::string& name)
		:Serialisable(SDBMHash(name.c_str()))
		
	{
		m_name = name;
	}
	virtual ~Item()
	{

	}

	const std::string& GetName() const
	{
		return m_name;
	}

	virtual void OnSave(std::ofstream& file)
	{

	}

	virtual void OnLoad(std::ifstream& file)
	{

	}
};
