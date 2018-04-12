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
    std::list<string> sLODListFilename;

public:
    void LODLoadFromFile();
    void LODAddFilename(string sFilename);
    string getFirst();
};
#endif
