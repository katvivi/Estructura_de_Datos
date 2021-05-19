#include <iostream> 
#include <stdlib.h>
using namespace std;

int const dimension= 8; 
typedef  int TamanioArreglo[dimension];

void ordenarElementos(TamanioArreglo);
int main(){
int miArreglo[]={14,5,43,39,24,84,65,45};
for(int i=0;i<dimension;i++){
	cout << miArreglo[i] << endl;
}
	ordenarElementos(miArreglo);
}

void ordenarElementos(TamanioArreglo miArreglo){
int n;
int fila,pos,pasadas,aux;
pasadas=0;
    for (int fila  = 0;fila < dimension; fila++){
		n=fila; 
		aux=miArreglo[fila];
        while((pos>0)&&(miArreglo[n-1]>aux)){
			miArreglo[n]=miArreglo[n-1];
			n--;
        	pasadas++;
		}
		miArreglo[n]=aux;
	}
cout<<"Numero de comparaciones"<<pasadas*4<<endl;
int contador;
cout << "Elementos del Arreglo Ordenado" << endl;
for (int contador = 0; contador < dimension; contador++) 
	cout << miArreglo[contador] << endl;
}

