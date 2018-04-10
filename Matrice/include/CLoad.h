#ifndef C_LOAD_H
#define C_LOAD_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatList.h"

class CLoad
{
private :
    char ** pcLODListFilename = 0;
    int iLODListLength = 0;

public:
    CLoad();

    void LODLoadFromFile();
    void LODAddFilename(char * pcFilename);
};

/* Declaration des methodes */
CLoad::CLoad()
{
    pcLODListFilename = (char **) malloc(0);
    pcLODListFilename[0] = (char *) malloc(0);
}

void CLoad::LODLoadFromFile()
{
    char cData[100];
    char * cType = (char *) malloc(0);
    int iLength = 0;
    ifstream infile;
    infile.open(pcLODListFilename[0]);
    infile >> cData;
    while(cData[iLength] != '=')
        iLength++;
    for(int i=0; cData[iLength] != '\0'; i++)
    {
        iLength++;
        cType = (char *) realloc(cType, (i+1) * sizeof(char));
        cType[i] = cData[iLength];
    }
    cout << "Type : " << cType << endl;

}


void CLoad::LODAddFilename(char * pcFilename)
{
    iLODListLength++;

    // On trouve la taille du nom du fichier
    int iLength = 0;
    while(pcFilename[iLength] != '\0')
        iLength++;

    // Allocation du tableau des noms de fichiers
    pcLODListFilename = (char **) realloc(pcLODListFilename, iLODListLength * sizeof(char *));
    pcLODListFilename[iLODListLength-1] = (char *) malloc((iLength+1) * sizeof(char));

    for(int i=0; i<iLength; i++)
        pcLODListFilename[iLODListLength-1][i] = pcFilename[i];
    pcLODListFilename[iLODListLength-1][iLength] = '\0';
}
#endif
