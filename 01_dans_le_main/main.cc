#include <print>

#include "entity.h"

// Une entite declaree dans le main. Elle est construite la ou on l'ecrit, et
// detruite a l'accolade fermante -- donc APRES la derniere ligne du main.
int main() {
  std::println("main : avant");

  Entity gobelin("Gobelin");
  gobelin.Act();

  std::println("main : apres");
  return 0;
}
