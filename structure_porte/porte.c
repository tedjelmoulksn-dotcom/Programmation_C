#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Porte {
	int hauteur; // en cms
	int largeur; // en cms
	char couleur[10]; // une couleur
	int etat; // fermée:0 ouverte:1
	char* (*f) (struct Porte*);
} Porte;

Porte* newPorte(int, int, char*);
char* toString(Porte*);
void openPorte(Porte*);
void closePorte(Porte*);
Porte* standardPorte();
void paintPorte(Porte*, char*);
int equals(Porte*, Porte*);

int main()
{
	Porte* porte1;
	Porte* standard_porte;
	Porte* porte3 = newPorte(50, 15, "Verte");
	char* res;

	/* Création et attribution des paramètres de la porte1 */
	porte1 = newPorte(50, 15, "Violet");

	/* Affichage de l'adresse de la porte1 */
	printf("%p\n", porte1);
	
	/* Affichage de la porte1 initialement fermée */
	printf("%s\n", toString(porte1));

	/* Ouverture de la porte1 et affichage de porte1 */
	openPorte(porte1);
	printf("%s\n", toString(porte1));

	/* Création et attribution des paramètres de la porte1 */
	standard_porte = standardPorte();

	/* Affichage de la standard_porte */
	printf("%s\n", toString(standard_porte));

	/* Affichage de la porte1 dont la couleur est maintenant verte */
	paintPorte(porte1, "Verte");
	printf("%s\n", toString(porte1));

	/* Tests d'égalités entre 2 portes */
	printf("porte1 == porte2 ? : %d\n", equals(porte1, porte3));
	
	res = porte1->f(porte3);
	printf("%s\n", res);

	return 0;
}

Porte* newPorte(int h, int l, char* c)
{
	Porte * porte = NULL;
	porte = (Porte*) malloc(1 * sizeof(Porte));

	if (porte != NULL)
	{
		porte->hauteur = h;
		porte->largeur = l;
		strcpy(porte->couleur, c);
		porte->etat = 0;
		porte->f = toString;
	}

	return porte;
}

char* toString(Porte* porte)
{
	char* string = (char*) malloc(100 * sizeof(char));

	sprintf(string, "{h:%d, l:%d, c:%s, e:%s}", porte->hauteur, porte->largeur, porte->couleur, (porte->etat)?"ouverte":"fermee");

	return string;
}

void openPorte(Porte* porte)
{
	porte->etat = 1;
}

void closePorte(Porte* porte)
{
	porte->etat = 0;
}

Porte* standardPorte()
{
	Porte* standard_porte;
	standard_porte = (Porte*) malloc(1 * sizeof(Porte));

	standard_porte->hauteur = 180;
	standard_porte->largeur = 90;
	strcpy(standard_porte->couleur, "Blanche");
	standard_porte->etat = 0;

	return standard_porte;
}

void paintPorte(Porte* porte, char* new_color)
{
	strcpy(porte->couleur, new_color);
}

int equals(Porte* porte1, Porte* porte2)
{
	if (porte1 == porte2)
	{
		return 1; // Retourne 1 si ce sont les mêmes adresses
	}

	if ((porte1 == NULL) || (porte2 == NULL))
	{
		return 0;
	}

	if (porte1->hauteur != porte2->hauteur)
	{
		return 0;
	}

	if (porte1->largeur != porte2->largeur)
	{
		return 0;
	}
	
	if (strcmp(porte1->couleur, porte2->couleur) != 0)
	{
		return 0;
	}

	return 1;
}