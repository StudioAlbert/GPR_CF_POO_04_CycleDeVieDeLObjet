#ifndef GPR_CF_POO_04_CYCLE_DE_VIE_ENTITY_H
#define GPR_CF_POO_04_CYCLE_DE_VIE_ENTITY_H

#include <string>

// Une entite qui raconte sa vie. Le constructeur et le destructeur ecrivent
// chacun une ligne : c'est la trace a l'ecran qui est le sujet de la seance,
// pas ce que la classe fait.
class Entity {
 public:
  explicit Entity(std::string name);
  ~Entity();

  void Act() const;

 private:
  std::string name_;
};

#endif  // GPR_CF_POO_04_CYCLE_DE_VIE_ENTITY_H
