/*
 * cola.h
 *
 *  Created on: Dec 3, 2020
 *      Author: aron
 */

#ifndef COLA_H_
#define COLA_H_

#include "nodo.h"
#include <string>

template <class T>

class cola{

	private:

	nodo<T>* frente;
	nodo<T>* final;
	int cantElementos;


	public:
	//pos : crea una cola sin elementos
	cola();
	//pos : obtiene el nodo que se fue ingresado primero
	nodo<T>* obtenerFrente();
	//pos : ingresa un nuevo nodo a la cola
	void acolar(nodo<T>* nuevoNodo);
	//pos : elimina los nodos , empezando por el primer nodo ingresado
	void desacolar();
	//pos : obtiene el valor contenido en el nodo ingresado primero
	T obtenerValorFrente();
	//pos : obtiene el valor del nodo ingresado al final
	T obtenerValorFinal();
	//pos : devuelve la cantidad de nodos
	int obtenerCantNodos();
	//pos : libera memoria dinamica
	~cola();



};

template <class T>

cola<T>::cola(){

	this->frente=NULL;
	this->final=NULL;
	this->cantElementos=0;
}

template <class T>

int cola<T>::obtenerCantNodos(){
	return this->cantElementos;
}

template <class T>

nodo<T>* cola<T>::obtenerFrente(){

	return this->frente;
}
template <class T>

void cola<T>::acolar(nodo<T>* nuevoNodo){

	if(this->frente == NULL){
		this->frente=nuevoNodo;
	}else{
		this->final->cambiarSig(nuevoNodo);

	}
	this->final=nuevoNodo;

	this->cantElementos++;

}
template <class T>

void cola<T>::desacolar(){

	nodo<T>* aux = this->frente;
	if(aux != NULL){


		this->frente = aux->obtenerSig();

	}else{
		throw std::string("no hay elementos para desacolar");

	}

	this->cantElementos--;
	delete aux;

}

template <class T>

T cola<T>::obtenerValorFrente(){

	if(this->frente != NULL){
		int mostrarNodo=this->frente->obtenerValor();
		return mostrarNodo;
	}else{
		throw std::string("no hay elementos en la pila");
	}
}

template <class T>

T cola<T>::obtenerValorFinal(){

	if(this->final != NULL){
		T mostrarNodo = this->final->obtenerValor();
		return mostrarNodo;

	}else{

		throw std::string("no hay elementos en la pila");
	}
}

template <class T>

cola<T>::~cola(){

	while(this->frente != NULL){

		nodo<T> * borrarNodo= this->frente;
		this->frente=this->frente->obtenerSig();

		delete borrarNodo;

	}

}


#endif /* COLA_H_ */
