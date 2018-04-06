#include "CException.h"

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
/********************************************//**
* \brief Constructeur par défaut
***********************************************/
CException::CException()
{
	//ctor
	uiEXCValeur = 0;
}


/********************************************//**
* \brief Constructeur à 1 argument
*
* \param uiVal unsigned int la valeur de l'exception
*
***********************************************/
CException::CException(unsigned int uiVal)
{
	//ctor
	uiEXCValeur = uiVal;
}

/********************************************//**
* \brief Destructeur
***********************************************/
CException::~CException()
{
	//dtor
}
