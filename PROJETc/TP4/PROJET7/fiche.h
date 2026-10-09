/* Sarah DAHMOUN   12108993   INSTRUMENTATION 1      TP4: Carnet de notes */
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 80
#define N_MATIERE 3 

typedef struct {
	char title[SIZE];
	double score;
} COURSE;

typedef struct {
	char name[SIZE];
	char surname[SIZE];
	int id;
	COURSE t_course[N_MATIERE]; /*Tableau de structure*/
}FICHE;

typedef struct _NODE {
	FICHE fiche;
	struct _NODE* next;
	struct _NODE* previous;

}NODE;

typedef struct {
	NODE* first;
	NODE* last;

}LIST;

void printFiche(FICHE);
void saveFiche(FILE*, FICHE);
void loadFiche(FICHE*, char*);

char* getName(FICHE* fiche);

void setName(FICHE* fiche, char* name);
char* getSurname(FICHE* fiche);
void setSurname(FICHE* fiche, char* surname);
int getId(FICHE* fiche);
void setId(FICHE* fiche, int num);
COURSE* getCourse(FICHE* fiche,int ind);
const char* getTitle(COURSE* t_course);
double getScore(COURSE* t_course);
void setCourse(FICHE* fiche, COURSE source, int n);
void setTitle(COURSE* course, char* titre);
void setScore(COURSE* t_course, double note); 
FICHE ficheFromInput(void);
COURSE courseFromInput(void);
void appendTolist(LIST *list, FICHE fiche);
void printList(LIST list);
FICHE removeFromList(LIST* list, int id);