#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrix.h"


template<class NType> void CMatrix<NType>(int iRow, int iCol, NType ppTab[][])
{
	ppMATMatrix = ppTab;
	uiMATRow = iRow;
	uiMATCol = iCol;
}
template<class NType> void CMatrix<NType>(CMatrix & MATParam)
{
	ppMATMatrix = new NType(MATParam.ppMATMatrix);
	uiMATRow = MATParam.uiMATRow;
	uiMATCol = MATParam.uiMATCol;

}

void CMatrix::CMatrix(int iRow, int iCol)
{
}

CMatrix CMatrix::operator+(CMatrix MATParam, double c)
{
	return 0;
}

CMatrix CMatrix::operator-(CMatrix MATParam, double c)
{
	return 0;
}

CMatrix CMatrix::operator/(double c)
{
	return 0;
}

CMatrix CMatrix::operator+(CMatrix MATParam)
{
	return 0;
}

CMatrix CMatrix::operator-(CMatrix MATParam)
{
	return 0;
}

CMatrix CMatrix::operator*(CMatrix MATParam)
{
	return 0;
}

void CMatrix::MATPrint()
{
}

CMatrix CMatrix::MATTranspose()
{
	return 0;
}
