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


    /** \brief Constructeur à 3 arguments
     *
     *E:
     * \param uiRow unsigned int le nombre de lignes
     * \param uiCol unsigned int le ombre de colonnes
     * \param ppTab NType** le tableau de deux dimensions représentant les données de la matrices (de type Ntype)
     *Necessite: uiRow et uiCol correspndent à la taille du tableau ppTab
     *S : Rien
     *Entraine : (L'objet est initialisé)
     */
    CMatrix(unsigned int uiRow, unsigned int uiCol, NType **ppTab);



    /** \brief Constructeur de recopie
     *
     *E:
     * \param MATParam CMatrix la matrice à recopier
     *Necessite : Néant
     *S : Rien
     *Entraine : (L'objet est initialisé en une copie de MATParam)
     */
	CMatrix(const CMatrix & MATParam);


    /** \brief Constructeur à 2 arguments
     *
     *E:
     * \param uiRow unsigned int le nombre de lignes
     * \param uiCol unsigned int le ombre de colonnes
     *Necessite: Néant
     *S : Rien
     *Entraine : (L'objet est initialisé avec une matrice de 0)
     */
	CMatrix(unsigned int uiRow, unsigned int uiCol);

	 /** \brief Destructeur
     *
     *E:Rien
     *Necessite: Néant
     *S : Rien
     *Entraine : (L'objet est correctement détruit)
     */
	~CMatrix();


	/** \brief Surchage de l'opérateur =
     *
     *E:
     * \param MATParam CMatrix la matrice à recopier
     *Necessite : Néant
     *S : Rien
     *Entraine : (L'objet devient une copie de MATParam)
     */
    void operator=(CMatrix<NType> * MATParam);

    /** \brief Surchage de l'opérateur *
     *
     *E:
     *\param dConstant double le double à multiplier
     *Necessite : Néant
     *S :
     *\return CMatrix
     *Entraine : (Retourne le produit de la matrice par dConstant)
     */
	CMatrix* operator*(double dConstant);


    /** \brief Surchage de l'opérateur /
     *
     *E:
     *\param dConstant double le double à diviser
     *Necessite : Néant
     *S :
     *\return CMatrix
     *Entraine : (Retourne la division de la matrice par dConstant) OU (Exception : dénominateur nul
     *dConstant == 0)
     */
	CMatrix* operator/(double dConstant);

	/** \brief Surchage de l'opérateur +
     *
     *E:
     *\param MATParam CMatrix la matrice à ajouter
     *Necessite : Néant
     *S :
     *\return CMatrix
     *Entraine : (Retourne l'addition des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne sont pas de la même taille)
     */
	CMatrix* operator+(CMatrix<NType> MATParam);

	/** \brief Surchage de l'opérateur -
     *
     *E:
     *\param MATParam CMatrix la matrice que l'on soustrait
     *Necessite : Les valeurs de MATParam sont supérieurs à celles de this si les matrices contiennent des
     * unsigned int
     *S :
     *\return CMatrix
     *Entraine : (Retourne la soustraction des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne sont pas de la même taille)
     */
	CMatrix* operator-(CMatrix MATParam);

	/** \brief Surchage de l'opérateur *
     *
     *E:
     *\param MATParam CMatrix la matrice que que l'on veut multiplier
     *Necessite : Rien
     *S :
     *\return CMatrix
     *Entraine : (Retourne la multiplication des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne peuvent pas être multipliées à cause de leurs tailles)
     */
	CMatrix* operator*(CMatrix MATParam);

	/** \brief Affichage de la matrice
     *
     *E:Néant
     *Necessite : Rien
     *S :Néant
     *Entraine : (Affiche la matrice)
     */
	void MATPrint();

	/** \brief Transposition de la matrice
     *
     *E:Néant
     *Necessite : Rien
     *S :CMatrix
     *Entraine : (retourne la transposée de la matrice)
     */
	CMatrix MATTranspose();




	NType** MATCreateTab(unsigned int uiRow, unsigned int uiCol);




	/** \brief Getter du nombre de ligne de la matrice
     *E : Néant
     *Necessite : Rien
     *S:
     * \return unsigned int le nombre de ligne de la matrice
     *Entraine :(Retourne le nombre de ligne de la matrice)
     */
    unsigned int MATgetRow();

    /** \brief Getter du nombre de colonne de la matrice
     *E : Néant
     *Necessite : Rien
     *S:
     * \return unsigned int le nombre de colonne de la matrice
     *Entraine :(Retourne le nombre de colonne de la matrice)
     */
    unsigned int MATgetCol();


};

//Constructors and destructor

