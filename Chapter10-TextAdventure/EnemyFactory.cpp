#include "EnemyFactory.h"
#include "Enemy.h"
#include <cassert>

Enemy* CreateEnemy(EnemyType enemyType, unsigned int serialisableId)
{
	Enemy* pEnemy = nullptr;
	switch (enemyType)
	{
	case EnemyType::Dragon:
		pEnemy = new Enemy(EnemyType::Dragon, serialisableId);
		break;
	case EnemyType::Orc:
		pEnemy = new Enemy(EnemyType::Orc, serialisableId);
		break;
	default:
		assert(false);
		break;
	}
	return pEnemy;
}