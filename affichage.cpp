#include <iostream>
#include "Structure.h"

using namespace std;

void affichage_solution(const Pb* MonPb)
{
    if(MonPb == NULL)
    {
        cout<<"Pas de solution trouvee."<<endl;
        return;
    }

    cout<<"\n \n====== SOLUTION =======\n"<<endl;
    cout<<"Nombre de Variables: "<< MonPb->nbVar<<endl;
    for (int i=0; i<MonPb->nbVar; i++)
    {
        cout<<"- Variable x"<<MonPb->var[i].indice<<" prend la valeur: "<<MonPb->var[i].Val[0]<<endl;
    }
    cout<<endl;
}

void affichage(const Pb* MonPb)
{
    cout<<"\n \n====== PROBLEME =======\n"<<endl;
    cout<<"Nombre de Variables: "<< MonPb->nbVar<<endl;
    for (int i=0; i<MonPb->nbVar; i++)
    {
        cout<<"- Variable x"<<MonPb->var[i].indice<<" peut prendre "<<MonPb->var[i].nbValeurs<< " valeur(s): ";
        for(int j =0; j<MonPb->var[i].nbValeurs;j++)
        {
            cout<<MonPb->var[i].Val[j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"----- Les contraintes -----\n"<<endl;
    cout<<"Il existe "<< MonPb->NbTotContr<<" contrainte(s): "<<endl;
    for (int i=0; i<MonPb->NbTotContr; i++)
    {
        switch (MonPb->Cpb[i].type)
        {
        case 1:
            cout<<"- Variables egales: "<<endl;
            cout<<"x"<<MonPb->Cpb[i].variable<<" =";
            for(int j=0;j<MonPb->Cpb[i].nbContr; j++)
            {
                cout<<" x"<<MonPb->Cpb[i].ListeContr[j];
            }
            break;
        case 2:
            cout<<"- Variables differentes: "<<endl;
            cout<<"x"<<MonPb->Cpb[i].variable<<" <>";
            for(int j=0;j<MonPb->Cpb[i].nbContr; j++)
            {
                cout<<" x"<<MonPb->Cpb[i].ListeContr[j];
            }
            break;
        case 3:
            cout<<"- Variable inferieure ou egale a une autre: "<<endl;
            cout<<"x"<<MonPb->Cpb[i].variable<<" <=";
            for(int j=0;j<MonPb->Cpb[i].nbContr; j++)
            {
                cout<<" x"<<MonPb->Cpb[i].ListeContr[j];
            }
            break;
        case 4:
            cout<<"- Somme de variable egales a une valeur determinee: "<<endl;
            cout<<"x"<<MonPb->Cpb[i].variable<<" =";
            for(int j=1;j<MonPb->Cpb[i].nbContr; j++)
            {
                cout<<" x"<<MonPb->Cpb[i].ListeContr[j];
            }
            break;

        default: cout<<endl<<"Erreur de description"<<endl;
            break;
        }
        cout<<endl<<endl;
    }
}
