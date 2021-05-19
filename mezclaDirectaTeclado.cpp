#include <iostream>
#include <cstdlib>
#define T 100
using namespace std;

int numElementos, contador, opcion,salir;
int arregloOriginal[T];
void ingresarArreglo();
void imprimirArreglo(int arregloOriginal[T],int ini,int numElementos);
void ordenarElementos(int *A,int numElementos);
void mezclaDirecta(int *f1,int arreglo1,int *f2,int arreglo2,int *A);

int main(){
	
	cout<<"\n\tALGORITMO MEZCLA DIRECTA  \n"<<endl;
	do{	
		cout<<"\n\t----MENU----"<<endl;
		cout<<"1. Ingresar el Arreglo"<<endl;
		cout<<"2. Ordenar y comprobar"<<endl;
		cout<<"0. Salir"<<endl;	
		cout<<"Ingrese su opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: 
				ingresarArreglo();
				break;			
			case 2:
				ordenarElementos(arregloOriginal,numElementos);
				cout<<"\n\nARREGLO ORDENADO: \n";
				imprimirArreglo(arregloOriginal,0,numElementos);
				system("PAUSE");
				system("CLS");
				break;	
		}	
	}while(opcion!=0);
	
}

void ingresarArreglo(){
	cout<<"Ingrese la dimension del arreglo: ";
	cin>>numElementos;
	cout<<endl;
	arregloOriginal[numElementos];
	for(contador=0; contador<numElementos; contador++){
		cout<<"Ingrese el valor del elemento "<<contador<<": ";
		cin>>arregloOriginal[contador];
	}
	cout<<"\n\nARREGLO ORIGINAL: \n";
	imprimirArreglo(arregloOriginal,0,numElementos);
}

void imprimirArreglo(int arregloOriginal[T],int ini,int numElementos){
	for(int i=ini;i<numElementos;i++)
  	cout<<arregloOriginal[i]<<" ";
 	cout<<endl;
}

void ordenarElementos(int *A,int numElementos){
	if(numElementos==1){return;}
 	int mitad = numElementos / 2;
 	int *f1 = new int[mitad];
 	int *f2 = new int[numElementos-mitad];
 	for(int i=0;i<mitad;i++){
 		f1[i] = A[i];
	}
 	for(int i=mitad;i<numElementos;i++){
 		f2[i-mitad] = A[i];
	}
  	
 	ordenarElementos(f1, mitad);
 	ordenarElementos(f2, numElementos-mitad);
 	mezclaDirecta(f1, mitad, f2, numElementos-mitad, A);	
}

void mezclaDirecta(int *f1,int arreglo1,int *f2,int arreglo2,int *A){
	int i=0,j=0,k=0;
	while( ( i < arreglo1 ) && ( j < arreglo2 ) ){
		if( f1[i] <= f2[j]){
			A[k] = f1[i];
			i++;
		}else
		{
		A[k] = f2[j];
   		j++;
  		}
  		k++;
 	}
 	while(i < arreglo1){
  		A[k] = f1[i];
  		i++;k++;
	}
 	while(j < arreglo2){
  		A[k] = f2[j];
  		j++;k++;
 	}
}

