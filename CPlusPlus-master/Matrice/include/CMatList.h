#ifndef C_MAT_LIST_H
#define C_MAT_LIST_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CMatrix.h"

template <class NType>
class CMatList
{
private:
	vector<CMatrix<NType> > lMTLList;

	unsigned int uiMTLLength;

public:

    /** \brief Constructeur par d�faut
     *
     *E: N�ant
     *Necessite : Rien
     *S :N�ant
     *Entraine : (Cr�� un nouveau CMatList avec uiMTLLength = 0)
     */
    CMatList<NType>();

    /** \brief Destructeur
     *
     *E:Rien
     *Necessite: N�ant
     *S : Rien
     *Entraine : (L'objet est correctement d�truit)
     */
    ~CMatList();

    /** \brief Ajoute une CMatrix � notre liste
     *
     *E: MATParam & CMatrix
     *Necessite : Rien
     *S :N�ant
     *Entraine : (Ajoute MATParam � la liste CMATList)
     */
	void MTLadd(CMatrix<NType> &MATParam);

	/** \brief Multiplie chaque matrice par un double
     *
     *E: dConstant double le double par lequel on veut multiplier les matrices
     *Necessite : Rien
     *S :N�ant
     *Entraine : (Multiplie chacune des matrices de la liste par dConstant et les affiche)
     */
	void MTLMultByConst(double dConstant);

	/** \brief Divise chaque matrice par un double
     *
     *E: dConstant double le double par lequel on veut diviser les matrices
     *Necessite : Rien
     *S :N�ant
     *Entraine : (Divise chacune des matrices de la liste par dConstant et les affiche)
     */
	void MTLDivByConst(double dConstant);

	/** \brief Fais la somme de toutes les matrices de la liste
     *
     *E:N�ant
     *Necessite : Rien
     *S :N�ant
     *Entraine :(Affiche la somme de toutes les matrices de la liste) OU (Erreur : matrices de mauvaise taille)
     */
	void MTLSum();

	/** \brief Alterne la somme et la soustraction de toutes les matrices de la liste
     *
     *E:N�ant
     *Necessite : Rien
     *S :N�ant
     *Entraine :(Affiche l'aternance de la somme et de la soustraction de toutes les matrices de la liste)
     *OU (Erreur : matrices de mauvaise taille)
     */
	void MTLAltPlusMinus();

	/** \brief Fais le produit de toutes les matrices de la liste
     *
     *E:N�ant
     *Necessite : Rien
     *S :N�ant
     *Entraine :(Affiche le produit de toutes les matrices de la liste) OU (Erreur : matrices de mauvaise taille)
     */
	void MTLProduct();

};

/** \brief Constructeur par d�faut
*
*E: N�ant
*Necessite : Rien
*S :N�ant
*Entraine : (Cr�� un nouveau CMatList avec uiMTLLength = 0)
*/
template <typename NType>
CMatList<NType>::CMatList()
{
    uiMTLLength = 0;
}


/** \brief Destructeur
     *
     *E:Rien
     *Necessite: N�ant
     *S : Rien
     *Entraine : (L'objet est correctement d�truit)
     */
template <typename NType>
CMatList<NType>::~CMatList()
{
    for (unsigned int uiLoop = 0; uiLoop < lMTLList.size(); uiLoop++)
    {
        delete &lMTLList.at(uiLoop);
    }
}


/** \brief Ajoute une CMatrix � notre liste
*
*E: MATParam & CMatrix
*Necessite : Rien
*S :N�ant
*Entraine : (Ajoute MATParam � la liste CMATList)
*/
template <class NType>
void CMatList<NType>::MTLadd(CMatrix<NType> &MATParam)
{
    lMTLList.push_back(MATParam);

}

	/** \brief Multiplie chaque matrice par un double
     *
     *E: dConstant double le double par lequel on veut multiplier les matrices
     *Necessite : Rien
     *S :N�ant
     *Entraine : (Multiplie chacune des matrices de la liste par dConstant et les affiche)
     */
