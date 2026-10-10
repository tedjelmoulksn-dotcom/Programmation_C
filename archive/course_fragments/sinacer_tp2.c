/* SINACER TEDJ EL MOULK - 26/01/2024 - TP2 */

#define _CRT_SECURE_NO_WARNINGS //pour les warnings
#define TAILLE 80

//les bib
#include <time.h>       /* for time() */
#include <stdlib.h>     /* pour srand() et rand()*/
#include<stdio.h>
#include <string.h> 



typedef char MOT[TAILLE]; // alias pour les char 





struct _COURSE    //structure contenant la matoere et la note  
{
	MOT title ;
	double score;

};
typedef struct _COURSE COURSE;

struct _FICHE   //structure contenant les info de letudiant 
{
	MOT name;
	MOT surname;
	int id;
	COURSE matiere[3];
};


typedef struct _FICHE FICHE ;//alias fiche

// mes fonctions
void printFiche(FICHE fiche); //affichage de la strct
void saveFiche(FILE* file, FICHE fiche); 
void loadFiche(FICHE* fiche, char* str);




//fontcion princ
int main()

{
	//exo1
	FICHE personne = { "Doe"," John " ,11300055 ,
{{" Maths " ,12.0} ,{" Info " ,8.5} ,{" Physics " ,10.0}} };

printFiche(personne);
    
   /*exo2*/

saveFiche(stdout, personne);

   /*exo3*/

  FILE* file_1 = fopen("database.csv", "w"); /*pour ouvrir le fichier*/
  saveFiche(file_1, personne);
  fclose(file_1);                             /*pour fermer le fichier */




/*exo4*/

FICHE file_2;
char phrase[TAILLE]  = "Doe; John; 11300055; Maths; 12.0; Info; 8.5; Physics; 10.0 ";
loadFiche(&file_2, phrase);
printFiche(file_2);



  /*exo5*/ 
  FICHE file_3, *lecture;
  FICHE * file_4 = fopen("database.csv", "r");
  while ((lecture=fgets(&file_3 ,TAILLE , file_4)) != NULL ) /* pour mlire la premiere ligne de du fichier */
  {
       loadFiche(&file_3, lecture); /*recpier la ligne dans file_3*/
  }
  
 printFiche(file_3); /*affichage*/
 
fclose(file_4);



	return 0;
}







void printFiche(FICHE fiche)
{
	printf("name:%s;surname:%s;id:%d;%s:%f;%s:%f;%s:%f\n", fiche.name, fiche.surname, fiche.id, fiche.matiere[0].title, fiche.matiere[0].score, fiche.matiere[1].title, fiche.matiere[1].score , fiche.matiere[2].title, fiche.matiere[2].score);
	
}



void saveFiche(FILE* file, FICHE fiche)
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


void loadFiche(FICHE* fiche, char* str)
{

	int i = 0;
	char* ptr;
	ptr = strtok(str, ";");

	while (ptr != NULL)
	{
		strcpy(fiche->name,ptr);
		ptr = strtok(NULL, ";");
		strcpy(fiche->surname,ptr);
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

	/*const char* delimiteur = ";" ;

	fiche= strtok(str, delimiteur);
	while (fiche != NULL)
	{
		printf("%s", fiche);
	}*/