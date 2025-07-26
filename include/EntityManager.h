//
// Created by Lukáš Blažek on 23.07.2025.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <cassert>
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

	Entity CreateEntity()
	{
		assert(mEntityCount < MAX_ENTITIES && "Entity amount exceeding limit");

		Entity id = mAvailableEntities.front();
		mAvailableEntities.pop();
		++mEntityCount;
		return id;
	}

	void DestroyEntity(Entity entity)
	{
		assert(entity < MAX_ENTITIES && "Entity outside max index range");

		mSignatures[entity].reset();

		mAvailableEntities.push(entity);
	}

	void SetSignature(Entity entity, Signature signature)
	{
		assert(entity < MAX_ENTITIES && "Entity outside max index range");

		mSignatures[entity] = signature;
	}

	Signature GetSignature(Entity entity) const
	{
		assert(entity < MAX_ENTITIES && "Entity outside max index range");

		return mSignatures[entity];
	}

private:
	std::queue<Entity> mAvailableEntities;
	std::array<Signature, MAX_ENTITIES> mSignatures{};
	uint32_t mEntityCount{};
};



#endif //ENTITYMANAGER_H
