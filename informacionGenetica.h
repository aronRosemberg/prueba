/*
 * informacionGenetica.h
 *
 *  Created on: Dec 7, 2020
 *      Author: aron
 */

#ifndef INFORMACIONGENETICA_H_
#define INFORMACIONGENETICA_H_
#include<string>
#include "nodo.h"

template<class T>

class informacionGenetica{

	private :

	nodo<T>* ultimoBit;
	unsigned int cantBits;

	public:
	//pos : asigna informacion genetica el valor ingresado por parametro
	informacionGenetica(std::string bits);
	//pos : asigna el valor 0 a la informacion genetica
	informacionGenetica();
	//pos :obtiene el bit asignado en la posicion , comenzando desde el final
	nodo<T>* obtenerNodo(unsigned int pos);
	//pos : obtiene el ultimo bit
	nodo<T>* obtenerUltimoNodo();
	//pos : devuelve si la informacion genetica es igual a la ingresada por parametro
	bool esIgual(informacionGenetica<T>* otra);
	//pos :combia la informacion genetica con otra informacion genetica
	void convinarCon(informacionGenetica<T>* otra);
	//pos : indica si el bit en la posicion indicada por parametro esta encendida , comenzando por el final
	bool estaEncendidoBit(unsigned int i);
	//pos : devuelve la cantidad de bits que posee informacion genetica
	unsigned int contarBits();
	//pos : libera memoria dinamica
	~informacionGenetica();

};


template<class T>

informacionGenetica<T>::informacionGenetica(std::string bits){

	this->ultimoBit=NULL;
	this->cantBits=0;

	int valor;
	for(unsigned int i=0; i< bits.size() ;i++){

		if(bits[i]== '1'){
			valor=1;
		}else{
			if(bits[i]== '0'){
				valor=0;
			}
			else{
				throw std::string("no se ingreso secuencia de 0 y 1 ");
			}
		}


		nodo<T>* colocarBits=new nodo<T>(valor);

		colocarBits->cambiarSig(ultimoBit);

		ultimoBit=colocarBits;
		cantBits++;
	}

}
template<class T>

informacionGenetica<T>::informacionGenetica(){

	this->ultimoBit=new nodo<T>(0);
	this->cantBits=1;

}

template<class T>

nodo<T>* informacionGenetica<T>::obtenerNodo(unsigned int pos){




	if(1 <= pos &&  pos <= this->cantBits){

		nodo<T>* nodoRecorredor=this->ultimoBit;

		for(unsigned int i=1;i < pos;i++){

			nodoRecorredor= nodoRecorredor->obtenerSig();

		}

		return nodoRecorredor;

	}
	else{
		throw std::string("error");
	}


}

template<class T>

nodo<T>* informacionGenetica<T>::obtenerUltimoNodo(){

	return ultimoBit;
}

template<class T>

bool informacionGenetica<T>::esIgual(informacionGenetica<T>* otra){

	bool sonIguales;

	if(this->contarBits() == otra->contarBits()){
		sonIguales=true;
		for(unsigned int i=1 ; i < contarBits() ; i++){
			if(this->estaEncendidoBit(i)){
				if(!otra->estaEncendidoBit(i)){
					sonIguales=false;
				}
			}else{
				if(otra->estaEncendidoBit(i)){
					sonIguales=false;
				}
			}
		}
	}else{
		sonIguales=false;
	}

	return sonIguales;


}

template<class T>

void informacionGenetica<T>::convinarCon(informacionGenetica<T>* otra){
	nodo<T>* recorre1=this->ultimoBit;
	nodo<T>* recorre2=otra->ultimoBit;
	unsigned int i=1;
	while(recorre1 != NULL && recorre2 != NULL  ){
		if(this->estaEncendidoBit(i)){
			if(otra->estaEncendidoBit(i)){
				recorre1->cambiarValorNodo(0);
			}
			else{
				recorre1->cambiarValorNodo(1);
			}


		}else{
			if(otra->estaEncendidoBit(i)){
				recorre1->cambiarValorNodo(1);
			}
			else{
				recorre1->cambiarValorNodo(0);
			}
		}
		recorre1=recorre1->obtenerSig();
		recorre2=recorre2->obtenerSig();
		i++;
	}


	while(recorre2 != NULL){

		if(otra->estaEncendidoBit(i)){


			nodo<T>* nodoFinal = this->obtenerNodo(this->contarBits());
			nodoFinal->cambiarSig(new nodo<T>(1));
		}
		else{
			nodo<T>* nodoFinal = this->obtenerNodo(this->contarBits());
			nodoFinal->cambiarSig(new nodo<T>(0));
		}
		this->cantBits++;
		recorre2=recorre2->obtenerSig();

		i++;

	}



}

template<class T>

bool informacionGenetica<T>::estaEncendidoBit(unsigned int pos){

	T valor;
	nodo<T>* nodoBuscado = this->obtenerNodo(pos);
	valor= nodoBuscado->obtenerValor();

	return valor == 1;
}

template<class T>

unsigned int informacionGenetica<T>::contarBits(){

	return this->cantBits;
}

template<class T>

informacionGenetica<T>::~informacionGenetica(){

	while( this->ultimoBit != NULL){
		nodo<T>* nodoBorrar=this->ultimoBit;
		this->ultimoBit=this->ultimoBit->obtenerSig();
		delete nodoBorrar;

	}
}

#endif /* INFORMACIONGENETICA_H_ */
