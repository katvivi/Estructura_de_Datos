#include <iostream> 
#include<stdlib.h>
using namespace std;

void quicksort(int lista[] ,int inferior, int superior  );

int main(){
	
	int lista[]={92,25,55,34,49,41,12,45,60,18,53,39,23,79,96,87,29,49,37,66,49,93,95,97,16,86,5,88,82,55,34,1,41,16,71,86,63,13,55,85,53,12,8,32,45,13,56,21,58,46,82,81,44,96,22,29,61,35,50,73,66,44,59,92,39,53,24,54,10,45,49,86,13,74,22,68,18,87,5,58,91,2,25,77,14,14,24,34,74,72,59,33,70,87,97,18,77,73,70,63,68};
	int contador,numElementos;
	
	numElementos=sizeof(lista)/sizeof(int);
	cout<<"\n\n VECTOR ORIGINAL: \n-----------\n";
	for(contador=0;contador<numElementos;contador++)
		cout <<"   "<<lista[contador] << endl;
		quicksort(lista,0,numElementos-1);
		cout<<"\n\n VECTOR ORDENADO EN FORMA ASCENDENTE : \n";
		cout<<"---------------------\n";
		
		for (contador=0;contador<numElementos;contador++)
			cout <<"   "<<lista[contador] << endl;
	
}

void quicksort(int lista[] ,int inferior, int superior){
	
	int pivote,elemento,izquierda,derecha;
	izquierda=inferior;
	derecha=superior;
	pivote=lista[(izquierda+derecha)/2];
	
	do {
		 while (lista[izquierda]<pivote && izquierda<superior)
		 	izquierda++;
		 while (pivote<lista[derecha] && derecha>inferior)
		 	derecha--;
		 
		 	if (izquierda<=derecha){
		 		elemento=lista[izquierda];
		 		lista[izquierda]=lista[derecha];
		 		lista[derecha]=elemento;
		 		izquierda++;
		 		derecha--;
		 	}
		 
	}while(izquierda<=derecha);
	
	if(inferior<derecha)
		quicksort(lista,inferior,derecha);//igual proceso con sub lista izquierda
			
	if(izquierda<superior)
		quicksort(lista,izquierda,superior);//igual proceso con sub lista derecha
}