template <class NType>
void CMatList<NType>::MTLMultByConst(double dConstant)
{
    for (unsigned int uiLoop = 0; uiLoop < lMTLList.size(); uiLoop++)
    {
        CMatrix<NType> *MATRes = (lMTLList.at(uiLoop)*dConstant);
        MATRes->MATPrint();
        delete MATRes;

    }

}

	/** \brief Divise chaque matrice par un double
     *
     *E: dConstant double le double par lequel on veut diviser les matrices
     *Necessite : Rien
     *S :N�ant
     *Entraine : (Divise chacune des matrices de la liste par dConstant et les affiche)
     */
template <class NType>
void CMatList<NType>::MTLDivByConst(double dConstant)
{
    for (unsigned int uiLoop = 0; uiLoop < lMTLList.size(); uiLoop++)
    {
        CMatrix<NType> *MATRes = (lMTLList.at(uiLoop)/dConstant);
        MATRes->MATPrint();
        delete MATRes;
    }
}

	/** \brief Fais la somme de toutes les matrices de la liste
     *
     *E:N�ant
     *Necessite : Rien
     *S :N�ant
     *Entraine :(Affiche la somme de toutes les matrices de la liste) OU (Erreur : matrices de mauvaise taille)
     */
template <class NType>
void CMatList<NType>::MTLSum()
{
    CMatrix<NType> * pMATResult = new CMatrix<NType>(lMTLList.at(0).MATgetRow(), lMTLList.at(0).MATgetCol());
    try{
        for(unsigned int uiLoop=0; uiLoop<lMTLList.size(); uiLoop++)
        {
            CMatrix<NType> *pMATResult2 = *pMATResult + lMTLList.at(uiLoop);
            delete pMATResult;
            pMATResult = pMATResult2;
        }
        pMATResult->MATPrint();
        delete pMATResult;
    }
    catch(CException* EXCErreur){EXCErreur->EXCAfficheErreur();}
}

	/** \brief Alterne la somme et la soustraction de toutes les matrices de la liste
     *
     *E:N�ant
     *Necessite : Rien
     *S :N�ant
     *Entraine :(Affiche l'aternance de la somme et de la soustraction de toutes les matrices de la liste)
     *OU (Erreur : matrices de mauvaise taille)
     */
template <class NType>
void CMatList<NType>::MTLAltPlusMinus()
{
    CMatrix<NType> * pMATResult = new CMatrix<NType>(lMTLList.at(0).MATgetRow(), lMTLList.at(0).MATgetCol());
    try{
        for(unsigned int uiLoop=0; uiLoop<lMTLList.size(); uiLoop++)
        {
            if(uiLoop%2 == 0)
            {
                CMatrix<NType> *pMATResult2 = *pMATResult + lMTLList.at(uiLoop);
                delete pMATResult;
                pMATResult = pMATResult2;
            }
            else
            {
                CMatrix<NType> *pMATResult2 = *pMATResult - lMTLList.at(uiLoop);
                delete pMATResult;
                pMATResult = pMATResult2;
            }
        }
        pMATResult->MATPrint();
        delete pMATResult;
    }
    catch(CException* EXCErreur){EXCErreur->EXCAfficheErreur();
    }
}

	/** \brief Fais le produit de toutes les matrices de la liste
     *
     *E:N�ant
     *Necessite : Rien
     *S :N�ant
     *Entraine :(Affiche le produit de toutes les matrices de la liste) OU (Erreur : matrices de mauvaise taille)
     */
template <class NType>
void CMatList<NType>::MTLProduct()
{
    CMatrix<NType> * pMATResult = new CMatrix<NType>(lMTLList.at(0));

    try{
        for(unsigned int uiLoop=1; uiLoop<lMTLList.size(); uiLoop++)
        {
            CMatrix<NType> *pMATResult2 = *pMATResult * lMTLList.at(uiLoop);
            delete pMATResult;
            pMATResult = pMATResult2;
        }
        pMATResult->MATPrint();
        delete pMATResult;

    }
    catch(CException* EXCErreur){EXCErreur->EXCAfficheErreur();}

}


#endif
