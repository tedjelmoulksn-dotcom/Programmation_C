
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

#define SIZE 500
#define AJOUT 1
#define SUPPRESSION 0

void print_produits(CATEGORIE categorie) 
{
	NODE_P* n = categorie.list_produits->first;
	while (n != categorie.list_produits->last)
	{
		printf("Nom produit : %s ; Prix du produit : %f ; Quantite disponible : %d \n", n->produit.nom_produit, n->produit.prix_produit, n->produit.quantite_produit);
		
		n= n->next;
	}
	printf("Nom produit : %s ; Prix du produit : %f ; Quantite disponible : %d \n", n->produit.nom_produit, n->produit.prix_produit,
		n->produit.quantite_produit);
}
/* Fonction qui compare les noms et renvoi 0,1 ou -1  */
	
void tri_alphabetique(CATEGORIE* categorie)
{
	
	NODE_P* current = categorie->list_produits->first;         /* Me permet de savoir ou j'en suis dans le tri*/
	NODE_P* min = categorie->list_produits->first;			   /*Je considère le nom du premier produit comme étant le premier dans un ordre alphabétique */
	NODE_P* node_next = current->next;							/*Noeud auxiliaire*/
	PRODUIT temp = { "",0.0,0 };
						   
	while (current != NULL)										/*Se balader dans la liste tant qu'on est pas arrivé à la fin */
	{
			 min = current;										/*Je considère le nom du  produit actuelle comme étant le premier dans un ordre alphabétique */	
			 node_next = current->next;						

		while(node_next != NULL)
		{
			if (strcoll(min->produit.nom_produit, node_next->produit.nom_produit) > 0)   /* La fonction strcoll fonctionne comme strcmp mais est insensible à la casse */
			{
				min = node_next;                                                         /* Elle compare tous les mots à partir du current et trouve le nom placer au début alphabétiquement */
			}
			node_next = node_next -> next;
		}

		if (min != current)																  
		{
			temp = current->produit;													/*permutation des produits selon l'ordre du tri*/
			current->produit = min->produit;
			min->produit = temp;

		}
		
		current = current->next;
	}
	
	print_produits(*categorie);
}


void tri_prix_croissant(CATEGORIE* categorie)
{
	NODE_P* current = categorie->list_produits->first;         /* Me permet de savoir ou j'en suis dans le tri*/
	NODE_P* min = categorie->list_produits->first;
	NODE_P* node_next = current->next;
	PRODUIT temp = { "",0.0,0 };
																/* Me permet de comparer le  prix avec tous les autres qui suivent  */
	while (current != NULL)
	{
		min = current;
		node_next = current->next;

		while (node_next != NULL)
		{
			if (min->produit.prix_produit > node_next->produit.prix_produit)   
			{
				min = node_next;
			}
			node_next = node_next->next;
		}

		if (min != current)									
		{
			temp = current->produit;
			current->produit = min->produit;
			min->produit = temp;

		}

		current = current->next;
	}

	print_produits(*categorie);
	
}
    /*Fonction de tri des prix décroissant */
void tri_prix_decroissant(CATEGORIE* categorie) 
{
	NODE_P* current = categorie->list_produits->first;        
	NODE_P* max = categorie->list_produits->first;
	NODE_P* node_next = current->next;
	PRODUIT temp = { "",0.0,0 };
	
	while (current != NULL)
	{
		max = current;
		node_next = current->next;

		while (node_next != NULL)
		{
			if (max->produit.prix_produit < node_next->produit.prix_produit)   /* La fonction strcoll fonctionne comme strcmp mais est insensible à la casse */
			{
				max = node_next;
			}
			node_next = node_next->next;
		}

		if (max != current)
		{
			temp = current->produit;
			current->produit = max->produit;
			max->produit = temp;

		}

		current = current->next;
	}

	print_produits(*categorie);
}



void tri_quantite_dispo(CATEGORIE* categorie) 
{
	
	NODE_P* current = categorie->list_produits->first;         /* Me permet de savoir ou j'en suis dans le tri*/
	NODE_P* quantité_min = categorie->list_produits->first;
	NODE_P* node_next = current->next;
	PRODUIT temp = { "",0.0,0 };
	
	while (current != NULL)
	{
		quantité_min = current;
		node_next = current->next;

		while (node_next != NULL)
		{
			if (quantité_min->produit.prix_produit > node_next->produit.prix_produit)  
			{
				quantité_min = node_next;
			}
			node_next = node_next->next;
		}

		if (quantité_min != current)
		{
			temp = current->produit;
			current->produit = quantité_min->produit;
			quantité_min->produit = temp;

		}

		current = current -> next;
	}

	print_produits(*categorie);
}

