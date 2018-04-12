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
    CMatList<NType>();

	void MTLadd(CMatrix<NType> &MATParam);

	void MTLMultByConst(double C);

	void MTLDivByConst(double C);

	void MTLSum();

	void MTLAltPlusMinus();

	void MTLProduct();

};

template <typename NType>
CMatList<NType>::CMatList()
{
    uiMTLLength = 0;
}

template <class NType>
void CMatList<NType>::MTLadd(CMatrix<NType> &MATParam)
{
    lMTLList.push_back(MATParam);

}

template <class NType>
void CMatList<NType>::MTLMultByConst(double C)
{
    for (unsigned int loop = 0; loop < lMTLList.size(); loop++)
    {
        (lMTLList.at(loop)*C).MATPrint();
    }

}

template <class NType>
void CMatList<NType>::MTLDivByConst(double C)
{
    for (unsigned int loop = 0; loop < lMTLList.size(); loop++)
    {
        (lMTLList.at(loop)/C).MATPrint();
    }
}

template <class NType>
void CMatList<NType>::MTLSum()
{
    CMatrix<NType> * c = new CMatrix<NType>(lMTLList.at(0).getRow(), lMTLList.at(0).getCol());
    for(unsigned int i=0; i<lMTLList.size(); i++)
    {
        *c = *c + lMTLList.at(i);
    }
    c->MATPrint();
}

template <class NType>
void CMatList<NType>::MTLAltPlusMinus()
{
}

template <class NType>
void CMatList<NType>::MTLProduct()
{
}


#endif
