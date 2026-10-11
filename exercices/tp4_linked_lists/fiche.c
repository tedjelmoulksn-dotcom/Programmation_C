
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fiche.h"

#define SIZE 80
#define N_MATIERE 3

void printFiche(FICHE fiche) {
	int i;
	/*Affichage de la fiche pour l'étudiant dont les données sont dans la structure fiche*/
	printf("Fiche : \n{ \nName : %s \nSurname : %s \n Id : %d \nMatieres :\n{", getName(&fiche), getSurname(&fiche), getId(&fiche));
	/*Affichage des matières et le score dans chacunes*/
	for (i = 0; i < N_MATIERE; i++) {
		printf("\n%s : %f \n", getTitle(getCourse(&fiche, i)), getScore(getCourse(&fiche, i)));
	}
	printf("} \n} \n");
}

void saveFiche(FILE* file, FICHE fiche) {
	int i = 0;
	/*getName remplace le fich.name donc elle retourne directement cette valeur*/
	fprintf(file, "%s;%s;%d;", getName(&fiche), getSurname(&fiche), getId(&fiche));
	for (i = 0; i < N_MATIERE; i++) {
		fprintf(file, "%s;%f;", getTitle(getCourse(&fiche, i)), getScore(getCourse(&fiche, i)));
	}
	fprintf(file, "\n");
}	/* La fonction sauvegarde le contenu de la fiche dans un fichier déja ouvert */

void loadFiche(FICHE* fiche, char ch[]) {
	int i;
	const char* delimiteur = ";";
	char* strToken = strtok(ch, delimiteur);
	COURSE aux = { "",0.0 };

	setName(fiche, strToken);

	strToken = strtok(NULL, delimiteur);
	setSurname(fiche, strToken);

	strToken = strtok(NULL, delimiteur);
	setId(fiche, atoi(strToken)); //fiche->id = atoi(strToken);
	for (i = 0; i < N_MATIERE; i++) {
		strToken = strtok(NULL, delimiteur);
		setTitle(&fiche->t_course[i], strToken);
		strToken = strtok(NULL, delimiteur);
		setScore(&fiche->t_course[i], atof(strToken));
	}
	puts(fiche->name);
	puts(fiche->surname);
	printf("%d\n", fiche->id);
	for (i = 0; i < N_MATIERE; i++) {
		puts(fiche->t_course[i].title);
		printf("%f\n", fiche->t_course[i].score);
	}
	/*La fonction convertit des parties de la chaine de caractère séparées par des ; en fiche et les affiche par suite */

}



char* getName(FICHE* fiche) {
	return fiche->name;
}

void setName(FICHE* fiche, char* name) {
	int i = 0;
	/*Je ne peux pas modifier name donc je crée temp pour mettre la nouvelle chaine de caractère écrite en majuscule */
	char temp[SIZE] = { "", };
	for (i = 0; name[i] != '\0'; i++) {
		if (name[i] <= 'z' && name[i] >= 'a') {
			temp[i] = name[i] - 32;
		}
		else {
			temp[i] = name[i];
		}
	}
	strncpy(fiche->name, temp, SIZE);
}

char* getSurname(FICHE* fiche) {
	return fiche->surname;
}

void setSurname(FICHE* fiche, char* surname) {
	int i = 0;
	char temp[SIZE] = { "", };
	for (i = 0; surname[i] != '\0'; i++) {
		if (surname[i] <= 'z' && surname[i] >= 'a') {
			temp[i] = surname[i] - 32;
		}
		else {
			temp[i] = surname[i];
		}
	}
	strncpy(fiche->surname, temp, SIZE);

}

int getId(FICHE* fiche) {
	return fiche->id;
}

void setId(FICHE* fiche, int num) {
	fiche->id = num;
}

COURSE* getCourse(FICHE* fiche, int ind) {
	return &fiche->t_course[ind];
}

const char* getTitle(COURSE* t_course) {
	return t_course->title;
}

double getScore(COURSE* t_course) {
	return t_course->score;
}

void setCourse(FICHE* fiche, COURSE source, int n) {
	setTitle(&fiche->t_course[n], source.title);
	setScore(&fiche->t_course[n], source.score);
}

void setTitle(COURSE* course, const char* titre) {
	strncpy(course->title, titre, SIZE);
}

void setScore(COURSE* t_course, double note) {
	t_course->score = note;
}
COURSE courseFromInput() {
	COURSE t_course;
	printf("Entrez le nom du cours : ");
	fgets(t_course.title, SIZE, stdin);
	printf("Entrez la note du cours : ");
	scanf("%f", &t_course.score);

	return t_course;
}
FICHE ficheFromInput(void) { /*La focntion permet de rentrer des chaine de
	caractères et des valeurs pour ensuite afficher une fiche*/
	int i = 0;
	char ch[SIZE] = { "", };
	FICHE fiche = { "","",0,{{"",0.0},{"",0.0},{"",0.0}} };
	printf("Entrez un nom :");
	fgets(fiche.name, SIZE, stdin);
	printf("\nEntrez un surname :");
	fgets(fiche.surname, SIZE, stdin);
	printf("\nEntrez un numero etudiant :");
	scanf("%d", &fiche.id);
	for (i = 0; i < N_MATIERE; i++) {
		fiche.t_course[i] = courseFromInput(); /*La focntion permet de saisir la matiere*/
	}


	return fiche;
}