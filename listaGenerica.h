#pragma once;
#include "nodoGenerico.h"
#include<fstream>
#include"empresa.h"
#include"iteradorLista.h"
template<class T>
class listaGenerica//Clase listaGenerica sirve para poder crear diferentes tipos de listas
{					//como por ejemplo, gracias a esta clase se puede crear la lista de puestos,
protected:			//empleados, entre otras
	nodoGenerico<T> *primero;
	int size;
public:
	nodoGenerico<T>*getPrimero();
	listaGenerica();
	listaGenerica(listaGenerica&);
	bool esVacia();
	void insertarInicio(T*);
	void insertarFinal(T*);
	string toString();
	bool buscar(T*aux);
	T*retornaPuesto(T*aux);
	void eliminarInicio();
	bool eliminarFinal();
	bool eliminarEspecifico(T*);
	listaGenerica& operator=(listaGenerica&);
	~listaGenerica();
	iteradorLista<T>*obtenerIterador();
	void guardar(ofstream& salida);
	void guardar1(ofstream & salida);
};
template <class T>
listaGenerica<T>::listaGenerica(listaGenerica &aux) {
	while (!esVacia())
	{
		eliminarInicio();
	}
	primero = NULL;
	size = 0;
	nodoGenerico<T>* actual = aux.primero;
	while (actual)
	{
		insertarFinal(actual->getInfo());
		actual = actual->getSig();
	}
}

template<class T>
bool listaGenerica<T>::esVacia() {
	return (primero == NULL);
}

template<class T>
inline nodoGenerico<T>* listaGenerica<T>::getPrimero()
{
	return primero;
}

template<class T>
listaGenerica<T>::listaGenerica() {
	primero = NULL;
	size = 0;
}

template<class T>
string listaGenerica<T>::toString()
{
	stringstream s;
	nodoGenerico<T> *actual = primero;
	int contador = 1;
	while (actual != NULL)
	{
		s << "---------------------------------------------------------" << endl;
		s << endl;
		s << contador << ")" << *actual->getInfo();
		contador++;
		actual = actual->getSig();
		s << endl;
	}
	return s.str();
}

template<class T>
void listaGenerica<T>::insertarInicio(T* dato) {
	nodoGenerico<T> *actual;
	actual = new nodoGenerico<T>(dato);
	actual->setSig(primero);
	primero = actual;
	size++;
}

template <class T>
void listaGenerica<T>::insertarFinal(T* dato) {
	nodoGenerico<T>* actual = primero;
	if (esVacia()) {
		insertarInicio(dato);
	}
	else {
		while (actual->getSig() != NULL)
		{
			actual = actual->getSig();

		}
		actual->setSig(new nodoGenerico<T>(dato));
		size++;
	}
}
template<class T>
bool listaGenerica<T>::buscar(T* aux)
{
	nodoGenerico<T> *actual = primero;
	while (actual)
	{
		if ((*actual->getInfo()) == (*aux))
		{
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
inline T * listaGenerica<T>::retornaPuesto(T* aux)
{
	//nodoGenerico<T> *actual = primero;
	//while (actual)
	//{
	//	if (*(actual->getInfo()) == (*aux))
	//	{
	//		T = actual->getInfo();
	//	}
	//	actual = actual->getSig();
	//}
	//return T;
}

template<class T>
void listaGenerica<T>::eliminarInicio() {
	nodoGenerico<T> *actual = primero;
	if (primero == NULL)
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		actual = primero;
		primero = primero->getSig();
		delete actual;
		size--;
	}
}
template<class T>
bool listaGenerica<T>::eliminarFinal() {
	nodoGenerico<T> *actual = primero;
	
	if (primero == NULL)
	{
		return false;
	}
	else
	{
		if (primero->getSig() == NULL)
		{
			delete primero;
			size--;
			primero = NULL;
		}
		else
		{

			while (actual->getSig()->getSig() != NULL)
			{
				actual = actual->getSig();
			}
			delete  actual->getSig();
			size--;
			actual->setSig(NULL);
		}
		return true;
	}
}
template<class T>
bool listaGenerica<T>::eliminarEspecifico(T* aux) {
	nodoGenerico<T>* panterior = NULL;
	nodoGenerico<T>* actual = primero;
	actual = primero;

	if (primero == NULL)
	{
		return false;
	}

	if ((*primero->getInfo()) == (*aux)) 
	{
		actual = actual->getSig();
		delete (primero);
		size--;
		primero = actual;
		return true;
	}

	while (actual != NULL && (*actual->getInfo()) != (*aux)) {
		panterior = actual;
		actual = actual->getSig();
	}

	if (actual == NULL) {  }
	else {
		panterior->setSig(actual->getSig());
		delete actual;
		size--;
		return true;
	}
	return false;
}

template <class T>
listaGenerica<T>& listaGenerica<T>::operator=(listaGenerica& aux)
{
	while (!esVacia())
	{
		eliminarInicio();
	}
	primero = NULL;
	size = 0;
	nodoGenerico<T>* actual = aux.primero;
	while (actual)
	{
		insertarFinal(actual->getInfo());
		actual = actual->getSig();
	}
	return *this;
}

template<class T>
listaGenerica<T>::~listaGenerica()
{
	while (!esVacia())
		eliminarInicio();
	size = 0;
}

template<class T>
inline iteradorLista<T>* listaGenerica<T>::obtenerIterador()
{
	return new iteradorLista<T>(primero);
}

template<class T>
inline void listaGenerica<T>::guardar(ofstream & salida)
{
	T*_t;
	nodoGenerico<T>*actual = primero;
	while (actual != NULL) {
		_t = actual->getInfo();
		if (_t != NULL) {
			_t->autoGuardar(salida);
		}
		actual = actual->getSig();
	}
}

template<class T>
inline void listaGenerica<T>::guardar1(ofstream & salida)
{
	T*_t;
	nodoGenerico<T>*actual = primero;
	while (actual != NULL) {
		_t = actual->getInfo();
		if (_t != NULL) {
			_t->autoGuardar2(salida);
		}
		actual = actual->getSig();
	}
}