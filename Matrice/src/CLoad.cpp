#include <string>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include "CLoad.h"

void CLoad::LODLoadFromFile()
{
    string sData ("");
    CMatList<double> * lMatList = new CMatList<double>();
    list<string>::iterator it;

    for(it = sLODListFilename.begin(); it != sLODListFilename.end(); it++)
    {
        ifstream infile;
        infile.open((*it).c_str());
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
            for(unsigned int i=0; i<uiNbRow; i++)
            {
                for(unsigned int j=0; j<uiNbCol; j++)
                {
                    infile >> sData;
                    ppdMatrix[i][j] = atof(sData.c_str());
                }
            }

            CMatrix<double> * matrice = new CMatrix<double>(uiNbRow, uiNbCol, ppdMatrix);
            matrice->MATPrint();
            lMatList->MTLadd(*matrice);
        }else
            throw new CException(WRONG_TYPE);
    }
    lMatList->MTLProduct();
}


void CLoad::LODAddFilename(string sFilename){
    sLODListFilename.push_back(sFilename);
}

string CLoad::getFirst()
{
    return sLODListFilename.front();
}
