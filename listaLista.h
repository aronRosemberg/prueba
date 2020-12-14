/*
 * listaLista.h
 *
 *  Created on: Dec 5, 2020
 *      Author: aron
 */

#ifndef LISTALISTA_H_
#define LISTALISTA_H_

#include "lista.h"

template<class T>

class listaLista{

	private :
	int cantListas;
	lista<T>* primeraLista;

	public :
	//pos : inicializa una lista de lista con 0 elementos
	listaLista();
	//pos : obtiene un puntero a la primera lista
	lista<T>* obtenerPrimeraLista();
	//pos :obtiene la lista de la posicion ingresada por parametro
	lista<T>* obtenerLista(int i);
	//pos :obtien cantidad de ekementos en la lista
	int obtenerCantLista();
	//pos :agrega una nueva lista ingresada por parametro

	void agregarLista(lista<T>* nuevaLista);
	//pos: analiza veninos y devuelve la cantidad de vecinos vivos
	int cantidadDeVecinosVivos(int posf,int posc);
	//pos : libera memoria dinamica
	~listaLista();

};

template<class T>

listaLista<T>::listaLista(){

	this->cantListas=0;
	this->primeraLista=NULL;
}

template<class T>

lista<T>* listaLista<T>::obtenerPrimeraLista(){
	return this->primeraLista;
}

template<class T>

lista<T>* listaLista<T>::obtenerLista(int pos){

	lista<T>* listaSolicitada=obtenerPrimeraLista();

	if(pos>0 && pos<=this->obtenerCantLista()){
		for(int i=1;i<pos;i++){
			listaSolicitada = listaSolicitada->obtenerSigLista();
		}

	}
	else{

		throw std::string ("anda mal");
	}

	return listaSolicitada;
}

template<class T>

int listaLista<T>::obtenerCantLista(){
	return this->cantListas;
}

template<class T>

void listaLista<T>::agregarLista(lista<T>* nuevaLista){

	if(this->primeraLista==NULL){
		this->primeraLista=nuevaLista;
	}else{
		lista<T>* listaAnterior=obtenerLista(this->obtenerCantLista());
		listaAnterior->asignarNuevaLista(nuevaLista);

	}
	this->cantListas++;
}

template<class T>

int listaLista<T>::cantidadDeVecinosVivos(int posf,int posc){


	int vecinos =0;
	int cantidadDeColumnas=this->primeraLista->obtenerCantNodos();
	int cantidadDefilas=this->obtenerCantLista();

	if(posf-1 >= 1 && posc-1 >= 1){
		if(this->obtenerLista(posf-1)->obtenerNodo(posc-1)->obtenerValor()->obtenerEstadoCelula()== 1 ){
			vecinos++;
		}
	}
	if(posf-1 >= 1){

		if(this->obtenerLista(posf-1)->obtenerNodo(posc)->obtenerValor()->obtenerEstadoCelula()==1){
			vecinos++;

		}
	}
	if(posf-1 >=1 && posc+1 <=  cantidadDeColumnas){

		if(this->obtenerLista(posf-1)->obtenerNodo(posc+1)->obtenerValor()->obtenerEstadoCelula()==1){
			vecinos++;
		}

	}
	if(posc-1 >= 1){

		if(this->obtenerLista(posf)->obtenerNodo(posc-1)->obtenerValor()->obtenerEstadoCelula()==1){
			vecinos++;
		}
	}
	if(posc+1 <=  cantidadDeColumnas){
		if(this->obtenerLista(posf)->obtenerNodo(posc+1)->obtenerValor()->obtenerEstadoCelula()==1){
			vecinos ++;
		}
	}
	if(posf+1 <=  cantidadDefilas && posc-1 >=1){
		if(this->obtenerLista(posf+1)->obtenerNodo(posc-1)->obtenerValor()->obtenerEstadoCelula()==1){
			vecinos ++;
		}
	}
	if(posf+1 <= cantidadDefilas){
		if(this->obtenerLista(posf+1)->obtenerNodo(posc)->obtenerValor()->obtenerEstadoCelula()==1){
			vecinos ++;
		}
	}
	if(posf+1 <=cantidadDefilas && posc+1 <= cantidadDeColumnas){
		if(this->obtenerLista(posf+1)->obtenerNodo(posc+1)->obtenerValor()->obtenerEstadoCelula()==1){
			vecinos ++;
		}
	}

	return vecinos;



}


template<class T>

listaLista<T>::~listaLista(){


	while(this->primeraLista != NULL){
		lista<T>* listaEliminar=this->primeraLista;

		this->primeraLista = listaEliminar->obtenerSigLista();
		delete listaEliminar;
	}


}




#endif /* LISTALISTA_H_ */
