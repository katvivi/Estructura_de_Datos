#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int i=1,j;
	char opcion;
	do{ 
		cout<<"\n\tMaquinas: ";
		cin>>i;
		cout<<"\n\tNumeros de serie de palas cargadoras"<<endl;

		while(i!=63287){
			cout<<"\t|"<<i<<"|";
			if(i==78345){
				cout<<"\n\tNumero de serie de retroexcavadoras"<<endl;
			}
			if(i==33287){
				cout<<"\n\tNumero de serie de dumpers"<<endl;
			}
			j++;
			cin>>i;
		}
		cout<<"\t|"<<i<<"|";
		cout<<"\n\tFinalizada la extraccion desde el archivo"<<j;
		cout<<"\n\tDesea continuar? (s/n): ";
    	cin>>opcion;
    	system("CLS");
	}while(opcion=='s');
	cout<<"\n\tInformacion de maquinas completado con exito"<<endl;
}
