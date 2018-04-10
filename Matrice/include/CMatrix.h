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

    void operator=(CMatrix MATParam);

	CMatrix& operator*(double dc);


	CMatrix operator/(double dc);

	CMatrix operator+(CMatrix MATParam);

	CMatrix operator-(CMatrix MATParam);

	CMatrix operator*(CMatrix MATParam);

	void MATPrint();

	CMatrix MATTranspose();



};

//Constructors and destructor

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
    uiMATRow = MATParam.uiMATRow;
	uiMATCol = MATParam.uiMATCol;
	NType ppTab[uiMATRow][uiMATCol];
	 for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	 {
		 for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		 {
			 ppTab[uiLoopRow][uiLoopCol] = MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
		 }
	 }
	 ppMATMatrix = ppTab;
}

 template <class NType>
 CMatrix<NType>::CMatrix(unsigned int uiRow, unsigned int uiCol)
{
	 uiMATRow = uiRow;
	 uiMATCol = uiCol;
	 NType ppTab[uiRow][uiCol];
	 for (unsigned int uiLoopRow = 0; uiLoopRow < uiRow; uiLoopRow++)
	 {
		 for (unsigned int uiLoopCol = 0; uiLoopCol < uiCol; uiLoopCol++)
		 {
			 ppTab[uiLoopRow][uiLoopCol] = 0;
		 }
	 }
	 ppMATMatrix = ppTab;
}


//methods

template <class NType>
void CMatrix<NType>::operator=(CMatrix MATParam)
{
    uiMATRow = MATParam.uiMATRow;
	uiMATCol = MATParam.uiMATCol;

	NType ppTab[uiMATRow][uiMATCol];
	 for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	 {
		 for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		 {
			 ppTab[uiLoopRow][uiLoopCol] = MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
		 }
	 }
	 ppMATMatrix = ppTab;
}


 template <class NType>
CMatrix<NType>& CMatrix<NType>::operator*(double dc)
{
	NType **ppTab = ppMATMatrix;
	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] *= dc;
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);
}

template <class NType>
CMatrix<NType> operator*(double dc, CMatrix<NType> MATParam)
{
	NType **ppTab = MATParam.ppMATMatrix;
	for (unsigned int uiLoopRow = 0; uiLoopRow < MATParam.uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < MATParam.uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] *= dc;
		}
	}

	return new CMatrix<NType>(MATParam.uiMATRow,MATParam.uiMATCol,ppTab);
}

template <class NType>
CMatrix<NType> CMatrix<NType>::operator/(double dc)
{
    if(dc == 0)
    {
        throw new CException(DIV_PAR_0);;
    }

	NType **ppTab = ppMATMatrix;
	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] /= dc;
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
	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] += MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
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

    NType **ppTab = ppMATMatrix;//verifier si ça ne modifie pas un des params
	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] -= MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);
}

template <class NType>
CMatrix<NType> CMatrix<NType>::operator*(CMatrix MATParam)
{
	if(uiMATCol != MATParam.uiMATRow)
        throw new CException(BAD_SIZE_OF_MAT);

    unsigned int uiRowSize = uiMATRow;
    unsigned int uiColSize = MATParam.uiMATCol;

    CMatrix *pMATResult = new CMatrix(uiRowSize, uiColSize);

    //initialisation of ppTab;

    for (unsigned int uiLoopRow = 0; uiLoopRow < uiRowSize; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiColSize; uiLoopCol++)
		{
			for(unsigned int uiLoop = 0; uiLoop < uiMATCol; uiLoop++)
            {
                pMATResult.ppMATMatrix[uiLoopRow][uiLoopCol] += ppMATMatrix[uiLoopRow][uiLoop] * MATParam.ppMATMatrix[uiLoop][uiLoopCol];
            }
		}
	}
	return pMATResult; //Verifier si on ne doit pas faire un retour par référence (ou un truc comme ça)

}

template <class NType>
void CMatrix<NType>::MATPrint()
{
    for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			cout << ppMATMatrix[uiLoopRow][uiLoopCol] << " ";

		}
		cout << endl;
	}
}

template <class NType>
CMatrix<NType> CMatrix<NType>::MATTranspose()
{

    CMatrix *pMATResult = new CMatrix(uiMATCol, uiMATRow);

	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			pMATResult.ppMATMatrix[uiLoopCol][uiLoopRow] = ppMATMatrix[uiLoopRow][uiLoopCol];
		}
	}
	return pMATResult;
}








#endif
