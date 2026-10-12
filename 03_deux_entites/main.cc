#include <print>

#include "entity.h"

// Deux entites a la suite. Construites dans l'ordre d'ecriture, detruites dans
// l'ordre inverse : la portee se depile.
int main() {
  std::println("main : avant");

  Entity gobelin("Gobelin");
  Entity troll("Troll");

  gobelin.Act();
  troll.Act();

  std::println("main : apres");
  return 0;
}
