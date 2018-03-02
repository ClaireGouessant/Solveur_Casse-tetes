#include <iostream>
#include "Structure.h"

using namespace std;

int main()
{
    int choix=0;
    system("cls");
    char MonF[] = "pb1.txt";//problème par défaut
    Pb* Monpb;
    cout<<"---- Projet d'Aide a la Decision ----"<<endl;
    cout<<"---------- Solveur PSC --------------\n\n"<<endl;
    cout<<" Veuillez choisir le pb a resoudre: \n"<<endl;
    cout<<" 1. Le Sudoku\n 2. Les 4 dames\n 3. Le Coloriage de carte avec 3 couleurs\n 4. Le Coloriage de carte avec 4 couleurs\n"<<endl;
    do{
        cout<< "\nVotre choix: ";
        cin>>choix;
    }while(choix<1 || choix>4);
    switch(choix)
    {
    case 1:
        MonF[2] = '1';
        break;
    case 2:
        MonF[2] = '2';
        break;
    case 3:
        MonF[2] = '3';
        break;
    case 4:
        MonF[2] = '4';
        break;
    default:
        return 0;
    }
    Monpb= lecture(MonF);
    affichage(Monpb);
    cout<<endl<<"Reduction en cours"<<endl<<endl;
    affichage_solution(reduction(Monpb));


    cout<<"\n\nProgramme developpe par Marc Gayraud et Claire Gouessant"<<endl;
    return 0;
}
