#pragma once

#include "Entity.h"
#include "Option.h"
#include "Item.h" //suspicious
#include <vector>
#include <map>
#include < array > 
#include "Serialisable.h"

class Room
	: public Entity
	, public Serialisable
{
public:

	using Pointer = std::shared_ptr < Room > ;

	enum class JoiningDirections
	{
		North = 0,
		East,
		South,
		West,
		Max
	};

private:
	using JoiningRooms = std::array < Pointer, static_cast<size_t> (JoiningDirections::Max) >;
	JoiningRooms m_pJoiningRooms;

	using StaticOptions = std::map < unsigned int, Option::Pointer>;
	StaticOptions m_staticOptions;
	unsigned int m_staticOptionsStartKey{ 1 };

	using DynamicOptions = std::vector < Option::Pointer >;
	DynamicOptions m_dynamicOptions;

	Pointer m_pointer{ this };

public:
	explicit Room(unsigned int serialisableId);

	void AddRoom(JoiningDirections direction, Pointer room);
	Pointer GetRoom(JoiningDirections direction) const;

	Option::Pointer EvaluateInput(unsigned int playerInput);
	void AddStaticOption(Option::Pointer option);
	void AddDynamicOption(Option::Pointer option);
	void PrintOptions() const;

	virtual void OnSave(std::ofstream& file);
	virtual void OnLoad(std::ifstream& file);

	Pointer GetPointer() const { return m_pointer; }
};