/** \brief Constructeur à 3 arguments
     *
     *E:
     * \param uiRow unsigned int le nombre de lignes
     * \param uiCol unsigned int le ombre de colonnes
     * \param ppTab NType** le tableau de deux dimensions représentant les données de la matrices (de type Ntype)
     *Necessite: uiRow et uiCol correspndent à la taille du tableau ppTab
     *S : Rien
     *Entraine : (L'objet est initialisé)
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
     * \param MATParam CMatrix la matrice à recopier
     *Necessite : Néant
     *S : Rien
     *Entraine : (L'objet est initialisé en une copie de MATParam)
     */
template <class NType>
 CMatrix<NType>::CMatrix(const CMatrix & MATParam)
{
    uiMATRow = MATParam.uiMATRow;
	uiMATCol = MATParam.uiMATCol;

    ppMATMatrix = MATCreateTab(uiMATRow, uiMATCol);

    for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
    {
        for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
        {
            ppMATMatrix[uiLoopRow][uiLoopCol] = MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
        }
    }
}

/** \brief Constructeur à 2 arguments
     *
     *E:
     * \param uiRow unsigned int le nombre de lignes
     * \param uiCol unsigned int le nombre de colonnes
     *Necessite: Néant
     *S : Rien
     *Entraine : (L'objet est initialisé avec une matrice de 0)
     */
 template <class NType>
 CMatrix<NType>::CMatrix(unsigned int uiRow, unsigned int uiCol)
{
    uiMATRow = uiRow;
    uiMATCol = uiCol;

    NType **ppTab = MATCreateTab(uiMATRow,uiMATCol);

    for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
    {
        for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
        {
            ppTab[uiLoopRow][uiLoopCol] = 0;
        }
    }
    ppMATMatrix = ppTab;
}

template <class NType>
 CMatrix<NType>::~CMatrix()
 {
     for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
    {
            free(ppMATMatrix[uiLoopRow]);
    }
    free(ppMATMatrix);
 }
//getter et setter

/** \brief Getter du nombre de ligne de la matrice
 *E : Néant
 *Necessite : Rien
 *S:
 * \return unsigned int le nombre de ligne de la matrice
 *Entraine :(Retourne le nombre de ligne de la matrice)
 */
template <class NType>
unsigned int CMatrix<NType>::MATgetRow()
{
    return uiMATRow;
}

/** \brief Getter du nombre de colonne de la matrice
 *E : Néant
 *Necessite : Rien
 *S:
 * \return unsigned int le nombre de colonne de la matrice
 *Entraine :(Retourne le nombre de colonne de la matrice)
 */
template <class NType>
unsigned int CMatrix<NType>::MATgetCol()
{
    return uiMATCol;
}

//methods
/** \brief Surchage de l'opérateur =
     *
     *E:
     * \param MATParam CMatrix la matrice à recopier
     *Necessite : Néant
     *S : Rien
     *Entraine : (L'objet devient une copie de MATParam)
     */
template <class NType>
void CMatrix<NType>::operator=(CMatrix<NType> * MATParam)
{
    uiMATRow = MATParam->MATgetRow();
	uiMATCol = MATParam->MATgetCol();

    NType **ppTab = MATCreateTab(uiMATRow,uiMATCol);

	 for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	 {
		 for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		 {
			 ppTab[uiLoopRow][uiLoopCol] = MATParam->ppMATMatrix[uiLoopRow][uiLoopCol];
		 }
	 }
	 ppMATMatrix = ppTab;
}

/** \brief Surchage de l'opérateur *
     *
     *E:
     *\param dConstant double le double à multiplier
     *Necessite : Néant
     *S :
     *\return CMatrix
     *Entraine : (Retourne le produit de la matrice par dConstant)
     */
 template <class NType>
CMatrix<NType> * CMatrix<NType>::operator*(double dConstant)
{
	NType **ppTab = MATCreateTab(uiMATRow,uiMATCol);

	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] = ppMATMatrix[uiLoopRow][uiLoopCol] * dConstant;
		}
	}
	//cout << "coucou" << endl;
	return new CMatrix(uiMATRow,uiMATCol,ppTab);
}


/** \brief Surcharge de l'opérateur *
 *  Cette surchage sert à la mommutativité de l'opérateur
 *E:
 * \param dConstant double, le double que l'on veut multiplier
 * \param MATParam CMatrix la matrice que l'on veut multiplier
 *Necessite : Rien
 *S:
 * \return CMatrix
 *Entraine : (Retourne le produit de la matrice par dConstant)
 */
template <class NType>
CMatrix<NType>* operator*(double dConstant, CMatrix<NType> MATParam)
{
	NType **ppTab = MATCreateTab(MATParam.uiMATRow,MATParam.uiMATCol);
	for (unsigned int uiLoopRow = 0; uiLoopRow < MATParam.uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < MATParam.uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] = MATParam.ppMATMatrix[uiLoopRow][uiLoopCol] * dConstant;
		}
	}

	return new CMatrix<NType>(MATParam.uiMATRow,MATParam.uiMATCol,ppTab);
}

