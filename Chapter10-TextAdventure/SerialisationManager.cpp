#include "SerialisationManager.h"
#include "EventManager.h"
#include <string>
#include "Serialisable.h"

void SerialisationManager::RegisterSerialisable(Serialisable* pSerialisable)
{
	assert(m_serialisables.find(pSerialisable->GetId()) == m_serialisables.end());
	m_serialisables.emplace(pSerialisable->GetId(), pSerialisable);
}

void SerialisationManager::RemoveSerialisable(Serialisable* pSerialisable)
{
	auto iter = m_serialisables.find(pSerialisable->GetId());
	if (iter  != m_serialisables.end())
	{
		m_serialisables.erase(iter);
	}
}

Serialisable* SerialisationManager::GetSerialsable(unsigned int serialisableId) const
{
	Serialisable* pSerialisable{ nullptr };
	auto iter = m_serialisables.find(serialisableId);
	if (iter != m_serialisables.end())
	{
		pSerialisable = iter->second;
	}

	return pSerialisable;
}

void SerialisationManager::Save()
{
	std::ofstream file{ m_filename };
	file << true;
	file << std::endl;

	for (auto& serialisable : m_serialisables)
	{
		Serialisable* pSerialisable = serialisable.second;
		file << pSerialisable->GetId();
		file << std::endl;
		pSerialisable->OnSave(file);

		file << std::endl;
		file << std::endl;
	}
}

bool SerialisationManager::Load()
{
	std::ifstream file{ m_filename };
	bool found = file.is_open();
	if (found)
	{
		bool isValid;
		file >> isValid;
		if (isValid)
		{
			std::cout << "Save game found, would you like to load? (Type yes to load)" << std::endl << std::endl;
			std::string shouldLoad;
			std::cin >> shouldLoad;
			if (shouldLoad == "yes")
			{

				while (!file.eof())
				{
					unsigned int serialisableId{ 0 };
					file >> serialisableId;
					auto iter = m_serialisables.find(serialisableId);
					if (iter != m_serialisables.end())
					{
						iter->second->OnLoad(file);
					}
				}
			}
			else
			{
				found = false;
			}
		}
		
	}
	return found;
}

void SerialisationManager::ClearSave()
{
	std::ofstream file{ m_filename };
	file << false;
}

