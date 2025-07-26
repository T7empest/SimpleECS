//
// Created by Lukáš Blažek on 26.07.2025.
//

#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H
#include <assert.h>
#include <memory>
#include <unordered_map>

#include "System.h"
#include "Types.h"


class SystemManager
{
public:
	template<typename T>
	std::shared_ptr<T> RegisterSystem()
	{
		const char* typeName = typeid(T).name();

		assert(mSystems.find(typeName) == mSystems.end() && "cannot register system, already exists");

		auto system = std::make_shared<T>();
		mSystems.insert({typeName, system});
		return system;
	}

	template<typename T>
	void SetSignature(Signature signature)
	{
		const char* typeName = typeid(T).name;

		assert(mSystems.find(typeName) != mSystems.end() && "system doesnt exist, cant SetSignature");

		mSignatures.insert({typeName, signature});
	}

	void EntityDestroyed(Entity entity)
	{
		for (auto const& pair : mSystems)
		{
			auto const& system = pair.second

			system->mEntities.erase(entity);
		}
	}

	void EntitySignatureChanged(Entity entity, Signature entitySignature)
	{
		for (auto const& pair : mSystems)
		{
			auto const& type = pair.first;
			auto const& system = pair.second;
			auto const& systemSignature = mSignatures[type];

			if ((entitySignature & systemSignature) == systemSignature)
			{
				system->mEntities.insert(entity);
			}
			else
			{
				system->mEntities.erase(entity);
			}
		}
	}

private:
	std::unordered_map<const char*, Signature> mSignatures{};
	std::unordered_map<const char*, std::shared_ptr<System>> mSystems{};
};


#endif //SYSTEMMANAGER_H
