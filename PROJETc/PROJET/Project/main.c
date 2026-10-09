/* Dahmoun sarah     Sinacer Tedj el moulk             INSTRU 1*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"


int main() {
	CATEGORIE fruits;
	PRODUIT p = { "Banane" , 200 , 1 };
	NODE_P* n = calloc( 1, sizeof(NODE_P));/*Allocation dynamique de mémoire et initialisation à 0 de la node*/
	n->produit = p;
	LISTE_P* liste_de_produits = { n };
	PRODUIT K = { "Orange" , 300 ,2 };
	n->produit = K;
	n->previous = liste_de_produits->first;
	liste_de_produits->first->next = n;
	print_produits(fruits);
	return 0;
}


