/*Materia: Estructuras de Datos
Tema: MEMORIA ESTATICA-Ingresa los datos por codigo*/
#include <iostream>
#include <stdlib.h>
#define TAMANIO 100

using namespace std;

typedef struct Pila{
       int tope;        
       int elementosPila[TAMANIO];
}Pila;

void PushElemento(Pila*pila, int valorDato);
int PopElemento(Pila*pilaTemporal);
int LlenarPila(Pila pila);
int VaciarPila(Pila pila);
void ImprimirElemento(Pila *pila);

int main(){	
	Pila pila={1,9};//Dato ingresado por codigo
	PushElemento(&pila,8);//Dato ingresado por codigo
	PushElemento(&pila,4);	//Dato ingresado por codigo
	ImprimirElemento(&pila);
}
void PushElemento(Pila*pila, int valorDato){
	Pila *pilaTemporal = pila;
	pilaTemporal->tope++;
	pila->elementosPila[pilaTemporal->tope]=valorDato;
}
int PopElemento(Pila*pilaTemporal){
	int valorDato;
	valorDato=pilaTemporal->elementosPila[pilaTemporal->tope];
	pilaTemporal->tope--;
	return valorDato;
}
int LlenarPila(Pila *pila){
	int bandera=0;
	if(sizeof(pila->tope)==TAMANIO-1){
		bandera =1;
	}
	return bandera;
}
int VaciarPila(Pila *pila){
	int bandera =0;
	if (sizeof(pila->tope)==-1){
		bandera =1;
	}
	return 0;
}
void ImprimirElemento(Pila *pila){
	if(pila->tope){
		for(int i=pila->tope;i>=1;i--){
		    cout<<" "<<pila->elementosPila[i]<<endl;
		}			
	}
}
