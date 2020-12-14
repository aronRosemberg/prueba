/*
 * pila.h
 *
 *  Created on: Dec 2, 2020
 *      Author: aron
 */

#ifndef PILA_H_
#define PILA_H_

#include "nodo.h"

template<class T>

class pila{

	private:
	nodo<T>* tope ;
	int cantNodos;


	public:

	pila();
	nodo<T>* obtenerTope();
	void apilar(nodo<T>* nuevoNodo);
	void desapilar();
	bool estaVacia();
	T obtenerValorTope();
	~pila();


};

template <class T>

pila<T>::pila(){

	this->tope=	NULL;
	this->cantNodos=0;


}

template <class T>

void pila<T>::apilar(nodo<T>* nuevoNodo){


	nuevoNodo->cambiarSig(this->tope);
	this->tope=nuevoNodo;
	this->cantNodos++;

}

template <class T>

void pila<T>::desapilar(){
	if( !estaVacia()){
		nodo<T>* aux=this->tope;
		this->tope=tope->obtenerSig();
		this->cantNodos--;
		delete aux;



	}else{
		throw std::string("no hay elementos en la pila");
	}

}

template <class T>

nodo<T>* pila<T>::obtenerTope(){

	return this->tope;
}

template <class T>

bool pila<T>::estaVacia(){
	this->tope == NULL;
}

template <class T>

T pila<T>::obtenerValorTope(){

	T elemento;

	if(!estaVacia()){
		elemento=this->tope->obtenerValor();
	}else{
		throw std::string("cola vacia");
	}
	return elemento;

}

template <class T>

pila<T>::~pila(){
	while(!this->estaVacia()){
		this->desapilar();
	}

}


#endif /* PILA_H_ */
