#include "Chest.h"

Chest::Chest(const Item* item, unsigned int serialisableId)
	:m_item{ item }, Serialisable{ serialisableId }
{
}

void Chest::Update()
{

}