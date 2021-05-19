#include <iostream> 
#include<stdlib.h>
using namespace std;

void ordenamientoInterno(int arreglo[],int n);

int main(){
	int i,x=10;
	int arreglo[x];
	int valorMax=100;
	
	for(i=0;i<=x-1;i++){
		arreglo[i] = valorMax;
		valorMax--;
	}
	cout<<"Desordenado: "<<endl;
	for(i=0;i<=x-1;i++){
		cout<<"  "<<arreglo[i];
	}
	ordenamientoInterno(arreglo,x);
	cout<<"\nOrdenado"<<endl;
	for(i=0;i<=x-1;i++){
		cout<< " "<<arreglo[i];
	}
	return 0;
}

void ordenamientoInterno(int arreglo[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>=i+1;j--){
			if(arreglo[j]<arreglo[j-1]){
				temp = arreglo[j];
				arreglo[j]=arreglo[j-1];
				arreglo[j-1]=temp;
			}
		}
	}
}
