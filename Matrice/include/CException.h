
#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#define ERR_POINTEUR_NULL 1
#define ERR_TAB_DEPPASSE  2
#define ERR_DIV_PAR_0     3

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class CException
{
public:
	/********************************************//**
	 * \brief Constructeur par défaut
	***********************************************/
	CException();

	/********************************************//**
	 * \brief Constructeur à 1 argument
	*
	* \param uiVal unsigned int la valeur de l'exception
	*
	***********************************************/
	CException(unsigned int uiVal);

	/********************************************//**
	* \brief destructeur
	***********************************************/
	~CException();

	/********************************************//**
	* \brief Retourne la valeur de l'exception
	*
	* \return unsigned int la valeur de l'exception
	*
	***********************************************/
	unsigned int GetuiEXCValeur() { return uiEXCValeur; }

	/********************************************//**
	* \brief Change la valeur de l'exception
	*
	* \param uiVal unsigned int la valeur de l'exception
	* \return void
	*
	***********************************************/
	void SetuiEXCValeur(unsigned int uiVal) { uiEXCValeur = uiVal; }

protected:

private:
	unsigned int uiEXCValeur;
};

#endif // CEXCEPTION_H

#endif
