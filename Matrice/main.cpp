#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <CMatList.h>
#include <CLoad.h>
#include <string>

using namespace std;

int main()
{
    /* Cr�ation de l'instance qui effectura les differents calcul */
    CLoad * pLODList;
    try {
        pLODList = new CLoad();
    }catch(CException* EXCErreur){
        EXCErreur->EXCAfficheErreur();
    }


    /* On demande � l'utilisateur le noms des differents fichier */
    string sFileName;
    cout << "Entrer \"quitter\" pour voir les resultats des matrices entrees" << endl;
    do {
        cout << "Nom du fichier : " << endl;
        cin >> sFileName;
        if(sFileName.compare("quitter"))
            pLODList->LODAddFilename(sFileName);
    }while(sFileName.compare("quitter"));

    /* On demande � l'utilisateur la saisie d'une valeur quelconque */
    double dConstante;
    cout << "Entrer une valeur quelconque" << endl;
    cin >> dConstante;

    /* On r�cup�re toutes les matrices a partir des fichiers donn�s */
    try{
        CMatList<double> * pMTLList = pLODList->LODLoadFromFile<double>();

        cout << "Mulitplication par constantes :" << endl;
        pMTLList->MTLMultByConst(dConstante);
        cout << "Division par constantes :" << endl;
        pMTLList->MTLDivByConst(dConstante);
        cout << "Somme :" << endl;
        pMTLList->MTLSum();
        cout << "+ - + - + - + - :" << endl;
        pMTLList->MTLAltPlusMinus();
        cout << "Produit :" << endl;
        pMTLList->MTLProduct();

        delete pLODList;
        delete pMTLList;
    }catch(CException* EXCErreur){
        EXCErreur->EXCAfficheErreur();
    }

    /* On affiche les r�sultats voulu */
    //pLOAList->

    /*  */
    system("pause");
    return 0;
}
