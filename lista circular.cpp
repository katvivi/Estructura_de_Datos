/*Materia: Estructuras de Datos
Tema: LISTA CIRCULAR SIMPLE*/

#include<iostream>
using namespace std;

struct nodo{
    int dato;
    struct nodo *siguiente;
    
} *primero, *ultimo;

typedef struct nodo*Tlista;

void insertarNodo ();
void imprimirLista();
void modificarElemento();
void eliminarElemento();

void insertarNodo (){
	nodo* nuevo=new nodo();
	
	    cout<<"El elemento  es :  ";
	    cin >>nuevo->dato; 
     	if (primero==NULL){
	    	primero=nuevo;
	    	primero->siguiente= primero;
	    	ultimo=primero;
    	}else{
	    	ultimo->siguiente=nuevo;
	    	nuevo->siguiente=primero;
	    	ultimo=nuevo;
    	}	
				
}		

void imprimirLista(){
	nodo* actual=new nodo ();
	actual=primero;
	if(primero!= NULL){
		do{
			cout<<" --> "<<actual->dato;
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		cout<< " la liata se encuentra vacia ";
	}
	
}

void modificarElemento(){
	nodo* actual=new nodo ();
	actual=primero;
	bool encontrado =false;
	int elementoModi =0;
	cout<< " Ingrese el elemento a modificar:   ";
	cin >>elementoModi ;
	if(primero!=NULL){
		do{
			
			if (actual->dato==elementoModi){
				
			cout<< " El elemento  " << elementoModi<< "  fue exterminado. ";
			cout<< " Ingrese el valor para el elemento ";
			cin>>actual->dato;
			cout<< " Elemento transpuesto  ";
			encontrado=true;
				
			}
			actual=actual->siguiente;		
		}while (actual!=primero && encontrado != true);
		if (!encontrado){
			cout<< " Elemento no encontrado :  ";
		}
		
	}
}

void eliminarElemento(){
	nodo* actual=new nodo ();
	actual=primero;
	nodo* anterior= new nodo();
	anterior = NULL;
	bool encontrado =false;
	int elementoEli =0;
	cout<< " Ingrese el elemeto a eliminar:  ";
	cin >>elementoEli ;
	if(primero!=NULL){
		do{
			//Busca al elemento 
			if (actual->dato==elementoEli){
	
			//eliminar elemento
			if (actual==primero){
				primero=primero->siguiente;
				ultimo->siguiente=primero;				
			}else if(actual==ultimo) {
				anterior->siguiente=actual->siguiente;
				ultimo=anterior;
			}else{
				anterior->siguiente=actual->siguiente;
			}
	  	    	cout<< " El elemento eliminado";
	    		encontrado=true;
	 	  	}
	 	  	
			anterior=actual;
			actual=actual->siguiente;		
		}while (actual!=primero && encontrado != true);
		if (!encontrado){
			cout<< " Elemento no encontrado :  ";
		}
		
	}
}

int main ()
{
	Tlista lista = NULL;
	int elemento;
	int num;
	int posicion;
	int opcion;
	do
	{
		cout<<"               "<<endl;
		cout<<"        MENU       "<<endl;
		cout<<"               "<<endl;
        cout<<"1.INSERTA  ELEMENTOS"<<endl;
        cout<<"2.VISUALIZAR LISTA"<<endl;
        cout<<"3.CAMBIAR ELEMENTO "<<endl;
        cout<<"4.ELIMINAR ELEMENTO "<<endl;
        cout<<"                "<<endl;
        cout<<"5.SALIR"<<endl;
        cout<<"               "<<endl;
        cout<<"Escoja una opcion:";
		cin>>opcion; 
        switch(opcion)
		{
        	case 1 :
        		cout<<"Dijite la dimencion:  ";
	            cin >>num;
        		for(int i=0;i<num;i++){	
	        	insertarNodo();
                }
        		break;
        	case 2 :
        		cout<<"               "<<endl;
        		cout<<"   LISTA   "<<endl;
        	    cout<<"               "<<endl;
                imprimirLista();
          
        		break;
        	case 3 :
        		modificarElemento();
        		break;
        		
        	case 4 :
        		eliminarElemento();
        		break;
	    	}
	
       	}
        	while(opcion!=5);
            cout<<endl;
            cout<<"               "<<endl;
            cout<<"Gracias por usuar el programa Guap@  *_* ";
            cout<<"               "<<endl;
}








