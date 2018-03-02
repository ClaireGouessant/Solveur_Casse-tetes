#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdlib.h>

typedef struct Contraintes Contraintes;
typedef struct Variable Variable;
typedef struct Pb Pb;

struct Contraintes
{
    int variable;//l'indice de la variable
    int type;//la catégorie de la contrainte
    int nbContr;//nb d entites dans chaque contraintes
    int* ListeContr;//Liste des contraintes//Selon la contrainte donne la liste des variables dependante de cette derniere
};

struct Variable
{
    int indice;//Le nom de la variable
    int nbValeurs;// Nb de valeurs prises par la variable
    int* Val; //Tableau contenant les valeurs de la variable
};

struct Pb
{
    int nbVar;//Nombre de variables
    int NbTotContr;//Nombre de regles ou contraintes differentes
    Contraintes* Cpb;//Tableau contenant la definition de chaque contrainte
    Variable* var;//Tableau contenant l'ensemble des variables et ses ensembles de definition
};

Pb* lecture(char* MonF);
Pb* copie(const Pb* precedentPb);
Pb* reduction(const Pb* precedentPb);
void affichage_solution(const Pb* MonPb);
void affichage(const Pb* MonPb);

#endif // STRUCTURE_H_INCLUDED
