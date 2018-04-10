#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "CException.h"

using namespace std;

template <class NType>
class CMatrix
{
private:

	unsigned int uiMATRow;

	unsigned int uiMATCol;

    NType **ppMATMatrix;

public:
    CMatrix(unsigned int uiRow, unsigned int uiCol, NType **ppTab);

	CMatrix(const CMatrix & MATParam);

	CMatrix(unsigned int uiRow, unsigned int uiCol);

	CMatrix& operator*(double c);


	CMatrix operator/(double c);

	CMatrix operator+(CMatrix MATParam);

	CMatrix operator-(CMatrix MATParam);

	CMatrix operator*(CMatrix MATParam);

	void MATPrint();

	CMatrix MATTranspose();

};

//Definition des méthodes

template <class NType>
CMatrix<NType>::CMatrix(unsigned int uiRow, unsigned int uiCol, NType **ppTab)
{
	uiMATRow = uiRow;
	uiMATCol = uiCol;
	ppMATMatrix = ppTab;
}

template <class NType>
 CMatrix<NType>::CMatrix(const CMatrix & MATParam)
{

}

 template <class NType>
 CMatrix<NType>::CMatrix(unsigned int uiRow, unsigned int uiCol)
{
	 uiMATRow = uiRow;
	 uiMATCol = uiCol;
	 NType ppTab[uiRow][uiCol];
	 for (unsigned int uiLoop = 0; uiLoop < uiRow; uiLoop++)
	 {
		 for (unsigned int uiLoop2 = 0; uiLoop2 < uiCol; uiLoop2++)
		 {
			 ppTab[uiLoop][uiLoop2] = 0;
		 }
	 }
	 ppMATMatrix = ppTab;

}

 template <class NType>
CMatrix<NType>& CMatrix<NType>::operator*(double c)
{
	NType **ppTab = ppMATMatrix;
	for (unsigned int uiLoop = 0; uiLoop < uiMATRow; uiLoop++)
	{
		for (unsigned int uiLoop2 = 0; uiLoop2 < uiMATCol; uiLoop2++)
		{
			ppTab[uiLoop][uiLoop2] *= c;
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);
}

template <class NType>
CMatrix<NType> operator*(double c, CMatrix<NType> MATParam)
{
	NType **ppTab = MATParam.ppMATMatrix;
	for (unsigned int uiLoop = 0; uiLoop < MATParam.uiMATRow; uiLoop++)
	{
		for (unsigned int uiLoop2 = 0; uiLoop2 < MATParam.uiMATCol; uiLoop2++)
		{
			ppTab[uiLoop][uiLoop2] *= c;
		}
	}

	return new CMatrix<NType>(MATParam.uiMATRow,MATParam.uiMATCol,ppTab);
}

template <class NType>
CMatrix<NType> CMatrix<NType>::operator/(double c)
{
    if(c == 0)
    {
        throw new CException(DIV_PAR_0);;
    }

	NType **ppTab = ppMATMatrix;
	for (unsigned int uiLoop = 0; uiLoop < uiMATRow; uiLoop++)
	{
		for (unsigned int uiLoop2 = 0; uiLoop2 < uiMATCol; uiLoop2++)
		{
			ppTab[uiLoop][uiLoop2] /= c;
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);
}

template <class NType>
CMatrix<NType> CMatrix<NType>::operator+(CMatrix MATParam)
{
    if(uiMATCol != MATParam.uiMATCol || uiMATRow != MATParam.uiMATRow)
        throw new CException(BAD_SIZE_OF_MAT);

    NType **ppTab = ppMATMatrix;
	for (unsigned int uiLoop = 0; uiLoop < uiMATRow; uiLoop++)
	{
		for (unsigned int uiLoop2 = 0; uiLoop2 < uiMATCol; uiLoop2++)
		{
			ppTab[uiLoop][uiLoop2] += MATParam.ppMATMatrix[uiLoop][uiLoop2];
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);

}




/** \brief
 *Peut-être problème si NType = unsigned int et que l'on soustrait le + petit par le plus grand
 * \param
 * \param
 * \return
 *
 */
template <class NType>
CMatrix<NType> CMatrix<NType>::operator-(CMatrix MATParam)
{
	 if(uiMATCol != MATParam.uiMATCol || uiMATRow != MATParam.uiMATRow)
        throw new CException(BAD_SIZE_OF_MAT);

    NType **ppTab = ppMATMatrix;
	for (unsigned int uiLoop = 0; uiLoop < uiMATRow; uiLoop++)
	{
		for (unsigned int uiLoop2 = 0; uiLoop2 < uiMATCol; uiLoop2++)
		{
			ppTab[uiLoop][uiLoop2] -= MATParam.ppMATMatrix[uiLoop][uiLoop2];
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);
}

template <class NType>
CMatrix<NType> CMatrix<NType>::operator*(CMatrix MATParam)
{
	return 0;
}

template <class NType>
void CMatrix<NType>::MATPrint()
{
}

template <class NType>
CMatrix<NType> CMatrix<NType>::MATTranspose()
{
	return 0;
}








#endif
