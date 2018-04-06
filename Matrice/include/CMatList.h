#ifndef C_MAT_LIST_H
#define C_MAT_LIST_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrix.h"

class CMatList
{
private:
	CMatrix pMTLList[];

	unsigned int uiMTLLength;

	CMatrix cMatrix[];

public:
	void MTLadd(CMatrix MATParam);

	void MTLMultByConst(double C);

	void MTLDivByConst(double C);

	void MTLSum();

	void MTLAltPlusMinus();

	void MTLProduct();

};
#endif
