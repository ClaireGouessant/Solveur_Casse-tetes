#include <iostream>
#include "Structure.h"

Pb* copie(const Pb* precedentPb)
{
    Pb* probleme = new Pb;
    probleme->nbVar = precedentPb->nbVar;
    probleme->NbTotContr = precedentPb->NbTotContr;
    probleme->Cpb = NULL;
    probleme->Cpb = new Contraintes[probleme->NbTotContr];
    probleme->var = NULL;
    probleme->var = new Variable[precedentPb->nbVar];

    //recopier les contraintes
    for(int i=0; i<probleme->NbTotContr; i++)
    {
        probleme->Cpb[i].variable = precedentPb->Cpb[i].variable;
        probleme->Cpb[i].type = precedentPb->Cpb[i].type;
        probleme->Cpb[i].nbContr = precedentPb->Cpb[i].nbContr;
        probleme->Cpb[i].ListeContr = new int [probleme->Cpb[i].nbContr];
        for(int j=0; j<probleme->Cpb[i].nbContr; j++)
        {
            probleme->Cpb[i].ListeContr[j] = precedentPb->Cpb[i].ListeContr[j];
        }
    }

    //recopier les variables
    for(int i=0; i<probleme->nbVar; i++)
    {
        probleme->var[i].indice = precedentPb->var[i].indice;
        probleme->var[i].nbValeurs = precedentPb->var[i].nbValeurs;
        probleme->var[i].Val = new int [probleme->var[i].nbValeurs];
        for(int j=0; j<probleme->var[i].nbValeurs; j++)
        {
            probleme->var[i].Val[j] = precedentPb->var[i].Val[j];
        }
    }
    return probleme;
}

//trouver une variable acceptant plusieurs valeurs
int determine(const Pb* probleme)
{
    for(int i=0; i < probleme->nbVar; i++)
    {
        if(probleme->var[i].nbValeurs > 1)
            return i;
    }
    return -1;//toutes les variables ont une et une seule valeur
}

//retourne le nombre de valeurs possibles pour une variable
int indetermine(const Pb* probleme, int indice)
{
    for(int i=0; i < probleme->nbVar; i++)
    {
        if(probleme->var[i].indice == indice)
            return probleme->var[i].nbValeurs;
    }
    return 0;
}

//attribuer une et une seule valeur à une variable
Variable fixer(const Variable ancienne)
{
    Variable nouvelle;
    nouvelle.indice = ancienne.indice;
    nouvelle.nbValeurs = 1;
    nouvelle.Val = new int [1];
    nouvelle.Val[0] = ancienne.Val[0];
    return nouvelle;
}

