#include "entity.h"

#include <print>
#include <utility>

Entity::Entity(std::string name) : name_(std::move(name)) {
  std::println("  + {} : constructeur", name_);
}

Entity::~Entity() { std::println("  - {} : destructeur", name_); }

void Entity::Act() const { std::println("    {} agit", name_); }
