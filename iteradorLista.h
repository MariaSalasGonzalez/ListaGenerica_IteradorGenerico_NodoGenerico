#pragma once
#include"nodoGenerico.h"
template<class T>
class iteradorLista {
private:
	nodoGenerico<T>* cursor;
public:
	iteradorLista(nodoGenerico<T>*);
	virtual bool masElementos();
	virtual T* proximoElemento();
	~iteradorLista();
};

//Este m�todo es para la creaci�n de un iterador, para efecto de recorrer la lista
template<class T>
inline iteradorLista<T>::iteradorLista(nodoGenerico<T>*elNod)
{
	cursor = elNod;
}

//Este m�todo es para saber si se encuentran m�s elementos en la lista
template<class T>
inline bool iteradorLista<T>::masElementos()
{
	if (cursor != NULL) {
		return true;
	}
	else
		return false;
}

//Este m�todo es para colocar el iteradoren el siguiente elemento
template<class T>
inline T* iteradorLista<T>::proximoElemento()
{
	T* aux;
	if (masElementos() == true) {
		aux = cursor->getInfo();
		cursor = cursor->getSig();
		return aux;
	}
	return NULL;
}

//Destructor
template<class T>
inline iteradorLista<T>::~iteradorLista()
{
}

