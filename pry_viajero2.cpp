#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define Nodo struct nodo
#define Arista struct arista
#define Lista struct pila

using namespace std;

Nodo{
	char dato; 
	Nodo* siguiente;
	Arista* adyacencia; 
	int visitado,terminado;
	int monto;
	char anterior;
};

Arista{
	Nodo*vrt; 
	Arista*siguiente;
	int peso;
};

Lista{
	Nodo* dato;
	Lista*siguiente;
};

Nodo*inicio=NULL;
Lista*ini=NULL;
Lista*final=NULL; 

void insertarNodo();
void agregarArista(Nodo*aux,Nodo*aux2,Arista*nuevo);
void insertarArista();
void visualizarGrafo();
void insertarPila(Nodo* aux);
Nodo*desencolar();
void reiniciar();
void dijkstra();

int main(){   
	int opcion,i;
    do{
    	cout<<"\n\t\tComerciante Viajero";
    	cout<<"\n\n\t\t-----RUTA DE VIAJE------";
    	cout<<"\n\t1. Ingresar Ciudades: ";
    	cout<<"\n\t2. Establecer Rutas";
    	cout<<"\n\t3. Listar Ciudades con su lista de adyacencia.";
    	cout<<"\n\t4. Algoritmo de Dijkstra.";
    	cout<<"\n\t5. Salir";
    	cout<<"\n\n\t\t Ingrese una Opcion: ";
        printf("\tDestinos\n");
		printf("\t1. Cuenca    \n");
        printf("\t2. Imbarra  \n");
        printf("\t3. Latacunga\n");
        printf("\t4. Ambato  \n");
        printf("\t5. Quito  \n");
        printf("\t6. Tulcan\n");

        printf("Ingrese una Opcion:");
        scanf("%i",&opcion);
        switch(opcion){
            case 1: 
				insertarNodo();
    			break;
            case 2: 
				insertarArista();
                break;
            case 3: 
				visualizarGrafo();
                break;        
            case 4: 
				dijkstra();
			    break;
			case 5: 
				char respuesta;
			    cout<<"\n¿DESEA CONTINUAR PROBANDO EL ALGORITMO SOBRE BUSQUEDA EXHAUSTIVA-SOLUCION OPTIMA: SI/NO?";
			    cin >>respuesta;
			        if(respuesta =='s'|| respuesta =='S'){
			        	system("cls");
			        	main();
			        }else{
			        	system("cls");
			        	cout<<"\n\tEL PROCESAMIENTO SOBRE BUSQUEDA EXHAUSTIVA-SOLUCION OPTIMA DEL PROBLEMA";
				   		cout<<"\n\tDEL COMERCIANTE VIAJERO POR TODAS LAS PROVINCIAS DE LA REGION DE LA SIERRA DEL ECUADOR A FINALIZADO";
						cout<<"\n\n\n\t\tNo te preocupes si no funciona bien. Si todo estuviera correcto, serias despedido de tu trabajo";
						cout<<"\n\t\t\tLey de Mosher de la Ingeniería del Software"<<endl;
			        	exit(0);
			        }
			        
					break;
            default: printf("Opcion no valida\n");
                     system("pause");
                     break;
        }
        system("pause");
        system("cls");
    }while(opcion!=5);
    return 0;
}
void insertarNodo(){
    Nodo* aux;
	Nodo* nuevo=(Nodo*)malloc(sizeof(Nodo));
	fflush(stdin);
	printf("Ingrese el destino:");
	scanf("%c",&nuevo->dato);
	nuevo->siguiente=NULL;
    nuevo->adyacencia=NULL;
    nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    nuevo->anterior=0;
    if(inicio==NULL){
        inicio=nuevo;
    }else{
        aux=inicio;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
      }
 
 }
 void insertarArista(){   
    char ini, fin;
    Arista* nuevo=(Arista*)malloc(sizeof(Arista));
    nuevo->siguiente=NULL;
    Nodo* aux;
	Nodo* aux2;
    if(inicio==NULL){
         printf("GRAFO VACIO\nIngrese Ciudad de partida\n");
         return;
    }
    fflush(stdin);
    printf("Ingresar destino Inicial y Final:\n");
    scanf("%c %c",&ini,&fin);
    printf("Ingrese la distancia: ");
    scanf("%i",&nuevo->peso);
    aux=inicio;
    aux2=inicio;
    while(aux2!=NULL){
        if(aux2->dato==fin){
            break;
        }
        aux2=aux2->siguiente;
    }
    if(aux2==NULL){
    	printf("Error \n");
    	return;
	}
    while(aux!=NULL){
        if(aux->dato==ini){
            agregarArista(aux,aux2,nuevo);
            return;
        }
        aux = aux->siguiente;
    }
    if(aux==NULL)
    	printf("La Ciudad ya se ha ingresado\n");
}
void agregarArista(Nodo* aux,Nodo* aux2,Arista* nuevo){
    Arista* a;
    if(aux->adyacencia==NULL){   
	    aux->adyacencia=nuevo;
        nuevo->vrt=aux2;
    }else{   
	    a=aux->adyacencia;
        while(a->siguiente!=NULL)
            a=a->siguiente;
        nuevo->vrt=aux2;
        a->siguiente=nuevo;
    }
}
void visualizarGrafo(){
    Nodo*aux=inicio;
    Arista* ar;
    printf("Ciudades |  Destinos\n");
    while(aux!=NULL){   
	    printf("\t %c :    ",aux->dato);
        if(aux->adyacencia!=NULL){
            ar=aux->adyacencia;
            while(ar!=NULL){ 
			    printf(" %c",ar->vrt->dato);
                ar=ar->siguiente;
            }
        }
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}
void dijkstra(){
	Nodo*aux=inicio;
	char a,b;
	fflush(stdin);
	printf("Ingresar ciudad Inicial y Final:");
	scanf("%c %c",&a,&b);
	while(aux!=NULL){
		if(aux->dato==a){
			aux->terminado=1;
			aux->monto=0;
			break;
		}
		aux=aux->siguiente;
	}
	if(aux==NULL){
		printf("Ciudad no encontrada\n");
		return;
	}
	while(aux!=NULL){
		Arista*a=aux->adyacencia;
	    while(a!=NULL){
		    if(a->vrt->monto==-1 || (aux->monto+a->peso)<a->vrt->monto){
		    	a->vrt->monto=aux->monto+a->peso;
		        a->vrt->anterior=aux->dato;
			}
		    a=a->siguiente;
	    }
	    aux=inicio;
	    Nodo*min=inicio;
	    while(min->anterior==0 || min->terminado ==1)
	    min=min->siguiente;
	    while(aux!=NULL){
	    	if(aux->monto<min->monto && aux->terminado==0 && aux->anterior!=0)
	    	min=aux;
	    	aux=aux->siguiente;
		}
		aux=min;
		aux->terminado=1;
		if(aux->dato==b)
		break;
	}
	while(aux->anterior!=0){
		insertarPila(aux);
		char temp=aux->anterior;
		aux=inicio;
		while(aux->dato!=temp){
		   aux=aux->siguiente;	
		}
	}
	insertarPila(aux);
	while(ini!=NULL){
		printf(" => %c ",desencolar()->dato);
	}
		printf("\n");
	reiniciar();
}
void insertarPila(Nodo* aux){
	Lista*nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->dato=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
	   nuevo->siguiente=ini;
	   ini=nuevo;    	
	}
}

Nodo*desencolar(){
	Lista*aux;
	if(ini==NULL){
		return NULL;
	}else{
		aux=ini;
		ini=ini->siguiente;
		aux->siguiente=NULL;
		if(ini==NULL)
		final=NULL;
	}
	Nodo*resultado=aux->dato;
	free(aux);
	return resultado;
}

void reiniciar(){
	if(inicio!=NULL){
		Nodo*aux=inicio;
		while(aux!=NULL){
			aux->visitado=aux->terminado=0;
		    aux=aux->siguiente;
		}
	}
}
