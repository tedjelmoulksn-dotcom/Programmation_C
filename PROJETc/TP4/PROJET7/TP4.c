/* Sarah DAHMOUN   12108993   INSTRUMENTATION 1      TP4: Carnet de notes */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fiche.h"


void exo2(void);
void exo3(void);
void exo4(void);
void appendTolist(LIST* list, FICHE fiche);
int main() {
	printf("QUESTION1:\n");
	printf("Rien a afficher\n");
	printf("___________________\n");
	printf("QUESTION2:\n");
	exo2();
	printf("___________________\n");
	printf("QUESTION3:\n");
	exo3();
	printf("___________________\n");
	printf("QUESTION4:\n");
	exo4();




}

void exo2(void) {
	FICHE fiche = { " Doe "," John " ,115 ,{{" Maths " ,12.0} ,{" Info " ,8.5} ,{" Physics " ,10.0}} };
	LIST list = { NULL, NULL };
	appendTolist(&list, fiche);
}
void appendTolist ( LIST* list , FICHE fiche ) {
	NODE* node = calloc(1, sizeof(NODE));/*Allocation dynamique de mémoire et initialisation à 0 de la node*/
	node->fiche = fiche;
	if (list->last != NULL) {
		/*Si le last existe*/
		list->last->next = node;
		/*On crée un autre noeud apres le dernier*/
		node->previous = list->last;
		/*Celui-ci doit avoir comme noeud d'avant l'ancien dernier noeud de la list*/
		list->last = node;
	}
	else {
		list->last = node;
		list->first = node;
	}
}
void exo3(void) {
	FICHE fiche1 = { " Doe "," John " ,115 ,
{{" Maths " ,12.0} ,{" Info " ,8.5} ,{" Physics " ,10.0}} };
	
	FICHE fiche2 = { " Doe "," Jane " ,27 ,
	{{" Maths " ,12.0} ,{" Info " ,8.5} ,{" Physics " ,10.0}} };
	
	FICHE fiche3 = { " Smith "," John " ,33 ,
	{{" Maths " ,12.0} ,{" Info " ,8.5} ,{" Physics " ,10.0}} };
	
	LIST list = { NULL, NULL };
/*Ajout des trois fiche à la liste vide*/
	appendTolist(&list, fiche1);
	appendTolist(&list, fiche2);
	appendTolist(&list, fiche3);
	printList(list);
}
void printList(LIST list) {
	if ((list.last != NULL) && (list.first != NULL)) {
		NODE* node;
		node = list.first ;
		while (node != list.last) {
			printFiche(node->fiche);
			printf("->");
			node = node->next;
		}
		printFiche(list.last->fiche);
		printf("\n");
	}
	else {
		printf("Le dernier element est nul\n");
	}
}/*Cette fonction permet d'afficher les éléments de la liste sur la console*/

void exo4(void)
	{
		FICHE etudiant1 = { " Doe "," John " ,115 ,
		{{" Maths " ,12.0} ,{" Info " ,8.5} ,{" Physics " ,10.0}} };
		FICHE etudiant2 = { " Doe "," Jane " ,27 ,
		{{" Maths " ,12.0} ,{" Info " ,8.5} ,{" Physics " ,10.0}} };
		FICHE etudiant3 = { " Smith "," John " ,33 ,
		{{" Maths " ,12.0} ,{" Info " ,8.5} ,{" Physics " ,10.0}} };
		FICHE tmp = { "","" ,0 ,{{"" ,0} ,{"" ,0} ,{"" ,0}} };
		LIST list = { NULL , NULL };
		appendTolist(&list, etudiant1);
		appendTolist(&list, etudiant2);
		appendTolist(&list, etudiant3);
		printf(" List initiale :\n");
		printList(list);
		// Test remove non existing element
		tmp = removeFromList(&list, 333);
		printFiche(tmp);
		// Test remove element in the middle
		tmp = removeFromList(&list, 27);
		printFiche(tmp); // Verify the return value
		printList(list); // Verify the list
		// Test remove first element
		tmp = removeFromList(&list, 115);
		printFiche(tmp); // Verify the return value
		printList(list); // Verify the list
		// Test remove last element
		tmp = removeFromList(&list, 33);
		printFiche(tmp); // Verify the return value
		printList(list); // Verify the list
		// Test remove on an empty list
		tmp = removeFromList(&list, 115);
		printFiche(tmp); // Verify the return value
		printList(list); // Verify the list

}
FICHE removeFromList(LIST* list, int id) {
	
	FICHE fichevide = { "","" ,0 ,{{"" ,0.0} ,{"" ,0.0} ,{"" ,0.0}} };
		NODE* node = list->first; /*Pour pouvoir se deplacer dans la liste*/
		
		while (node != NULL) {
			if (node->fiche.id == id){
				break;
				/*Dans le cas ou le numéro étudiant a été retrouvé on arrete de chercher */
			}
			else {
				node = node->next;
				/*On continue de parcourir la liste*/
			}
		}
			if (node == NULL){
				return fichevide;
				/* Si on ne trouve pas cete donnée on retourne la fiche vide */
			}
			else {
				if (list->first == node) {
	/*Si la donnée est dans la première fiche*/
					list->first = node->next;
/*Le début de la liste donc la première fiche devient la deuxième */
					if (list->first != NULL) {
						list->first->previous = NULL;
					}
					return node->fiche;
				}
				else {
					if (list->last == node) {
						/*Si la donnée est dans la dernière fiche */
						list->last = node->previous;
						/*La dernière fiche devient l'avant dernière*/
						list->last->next = NULL;
						printf("If 3 \n");
						return node->fiche;
					}
					else {
						/*Si la donnée est dans la deuxième fiche*/
						node->next->previous = node->previous;
						/*la fiche d'avant (après la 2 donc la 3) devient la 1*/
						node->previous->next = node->next;
						/*la fiche d'aprè (avant la 2 donc la 1) devient la 3*/
						printf("If 4 \n");
						return node->fiche;
					}
				}
			}
		
	}
/*Cette fonction va chercher une fiche dans la liste à partir du numéro étudiant*/
/*la fonction va parcourir la liste cherchersi le num étudiant
existe si c'est le cas renvoyer la fiche en l'enlevant de la liste
si on a pas trouver on revoi une liste vide*/