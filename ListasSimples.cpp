/*Materia: Estructuras de Datos
Tema: LISTAS DOBLEMENTE ENLAZADA*/
			
#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
       int dato;    
       struct nodo *siguiente;
       struct nodo *anterior;
};

typedef struct nodo *ListaTotal;

void insertarNodo(ListaTotal &lista , int valorElemento );
bool buscarNodo(ListaTotal &lista ,int valorElemento, int &posicion);
void imprimirLista(ListaTotal &lista);
void eliminarElemento(ListaTotal &lista, int valorElemento);

int main(){
	ListaTotal lista = NULL;
	int valorElemento, opcion, posicion, contador;
	bool recorrido;
	char seleccion;
	
	do{
		cout << "\n\t***Listas Enlazadas***\n" <<endl;
		cout << "1: Insertar el elemento a la lista" <<endl;
		cout << "2: Buscar el elemento en la lista" <<endl;
		cout << "3: Mostrar lista" <<endl;
		cout << "4: Eliminar elemento" <<endl;
		cout << "5: Salir" <<endl;
		cout << "\n Elija una opcion: ";
		cin >> opcion;
		cout<<endl;
        
        switch (opcion)
        {
        	
        	case 1:
        		seleccion = 's';
        		
        		while(seleccion == 's'|| seleccion == 'S'){
        			cout<< "\n Ingrese el valor del campo: ";
					cin >> valorElemento;
					insertarNodo(lista, valorElemento);
					cout<<endl;
					cout<< " Desea seguir ingresando[s/n]: ";
					cin >> seleccion;
				}
				
				system("pause"); system("cls");
        		cin.clear();
				break;
       		
			case 2:
				cout<< "\t***Buscar el valor del elemento en la lista***\n" <<endl;
				cout<< " Ingrese el valor del elemento a buscar: ";
				cin >> valorElemento;
				imprimirLista(lista);
				recorrido = buscarNodo(lista, valorElemento, posicion);
				
				if(recorrido == true){
					cout<< " Posicion: " <<posicion<<endl;
					
				}
				else{
					
					cout<< " El valor del elemento es: " << valorElemento <<endl;
					cout<< " No existe" <<endl;
				}
					
				system("pause"); system("cls");
        		cin.clear();
				break;
				
       		case 3:
				cout<< "\t***Listado de nodos***" <<endl<<endl;
				imprimirLista(lista);
				
				system("pause"); system("cls");
        		cin.clear();
				break;
				
			case 4:
				cout<< "\t***Eliminar elemento***" <<endl<<endl;
				imprimirLista(lista);
				cout<< " Ingrese el valor del elemento a eliminar: ";
				cin >> valorElemento;
				eliminarElemento(lista,valorElemento);
				imprimirLista(lista);
				
				system("pause"); system("cls");
        		cin.clear();
				break;
				
        	default:
        		cout<<"\t*** Gracias por utilizar nuestro programa ***"<<endl;
           		break;
        }
		
	} while (opcion != 5);
}
void insertarNodo(ListaTotal &lista , int valorElemento ){

	ListaTotal nuevoElemento, actualElemento;
	nuevoElemento = new nodo();
	nuevoElemento->dato = valorElemento;
	nuevoElemento->siguiente = NULL;
	nuevoElemento->anterior =NULL;
	actualElemento = lista;
	
	if(lista == NULL){
		lista = nuevoElemento;
		lista->anterior = NULL;
		lista->siguiente = NULL;
		return ;	
	}
	while(actualElemento->siguiente!=NULL){
		actualElemento = actualElemento->siguiente;
	}
	actualElemento->siguiente = nuevoElemento;
}

bool buscarNodo(ListaTotal &lista, int valorElemento, int &posicion){
	ListaTotal auxiliar = lista;
	posicion = 0;
	while(auxiliar != NULL){
		if(auxiliar->dato == valorElemento){
			return true;
		}
		auxiliar = auxiliar-> siguiente;
		posicion++;
	}
	cout<<" Elemento no encontrado"<<endl;
	return false;
}
void imprimirLista(ListaTotal &lista){
	ListaTotal auxiliar = lista;
	int contador =0;
	cout <<" Nodos de la lista: "<<endl;
	while(auxiliar != NULL){
		cout <<auxiliar->dato<<endl;
		auxiliar = auxiliar->siguiente;
		contador++;
		
	}
	if(contador == 0){
		cout<< "No hay elementos en la lista "<<endl;
	}
}
void eliminarElemento(ListaTotal &lista, int valorElemento)
{
	ListaTotal auxiliar, anterior;
    auxiliar = lista;
 	
    if(lista!=NULL)
    {
        while(auxiliar != NULL)
        {
            if(auxiliar	->dato==valorElemento)
            {
                if(auxiliar==lista)
                    lista = lista->siguiente;
                else
                    anterior->siguiente = auxiliar->siguiente;
 
                delete(auxiliar);
                return;
            }
            anterior = auxiliar;
            auxiliar = auxiliar->siguiente;
        }
    }
    else
        cout<<" No hay elemento en la lista ";
}