void maj_produit_prix(CATEGORIE* categorie)
{
	NODE_P* node = categorie->list_produits->first;
	char produit[SIZE];
	float nouveau_prix_produit;
	

	printf("Entrer le nom du produit : \n");
	scanf("%s", produit);						//produit a mettre a jour

	printf("Entrer la nouveau produit : \n");
	scanf("%f", &nouveau_prix_produit);

	while(node!=NULL)
	{
		if (strcoll (produit, node->produit.nom_produit) == 0 )
		{
			node->produit.prix_produit = nouveau_prix_produit;
		}
		node = node->next;
	}
	print_produits(*categorie);
}   


void maj_produit_quantite(CATEGORIE* categorie)
{
	char produit[SIZE];
	float nouvelle_quantite_produit;

	NODE_P* node = categorie->list_produits->first;

	/* Pour donner le nombre d'éléments */
	

	printf("Entrtrer le nom du produit :\n");
	scanf("%s",produit);  //produit a mettre a jour

	printf("Entrer la nouvelle quantite :\n");
	scanf("%f",&nouvelle_quantite_produit);
	while (node != NULL)
	{
		if (strcoll(produit,node->produit.nom_produit) == 0)
		{
			node->produit.quantite_produit = nouvelle_quantite_produit;
		}
		node = node->next;
	}
	print_produits(*categorie);

}

void suppression_produit(CATEGORIE* categorie) 
{	
	char produit[SIZE];

	NODE_P* node = categorie->list_produits->first;
	NODE_P* supp;
	NODE_P* aux;
	NODE_P* aux1;
	
	printf("Entrer le nom du produit : \n");
	scanf("%s",produit);
	
	while (node != NULL)
	{


		if (strcoll(node->produit.nom_produit,produit) == 0)
		{	
			supp = node;

			if (node == categorie->list_produits->first)
			{
				node = node->next;
				categorie->list_produits->first = node;
				if (node != NULL)
				{
					node->previous = NULL;
				}
			}
			else if (node == categorie->list_produits->last)
			{
				node = node->previous;
				categorie->list_produits->last = node;

				if (node != NULL)
				{
					node->next = NULL;
				}
			}
			else
			{
				aux = node->previous;
				aux->next = node->next;
				aux1 = node->next;
				aux1->previous = node->previous;
		

			}
		}
		node = node->next;
	}

	print_produits(*categorie);
}

void ajout_produit(CATEGORIE* categorie)
{
	char nouveau_produit[SIZE];
	float nouveau_prix = 0.0;
	int nouvelle_quantite = 0;
	NODE_P* node = (NODE_P*)malloc(sizeof(NODE_P));  /*allocation d'espace mémoire pour un nouveau noeud pour le nouveau produit */
	NODE_P* dernier = categorie->list_produits->last;


	/* Création du nouveau produit */
	PRODUIT nouveau = { "",0.0,0 };
	printf("Entrer le nom du nouveau produit : \n");
	scanf("%s",nouveau_produit);

	printf("Entrer le prix du nouveau produit : \n");
	scanf("%f",&nouveau_prix);

	printf("Entrer la quantite du nouveau produit : \n");
	scanf("%d",&nouvelle_quantite);

	strcpy(nouveau.nom_produit,nouveau_produit); /* Copier le nom du nouveau produit entrée au clavier dans la structure du nouveau produit */
	nouveau.prix_produit = nouveau_prix;
	nouveau.quantite_produit = nouvelle_quantite;

	if (node == NULL)
	{
		printf("ERREUR \n : ");
		return;
	}

	node->produit = nouveau;                     
	node->next = NULL;

	if (dernier != NULL)
	{
		dernier->next = node;
		node->previous = dernier; 
	}
	else 
		/* Si la liste est vide, le nouveau noeud devient le premier noeud */
	{
		categorie->list_produits->first = node;
		node->previous = NULL;
	}

	categorie->list_produits->last = node;

	

	print_produits(*categorie); 
}
void suppression_categorie(LISTE_C* liste_categorie)
{
	char categorie[SIZE];

	NODE_C* node = liste_categorie->first;
	NODE_C* supp;
	NODE_C* aux;
	NODE_C* aux1;


	printf("Entrer le nom de la categorie  : \n");
	scanf("%s", categorie);

	while (node != NULL)
	{
		supp = node;			//je comprend pas pk 

		if (strcoll(node->categorie.nom_categorie, categorie) == 0)
		{


			if (node == liste_categorie->first)        //cas ou la categorie est au debut 
			{
				node = node->next;
				liste_categorie->first = node;

				if (node != NULL)
				{
					node->previous = NULL;
				}
			}
			else if (node == liste_categorie->last)		//cas ou la categorie est a la fin
			{
				node = node->previous;
				liste_categorie->last = node;

				if (node != NULL)
				{
					node->next = NULL;
				}
			}
			else                                       //cas ou la categorie nest ni en au debut  ni a la fin 
			{
				aux = node->previous;
				aux->next = node->next;
				aux1 = node->next;
				aux1->previous = node->previous;



			}
		}
		node = node->next;
	}
	affichage_des_categories(liste_categorie);
}

