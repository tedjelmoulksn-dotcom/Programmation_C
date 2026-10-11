/* Dahmoun sarah     Sinacer Tedj el moulk             INSTRU 1*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "projet.h"


int main() {

	setlocale(LC_ALL, ""); /*Permet d'utiliser strcoll configurer en Français */

	LISTE_P* produit = (LISTE_P*)malloc(sizeof(LISTE_P)); /*Initialisation et déclaration de la liste de produit*/
	produit->first = NULL;
	produit->last = NULL;
	/*Initialisation et décalaration de la catégorie on lui donne le nom fruits*/
	CATEGORIE Fruits = {     
		"fruits",
		produit       /*La liste prduit initialisée auparavant*/
	};

	NODE_P* node1 = malloc( sizeof(NODE_P)); /*Allocation dynamique de mémoire et initialisation à 0 de la node*/
	PRODUIT banane = { "Banane" , 200 , 1 };
	strcpy (node1 -> produit.nom_produit, banane.nom_produit) ;
	node1 -> produit.prix_produit = banane.prix_produit;
	node1 -> produit.quantite_produit = banane.quantite_produit;
	node1 -> next = NULL;
	node1->previous = NULL;
	produit -> first = node1;
	produit -> last = node1;

	NODE_P* node2 = malloc(sizeof(NODE_P));

	PRODUIT orange = { "Orange" , 900 , 2 };
	strcpy ( node2 -> produit.nom_produit , orange.nom_produit );
	node2->produit.prix_produit = orange.prix_produit;
	node2->produit.quantite_produit = orange.quantite_produit;
	node2->next = NULL;
	node2->previous = node1;
	produit -> last->next = node2;
	produit->last = node2;


	
	/* Affichage des produits de la catégorie */
	//print_produits(Fruits);
	//printf("tri alphabetique des produit\n");
	//tri_alphabetique(Fruits);

	//printf("tri prix croissant des produit\n");
	
	//tri_prix_croissant(&Fruits);
	
	//printf("tri prix decroissant des produit\n");
	//tri_prix_decroissant(&Fruits); 

	//printf("tri quantite dispo des produit\n");
	//tri_quantite_dispo(&Fruits);

	//printf("mettre a jour le prix d'un produit:\n");
	//maj_produit_prix(&Fruits);


	//printf("mettre a jour la quantite d'un produit\n  ");
	//maj_produit_quantite(&Fruits); 

	printf("supprimer un produit : \n");
	suppression_produit(&produit);


	return EXIT_SUCCESS;
}



