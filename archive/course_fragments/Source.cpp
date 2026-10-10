/* Header ( SINACER tedj el moulk , 23/01/2024 , instrumentation1, tp1) */

// bibliotheuqe pour utiliser les diff fnct
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SIZE 10 // la taille maximale des vecteurs

void printVector(double v[]); // answer to question 1

double dot(double v1[], double v2[]); // answer to question 2

void copyVector(double dest[], double src[]); //answerto,question 3


/* additional functions here */
double val_moyenne(double v[]); //pour calculer la valeur moyenne
double dev_standrad(double v[]); // pour calculer la deviation standard
double valeur_minimale(double v[]); //pour calculer la valeur minimale 
double valeur_maximale(double v[]); // pour calculer la valeur maximale 
double medianne(double v[]);  //pour trouver la valeur de la medianne
double initialiser(double v[]); //pour initialiser le vecteur  
int compare(const void* x_void, const void* y_void); //pour trier le vect


int main(void)
{
   //exo1
    double tab1[SIZE] = { 1 , 2 , 3 , 2 , 5 , 9.5 , 63 , 8, 5 , 0};
    printVector(tab1);
  

    //exo2
    double tab2[SIZE] = { 1 , 2 , 3 , 2 , 5 , 9.5 , 63 , 2, 5.5 , 8 };

    printf("le produit scalaire des deux vecteurs est %f \n" , dot(tab1, tab2));

    double tab3[SIZE] = { 8.2 , 7.6 , 5 , 6 , 3, 9, 3, 1, 2, 4.7 };
      
    //exo3 
    double coller[SIZE] ; // vect sans elements initialiser
    copyVector(coller, tab1); // pour recopier les elements du vecteur 
    printVector(coller); // pour afficher le vecteur cree

    //exo 4
    printf("%f\n ", val_moyenne(tab1));
    printf("la deviation standard du vecteur est %f \n ",dev_standrad(tab1));
    printf("la valeur minimale est %f et la valeur maximale est %f \n ", valeur_minimale(tab1), valeur_maximale(tab1));
    printf("la valeur de la medianne du vecteur est %f\n ", medianne(tab1));
    
    //exo 5    
    double qoqo[SIZE];
    initialiser(qoqo); //pour donner des elements au vecteur
    printVector(qoqo);//pour afficher le vect 


    return 0;
}

void printVector(double v[]) //fontcion pour afficher les elements d'un vecteur 
{
    int i; 

    for (i = 0 ; i < SIZE; i++)
    {
        printf("%f ", v[i]);
    }
}
 
double dot(double v1[], double v2[]) // fontcion pour calculere le produit vectorielle 
{

    int i;

    double produit_sclaire = 0; //le produit scalaire des vecteurs

    double somme=0 ; // somme de chaque elements de,la meme mlignes des deux vecteur

    for (i = 0 ; i < SIZE ; i++)
    {
        somme = v1[i] + v2[i]; 
        produit_sclaire = produit_sclaire + somme;
    }
    return produit_sclaire ;

       
}


void copyVector(double dest[], double src[])
{
    int i;
    for (i = 0; i < SIZE; i++)
        dest[i] = src[i];

}


double val_moyenne(double v[]) // fonction qui calcule la valeur moyenne 
{
    int i;
    double somme=0;
    double valeur_moyenne;
    for (i = 0 ; i < SIZE ; i++)
    {
        somme = somme + v[i];
   }
    valeur_moyenne = somme / SIZE ;
    return valeur_moyenne;
}

double dev_standrad(double v[]) //fontcion qui calcul la deviation standrad 
{
    int i;
    double somme_quadr = 0;
    double ecart_type;
    for (i = 0; i < SIZE; i++)
    {
        somme_quadr = somme_quadr + v[i] * v[i];
        ecart_type = sqrt(somme_quadr / SIZE);

    }
    return ecart_type;
}
 
double valeur_minimale(double v[]) //valeur min
{
    int i;
    double min = v[0];
    for (i = 0; i < SIZE; i++)
    {
        if (v[i] < min)
            min = v[i];
    }
    return min;
}
double valeur_maximale(double v[]) // valeur max
{
    int i;
    double max = v[0];
    for (i = 0 ; i < SIZE; i++)
    {
        if (v[i] > max)
            max = v[i];
    }
    return max;
}

int compare(const void* x_void, const void* y_void) //pour trier le tableau dans l''ordre croissant
{
    double x = *(double*)x_void; // to convert the type so it vcan compare anywhere( a pointer to an int ) and thenb derefrence the pointereb
    double y = *(double*)y_void;

    return x - y;
    //valeur negative = x avant y
    //valeur positive= x apres y
    // valeur nulle x et y sont equiv

}
double medianne(double v[]) // pour avoir la medianne 
{
    int i;
    double valeur_medianne;
    qsort(v, SIZE, sizeof(double), compare);

    if (SIZE % 2 == 0)  // si la valeur est pair 
    {
        i = SIZE / 2;
        valeur_medianne = (v[i-1] + v[i]) / 2;
    }

    else if (SIZE % 2 != 0) //si la valeur eszt impair 
    {
        i = (SIZE + 1) / 2;
        valeur_medianne = v[i-1];
    }
    return valeur_medianne;
}

double initialiser(double v[]) //pour initialiser un vecteur 
{

    int i;
    double interval;
    for (i = 0; i < SIZE; i++)
    {
        interval = (rand() /(double) RAND_MAX) * 2 - 1 ; //pour convertir le randmac en double car cest une variable
        v[i] = interval;
    }
    return v[SIZE];
} 