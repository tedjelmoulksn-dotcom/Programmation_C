/* SINACER TEDJ EL MOULK - 26/01/2024 - TP2 */
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>       /* for time() */
#include <stdlib.h>     /* pour srand() et rand()*/
#include <stdio.h>
#include <string.h> 
#include "fiche.h"
#define TAILLE 80
typedef char MOT[TAILLE]; // alias pour les char 

void printFiche(FICHE fiche)
{
	int i;

	printf("Name: %s\n", fiche.name);
	printf("Surname: %s\n", fiche.surname);
	printf("Id:%d\n", fiche.id);
	printf("Courses  : \n"); 

	for (i = 0; i < TAILLE; i++)
	{
		printf(" %s  :%f\n", fiche.matiere[i].title, fiche.matiere[i].score);


	}
}


void saveFiche(FILE* file, FICHE fiche)
{
	if (file == NULL)
		printf(stderr, "could nor write to NULL file!\n");
	else
	{
		fprintf(file, "%s", fiche.name);
		fprintf(file, ";");

		fprintf(file, "%s", fiche.surname);
		fprintf(file, ";");

		fprintf(file, "%d", fiche.id);
		fprintf(file, ";");

		fprintf(file, "%s", fiche.matiere[0].title);
		fprintf(file, ";");

		fprintf(file, "%f", fiche.matiere[0].score);
		fprintf(file, ";");

		fprintf(file, "%s", fiche.matiere[1].title);
		fprintf(file, ";");

		fprintf(file, "%f", fiche.matiere[1].score);
		fprintf(file, ";");

		fprintf(file, "%s", fiche.matiere[2].title);
		fprintf(file, ";");

		fprintf(file, "%f", fiche.matiere[2].score);
		fprintf(file, ";");
	}

}


void loadFiche(FICHE* fiche, char* str)
{

	int i = 0;
	char* ptr;
	ptr = strtok(str, ";");


	while (ptr != NULL)
	{
		strcpy(fiche->name, ptr);
		ptr = strtok(NULL, ";");
		strcpy(fiche->surname, ptr);
		ptr = strtok(NULL, ";");
		fiche->id = atoi(ptr);
		ptr = strtok(NULL, ";");
		while (i != 3)
		{
			strcpy(fiche->matiere[i].title, ptr);
			ptr = strtok(NULL, ";");
			fiche->matiere[i].score = atof(ptr);
			ptr = strtok(NULL, ";");
			i++;
		}




	}



}



const char* getName(FICHE* fiche)
{
	return fiche->name; //pour quil modifie la valeur dans ladresse du name 

}

const char* getSurname(FICHE* fiche)
{
	return fiche->surname; //pour quil modifie la valeur dans ladresse du name 

}

unsigned int getId(FICHE* fiche)
{
	return fiche->id;

}
COURSE* getCourse(FICHE* fiche, int ind) //comme jai pluisuers courses , l'indice maide a choisir mql indice je beux acceder
{

	return fiche->matiere[ind];
}


const char* getTitle(COURSE* matiere)
{
	return matiere->title;
}
double getScore(COURSE* matiere)
{
	return matiere->score;
}

void setName(FICHE* fiche, char* name)
{
	strncpy(fiche->name, name, TAILLE);
}

void setSurname(FICHE* fiche, char* surname)
{
	strncpy(fiche->surname, surname, TAILLE);
}
void setId(FICHE* fiche, unsigned int num)

{
	fiche->id = num;


}
void setCourse(FICHE* fiche, COURSE matiere, int ind)
{
	setTitle(&fiche->matiere[ind], matiere.title); //je veux ladresse et donc je me & et je rajoutre un indice ind car jai pluisuer matiere 
	setScore(&fiche->matiere[ind], matiere.score);
}
void setTitle(COURSE* matiere, const char title2)
{
	strncpy(matiere->title, title2, TAILLE);
}
void setScore(COURSE* matiere, double score2)
{
	matiere->score = score2;

}