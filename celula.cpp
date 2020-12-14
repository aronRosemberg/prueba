/*
 * celula.cpp
 *
 *  Created on: Dec 10, 2020
 *      Author: aron
 */

#include "celula.h"



celula::celula(){

	this->estadoCelula=0;
	this->genesContenidos=NULL;

}

celula::celula(unsigned int estadoCelula,gen* primerGen){

	this->estadoCelula=estadoCelula;
	this->genesContenidos=new lista<gen*>();
	genesContenidos->agregarFinal(new nodo<gen*>(primerGen));
}


void celula::cambiarEstadoCelula(unsigned int nuevoEstadoDeCelula){

	this->estadoCelula=nuevoEstadoDeCelula;

}

void celula::agregarNuevoGen(gen* nuevoGen){

	this->genesContenidos->agregarFinal(new nodo<gen*> (nuevoGen));

}

unsigned int celula::obtenerEstadoCelula(){

	return this->estadoCelula;
}

lista<gen*>* celula::obtenerListaDeGenes(){


	return this->genesContenidos;
}

celula::~celula(){

	delete this->genesContenidos;

}
