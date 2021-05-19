#include <iostream> 
using namespace std;
#include<stdlib.h>
int const DIMENSION= 10; 
typedef  float TamanioArreglo[DIMENSION];

void ingresarElementosArreglo(TamanioArreglo);
void ordenarElementosArreglo(TamanioArreglo);
void mostrarArreglo(const TamanioArreglo);

int main(){
	char opc;
	TamanioArreglo miArreglo;
	do{
	ingresarElementosArreglo(miArreglo);
    ordenarElementosArreglo(miArreglo);
    mostrarArreglo(miArreglo);	
    cout<<"desea volver a ingresar[s/n]:\t";
    cin>>opc;
    system("cls");
	}while(opc=='s'||opc=='S');
	cout<<"Gracias por utilizar nuetro software buena tarde ";
	return 0;
}

void ingresarElementosArreglo(TamanioArreglo miArreglo){
	int contador;
	cout << "Ingresar los 10 elementos " << endl;
	
	for (int contador = 0; contador < DIMENSION; contador++){ 
		cin >> miArreglo[contador];
	}
}

void ordenarElementosArreglo(TamanioArreglo miArreglo){
	float temporal;
	int fila,columna;
	for (int fila = 0;fila < DIMENSION; fila++){
		for (int columna = 0; columna< DIMENSION-1; columna++){
			if (miArreglo[columna] < miArreglo[columna+1]){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
			temporal = miArreglo[columna]; 
			miArreglo[columna] = miArreglo[columna+1]; 
			miArreglo[columna+1] = temporal;
			}
		}
	}
}

void mostrarArreglo(const TamanioArreglo miArreglo){
	int contador;
	cout << "Elementos del Arreglo Ordenado" << endl;
	for (int contador = 0; contador < DIMENSION; contador++) // Imprime las 10 posiciones
		cout << miArreglo[contador] << endl;
}
