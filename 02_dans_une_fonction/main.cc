#include <print>

#include "entity.h"

// La fonction a sa propre portee. L'entite qu'elle cree meurt a l'accolade
// fermante de la fonction, avant que le main reprenne la main.
void Invoquer() {
  std::println("  Invoquer : debut");

  Entity squelette("Squelette");
  squelette.Act();

  std::println("  Invoquer : fin");
}

int main() {
  std::println("main : avant l'appel");
  Invoquer();
  std::println("main : apres l'appel");
  return 0;
}
