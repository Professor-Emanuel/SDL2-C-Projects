#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t; // type alias: In C++11, the using keyword when used for type alias is identical to typedef.

inline ComponentID getComponentTypeID() {
	static ComponentID lastID = 0;
	return lastID++;
}

//template function
template<typename T> inline ComponentID getComponentTypeID() noexcept {
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>; // type alias: In C++11, the using keyword when used for type alias is identical to typedef.
using ComponentArray = std::array<Component*, maxComponents>; // type alias: In C++11, the using keyword when used for type alias is identical to typedef.

class Component {
public:
	Entity* entity; //reference to its owner

	virtual void initialize() {}
	virtual void update() {}
	virtual void draw() {}
	virtual ~Component() {}

private:

};

class Entity {
private:
	bool active = true; //keep track if this entity is active, if false we remove it from the Game
	std::vector<std::unique_ptr<Component>> components; //list of all components the entity holds

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	void update() {
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}

	void draw() {

	}

	bool isActive() const { return active; }
	void destroy() { active = false; }

	template<typename T> bool hasComponent() const {
		return componentBitSet[getComponentTypeID<T>];
	}

	//add component to our entity
	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->initialize();
		return *c;
	}

	template<typename T> T& getComponent() const {
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

//class to manage the list of all our entities
class Manager {
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update() {
		for (auto& e : entities) e->update();
	}

	void draw() {
		for (auto& e : entities) e->draw();
	}

	void refresh() {
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity) {
				return !mEntity->isActive();
			}),
			std::end(entities));
	}

	Entity& addEntity() {
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e }; //initialize uPtr to e
		//add this entity to our entity list
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
};