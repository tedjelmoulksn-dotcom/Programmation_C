
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 200
 
/*la structure d'un produit*/

typedef struct {
	char nom_produit[SIZE];
	float prix_produit;
	int quantite_produit;
}PRODUIT;

/* Liste chainée des produits */

typedef struct {
	PRODUIT produit;
	struct _NODE_P* next;
	struct _NODE_P* previous;
}NODE_P;

typedef struct {
	NODE_P* first;
	NODE_P* last;

}LISTE_P;

/* la structure d'une catégorie */

typedef struct {
	char nom_categorie[SIZE];
	LISTE_P* list_produits;
}CATEGORIE;

/* Liste chainée des catégories */

typedef struct {
	CATEGORIE categorie;
	struct _NODE_C* next;
	struct _NODE_C* previous;
}NODE_C;

typedef struct {
	NODE_C* first;
	NODE_C* last;

}LISTE_C;

void print_produits(CATEGORIE );







