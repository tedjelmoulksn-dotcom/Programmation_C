/* SINACER TEDJ EL MOULK - 26/01/2024 - TP2 */
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>       /* for time() */
#include <stdlib.h>     /* pour srand() et rand()*/
#include<stdio.h>
#include <string.h> 
#define TAILLE 80
typedef char MOT[TAILLE]; // alias pour les char 

void printFiche(FICHE fiche)
{
	int i;

	printf("Name:  %s\n"\
		"Surname:  %s\n"\
		"Id      :%d\n"\
		"Courses :\n", fiche.name, fiche.surname, fiche.id);
	for (i=0 ; i<TAILLE ;i++)
		printf("    %s  :%f\n", fiche.matiere[i].title, fiche.matiere[i].score)r

}



void saveFiche(FILE* file, FICHE fiche)
{
	if (file == NULL)
		fprint(stderr, "could nor write to NULL file!\n");
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

