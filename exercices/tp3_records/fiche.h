#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>       /* for time() */
#include <stdlib.h>     /* pour srand() et rand()*/
#include <stdio.h>
#include <string.h> 
#define TAILLE 80
typedef char MOT[TAILLE]; // alias pour les char 





struct _COURSE    //structure contenant la matoere et la note  
{
	MOT title;
	double score;



};
typedef struct _COURSE COURSE;

struct _FICHE   //structure contenant les info de letudiant 
{
	MOT name;
	MOT surname;
	unsigned int id;
	COURSE matiere[3];
};


typedef struct _FICHE FICHE;//alias fiche

// mes fonctions
void printFiche(FICHE fiche);
void saveFiche(FILE* file, FICHE fiche);
void loadFiche(FICHE* fiche, char* str);


const char* getName(FICHE* fiche);
const char* getSurname(FICHE* fiche);
unsigned int getId(FICHE* fiche);
COURSE* getCourse(FICHE* fiche, int ind);
const char* getTitle(COURSE* matiere);
double getScore(COURSE* matiere);
void setName(FICHE* fiche, char* name);
void setSurname(FICHE* fiche, char* surname);
void setId(FICHE* fiche, unsigned int num);
void setCourse(FICHE* fiche, COURSE matiere, int ind);
void setTitle(COURSE* matiere, const char title2);
void setScore(COURSE* matiere, double score2);