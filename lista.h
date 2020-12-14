/*
 * lista.h
 *
 *  Created on: Dec 4, 2020
 *      Author: aron
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "nodo.h"

template<class T>

class lista{

	private:

	lista<T>* sigLista;
	nodo<T>* primerNodo;
	int cantNodos;


	public:
	//pos: inicializa la lista con 0 elementos
	lista();
	//pos : devuelve el primer nodo
	nodo<T>* obtenerPrimerNodo();
	//pos : obtiene puntero siguiente
	lista<T>* obtenerSigLista();
	//pos : asigna una nueva lista al puntero siguiente
	void asignarNuevaLista(lista<T>* nuevaLista);
	//pos : agrega un nuevo nodo al principio
	void agregarPrincipio(nodo<T>* elemento);
	//pos :agrega nodo en la poscision asignada
	void agregarPosicion(nodo<T>* elemento, int posicion);
	//pos :agrega nodo al final de la lista
	void agregarFinal(nodo<T>* elemento);
	//pos :obtien el nodo en la posicion indicada por parametro
	nodo<T>* obtenerNodo(int pos);
	//pos :obtiene cantidad de nodos
	int obtenerCantNodos();
	//pos : obtien el valor del nodo de la posicion indicada por parametro
	T obtenerValorPosicion(int i);
	//pos : valida que la posicion ingresada por parametro se encuentra entre [0 y cantNodos]
	bool validarCantLista(int pos);
	// pos : vacia la lista
	void vaciarLista();
	//pos : libera memoria dinamica
	~lista();

};

template<class T>

lista<T>::lista(){
		this->primerNodo=NULL;
		this->cantNodos=0;
		this->sigLista=NULL;
}

template<class T>

nodo<T>* lista<T>::obtenerPrimerNodo(){

	return this->primerNodo;
}

template<class T>

lista<T>* lista<T>::obtenerSigLista(){

	return this->sigLista;
}

template<class T>

void lista<T>::asignarNuevaLista(lista<T>* nuevaLista){
	this->sigLista=nuevaLista;
}

template<class T>

void lista<T>::agregarPrincipio(nodo<T>* elemento){

	agregarPosicion(elemento,1);

}

template<class T>

void lista<T>::agregarPosicion(nodo<T>* elemento, int pos){
	nodo<T>* nuevoNodo = elemento;

	if(this->validarCantLista(pos)){
		if(pos == 1){
			nuevoNodo->cambiarSig(primerNodo);
			this->primerNodo=nuevoNodo;
		}else{
			nodo<T>* nodoAnt=obtenerNodo(pos-1);
			nuevoNodo->cambiarSig(nodoAnt->obtenerSig());
			nodoAnt->cambiarSig(nuevoNodo);
		}
	}
	else{
		throw std::string("posicion incorrecta");

	}
	this->cantNodos++;

}

template<class T>

void lista<T>::agregarFinal(nodo<T>* elemento){
	agregarPosicion(elemento,this->obtenerCantNodos()+1);
}

template<class T>

nodo<T>* lista<T>::obtenerNodo(int pos){
	nodo<T>* nodoBuscado = primerNodo;
	if(pos > 0 && pos <= this->obtenerCantNodos()){
		for(int i=1; i<pos ;i++){
			nodoBuscado=nodoBuscado->obtenerSig();
		}

	}else{
		throw std::string(" no hay nodo");
	}

	return nodoBuscado;
}

template<class T>

int lista<T>::obtenerCantNodos(){
	return this->cantNodos;
}

template<class T>

T lista<T>::obtenerValorPosicion(int i){
	int valorPedido;
	if(validarCantLista(i)){
		nodo<T>* nodoPedido=obtenerNodo(i);
		valorPedido=nodoPedido->obtenerValor();

	}else{
		throw std::string("posicion incorrecta");
	}

	return valorPedido;
}

template<class T>

void lista<T>::vaciarLista(){
	this->cantNodos=0;
	this->primerNodo=NULL;
	this->sigLista=NULL;
}

template<class T>

bool lista<T>::validarCantLista(int pos){

	return (pos>0 && pos <= obtenerCantNodos()+1);
}


template<class T>

lista<T>::~lista(){

	while(this->primerNodo != NULL){
		nodo<T>* nodoBorrar = this->primerNodo;
		primerNodo = primerNodo->obtenerSig();
		delete nodoBorrar;
	}

}



#endif /* LISTA_H_ */
