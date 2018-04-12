<<<<<<< HEAD
#ifndef C_MAT_LIST_H
#define C_MAT_LIST_H

#include <string>
#include <list>
#include <vector>
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
	void MTLadd(CMatrix<NType> MATParam);

	void MTLMultByConst(double C);

	void MTLDivByConst(double C);

	void MTLSum();

	void MTLAltPlusMinus();

	void MTLProduct();

};



template <class NType>
void CMatList<NType>::MTLadd(CMatrix<NType> MATParam)
{
    printf("test");
    lMTLList.push_back(MATParam);
    printf("test");
}

template <class NType>
void CMatList<NType>::MTLMultByConst(double C)
{
    for (unsigned int loop = 0; loop <= uiMTLLength; loop++)
    {
        (lMTLList.At(loop)*C).MATPrint();
    }
}

template <class NType>
void CMatList<NType>::MTLDivByConst(double C)
{
    for (unsigned int loop = 0; loop <= uiMTLLength; loop++)
    {
        (lMTLList.At(loop)/C).MATPrint();
    }
}

template <class NType>
void CMatList<NType>::MTLSum()
{
    /*CMatrix<NType> c;
    typename list<CMatrix<NType> >::iterator it;
    for(it = lMTLList.begin(); it++ != lMTLList.end(); it++)
    {
        c = *it + *(it++);
    }
    c.MATPrint();*/
    CMatrix<NType> MATResult = new CMatrix<NType>(lMTLList.At(0).MATgetRow(),lMTLList.At(0).MATgetCol());
    for (unsigned int loop = 0; loop <= uiMTLLength; loop++)
    {
        MATResult += lMTLList.At(loop);
    }
    MATResult.MATPrint();
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
=======
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
	list<CMatrix<NType> > lMTLList;

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
}

template <class NType>
void CMatList<NType>::MTLDivByConst(double C)
{
}

template <class NType>
void CMatList<NType>::MTLSum()
{
    CMatrix<NType> * c = new CMatrix<NType>();
    typename list<CMatrix<NType> >::iterator it;
    for(it = lMTLList.begin(); it++ != lMTLList.end(); it++)
    {
        c = *it + *(it++);
    }
    c.MATPrint();
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
>>>>>>> 038852243f194254dc8a55b9a872b8c004daede0
