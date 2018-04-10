#ifndef C_LOAD_H
#define C_LOAD_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatList.h"

template <class NType>
class CLoad
{
private:
    char ** pcLODFilename;

public:
	CMatList<NType> LODLoadFromFile();
    void addFilename(char * pcFilename);
};
#endif
