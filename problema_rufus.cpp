#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct NODO
{
	 int codigo ;
     char nombre[40];
	 NODO *sig;
};
int menu(string opcion,int lim);
int ingreso_lista(NODO *&cab,NODO *&ant,NODO *&nuevo,NODO *&ult,NODO *&aux);
void listar(NODO *&cab,NODO *&aux);
void hallar_sobreviviente(NODO *&cab,NODO *&ult,NODO *&ant,NODO *&aux,int n);
//se declara las funciones indicando que es un puntero los parametros funcio(TIPO *&puntero)
//se envia un parametro puntero directamente sin señaladors funcion(puntero)
int main()
{
	int op=-1,lim=4,n=0;
	NODO *cab=NULL,*ant,*nuevo,*ult,*aux;
	do
	{
		op=menu("MENU\n<1>INGRESAR SOLDADOS\n<2>LISTAR SOLDADOS\n<3>HALLAR SOBREVIVIENTE\n<4>SALIR\nselecione opcion: ",4);
		switch(op)
	    {
	    	case 1:
	    	{
	    		cout<<"***************INGRESAR_SOLDADOS***************\n";
	    		n=ingreso_lista(cab,ant,nuevo,ult,aux);
	    		system("PAUSE");
				system("CLS");
	    		
			}break;
			case 2:
	    	{
	    		cout<<"****************LISTAR_SOLDADOS****************\n";
	    		listar(cab,aux);
	    		system("PAUSE");
		        system("CLS");
				
			}break;
			case 3:
	    	{
				cout<<"**************HALLAR_SOBREVIENTE***************\n";
				hallar_sobreviviente(cab,ult,ant,aux,n);	    	
			}break;
			default:
		    {
		    	cout<<"*****************EASTER_EGG*********************\n";
			}break;
		}		
		
	}while(op!=lim);
	
}
int menu(string opcion,int lim)
{
	int op=0;
	do
	{
		cout<<opcion;
		cin>>op	;
		system("PAUSE");
		system("CLS");
	}while(op<0||op>lim);
 return op;
}
int ingreso_lista(NODO *&cab,NODO *&ant,NODO *&nuevo,NODO *&ult,NODO *&aux)
{
	int n;
	cab=NULL;
		nuevo=NULL;
		cout<<("ING CANTIDAD DE SOLDADOS: ");
		scanf("%d",&n);
		
		for(int i=0;i<n;i++){
			ant=nuevo;
			nuevo=(NODO*)malloc(sizeof(NODO));
			cout<<"Ingrese nombre soldado "<<i+1<<": ";
			//scanf("%s",&nuevo->nombre);
			cin>>nuevo->nombre;
			nuevo->codigo=i+1;
			nuevo->sig=NULL;
			if(cab==NULL)
			cab=nuevo;
			else
			ant->sig=nuevo;
			nuevo->sig=cab;
			ult=nuevo;		
	  }
	  return n;
}
void listar(NODO *&cab,NODO *&aux)
{
	aux=NULL;
		if(cab!=NULL){
		while(aux!=cab){
			if(aux==NULL)
			aux=cab;
			
			cout<<aux->codigo<<" "<<aux->nombre<<endl;
			aux=aux->sig;
		}
		}
		else
		printf("lista vacia\n");
}
void hallar_sobreviviente(NODO *&cab,NODO *&ult,NODO *&ant,NODO *&aux,int n)
{
		int nb,n2;
		char buscar[40];
		listar(cab,aux);
		cout<<"ingrese persona a buscar: ";
		cin>>buscar;
		cout<<"ingrese numero: ";
		cin>>n2;
		// ||n>=0
		while(strcmp(cab->nombre,buscar)!=0)
		{
			if(strcmp(cab->nombre,buscar)!=0) 
			{
				cab=cab->sig;
				ant=ant->sig;
				ult=ult->sig;

			}
		}

		while(ult!=cab)
		{
			for(int i=1;i<=n2;i++){
				aux=cab;
				if(i==n2){
					cab=aux->sig;
					ult->sig=cab;
					cout<<"se ha borrado "<<aux->codigo<<" "<<aux->nombre<<endl;
					free(aux);
				}else{
					cab=cab->sig;
					ant=ant->sig;
					ult=ult->sig;
					
					
				}
			}
		}
		system("PAUSE");
		system("CLS");
		cout<<"**************HALLAR_SOBREVIENTE***************\n El sobreviviente es: ";
	    listar(cab,aux);
        
}