bool verification(int index, const Pb* probleme)
{
    for(int i=0; i < probleme->NbTotContr; i++)
    {
        switch(probleme->Cpb[i].type)//ajouter les cas des variables dans la liste de contraintes ex:4 = addition
        {
        case 1://égalité
            if(probleme->Cpb[i].variable == probleme->var[index].indice)//la valeur est elle contrainte par une autre ?
            {
                for(int j=0; j < probleme->Cpb[i].nbContr; j++)
                {
                    if(probleme->var[probleme->Cpb[i].ListeContr[j]-1].nbValeurs == 1)//la variable a t elle été assignée ?
                    {
                        if(probleme->var[probleme->Cpb[i].ListeContr[j]-1].Val[0] != probleme->var[probleme->Cpb[i].variable-1].Val[0])
                            return false;
                    }
                }
            }
            else
            {
                for(int j=0; j < probleme->Cpb[i].nbContr; j++)//la valeur contraint elle une autre variable ?
                {
                    if(probleme->Cpb[i].ListeContr[j] == probleme->var[index].indice)//fait partie d'une contrainte
                    {
                        if(probleme->var[probleme->Cpb[i].variable-1].nbValeurs == 1)//la variable a t elle été assignée ?
                        {
                            if(probleme->var[probleme->Cpb[i].variable-1].Val[0] != probleme->var[index].Val[0])
                                return false;
                        }
                    }
                }
            }
            break;
        case 2://difference
            if(probleme->Cpb[i].variable == probleme->var[index].indice)//la valeur est elle contrainte par une autre ?
            {
                for(int j=0; j < probleme->Cpb[i].nbContr; j++)
                {
                    if(probleme->var[probleme->Cpb[i].ListeContr[j]-1].nbValeurs == 1)//verifie les conditions que si la variablea une valeur fixée
                    {
                        if(probleme->var[probleme->Cpb[i].ListeContr[j]-1].Val[0] == probleme->var[probleme->Cpb[i].variable-1].Val[0])
                            return false;
                    }
                }
            }
            else
            {
                for(int j=0; j < probleme->Cpb[i].nbContr; j++)//la valeur contraint elle une autre variable ?
                {
                    if(probleme->Cpb[i].ListeContr[j] == probleme->var[index].indice)//fait partie d'une contrainte
                    {
                        if(probleme->var[probleme->Cpb[i].variable-1].nbValeurs == 1)//la variable a t elle été assignée ?
                        {
                            if(probleme->var[probleme->Cpb[i].variable-1].Val[0] == probleme->var[index].Val[0])
                                return false;
                        }
                    }
                }
            }
            break;
        case 3://inférieur
            if(probleme->Cpb[i].variable == probleme->var[index].indice)//la valeur est elle contrainte par une autre ?
            {
                for(int j=0; j < probleme->Cpb[i].nbContr; j++)
                {
                    if(probleme->var[probleme->Cpb[i].ListeContr[j]-1].nbValeurs == 1)
                    {
                        if(probleme->var[probleme->Cpb[i].ListeContr[j]-1].Val[0] > probleme->var[probleme->Cpb[i].variable-1].Val[0])
                            return false;
                    }
                }
            }
            else
            {
                for(int j=0; j < probleme->Cpb[i].nbContr; j++)//la valeur contraint elle une autre variable ?
                {
                    if(probleme->Cpb[i].ListeContr[j] == probleme->var[index].indice)//fait partie d'une contrainte
                    {
                        if(probleme->var[probleme->Cpb[i].variable-1].nbValeurs == 1)//la variable a t elle été assignée ?
                        {
                            if(probleme->var[probleme->Cpb[i].variable-1].Val[0] < probleme->var[index].Val[0])
                                return false;
                        }
                    }
                }
            }
            break;
        case 4://addition
            if(probleme->Cpb[i].variable == probleme->var[index].indice)//la valeur est contrainte par une autre
            {
                int somme = 0;
                for(int j=0; j < probleme->Cpb[i].nbContr; j++)
                {
                    if(probleme->var[probleme->Cpb[i].ListeContr[j]-1].nbValeurs == 1)
                    {
                        somme += probleme->var[probleme->Cpb[i].ListeContr[j]-1].Val[0];
                    }
                    else
                    {
                        j = probleme->Cpb[i].nbContr;
                        somme = probleme->var[probleme->Cpb[i].variable-1].Val[0];
                    }
                }
                if(somme != probleme->var[probleme->Cpb[i].variable-1].Val[0]) return false;

            }
            else
            {
                for(int j=0; j < probleme->Cpb[i].nbContr; j++)//la valeur en contraint elle une autre par une somme ?
                {
                    if(probleme->Cpb[i].ListeContr[j] == probleme->var[index].indice)//fait partie de la somme
                    {
                        int somme = 0;
                        for(int k=0; k < probleme->Cpb[i].nbContr; k++)
                        {

                            if(probleme->var[probleme->Cpb[i].ListeContr[k]-1].nbValeurs == 1)
                            {
                                somme += probleme->var[probleme->Cpb[i].ListeContr[k]-1].Val[0];
                            }
                            else
                            {
                                k = probleme->Cpb[i].nbContr;
                                somme = probleme->var[probleme->Cpb[i].variable-1].Val[0];
                            }
                        }
                        if(probleme->var[probleme->Cpb[i].variable-1].nbValeurs == 1)
                        {if(somme != probleme->var[probleme->Cpb[i].variable-1].Val[0]) return false;}
                        else somme = probleme->var[probleme->Cpb[i].variable-1].Val[0];
                    }
                }
            }
        }
    }
    return true;
}

Variable defiler(const Variable ancienne)
{
    Variable nouvelle;
    nouvelle.indice = ancienne.indice;
    nouvelle.nbValeurs = ancienne.nbValeurs - 1;
    nouvelle.Val = new int [nouvelle.nbValeurs];
    for(int j=1; j<ancienne.nbValeurs; j++)
    {
        nouvelle.Val[j-1] = ancienne.Val[j];
    }
    return nouvelle;
}

Pb* reduction(const Pb* precedentPb)
{
    //créer une copie de precedentPb
    Pb* probleme;
    probleme = copie(precedentPb);

    //Si existe variable indeterminé
    int index = determine(probleme);
    if(index != -1)
    {
        Variable variableAFixer = probleme->var[index];//valeurs originales

        //Tant que la variable a différentes valeurs
        while(variableAFixer.nbValeurs > 0)
        {
            //la variable prend la 1e valeur possible
            probleme->var[index] = fixer(variableAFixer);

            //Si verification(variable, Pb) OK alors reduire Pb
            if(verification(index, probleme))
            {
                Pb* nouveauPb = reduction(probleme);
                if(nouveauPb != NULL) return nouveauPb;//Si reduction(Pb) OK alors retourner Pb
            }
            //Dans les deux autres cas supprimer la valeur du Pb
            variableAFixer = defiler(variableAFixer);
        }//Recommencer avec une autre valeur

        //S'il n'y a plus de valeur retourner null
        return NULL;
    }
    //retourner Pb résolu
    return probleme;
}
