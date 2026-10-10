#define _CRT_SECURE_NO_WARNINGS
#include <time.h>       /* for time() */
#include <stdlib.h>     /* pour srand() et rand()*/
#include<stdio.h>
#include <string.h> 
#include "fiche.h"

void exo1(void);
//void exo2(void);

int main(void)
{
	//exo 1



	FICHE fiche = { "" , "" ,0,{{"",0.0 },{"",0.0},{"",0.0}  } };
	MOT name = "DOE", surname = "John";
	COURSE  courses[3] = { {"Maths",12.5 },{"Info",8.5},{"Physics",9.0} };


	int n;
	printf("vide\n ");

	printFiche(fiche);

	setName(&fiche, name);
	setSurname(&fiche, surname);
	setId(&fiche, 11300055);
	for (n = 0; n < 3; n++)
	{
		setCourse(&fiche, courses[n], n);
		printf("Filled Fiche:\n ");
		printFiche(fiche);

	}
}