/*
 * celula.h
 *
 *  Created on: Dec 9, 2020
 *      Author: aron
 */

#ifndef CELULA_H_
#define CELULA_H_


#include "lista.h"
#include "gen.h"



class celula{

	private:

	unsigned int estadoCelula;

	lista <gen* >* genesContenidos;

	public:
	//pos : crea una nueva celula con el estado muerto y primer gen desactivado
	celula();
	//pos : crea una celula con el estada ingresado por parametro y el gen ingresado por parametro tambien
	celula(unsigned int estadoCelula,gen* primerGen);
	//pos : cambia el estado de la celula
	void cambiarEstadoCelula(unsigned int nuevoEstadoDeCelula);
	//pos : agrega un nuevo gen
	void agregarNuevoGen(gen* nuevoGen);
	//pos : obtiene el estado de la celula
	unsigned int obtenerEstadoCelula();
	//pos :obtiene la lista de genes que contiene la celula
	lista<gen*>* obtenerListaDeGenes();

	//pos : libera memoria
	~celula();


};




#endif /* CELULA_H_ */
