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

class CLoad
{
private :
    vector<string> sLODListFilename;

public:
    template <class NType>
    CMatList<NType> * LODLoadFromFile();
    void LODAddFilename(string sFilename);
};

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
        }else
            throw new CException(WRONG_TYPE);
    }

    return lMatList;
}
#endif
