#include "CMatrix.h"

/** \brief Surchage de l'op�rateur *
     *Cette surchage ne fait pas partie de la classe CMatrix
     *elle sert � la commutativit�e de l'op�ration *
     *E:
     *\param dc double le double � multiplier
     *\param MATParam CMatrix la matrice � multiplier
     *Necessite : N�ant
     *S :
     *\return CMatrix
     *Entraine : (Retourne le produit de la MATParam par dc)
     */
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
