#include <stdio.h>
#include <iostream>
#define TAMANIO 100

using namespace std;

//Variables
int numElementos, contador, opcion;
//Arreglos y matrices
int arreglo[TAMANIO], matriz[TAMANIO][TAMANIO];
//Funciones
void ingresarDatos(), imprimirArreglo(), radix();


int main(){
	char salir;
	cout<<"\n\tAlgoritmo de ordenamiento interna - RADIX\n"<<endl;
	do{	
		cout<<"\n\t----MENU----"<<endl;
		cout<<"1. Ingresar el Algoritmo"<<endl;
		cout<<"2. Ordenar y comprobar"<<endl;
		cout<<"0. Salir"<<endl;	
		cout<<"Ingrese su opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: 
				ingresarDatos();
				break;			
			case 2:
				radix();
				break;
			default:
		    {
		    	do{  
					cout<<"Desea ingresar un nuevo algoritmo (s/n)?:";
       				cin>>salir;
     				ingresarDatos();
  				}while((salir != 's') || (salir != 'S'));
  				cout<<"\n\t\t--Gracias por usar el programa--"<<endl;
			}break;
				
		}	
	}while(opcion!=0);
			
		
}

void ingresarDatos() {
	cout<<"Ingrese la dimencion de elementos: ";
	cin>>numElementos;
	cout<<endl;
	arreglo[numElementos];
	for(contador=0; contador<numElementos; contador++){
		cout<<"Ingrese el valor del elemento "<<contador+1<<": ";
		cin>>arreglo[contador];
	}
	imprimirArreglo();
}

void imprimirArreglo() {

	cout<<"\n---------------------------"<<endl;
	for(contador=0; contador<numElementos;contador++) {
		cout<<"\t"<<contador+1<<". "<<arreglo[contador]<<"\n";
	}
	cout<<"---------------------------"<<endl;
	
	/*for(i=0;i<;i++){
        for(j=0; j<0; j++){
    		cout<<matriz[i][j]<<endl;
	    }
	}*/
}

//La variable areglo[] indica el arreglo a clasificar 
//n es el  numero de datos que tiene el arreglo[].

void radix(){
	matriz[10][21];  
	int indice,k,i,divisor,j,temporal,residuo,m;
	
	for(j=0;j<10;j++){
		matriz[j][0] = 1;
	}
	divisor = 1;
	for(i=0;i<6;i++){
        for(j=0; j<numElementos; j++){
			temporal = arreglo[j];
			temporal = temporal / divisor;
			residuo = temporal%10;
			indice = matriz[residuo][0];
			matriz[residuo][indice] = arreglo[j];
			indice = indice+1;
			matriz[residuo][0] = indice;
		}
		m=0;
		for(k=0; k<10; k++){
	       	indice = matriz[k][0]-1;
			for(j=1; j<=indice; j++ ){
		     	arreglo[m] = matriz[k][j];
		    	m = m+1;
			}
		}
		divisor = divisor*10;
		for(j=0; j<10; j++){
			matriz[j][0] = 1;
		}
    }
    imprimirArreglo();
}

