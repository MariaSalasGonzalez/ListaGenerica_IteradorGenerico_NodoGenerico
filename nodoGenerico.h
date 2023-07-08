#pragma once
#include<iostream>
#include<sstream>
#include <string>
using namespace std;

template<class T>
class nodoGenerico
{
	T* info;
	nodoGenerico<T>*sig;
public:
	nodoGenerico(T*);
	nodoGenerico<T>* getSig();
	T* getInfo();
	void setSig(nodoGenerico<T> *info);
	nodoGenerico<T>& operator =(const nodoGenerico<T>& sum1);//5
};
template<class T>
nodoGenerico<T>::nodoGenerico(T* info)
{
	this->info = info;
	sig = NULL;
}
template<class T>
T* nodoGenerico<T>::getInfo() { 
	return info; 
}
template<class T>
inline void nodoGenerico<T>::setSig(nodoGenerico<T>* info)
{
	sig = info;
}

template<class T>
inline nodoGenerico<T>& nodoGenerico<T>::operator=(const nodoGenerico<T>& sum1)
{
	if (this != &sum1) {
		if (sum1.getInfo() != NULL) {
			this->getInfo() = sum1.getInfo();
		}
	}
	return *this;
}

template<class T>
nodoGenerico<T>*  nodoGenerico<T>::getSig()
{
	return sig;
}