/** \brief Surchage de l'opérateur /
     *
     *E:
     *\param dConstant double le double à diviser
     *Necessite : Néant
     *S :
     *\return CMatrix
     *Entraine : (Retourne la division de la matrice par dConstant) OU (Exception : dénominateur nul
     *dConstant == 0)
     */
template <class NType>
CMatrix<NType>* CMatrix<NType>::operator/(double dConstant)
{
    if(dConstant == 0)
    {
        throw new CException(DIV_PAR_0);
    }

	NType **ppTab = MATCreateTab(uiMATRow,uiMATCol);
	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] = ppMATMatrix[uiLoopRow][uiLoopCol] / dConstant;
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);
}

/** \brief Surchage de l'opérateur +
     *
     *E:
     *\param MATParam CMatrix la matrice à ajouter
     *Necessite : Néant
     *S :
     *\return CMatrix
     *Entraine : (Retourne l'addition des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne sont pas de la même taille)
     */
template <class NType>
CMatrix<NType>* CMatrix<NType>::operator+(CMatrix<NType> MATParam)
{
    if(uiMATCol != MATParam.uiMATCol || uiMATRow != MATParam.uiMATRow)
        throw new CException(BAD_SIZE_OF_MAT);

    NType **ppTab = MATCreateTab(uiMATRow,uiMATCol);

	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] = ppMATMatrix[uiLoopRow][uiLoopCol] + MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);

}




/** \brief Surchage de l'opérateur -
     *
     *E:
     *\param MATParam CMatrix la matrice que l'on soustrait
     *Necessite : Les valeurs de MATParam sont supérieurs à celles de this si les matrices contiennent des
     * unsigned int
     *S :
     *\return CMatrix
     *Entraine : (Retourne la soustraction des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne sont pas de la même taille)
     */
template <class NType>
CMatrix<NType>* CMatrix<NType>::operator-(CMatrix MATParam)
{
	 if(uiMATCol != MATParam.uiMATCol || uiMATRow != MATParam.uiMATRow)
        throw new CException(BAD_SIZE_OF_MAT);

    NType **ppTab = MATCreateTab(uiMATRow,uiMATCol);
	for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			ppTab[uiLoopRow][uiLoopCol] = ppMATMatrix[uiLoopRow][uiLoopCol] - MATParam.ppMATMatrix[uiLoopRow][uiLoopCol];
		}
	}
	return new CMatrix(uiMATRow,uiMATCol,ppTab);
}

/** \brief Surchage de l'opérateur *
     *
     *E:
     *\param MATParam CMatrix la matrice que que l'on veut multiplier
     *Necessite : Rien
     *S :
     *\return CMatrix
     *Entraine : (Retourne la multiplication des deux matrices) OU (Exception :BAD_SIZE_OF_MAT les deux matrices ne peuvent pas être multipliées à cause de leurs tailles)
     */
template <class NType>
CMatrix<NType>* CMatrix<NType>::operator*(CMatrix MATParam)
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
                pMATResult->ppMATMatrix[uiLoopRow][uiLoopCol] += ppMATMatrix[uiLoopRow][uiLoop] * MATParam.ppMATMatrix[uiLoop][uiLoopCol];
            }
		}
	}
	return pMATResult; //Verifier si on ne doit pas faire un retour par référence (ou un truc comme ça)
}

/** \brief Affichage de la matrice
     *
     *E:Néant
     *Necessite : Rien
     *S :Néant
     *Entraine : (Affiche la matrice)
     */
template <class NType>
void CMatrix<NType>::MATPrint()
{
    for (unsigned int uiLoopRow = 0; uiLoopRow < uiMATRow; uiLoopRow++)
	{
		for (unsigned int uiLoopCol = 0; uiLoopCol < uiMATCol; uiLoopCol++)
		{
			cout << ppMATMatrix[uiLoopRow][uiLoopCol] << "\t";

		}
		cout << endl;
	}
}

/** \brief Transposition de la matrice
     *
     *E:Néant
     *Necessite : Rien
     *S :CMatrix
     *Entraine : (retourne la transposée de la matrice)
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

template <class NType>
NType** CMatrix<NType>::MATCreateTab(unsigned int uiRow, unsigned int uiCol)
{
    NType ** ppTab = static_cast< NType** >(malloc(uiRow * sizeof(NType *)));
    for(unsigned int uiLoop=0; uiLoop<uiRow; uiLoop++)
        ppTab[uiLoop] = static_cast< NType* >(malloc(uiCol * sizeof(NType)));

    return ppTab;
}



#endif
