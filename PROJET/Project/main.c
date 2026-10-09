/* Dahmoun sarah     Sinacer Tedj el moulk             INSTRU 1*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "projet.h"


int main() {

	setlocale(LC_ALL, ""); /*Permet d'utiliser strcoll configurer en Français */

	LISTE_P* produit1 = (LISTE_P*)malloc(sizeof(LISTE_P)); /*Initialisation et déclaration de la liste de produit*/
	produit1->first = NULL;
	produit1->last = NULL;
	/*Initialisation et décalaration de la catégorie on lui donne le nom fruits*/
	CATEGORIE Fruits = {
		"Fruits",
		produit1       /*La liste prduit initialisée auparavant*/
	};

	NODE_P* node1 = malloc(sizeof(NODE_P)); /*Allocation dynamique de mémoire et initialisation à 0 de la node*/
	PRODUIT banane = { "Banane" , 200 , 1 };
	strcpy(node1->produit.nom_produit, banane.nom_produit);
	node1->produit.prix_produit = banane.prix_produit;
	node1->produit.quantite_produit = banane.quantite_produit;
	node1->next = NULL;
	node1->previous = NULL;
	produit1->first = node1;
	produit1->last = node1;

	NODE_P* node2 = malloc(sizeof(NODE_P));

	PRODUIT orange = { "Orange" , 900 , 2 };
	strcpy(node2->produit.nom_produit, orange.nom_produit);
	node2->produit.prix_produit = orange.prix_produit;
	node2->produit.quantite_produit = orange.quantite_produit;
	node2->next = NULL;
	node2->previous = node1;
	produit1->last->next = node2;
	produit1->last = node2;




	LISTE_P* produit2 = (LISTE_P*)malloc(sizeof(LISTE_P)); /*Initialisation et déclaration de la deuxième liste de produit*/
	produit2->first = NULL;
	produit2->last = NULL;




	/*Initialisation et décalaration de la catégorie on lui donne le nom fruits*/
	CATEGORIE	Legumes = {
		"Legumes",
		produit2      /*La liste prduit initialisée auparavant*/
	};

	NODE_P* node3 = malloc(sizeof(NODE_P)); /*Allocation dynamique de mémoire et initialisation à 0 de la node*/
	PRODUIT poivron = { "Poivron" , 200 , 1 };
	strcpy(node3->produit.nom_produit, poivron.nom_produit);
	node3->produit.prix_produit = poivron.prix_produit;
	node3->produit.quantite_produit = poivron.quantite_produit;
	node3->next = NULL;
	node3->previous = NULL;
	produit2->first = node3;
	produit2->last = node3;

	NODE_P* node4 = malloc(sizeof(NODE_P));

	PRODUIT oignon = { "Oignon" , 240.9 , 28 };
	strcpy(node4->produit.nom_produit, oignon.nom_produit);
	node4->produit.prix_produit = oignon.prix_produit;
	node4->produit.quantite_produit = oignon.quantite_produit;
	node4->next = NULL;
	node4->previous = node3;
	produit2->last->next = node4;
	produit2->last = node4;

	LISTE_C* stock = (LISTE_C*)malloc(sizeof(LISTE_C));
	NODE_C* cat1 = (NODE_C*)malloc(sizeof(NODE_C));
	NODE_C* cat2 = (NODE_C*)malloc(sizeof(NODE_C));




	stock->first = cat1;
	stock->last = cat2;

	cat1->categorie = Fruits;
	cat1->next = cat2;
	cat1->previous = NULL;

	cat2->categorie = Legumes;
	cat2->next = NULL;
	cat2->previous = cat1;



	
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

	//printf("supprimer un produit : \n");
	//suppression_produit(& Fruits);
	//ajout_produit(&Fruits);
	//suppression_categorie(stock);
	//print_produits(Legumes);
	//ajout_categorie(stock);
	//affichage_des_categories(stock);
	gestion_stock(stock);
	return EXIT_SUCCESS;
}



