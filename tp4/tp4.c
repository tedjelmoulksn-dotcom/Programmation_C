//SINACER tedj el moulk, INSTRU1

//Pour définir une liste on utilise en général deux structures :
//une pour représenter les nœuds et une autre pour représenter la
//liste


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fiche.h"


typedef struct _NODE
{
	FICHE fiche ;
	struct _NODE* next;
	struct _NODE* prev;
} NODE;



typedef struct
{
	NODE* first;
	NODE* last;
} LIST;
void appendToListe(LIST* list, FICHE fiche);
void printList(LIST list);
FICHE removeFromList(LIST* list, int id);
int main(void)
{
	//exo1
	FICHE fiche = { "Doe" ,"John",115, { {"Math",12.0},{"Info",8.5},{"Physics",10.0}} };
	LIST list = { NULL , NULL };
	appendToListe(&list, fiche);
	//exo2
	FICHE fiche1 = { "Doe" ,"John",115, { {"Math",12.0},{"Info",8.5},{"Physics",10.0}} };
	FICHE fiche2 = { "Doe" ,"Jane",27, { {"Math",12.0},{"Info",18.5},{"Physics",15.0}} };
	FICHE fiche3 = { "Smith" ,"John",33, { {"Math",13.5},{"Info",7.5},{"Physics",16.0}} };
	LIST list = { NULL , NULL };
	appendToListe(&list, fiche1);
	appendToListe(&list, fiche2);
	appendToListe(&list, fiche3);
	printList(list);
}




























void appendToListe(LIST* list, FICHE fiche)
{
	NODE* node = calloc(1, sizeof(NODE));  //jalloue ma memo a mon objet 
	node->fiche = fiche; //mon node contient ma fiche 

	if (list->last) //si je suis a la fin de ma liste 
	{
		node->prev = list->last; //mon prev va devenir mon last 
		list->last->next = node; //mon next va avoir mon node qui ext mon last
		list->last = node; //jaffecte node a mon last de ma liste 
	}
		else 
		{
			list->last = node;
			list->first = node;
		}
		}


void printList(LIST list)
{
	NODE* node;
	node = list.first;
while (node != list.last )
{
	printFiche(node->fiche);
	printf("->");
	node = node->next;
}
printFiche(list.last->fiche);
printf("\n");


}

FICHE removeFromList(LIST* list, int id)
{ 

	//cherche une fiche a partir  de son id 
	NODE* node = calloc(1, sizeof(NODE));  //jalloue ma memo a mon objet 
	node = list->first;

	while (node != NULL)
	{
		if (getId(&node->fiche) == id)
		{ // jenvleve la fiche 
			if (node == list->first) //le premier
			{
				
				 list->first =node->next;
				 node->prev = NULL;
			}
			else if (node == list->last) //le dernier
			{
		
				list->last = node->prev;
				node->next = NULL;
			}
			else //au milieu
			{
				node->next->prev = node->prev;
				node->prev->next = node->next;
			}
			}

		break;
		node = node->next;
	}


	


	 // il est sorti de la boucle car y a po le id
	if (node == NULL)
	{
		
		FICHE etudiant = { " "," "  ,00 ,{ { "  ", 0.00}, { "  " ,0.00 }, { "  " ,0.00 }} };
		printf("FICHE etudiant = { ,  ,00 ,{ { "  ", 0.00}, { "  " ,0.00 }, { "  " ,0.00 }}\n"); // ya pas la fiche 
		return etudiant;
	}

	

		 

return node->fiche;
}
	
