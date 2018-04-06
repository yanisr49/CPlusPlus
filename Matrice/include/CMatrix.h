#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

template <class NType>
class CMatrix
{
private:
	NType ppMATMatrix[][];

	unsigned int uiMATRow;

	unsigned int uiMatCol;


public:
	void CMatrix(int iRow, int iCol, NType ppTab[][]);

	void CMatrix(CMatrix MATParam);

	void CMatrix(int iRow, int iCol);

	CMatrix operator+(CMatrix MATParam, double c);

	CMatrix operator-(CMatrix MATParam, double c);

	CMatrix operator/(double c);

	CMatrix operator+(CMatrix MATParam);

	CMatrix operator-(CMatrix MATParam);

	CMatrix operator*(CMatrix MATParam);

	void MATPrint();

	CMatrix MATTranspose();

};
#endif
