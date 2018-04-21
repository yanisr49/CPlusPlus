#include <string>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include "CLoad.h"

/**
    *\brief ajout le nom d'un fichier a la classe
    *
    *E:
    *\param sFilename string : nom du fichier a ajouter
    *N�cessite : Rien
    *S : N�ant
    *Entraine : (Le nom du fichier est ajout� � la classe)
    */
void CLoad::LODAddFilename(string sFilename){
    sLODListFilename.push_back(sFilename);
}
