#include <iostream>
#include "Structure.h"
#include <fstream>

using namespace std;
int DefnbCont(char* MonF)//Compte les lignes du fichier
{
    ifstream in(MonF);
    string ligne; //Création d'une chaine de caractere
    int nbLignes = 0;
    while(std::getline(in, ligne)) //On lit chaque ligne du fichier que l'on stoke dans "ligne"
    nbLignes++;
    //cout<<nbLignes; //Affichage Test nombres de ligne
    in.close(); //On ferme le fichier
    return nbLignes;
}

Pb* lecture(char* MonF)
{
    int nbLignes = 0;
    nbLignes = DefnbCont(MonF);
    ifstream lectureEnCours(MonF);//debut de lecture
    Pb* lePb = new Pb;
    lePb->nbVar = 0;
    lectureEnCours >> lePb->nbVar;//Lecture nb de variable
    lePb->NbTotContr = 0;
    lePb->Cpb = NULL;
    lePb->var = NULL;//boucle for
    lePb->var = new Variable[lePb->nbVar];//Creation du tableau contenant des cases de type variables
    //variables
    for(int i=0; i<lePb->nbVar; i++)
    {
        lePb->var[i].indice=0;
        lePb->var[i].nbValeurs=0;
        lePb->var[i].Val = NULL;
        lectureEnCours>>lePb->var[i].indice;//lecture du nom de la variable
        lectureEnCours>>lePb->var[i].nbValeurs;// lecture du nombre de valeurs prises
        lePb->var[i].Val = new int [lePb->var[i].nbValeurs];//Creation du tableau contenant les valeurs prise par une variable
        for(int j=0; j<lePb->var[i].nbValeurs; j++)
        {
            lePb->var[i].Val[j] = 0;
            lectureEnCours >> lePb->var[i].Val[j];//lecture des valeurs d une variable n
        }
    }
    //contraintes
    lePb->NbTotContr = nbLignes - lePb->nbVar - 1;//Permet de determiner le nombre de lignes contraintes
    lePb->Cpb = new Contraintes[lePb->NbTotContr];
    for(int k=0; k<lePb->NbTotContr; k++)
    {
        lectureEnCours>>lePb->Cpb[k].type;//type de la contrainte
        lectureEnCours>>lePb->Cpb[k].nbContr;//Nb d entites dans cette contrainte
        lePb->Cpb[k].nbContr--;
        lectureEnCours>>lePb->Cpb[k].variable;//indice de la variable contrainte ou valeur de contrainte
        lePb->Cpb[k].ListeContr = new int [lePb->Cpb[k].nbContr];
        for(int l= 0; l<lePb->Cpb[k].nbContr; l++)
        {
             lePb->Cpb[k].ListeContr[l] = 0;
             lectureEnCours>>lePb->Cpb[k].ListeContr[l];//Parcours de l'ensemble des contraintes
        }
    }
    return lePb;
}


