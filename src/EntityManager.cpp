//
// Created by Lukáš Blažek on 23.07.2025.
//

#include "../include/EntityManager.h"

#include <cassert>

Entity EntityManager::CreateEntity()
{
	assert(mEntityCount < MAX_ENTITIES && "Entity amount exceeding limit");

	Entity id = mAvailableEntities.front();
	mAvailableEntities.pop();
	++mEntityCount;
	return id;
}

void EntityManager::DestroyEntity(Entity entity)
{
	assert(entity < MAX_ENTITIES && "Entity outside max index range");

	mSignatures[entity].reset();

	mAvailableEntities.push(entity);
}

void EntityManager::SetSignature(Entity entity, Signature signature)
{
	assert(entity < MAX_ENTITIES && "Entity outside max index range");

	mSignatures[entity] = signature;
}

Signature EntityManager::GetSignature(Entity entity) const
{
	assert(entity < MAX_ENTITIES && "Entity outside max index range");

	return mSignatures[entity];
}
