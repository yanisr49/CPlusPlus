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

    /** \brief Constructeur par défaut
     *
     *E: Néant
     *Necessite : Rien
     *S :Néant
     *Entraine : (Créé un nouveau CMatList avec uiMTLLength = 0)
     */
    CMatList<NType>();

    /** \brief Ajoute une CMatrix à notre liste
     *
     *E: MATParam & CMatrix
     *Necessite : Rien
     *S :Néant
     *Entraine : (Ajoute MATParam à la liste CMATList)
     */
	void MTLadd(CMatrix<NType> &MATParam);

	/** \brief Multiplie chaque matrice par un double
     *
     *E: dConstant double le double par lequel on veut multiplier les matrices
     *Necessite : Rien
     *S :Néant
     *Entraine : (Multiplie chacune des matrices de la liste par dConstant et les affiche)
     */
	void MTLMultByConst(double dConstant);

	/** \brief Divise chaque matrice par un double
     *
     *E: dConstant double le double par lequel on veut diviser les matrices
     *Necessite : Rien
     *S :Néant
     *Entraine : (Divise chacune des matrices de la liste par dConstant et les affiche)
     */
	void MTLDivByConst(double dConstant);

	/** \brief Fais la somme de toutes les matrices de la liste
     *
     *E:Néant
     *Necessite : Rien
     *S :Néant
     *Entraine :(Affiche la somme de toutes les matrices de la liste) OU (Erreur : matrices de mauvaise taille)
     */
	void MTLSum();

	/** \brief Alterne la somme et la soustraction de toutes les matrices de la liste
     *
     *E:Néant
     *Necessite : Rien
     *S :Néant
     *Entraine :(Affiche l'aternance de la somme et de la soustraction de toutes les matrices de la liste)
     *OU (Erreur : matrices de mauvaise taille)
     */
	void MTLAltPlusMinus();

	/** \brief Fais le produit de toutes les matrices de la liste
     *
     *E:Néant
     *Necessite : Rien
     *S :Néant
     *Entraine :(Affiche le produit de toutes les matrices de la liste) OU (Erreur : matrices de mauvaise taille)
     */
	void MTLProduct();

};

/** \brief Constructeur par défaut
*
*E: Néant
*Necessite : Rien
*S :Néant
*Entraine : (Créé un nouveau CMatList avec uiMTLLength = 0)
*/
template <typename NType>
CMatList<NType>::CMatList()
{
    uiMTLLength = 0;
}

/** \brief Ajoute une CMatrix à notre liste
*
*E: MATParam & CMatrix
*Necessite : Rien
*S :Néant
*Entraine : (Ajoute MATParam à la liste CMATList)
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
     *S :Néant
     *Entraine : (Multiplie chacune des matrices de la liste par dConstant et les affiche)
     */
template <class NType>
void CMatList<NType>::MTLMultByConst(double dConstant)
{
    for (unsigned int uiLoop = 0; uiLoop < lMTLList.size(); uiLoop++)
    {
        (lMTLList.at(uiLoop)*dConstant).MATPrint();
    }

}

	/** \brief Divise chaque matrice par un double
     *
     *E: dConstant double le double par lequel on veut diviser les matrices
     *Necessite : Rien
     *S :Néant
     *Entraine : (Divise chacune des matrices de la liste par dConstant et les affiche)
     */
template <class NType>
void CMatList<NType>::MTLDivByConst(double dConstant)
{
    for (unsigned int uiLoop = 0; uiLoop < lMTLList.size(); uiLoop++)
    {
        (lMTLList.at(uiLoop)/dConstant).MATPrint();
    }
}

	/** \brief Fais la somme de toutes les matrices de la liste
     *
     *E:Néant
     *Necessite : Rien
     *S :Néant
     *Entraine :(Affiche la somme de toutes les matrices de la liste) OU (Erreur : matrices de mauvaise taille)
     */
template <class NType>
void CMatList<NType>::MTLSum()
{
    CMatrix<NType> * pMATResult = new CMatrix<NType>(lMTLList.at(0).MATgetRow(), lMTLList.at(0).MATgetCol());
    try{
        for(unsigned int uiLoop=0; uiLoop<lMTLList.size(); uiLoop++)
        {
            *pMATResult = *pMATResult + lMTLList.at(uiLoop);
        }
        pMATResult->MATPrint();
    }
    catch(CException* EXCErreur){EXCErreur->EXCAfficheErreur();}
}

	/** \brief Alterne la somme et la soustraction de toutes les matrices de la liste
     *
     *E:Néant
     *Necessite : Rien
     *S :Néant
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
                *pMATResult = *pMATResult + lMTLList.at(uiLoop);
            else
                *pMATResult = *pMATResult - lMTLList.at(uiLoop);
        }
        pMATResult->MATPrint();
    }
    catch(CException* EXCErreur){EXCErreur->EXCAfficheErreur();
    }
}

	/** \brief Fais le produit de toutes les matrices de la liste
     *
     *E:Néant
     *Necessite : Rien
     *S :Néant
     *Entraine :(Affiche le produit de toutes les matrices de la liste) OU (Erreur : matrices de mauvaise taille)
     */
template <class NType>
void CMatList<NType>::MTLProduct()//réécrire cette fonction
{
    CMatrix<NType> * pMATResult = new CMatrix<NType>(lMTLList.at(0).MATgetRow(), lMTLList.at(lMTLList.size()-1).MATgetCol());
    try{
        for(unsigned int uiLoop=0; uiLoop<lMTLList.size(); uiLoop++)
        {
            *pMATResult = *pMATResult * lMTLList.at(uiLoop);
        }
        pMATResult->MATPrint();
    }
    catch(CException* EXCErreur){EXCErreur->EXCAfficheErreur();
    }

}


#endif
