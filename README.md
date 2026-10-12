# Cycle de vie de l'objet — companion GPR-CF-POO-04

Une classe `Entity` qui écrit une ligne à sa naissance et une à sa mort, et trois
programmes qui la font vivre dans trois situations. **La sortie console est le
cours** : prédire la trace avant de lancer, puis comparer.

| Étape | Ce qu'elle montre |
|---|---|
| `01_dans_le_main` | l'objet meurt à l'accolade fermante, donc **après** la dernière ligne du `main` |
| `02_dans_une_fonction` | la fonction a sa propre portée : l'objet y meurt **avant** que le `main` reprenne |
| `03_deux_entites` | deux objets, construits dans l'ordre, détruits dans l'ordre **inverse** |

`entity/` porte la classe, partagée par les trois : personne n'écrit `Entity` deux
fois, et une seule ligne à changer suffit à modifier les trois traces.

## Compiler et lancer

```powershell
cmake -S . -B build
cmake --build build
```

Puis, au choix :

```powershell
build/01_dans_le_main/01_dans_le_main.exe
build/02_dans_une_fonction/02_dans_une_fonction.exe
build/03_deux_entites/03_deux_entites.exe
```

## Les trois traces

### 01 — dans le `main`

```text
main : avant
  + Gobelin : constructeur
    Gobelin agit
main : apres
  - Gobelin : destructeur
```

`main : apres` sort **avant** le destructeur : personne n'a écrit l'appel, et
pourtant il a lieu — à l'accolade fermante, pas à la dernière instruction.

### 02 — dans une fonction

```text
main : avant l'appel
  Invoquer : debut
  + Squelette : constructeur
    Squelette agit
  Invoquer : fin
  - Squelette : destructeur
main : apres l'appel
```

La portée de la fonction se referme avant que le `main` reprenne : le destructeur
passe **entre** les deux lignes du `main`. C'est la même règle que ci-dessus, vue
sur une portée plus courte.

### 03 — deux entités à la suite

```text
main : avant
  + Gobelin : constructeur
  + Troll : constructeur
    Gobelin agit
    Troll agit
main : apres
  - Troll : destructeur
  - Gobelin : destructeur
```

Gobelin naît en premier et meurt en dernier. La portée se **dépile** : le dernier
construit est le premier détruit, toujours.

## À essayer

- mettre `Entity troll("Troll");` dans un bloc `{ }` à l'intérieur du `main`, et
  prédire où passe son destructeur ;
- dans `03`, échanger les deux déclarations : qu'est-ce qui change dans la trace ?
- ajouter un troisième objet entre les deux, et vérifier la règle sur trois.

## Conventions

En-têtes `.h` dans `include/`, implémentations `.cc` dans `src/` : voir
`01 courses/companion projects/CLAUDE.md` et la skill `programmation-cpp`.
