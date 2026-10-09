# Exercices de langage C

Deux travaux pratiques d'initiation au langage C : calculs statistiques sur des tableaux de `double`, puis structures, fichiers CSV et découpage de chaînes.

## Présentation

| Élément | Détail |
|---|---|
| Cadre | Travaux pratiques de langage C, Sup Galilée (Université Sorbonne Paris Nord), 1re année du cycle ingénieur Instrumentation |
| Dates | 23/01/2024 (TP1) et 26/01/2024 (TP2), d'après les en-têtes des fichiers |
| Auteure | Tedj El Moulk Sinacer (travail individuel d'après les en-têtes) |
| État | Exercices de TP. Le TP1 est complet mais contient des erreurs de calcul ; l'exercice 5 du TP2 n'est pas fonctionnel (voir Limites) |

Les sujets de TP et le polycopié de cours appartiennent aux enseignants et ne sont pas inclus dans ce dépôt.

## Matériel et outils

| Outil | Usage |
|---|---|
| Langage C | Bibliothèque standard uniquement (`stdio.h`, `stdlib.h`, `string.h`, `math.h`) |
| Visual Studio (MSVC) | Environnement d'origine : présence de `_CRT_SECURE_NO_WARNINGS` et de fichiers de projet `.vcxproj` dans l'archive source (non inclus) |

## Fichiers et notions

| Fichier | Notions travaillées | Fonctions principales |
|---|---|---|
| `src/tp1_vecteurs_statistiques.c` | Tableaux de taille fixe (`SIZE` = 10), passage de tableaux en argument, boucles, `qsort` avec fonction de comparaison, `rand`, `sqrt` | `printVector`, `dot`, `copyVector`, `val_moyenne`, `dev_standrad`, `valeur_minimale`, `valeur_maximale`, `medianne`, `initialiser`, `compare` |
| `src/tp2_fiches_etudiants_csv.c` | `struct` imbriquées, `typedef`, passage par valeur et par pointeur, écriture de fichier (`fopen`, `fprintf`, `fclose`), découpage de chaîne (`strtok`), conversions (`atoi`, `atof`) | `printFiche`, `saveFiche`, `loadFiche` |

## Fonctionnement

### TP1 — vecteurs et statistiques

Le `main` enchaîne cinq exercices sur des vecteurs de 10 `double` :

1. affichage d'un vecteur (`printVector`) ;
2. fonction `dot` appliquée à deux vecteurs ;
3. copie élément par élément (`copyVector`) ;
4. moyenne, « déviation standard », minimum, maximum et médiane. La médiane trie le tableau avec `qsort` puis prend la moyenne des deux éléments centraux si `SIZE` est pair, l'élément central sinon ;
5. remplissage aléatoire dans l'intervalle [-1 ; 1] par `(rand() / (double)RAND_MAX) * 2 - 1` (`initialiser`).

### TP2 — fiches étudiants et CSV

Structures de données :

```c
typedef char MOT[TAILLE];            /* TAILLE = 80 */
struct _COURSE { MOT title; double score; };
struct _FICHE  { MOT name; MOT surname; int id; COURSE matiere[3]; };
```

| Exercice | Contenu |
|---|---|
| 1 | Initialisation d'une `FICHE` et affichage sur une ligne (`printFiche`) |
| 2 | Sérialisation au format `champ;champ;...` sur `stdout` (`saveFiche`) |
| 3 | Même sérialisation dans `database.csv` ouvert en écriture |
| 4 | Reconstruction d'une `FICHE` depuis une chaîne avec `strtok(str, ";")`, `atoi` pour l'identifiant et `atof` pour les notes (`loadFiche`) |
| 5 | Relecture de `database.csv` ligne par ligne avec `fgets` puis `loadFiche` (non fonctionnel, voir Limites) |

## Contenu du dépôt

```
Exercices_C/
├── README.md
├── .gitignore
└── src/
    ├── tp1_vecteurs_statistiques.c
    └── tp2_fiches_etudiants_csv.c
```

## Compilation

Chaque fichier est un programme autonome avec son propre `main`. Commandes indicatives avec GCC (les sources ont été écrites sous Visual Studio ; la compilation sous GCC n'a pas été vérifiée) :

```sh
gcc src/tp1_vecteurs_statistiques.c -o tp1 -lm
gcc src/tp2_fiches_etudiants_csv.c -o tp2
```

Le TP2 est susceptible de produire des avertissements, voire des erreurs selon le compilateur, à cause des types incorrects de l'exercice 5.

## Limites

Constatées à la lecture du code ; rien n'a été corrigé.

**TP1 (`tp1_vecteurs_statistiques.c`)**

- `dot` ne calcule pas un produit scalaire : la boucle additionne `v1[i] + v2[i]` au lieu de `v1[i] * v2[i]`. La valeur affichée est donc la somme des éléments des deux vecteurs.
- `dev_standrad` renvoie `sqrt(somme(v[i]^2) / SIZE)`, c'est-à-dire la valeur quadratique moyenne (RMS) : la moyenne n'est pas soustraite, ce n'est pas un écart-type.
- `compare` renvoie `x - y` converti en `int` : un écart inférieur à 1 en valeur absolue est tronqué à 0 et les deux valeurs sont considérées comme égales par `qsort`.
- `medianne` trie le tableau reçu en place : le vecteur de l'appelant est modifié.
- `initialiser` renvoie `v[SIZE]`, soit une lecture hors du tableau ; `srand` n'est jamais appelé, la séquence aléatoire est identique à chaque exécution.
- Le vecteur `tab3` est déclaré mais n'est pas utilisé.

**TP2 (`tp2_fiches_etudiants_csv.c`)**

- Exercice 5 : le fichier est ouvert dans une variable de type `FICHE *` au lieu de `FILE *`, et `fgets` écrit directement dans la structure `file_3`, qui sert ensuite de source et de destination à `loadFiche`. Cette partie n'est pas fonctionnelle en l'état.
- `saveFiche` n'écrit pas de saut de ligne en fin d'enregistrement et ne teste pas si `file` vaut `NULL`.
- `loadFiche` ne vérifie pas le retour de `strtok` avant `strcpy`, `atoi` et `atof` : une ligne incomplète provoque un déréférencement de pointeur nul. Les espaces entourant les champs ne sont pas supprimés.
- Le retour de `fopen` n'est pas testé.

**Général**

- Pas de jeu de tests ni de trace d'exécution conservée : résultats à l'exécution « À documenter ».

## Licence

Aucune licence n'a été définie.
