/*
 * gen.h
 *
 *  Created on: Dec 10, 2020
 *      Author: aron
 */

#ifndef GEN_H_
#define GEN_H_

#include "informacionGenetica.h"

class gen{

	private:

	unsigned int edad;
	informacionGenetica<int>* infoGenetica;
	unsigned int intensidadGenetica;


	public:
	//pos : crea un nuevo gen con informacion genetica 0 y intenciadad genetica 0
	gen ();
	//pos : cra un nuevo gen con informacion genetica igual a 'nuevaInfo' y intensidadGenetica igual a 'intensidadGenetica'
	gen(informacionGenetica<int>* nuevaInfo,unsigned int intensidadGenetica);
	//pos :cambia la informacion genetica por la ingresada por parametro
	void cambiarInfoGenetica(informacionGenetica<int>* nuevaInformacion);
	//pos : obtien informacion genetica
	informacionGenetica<int>* obtenerInfoGenetica();
	//pos : puede asignar o cambiar informacion genetica
	void asignarIntensidadGenetica(unsigned int intensidadGenetica);
	//pos : aumenta la edad
	void aumentarEdad();
	//pos :obtiene la edad
	unsigned int obtenerEdad();
	//pos :obtiene la intensidad genetica
	unsigned int obtenerIntensidadGentica();
	//pos : valida si un gen es igual a otro
	bool esIgual(gen* nuevoGen);


};


#endif /* GEN_H_ */
