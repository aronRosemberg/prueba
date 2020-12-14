/*
 * gen.cpp
 *
 *  Created on: Dec 10, 2020
 *      Author: aron
 */


#include "gen.h"

gen::gen(){
	this->edad=0;
	this->intensidadGenetica=0;
	this->infoGenetica=NULL;


}

gen::gen(informacionGenetica<int>* nuevaInfo,unsigned int intensidadGenetica){

	this->edad=0;
	this->intensidadGenetica=intensidadGenetica;
	this->infoGenetica=nuevaInfo;

}

void gen::cambiarInfoGenetica(informacionGenetica<int>* nuevaInformacion){

	this->infoGenetica=nuevaInformacion;
}

informacionGenetica<int>* gen::obtenerInfoGenetica(){

	return this->infoGenetica;
}

void gen::asignarIntensidadGenetica(unsigned int intensidadGenetica){

	this->intensidadGenetica=intensidadGenetica;
}


unsigned int gen::obtenerEdad(){

	return this->edad;
}

void gen::aumentarEdad(){

	this->edad=this->edad + 1 ;

}

unsigned int gen::obtenerIntensidadGentica(){

	this->intensidadGenetica;
}

bool gen::esIgual(gen* nuevoGen){

	return this->infoGenetica->esIgual(nuevoGen->infoGenetica);
}



