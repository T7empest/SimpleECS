//
// Created by Lukáš Blažek on 23.07.2025.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <queue>

#include "Types.h"


class EntityManager {
public:
	EntityManager()
	{
		for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
		{
			mAvailableEntities.push(entity);
		}
	}

	Entity CreateEntity();

	void DestroyEntity(Entity entity);

	void SetSignature(Entity entity, Signature signature);

	Signature GetSignature(Entity entity) const;

private:
	std::queue<Entity> mAvailableEntities;
	std::array<Signature, MAX_ENTITIES> mSignatures{};
	uint32_t mEntityCount{};
};



#endif //ENTITYMANAGER_H
