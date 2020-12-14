/*
 * nodo.h
 *
 *  Created on: Dec 2, 2020
 *      Author: aron
 */

#ifndef NODO_H_
#define NODO_H_


#ifndef NULL
#define NULL 0
#endif
#include<string>


template <class T>
class nodo{

	private:

	T valor;
	nodo<T>* siguiente;

	public:
	//pre: ingresa el valor en el nodo
	nodo(T valor);
	//pos: cambia el valor del nodo

	void cambiarValorNodo(T num);
	//pos: devuelve valor
	T obtenerValor();
	//pos : devuelve el puntero a siguente
	nodo<T>* obtenerSig();
	//pos: cambie el puntero suguiente por el puntero ingresado por parametro

	void cambiarSig(nodo<T>* nuevoNodo);



};

template <class T>

nodo<T>::nodo(T numero){
	valor = numero;
	siguiente = NULL;
}

template <class T>

void nodo<T>::cambiarValorNodo(T num){
	this->valor=num;
}

template <class T>

T nodo<T>::obtenerValor(){
	return valor;
}

template <class T>

nodo<T>* nodo<T>::obtenerSig(){
	return this->siguiente;
}

template <class T>

void nodo<T>::cambiarSig(nodo<T>* nuevoNodo){
	this->siguiente=nuevoNodo;

}




#endif /* NODO_H_ */
