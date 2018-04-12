#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <stdlib.h>
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


    /** \brief Constructeur � 3 arguments
     *
     *E:
     * \param uiRow unsigned int le nombre de lignes
     * \param uiCol unsigned int le ombre de colonnes
     * \param ppTab NType** le tableau de deux dimensions repr�sentant les donn�es de la matrices (de type Ntype)
     *Necessite: uiRow et uiCol correspndent � la taille du tableau ppTab
     *S : Rien
     *Entraine : (L'objet est initialis�)
     */
    CMatrix(unsigned int uiRow, unsigned int uiCol, NType **ppTab);



    /** \brief Constructeur de recopie
     *
     *E:
     * \param MATParam CMatrix la matrice � recopier
     *Necessite : N�ant
     *S : Rien
     *Entraine : (L'objet est initialis� en une copie de MATParam)
     */
	CMatrix(const CMatrix & MATParam);


    /** \brief Constructeur � 2 arguments
     *
     *E:
     * \param uiRow unsigned int le nombre de lignes
     * \param uiCol unsigned int le ombre de colonnes
     *Necessite: N�ant
     *S : Rien
     *Entraine : (L'objet est initialis� avec une matrice de 0)
     */
	CMatrix(unsigned int uiRow, unsigned int uiCol);

	/** \brief Surchage de l'op�rateur =
     *
     *E:
     * \param MATParam CMatrix la matrice � recopier
     *Necessite : N�ant
     *S : Rien
     *Entraine : (L'objet devient une copie de MATParam)
     */
    void operator=(CMatrix<NType> * MATParam);

    /** \brief Surchage de l'op�rateur *
     *
     *E:
     *\param dc double le double � multiplier
     *Necessite : N�ant
     *S :
     *\return CMatrix
     *Entraine : (Retourne le produit de la matrice par dc)
     */
	CMatrix& operator*(double dc);


    /** \brief Surchage de l'op�rateur /
     *
     *E:
     *\param dc double le double � diviser
     *Necessite : N�ant
     *S :
     *\return CMatrix
     *Entraine : (Retourne la division de la matrice par dc) OU (Exception : d�nominateur nul
     *dc == 0)
     */
	CMatrix operator/(double dc);

	/** \brief Surchage de l'op�rateur +
     *
     *E:
     *\param MATParam CMatrix la matrice � ajouter
     *Necessite : N�ant
     *S :
     *\return CMatrix
     *Entraine : (Retourne l'addition des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne sont pas de la m�me taille)
     */
	CMatrix operator+(CMatrix<NType> MATParam);

	/** \brief Surchage de l'op�rateur -
     *
     *E:
     *\param MATParam CMatrix la matrice que l'on soustrait
     *Necessite : Les valeurs de MATParam sont sup�rieurs � celles de this si les matrices contiennent des
     * unsigned int
     *S :
     *\return CMatrix
     *Entraine : (Retourne la soustraction des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne sont pas de la m�me taille)
     */
	CMatrix operator-(CMatrix MATParam);

	/** \brief Surchage de l'op�rateur *
     *
     *E:
     *\param MATParam CMatrix la matrice que que l'on veut multiplier
     *Necessite : Rien
     *S :
     *\return CMatrix
     *Entraine : (Retourne la multiplication des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne peuvent pas �tre multipli�es � cause de leurs tailles)
     */
	CMatrix operator*(CMatrix MATParam);

	/** \brief Affichage de la matrice
     *
     *E:N�ant
     *Necessite : Rien
     *S :N�ant
     *Entraine : (Affiche la matrice)
     */
	void MATPrint();

	/** \brief Transposition de la matrice
     *
     *E:N�ant
     *Necessite : Rien
     *S :CMatrix
     *Entraine : (retourne la transpos�e de la matrice)
     */
	CMatrix MATTranspose();

    unsigned int getRow();
    unsigned int getCol();

};

//Constructors and destructor

/** \brief Constructeur � 3 arguments
     *
     *E:
     * \param uiRow unsigned int le nombre de lignes
     * \param uiCol unsigned int le ombre de colonnes
     * \param ppTab NType** le tableau de deux dimensions repr�sentant les donn�es de la matrices (de type Ntype)
     *Necessite: uiRow et uiCol correspndent � la taille du tableau ppTab
     *S : Rien
     *Entraine : (L'objet est initialis�)
     */
template <class NType>
CMatrix<NType>::CMatrix(unsigned int uiRow, unsigned int uiCol, NType **ppTab)
{
	uiMATRow = uiRow;
	uiMATCol = uiCol;
	ppMATMatrix = ppTab;
}

/** \brief Constructeur de recopie
     *
     *E:
     * \param MATParam CMatrix la matrice � recopier
     *Necessite : N�ant
     *S : Rien
     *Entraine : (L'objet est initialis� en une copie de MATParam)
     */
template <class NType>
 CMatrix<NType>::CMatrix(const CMatrix & MATParam)
{
    uiMATRow = MATParam.uiMATRow;
	uiMATCol = MATParam.uiMATCol;

    ppMATMatrix = static_cast< NType** >(malloc(uiMATRow * sizeof(NType *)));
    for(unsigned int i=0; i<uiMATRow; i++)
        ppMATMatrix[i] = static_cast< NType* >(malloc(uiMATCol * sizeof(NType)));

    for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
    {
        for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
        {
            ppMATMatrix[uiLoopRow][uiLoopCol] = MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
        }
    }
}

