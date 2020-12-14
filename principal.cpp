/*
 * principal.cpp
 *
 *  Created on: Dec 2, 2020
 *      Author: aron
 */



#include<iostream>
#include "lista.h"
#include "informacionGenetica.h"
#include "listaLista.h"
#include "celula.h"
#include "gen.h"
using namespace std;
#include "cola.h"
int main(){
	try{
		listaLista<celula*> matriz;
		int cantFilas,cantColumnas;
		int  fila,columna;
		string infoGeneticaIngresada;
		unsigned int intensidadGenetica;
		int cantCelulasPositicas;

		cout<<"ingrese cant de filas: "<<endl;
		cin>>cantFilas;

		cout<<"ingrese cant de columnas "<<endl;
		cin>>cantColumnas;





		//todos los elementos de la lista comienzan con celulas negativas

		for(int i=1;i<=cantFilas;i++){

			lista<celula*>* fila= new lista<celula*>();

			for(int j=1;j<= cantColumnas;j++){

				celula* celulaIngresar= new celula();

				fila->agregarFinal(new nodo<celula*>(celulaIngresar));

			}

			matriz.agregarLista(fila);

		}



		cout<<"ingrese la cantidad de celulas positivas a ingresar"<<endl;
		cin>>cantCelulasPositicas;



		for (int i=0;i<cantCelulasPositicas;i++){

			cout<<"ingrese fila en la que desee ingresar celulas pisitivas"<<endl;
			cin>>fila;

			cout<<"ingrese columna en la que desee ingresar celulas pisitivas"<<endl;
			cin>>columna;







			cout << "ingrese informacion genetica (combinacion de 1 y 0) : "<<endl;
			cin >> infoGeneticaIngresada;

			cout << "ingrese intensidad genetica (numero entre 0 y 100): "<<endl;
			cin >> intensidadGenetica;

			informacionGenetica<int>* infoIngresada = new informacionGenetica<int>(infoGeneticaIngresada);
			gen* genIngresar= new gen(infoIngresada ,intensidadGenetica);
			celula* celulaIndicada=new celula(1,genIngresar);


			lista<celula*>* filaIndicada = matriz.obtenerLista(fila);
			filaIndicada->obtenerNodo(columna)->cambiarValorNodo(celulaIndicada);

		}

		cout<<matriz.cantidadDeVecinosVivos(1,1) <<endl;
		cout<<matriz.cantidadDeVecinosVivos(1,2) <<endl;
		cout<<matriz.cantidadDeVecinosVivos(2,1) <<endl;



		cout<<"termino"<<endl;
	}


	catch(...){
		cout<<"error xD"<<endl;
	}



	return 0;
}
