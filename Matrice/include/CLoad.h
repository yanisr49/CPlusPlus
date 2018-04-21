#ifndef C_LOAD_H
#define C_LOAD_H

#include <string>
#include <iostream>
#include <assert.h>
#include <fstream>
#include <list>

#include "CMatrix.h"
#include "CMatList.h"

using namespace std;

/**
    *\brief Parse les fichiers pass�s en param�tres et cr�� une instance de la classe CMatList
*/
class CLoad
{
private :
    vector<string> sLODListFilename;

public:
    /**
    * \brief lit les fichiers pass�es en param�tres et cr�er les instances CMatrix associ�es
    *E: N�ant
    *N�cessite : Rien
    *S:
    * \return CMatList<NType> : instance contenant toutes les matrices
    *Entraine : (les matrices contenues dans les fichiers sont cr�es)
    */
    template <class NType>
    CMatList<NType> * LODLoadFromFile();

    /**
    *\brief ajout le nom d'un fichier a la classe
    *
    *E:
    *\param sFilename string : nom du fichier a ajouter
    *N�cessite : Rien
    *S : N�ant
    *Entraine : (Le nom du fichier est ajout� � la classe)
    */
    void LODAddFilename(string sFilename);
};

/**
* \brief lit les fichiers pass�es en param�tres et cr�er les instances CMatrix associ�es
*E: N�ant
*N�cessite : Rien
*S:
* \return CMatList<NType> : instance contenant toutes les matrices
*Entraine : (les matrices contenues dans les fichiers sont cr�es) OU (CException : WRONG_TYPE, le fichier contient des matrices
* qui ne sont pas de type double)
*/
template <class NType>
CMatList<NType> * CLoad::LODLoadFromFile()
{
    string sData ("");
    CMatList<double> * lMatList = new CMatList<double>();

    for(unsigned int uiCompteur=0; uiCompteur < sLODListFilename.size(); uiCompteur++)
    {
        ifstream infile;
        infile.open((sLODListFilename.at(uiCompteur)).c_str());
        infile >> sData;

        if(sData.compare(12,100,"double") == 0)
        {
            infile >> sData;
            unsigned int uiNbRow = atoi(sData.substr(9,100).c_str());
            infile >> sData;
            unsigned int uiNbCol = atoi(sData.substr(11,100).c_str());

            infile >> sData;

            /* Initialisation du tableau des valeurs de la matrice */
            double ** ppdMatrix = (double **) malloc(uiNbRow * sizeof(double *));
            for(unsigned int i=0; i<uiNbRow; i++)
                ppdMatrix[i] = (double *) malloc(uiNbCol * sizeof(double));

            /* On rempli le tableau des valeurs */
            for(unsigned int uiRow=0; uiRow<uiNbRow; uiRow++)
            {
                for(unsigned int uiCol=0; uiCol<uiNbCol; uiCol++)
                {
                    infile >> sData;
                    ppdMatrix[uiRow][uiCol] = atof(sData.c_str());
                }
            }

            CMatrix<double> * matrice = new CMatrix<double>(uiNbRow, uiNbCol, ppdMatrix);
            cout << "Matrice : " << endl;
            matrice->MATPrint();
            cout << endl;
            lMatList->MTLadd(*matrice);
            delete matrice;
        }else
            throw new CException(WRONG_TYPE);
    }

    return lMatList;
}
#endif
