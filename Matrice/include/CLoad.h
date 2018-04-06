#ifndef C_LOAD_H
#define C_LOAD_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatList.h"
#include "CMatrix.h"

class CLoad
{
private:
	CMatList pLODMatList;

	CMatList cMatList;

public:
	void LODLoadFromFile(char pcFilename[]);

	CMatrix LODParser();

};
#endif
