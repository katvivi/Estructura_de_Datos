#include <iostream> 
#include<stdlib.h>
using namespace std;

int const DIMENSION = 10; 
typedef  float TamanioArreglo[DIMENSION];

int menu();
void ingresarElementosArreglo(TamanioArreglo);
void ordenarElementosDelArreglo(TamanioArreglo);
void mostrarArreglo(const TamanioArreglo);

int main(){
	int elegir;
	TamanioArreglo miArreglo;
	
	do
	{
		elegir = menu();
		switch(elegir)
	    {
	    	case 1:
	    	{
	    		ingresarElementosArreglo(miArreglo);
	    		system("PAUSE");
				system("CLS");
	    		
			}break;
			case 2:
	    	{
	    		ordenarElementosDelArreglo(miArreglo);
	    		system("PAUSE");
		        system("CLS");
				
			}break;
			case 3:
	    	{
				mostrarArreglo(miArreglo);    	
				system("PAUSE");
		        system("CLS");
			}break;
			default:
		    {
		    	cout<<endl<<endl;
		    	cout<<"\n\t**¡ Hasta pronto !**";
			}break;
		}		
		
	}while(elegir<4);
}

int menu(){
	int elegir;
	do
	{
		cout<<"\t\t**METODO BURBUJA**"<<endl<<endl;
		cout<<"\t\tMenu Principal"<<endl;
		cout<<"\t1.- Ingresar Elementos al Arreglo"<<endl;
		cout<<"\t2.- Ordenar Elementos del Arreglo"<<endl;
		cout<<"\t3.- Mostrar Elementos del Arreglo"<<endl;
		cout<<"\t4.- Salir"<<endl;
		cout<<"\n\t\tDigite una opcion: ";
		cin>>elegir;
	}while(elegir<1 or elegir>4);
 return elegir;
}
void ingresarElementosArreglo(TamanioArreglo miArreglo){
	int contador;
	cout <<"\n\tIngrese los 10 elementos del arreglo " << endl;
	for (int contador = 0; contador<DIMENSION; contador++){ 
		cin >> miArreglo[contador];
	}
}

void ordenarElementosDelArreglo(TamanioArreglo miArreglo){
	float temporal;
	int fila,columna;
	for (int fila = 0; fila<DIMENSION; fila++){
		for (int columna = 0; columna< DIMENSION-1; columna++){
			if (miArreglo[columna] < miArreglo[columna+1]){ 
				temporal = miArreglo[columna]; 
				miArreglo[columna] = miArreglo[columna+1]; 
				miArreglo[columna+1] = temporal;
			}
		}
	}
	cout<<"\t**Arreglo Ordenado Exitosamente**"<<endl;
}

void mostrarArreglo(const TamanioArreglo miArreglo){
	int contador;
	cout <<"\n\tElementos del Arreglo Ordenado" << endl;
	for (int contador = 0; contador < DIMENSION; contador++) {
		cout <<"\t\t\t"<<miArreglo[contador] << endl;
	}	
}
