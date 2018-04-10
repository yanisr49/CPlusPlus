#ifndef C_MAT_LIST_H
#define C_MAT_LIST_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrix.h"

template <typename NType>
class CMatList
{
private:
	CMatrix<NType> pMTLList[];

	unsigned int uiMTLLength;

public:
	void MTLadd(CMatrix<NType> MATParam);

	void MTLMultByConst(double C);

	void MTLDivByConst(double C);

	void MTLSum();

	void MTLAltPlusMinus();

	void MTLProduct();

};
#endif
