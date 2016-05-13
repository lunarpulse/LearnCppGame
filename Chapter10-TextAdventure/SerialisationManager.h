#pragma once

#include "Singleton.h"
#include <fstream>
#include "SDBMHash.h"
#include <unordered_map>

class Serialisable;

class SerialisationManager : public Singleton<SerialisationManager>
{
public:

	void RegisterSerialisable(Serialisable* pSerialisable);
	
	void RemoveSerialisable(Serialisable* pSerialisable);

	Serialisable* GetSerialsable(unsigned int serialisableID) const;

	void ClearSave();

	void Save();

	bool Load();


private:
	using Serialisables = std::unordered_map < unsigned int, Serialisable* > ;
	Serialisables m_serialisables;

	const char* const m_filename{ "Save.txt" };

};

