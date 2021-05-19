#include <iostream>
#include <cstdlib>
using namespace std;

void imprimirArreglo(int x[],int ini,int numElementos);
void ordenarElementos(int *auxiliar,int numElementos);
void mezclaDirecta(int *f1,int arreglo1,int *f2,int arreglo2,int *auxiliar);

int main(){
 	int arregloOriginal[] = {92,25,55,34,49,41,12,45,60,18,53,39,23,79,96,87,29,49,37,66,49,93,95,97,16,86,5,88,82,55,34,1,41,16,71,86,63,13,55,85,53,12,8,32,45,13,56,21,58,46,82,81,44,96,22,29,61,35,50,73,66,44,59,92,39,53,24,54,10,45,49,86,13,74,22,68,18,87,5,58,91,2,25,77,14,14,24,34,74,72,59,33,70,87,97,18,77,73,70,63,68};
 	int numElementos = sizeof(arregloOriginal) / sizeof(int);
 
 	cout<<"\n\nARREGLO ORIGINAL: \n";
 	imprimirArreglo( arregloOriginal,0,numElementos);
 	ordenarElementos( arregloOriginal,numElementos);
 	cout<<"\n\nARREGLO ORDENADO: \n";
 	imprimirArreglo(arregloOriginal,0,numElementos);
 	return 0;
}

void imprimirArreglo(int x[],int ini,int numElementos){
	for(int i=ini;i<numElementos;i++)
  	cout<<x[i]<<" ";
 	cout<<endl;
}

void ordenarElementos(int *auxiliar,int numElementos){
	if(numElementos==1){return;}
 	int mitad = numElementos / 2;
 	int *f1 = new int[mitad];
 	int *f2 = new int[numElementos-mitad];
 	for(int i=0;i<mitad;i++){
 		f1[i] = auxiliar[i];
	}
 	for(int i=mitad;i<numElementos;i++){
 		f2[i-mitad] = auxiliar[i];
	}
  	
 	ordenarElementos(f1, mitad);
 	ordenarElementos(f2, numElementos-mitad);
 	mezclaDirecta(f1, mitad, f2, numElementos-mitad, auxiliar);
}

void mezclaDirecta(int *f1,int arreglo1,int *f2,int arreglo2,int *auxiliar){
	int i=0,j=0,k=0;
	while( ( i < arreglo1 ) && ( j < arreglo2 ) ){
		if( f1[i] <= f2[j]){
			auxiliar[k] = f1[i];
			i++;
		}else
		{
		auxiliar[k] = f2[j];
   		j++;
  		}
  		k++;
 	}
 	while(i < arreglo1){
  		auxiliar[k] = f1[i];
  		i++;k++;
	}
 	while(j < arreglo2){
  		auxiliar[k] = f2[j];
  		j++;k++;
 	}
}
