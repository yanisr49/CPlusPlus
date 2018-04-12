#include "CMatrix.h"

/** \brief Surchage de l'opérateur *
     *Cette surchage ne fait pas partie de la classe CMatrix
     *elle sert à la commutativitée de l'opération *
     *E:
     *\param dc double le double à multiplier
     *\param MATParam CMatrix la matrice à multiplier
     *Necessite : Néant
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
