<<<<<<< HEAD

#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#define POINTEUR_NULL   1
#define TAB_DEPPASSE    2
#define DIV_PAR_0       3
#define BAD_SIZE_OF_MAT 4
#define WRONG_TYPE      5

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

=======

#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#define POINTEUR_NULL   1
#define TAB_DEPPASSE    2
#define DIV_PAR_0       3
#define BAD_SIZE_OF_MAT 4
#define WRONG_TYPE      5

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

>>>>>>> 038852243f194254dc8a55b9a872b8c004daede0