/** \brief Constructeur � 2 arguments
     *
     *E:
     * \param uiRow unsigned int le nombre de lignes
     * \param uiCol unsigned int le ombre de colonnes
     *Necessite: N�ant
     *S : Rien
     *Entraine : (L'objet est initialis� avec une matrice de 0)
     */
 template <class NType>
 CMatrix<NType>::CMatrix(unsigned int uiRow, unsigned int uiCol)
{
    uiMATRow = uiRow;
    uiMATCol = uiCol;

    NType ** ppTab = static_cast< NType** >(malloc(uiRow * sizeof(NType *)));
    for(unsigned int i=0; i<uiRow; i++)
        ppTab[i] = static_cast< NType* >(malloc(uiCol * sizeof(NType)));

    for (unsigned int uiLoopRow = 0; uiLoopRow < uiRow; uiLoopRow++)
    {
        for (unsigned int uiLoopCol = 0; uiLoopCol < uiCol; uiLoopCol++)
        {
            ppTab[uiLoopRow][uiLoopCol] = 0;
        }
    }
    ppMATMatrix = ppTab;
}
//getter et setter

template <class NType>
unsigned int CMatrix<NType>::getRow()
{
    return uiMATRow;
}

template <class NType>
unsigned int CMatrix<NType>::getCol()
{
    return uiMATCol;
}

//methods
/** \brief Surchage de l'op�rateur =
     *
     *E:
     * \param MATParam CMatrix la matrice � recopier
     *Necessite : N�ant
     *S : Rien
     *Entraine : (L'objet devient une copie de MATParam)
     */
template <class NType>
void CMatrix<NType>::operator=(CMatrix<NType> * MATParam)
{
    uiMATRow = MATParam->getRow();
	uiMATCol = MATParam->getCol();

    NType ** ppTab = static_cast< NType** >(malloc(uiMATRow * sizeof(NType *)));
    for(unsigned int i=0; i<uiMATRow; i++)
        ppTab[i] = static_cast< NType* >(malloc(uiMATCol * sizeof(NType)));

	 for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	 {
		 for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		 {
			 ppTab[uiLoopRow][uiLoopCol] = MATParam->ppMATMatrix[uiLoopRow][uiLoopCol];
		 }
	 }
	 ppMATMatrix = ppTab;
}

/** \brief Surchage de l'op�rateur *
     *
     *E:
     *\param dc double le double � multiplier
     *Necessite : N�ant
     *S :
     *\return CMatrix
     *Entraine : (Retourne le produit de la matrice par dc)
     */
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
	return *(new CMatrix(uiMATRow,uiMATCol,ppTab));
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

/** \brief Surchage de l'op�rateur /
     *
     *E:
     *\param dc double le double � diviser
     *Necessite : N�ant
     *S :
     *\return CMatrix
     *Entraine : (Retourne la division de la matrice par dc) OU (Exception : d�nominateur nul
     *dc == 0)
     */
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
	return *(new CMatrix(uiMATRow,uiMATCol,ppTab));
}

/** \brief Surchage de l'op�rateur +
     *
     *E:
     *\param MATParam CMatrix la matrice � ajouter
     *Necessite : N�ant
     *S :
     *\return CMatrix
     *Entraine : (Retourne l'addition des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne sont pas de la m�me taille)
     */
template <class NType>
CMatrix<NType> CMatrix<NType>::operator+(CMatrix<NType> MATParam)
{
    if(uiMATCol != MATParam.uiMATCol || uiMATRow != MATParam.uiMATRow)
        throw new CException(BAD_SIZE_OF_MAT);

    NType ** ppTab = static_cast< NType** >(malloc(uiMATRow * sizeof(NType *)));
    for(unsigned int i=0; i<uiMATRow; i++)
        ppTab[i] = static_cast< NType* >(malloc(uiMATCol * sizeof(NType)));

	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] = ppMATMatrix[uiLoopRow][uiLoopCol] + MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
		}
	}
	return *(new CMatrix(uiMATRow,uiMATCol,ppTab));

}




/** \brief Surchage de l'op�rateur -
     *
     *E:
     *\param MATParam CMatrix la matrice que l'on soustrait
     *Necessite : Les valeurs de MATParam sont sup�rieurs � celles de this si les matrices contiennent des
     * unsigned int
     *S :
     *\return CMatrix
     *Entraine : (Retourne la soustraction des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne sont pas de la m�me taille)
     */
template <class NType>
CMatrix<NType> CMatrix<NType>::operator-(CMatrix MATParam)
{
	 if(uiMATCol != MATParam.uiMATCol || uiMATRow != MATParam.uiMATRow)
        throw new CException(BAD_SIZE_OF_MAT);

    NType **ppTab = ppMATMatrix;//verifier si �a ne modifie pas un des params
	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] -= MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);
}

/** \brief Surchage de l'op�rateur *
     *
     *E:
     *\param MATParam CMatrix la matrice que que l'on veut multiplier
     *Necessite : Rien
     *S :
     *\return CMatrix
     *Entraine : (Retourne la multiplication des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne peuvent pas �tre multipli�es � cause de leurs tailles)
     */
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
	return pMATResult; //Verifier si on ne doit pas faire un retour par r�f�rence (ou un truc comme �a)
}

/** \brief Affichage de la matrice
     *
     *E:N�ant
     *Necessite : Rien
     *S :N�ant
     *Entraine : (Affiche la matrice)
     */
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

/** \brief Transposition de la matrice
     *
     *E:N�ant
     *Necessite : Rien
     *S :CMatrix
     *Entraine : (retourne la transpos�e de la matrice)
     */
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