void ajout_categorie(LISTE_C* liste_categorie)
{
	char nvl_categorie[SIZE];
	int i=2;

	NODE_C* node = (NODE_C*)malloc(sizeof(NODE_C));

	NODE_C* dernier = liste_categorie->last;
	//creation de la nvl categorie 
	node->next = NULL;
	CATEGORIE nouvelle_categorie;
	printf("Entrer le nom de la nouvelle categorie  : \n");
	scanf("%s", nvl_categorie);

	strcpy(nouvelle_categorie.nom_categorie, nvl_categorie);	 /* Copier le nom de la nouvelle categorie entrée au clavier dans la structure de la nouvelle categorie*/
	nouvelle_categorie.list_produits = (LISTE_P*)malloc(sizeof(LISTE_P));
	nouvelle_categorie.list_produits->first = NULL;
	nouvelle_categorie.list_produits->last = NULL;
	//on rjoute le node a la fin de notre liste de categorie 

	if (node == NULL)
	{
		printf("ERREUR \n : ");
		return;
	}

	node->categorie = nouvelle_categorie;
	node->next = NULL;

	if (dernier != NULL)
	{
		dernier->next = node;
		node->previous = dernier;
	}
	else
		/* Si la liste est vide, le nouveau noeud devient le premier noeud */
	{
		liste_categorie->first = node;
		node->previous = NULL;
	}

	liste_categorie->last = node;

	ajout_produit(&nouvelle_categorie);

	while (i != 0)
	{
		printf("voulez-vous rajouter un autre produit a cette categorie?\n");
		printf("tappez '1' pour 'oui\n");
		printf("tappez '0' pour 'non'\n");
		scanf("%d", &i);
		if (i == 1)
			ajout_produit(&nouvelle_categorie);// bien pour un seul produit 
	}
}

void affichage_des_categories(LISTE_C* liste_categorie)
{
	if (liste_categorie->first == NULL)
	{
		printf("le stock est vide.\n ");
		return;
	}
	NODE_C* current = liste_categorie->first;
	printf("les categories dans le stock:\n ");
		while (current != NULL)
		{			printf("%s\n", current->categorie.nom_categorie);
					current = current->next;	
		}

}

void gestion_stock(LISTE_C* liste_categories)
{

	char categorie_amodifier[SIZE];
	int choix_action=9;
	//char nom_categorie[SIZE] = { "" };
	NODE_C* current = liste_categories->first;

	/*Demande quelle catégorie  modifier*/
	printf("Entrez le nom de la catégorie a modifier :\n ");
	scanf("%s", categorie_amodifier);

	/* Recherche de cette catégorie dans la liste */
	while (current != NULL)
	{
		if (strcmp(current->categorie.nom_categorie, categorie_amodifier) == 0) //on a trouver la categoriue 
		{

			printf("Quelle action souhaitez-vous effectuer ? : \n");
			printf("1. Ajouter un produit\n");
			printf("2. Supprimer un produit\n");
			printf("3. Trier la categorie dans un ordre alphabetique\n");
			printf("4. Trier la categorie par ordre de prix decroissant\n");
			printf("5. Trier la categorie par ordre de prix croissant\n");
			printf("6. Trier la categorie en fonction des quantites disponnibles \n");
			printf("7. Mettre à jour le prix d'un produit \n ");
			printf("8. Mettre à jour la quantité d'un produit \n");
			scanf("%d", &choix_action);


			if (choix_action == 1)
			{
				ajout_produit(&(current->categorie));
			}
			else if (choix_action == 2)
			{
				suppression_produit(&(current->categorie));
			}
			else if (choix_action == 3)
			{
				tri_alphabetique(&(current->categorie));
			}
			else if (choix_action == 4)
			{
				tri_prix_decroissant(&(current->categorie));
			}
			else if (choix_action == 5)
			{
				tri_prix_croissant(&(current->categorie));
			}
			else if (choix_action == 6)
			{
				tri_quantite_dispo(&(current->categorie));
			}
			else if (choix_action == 7)
			{
				maj_produit_prix(&(current->categorie));
			}
			else if (choix_action == 8)
			{
				maj_produit_quantite(&(current->categorie));
			}

			else
			{
				/* Demander quel type d'action effectuer */
				printf("Quelle action souhaitez-vous effectuer ? : \n");
				printf("1. Ajouter un produit\n");
				printf("2. Supprimer un produit\n");
				printf("3. Trier la categorie dans un ordre alphabetique\n");
				printf("4. Trier la categorie par ordre de prix decroissant\n");
				printf("5. Trier la categorie par ordre de prix croissant\n");
				printf("6. Trier la categorie en fonction des quantites disponnibles \n");
				printf("7. Mettre à jour le prix d'un produit \n ");
				printf("8. Mettre à jour la quantité d'un produit \n");
				printf(" \n");
				scanf("%d", &choix_action);
			}
			break;
		}
		current = current->next;
		if (strcmp(current->categorie.nom_categorie, categorie_amodifier) != 0)
				printf("la categorie est introuvable");
	}
		
}		



