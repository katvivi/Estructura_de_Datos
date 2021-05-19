#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class Binaria{
	int arreglo[15];
public: 
	Binaria(int arreglo[]);
	~Binaria(){	
	}
	int busqueBinaria(int izq,int der, int llave){
        int posicion;
        if(izq>der)
            return -1;
        posicion=(izq+der)/2;
        if(llave==arreglo[posicion])
            return posicion;
        else if(llave<arreglo[posicion])
            return busqueBinaria(izq,posicion-1,llave);
        else
            return busqueBinaria(posicion+1,der,llave);
    }
};

Binaria::Binaria(int arreglo[]){
    for(int i=0;i<15;i++){
        this->arreglo[i]=arreglo[i];
    }
    
}

int main(){
	int  prueba[]={10,17,18,20,45,60,70,71,72,80,85,90,93,95,98};
	int resultado;
	Binaria objeto(prueba);//Guarda en el objeto de prueba
	int x;
	char respuesta;
	
	cout<<endl;
	cout<<"Posicion | Elemento"<<endl<<endl;
	for(int i=0;i<15;i++){
		cout<<"       "<<i<<" | "<<prueba[i]<<endl;
	}
	cout<<endl;
	cout<<"\n\tIngrese un valor a buscar: ";
    cin>>x;
    //Instruccion de prueba
	resultado=objeto.busqueBinaria(0,14,x);
	
	if(resultado==-1){
		cout<<"\n\tNo existe la llave"<<endl;
	}else{
		cout<<"\n\tExiste la llave en la posicion: "<<resultado;
	}
	getch();
	
	cout<<"\n\n\tDesea realizar una nueva busqueda s/n: ";
	cin>>respuesta;
	if(respuesta=='s'||respuesta=='S'){
		system("cls");
		main();
	}else{
		system("cls");
		cout<<"\n\t**EL PROGRAMA SISTEMA DE BUSQUEDA SE EJECUTO CORRECTAMENTE**";
	}
}
