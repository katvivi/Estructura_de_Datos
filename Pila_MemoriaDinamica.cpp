/*Materia: Estructuras de Datos
Tema: MEMORIA DINAMICA*/
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct pila {
	int valorDato;
	struct pila *siguiente;
}Pila;

typedef Pila *PilaPuntero;

void PushElemento(PilaPuntero *tope, int valorDato);
int  PopElemento(PilaPuntero *tope);
void ImprimirElemento (PilaPuntero*tope);

int main(){
	PilaPuntero tope = NULL;
	PushElemento(&tope,1);
	PushElemento(&tope,9);
	PushElemento(&tope,8);
	PushElemento(&tope,4);
	ImprimirElemento(&tope);
}

void PushElemento(PilaPuntero *tope,int valorDato){
	PilaPuntero nuevoDato;
	//Reservar memoria dinamica
	nuevoDato=(PilaPuntero)malloc(sizeof(Pila));
	
	if (nuevoDato==NULL){
		cout<<"NO EXISTE MEMORIA"<<endl;
	}else{
		nuevoDato->valorDato = valorDato;
		nuevoDato->siguiente = *tope;
		*tope = nuevoDato;	
	}
}
int PopElemento(PilaPuntero *tope){
	PilaPuntero temporal;
	int elemento_a_Eliminar;
	temporal = *tope;
	elemento_a_Eliminar = temporal->valorDato;
	*tope = (*tope)->siguiente;
	free(temporal);
	
	//return elemento_a_Eliminar;
}
void ImprimirElemento(PilaPuntero *tope){
	PilaPuntero auxiliar;
	while(auxiliar!=NULL){
		cout<<auxiliar->valorDato<<endl;
		auxiliar=auxiliar->siguiente;
	}
}
