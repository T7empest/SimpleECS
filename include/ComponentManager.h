//
// Created by Lukáš Blažek on 26.07.2025.
//

#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H
#include <cassert>
#include <memory>
#include <unordered_map>

#include "ComponentArray.h"
#include "Types.h"


class ComponentManager {
public:
	template<typename T>
	void RegisterComponent()
	{
		const char* typeName = typeid(T).name();

		assert(mComponentTypes.find(typeName) == mComponentTypes.end() && "Registering a component type more than once");

		mComponentTypes.insert({typeName, mNextComponentType});

		mComponentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});
	}

	template<typename T>
	ComponentType getComponentType()
	{
		const char* typeName = typeid(T).name();

		assert(mComponentTypes.find(typeName) != mComponentTypes.end() && "Called get on non-existing component");

		return mComponentTypes[typeName];
	}

	template<typename T>
	void AddComponent(Entity entity, T component)
	{
		GetComponentArray<T>()->InsertData(entity, component);
	}

	template<typename T>
	void RemoveComponent(Entity entity)
	{
		GetComponentArray<T>()->RemoveData(entity);
	}

	template<typename T>
	T& GetComponent(Entity entity)
	{
		return GetComponentArray<T>()->GetData(entity);
	}

	void EntityDestroyed(Entity entity)
	{
		for (const auto& pair : mComponentArrays)
		{
			auto const& component = pair.second;

			component->EntityDestroyed(entity);
		}
	}


private:
	std::unordered_map<const char*, ComponentType> mComponentTypes{};

	std::unordered_map<const char*, std::shared_ptr<IComponentArray>> mComponentArrays{};

	ComponentType mNextComponentType{};

	template<typename T>
	std::shared_ptr<ComponentArray<T>> GetComponentArray()
	{
		const char* typeName = typeid(T).name();

		assert(mComponentTypes.find(typeName) != mComponentTypes.end() && "Component not registered before use.");

		return std::static_pointer_cast<ComponentArray<T>>(mComponentArrays[typeName]);
	}
};



#endif //COMPONENTMANAGER_H
