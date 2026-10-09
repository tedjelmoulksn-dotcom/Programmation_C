
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

#define SIZE 200

void print_produits(CATEGORIE categorie) {
	NODE_P* n = categorie.list_produits->first;
	while (n != categorie.list_produits->last)
	{
		printf("Nom produit : %s ; Prix du produit : %f ; Quantité disponible : %d \n", n->produit.nom_produit, n->produit.prix_produit, 
			n->produit.quantite_produit);
		n = n->next;
	}
}
