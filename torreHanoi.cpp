//Torre Hanoi con estructura Pila 
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 10
using namespace std;


struct pila {
	int item[TAMANIO];
	int tope;
};
typedef struct pila TDA_PILA;

void menu();
int push(TDA_PILA& p, int e);
int pop(TDA_PILA& p, int& e);
int pila(TDA_PILA p, int& e);
int torreVacia(TDA_PILA p);
void iniciarPila(TDA_PILA& p);
void torreHanoi(int n, TDA_PILA& O, TDA_PILA& A, TDA_PILA& D,TDA_PILA* o, TDA_PILA* a, TDA_PILA* d);
void mostrar(TDA_PILA D);

int main() {
	menu();
	return 0;
}

void menu(){
	int n,opcion;
	char salir;
	
	TDA_PILA O, A, D;
	iniciarPila(O);
	iniciarPila(A);
	iniciarPila(D);

	TDA_PILA* o = &O;
	TDA_PILA* a = &A;
	TDA_PILA* d = &D;
	
	string texto="";
	do{
		cout<<texto<<endl;
		cout<<"\t     ** MENU **"<<endl;
		cout<<"\n\t TORRE DE HANOI"<<endl;
		cout<<"\t1. Insertar Discos "<<endl;
		cout<<"\t2. Mostrar Torre"<<endl;
		cout<<"\t3. Salir"<<endl;
		
		cout<<"\tIngrese su opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				
				cout<<"\n\tIngrese la cantidad de discos: ";
				cin>>n;
				cout<<"\n\tInicializando la Torre Origen con discos del 1 al "<< n<<endl<<endl;
				
				for (int i = n; i > 0; i--)
					push(O, i);
					
				cout<<"\t\t\tTorre llena exitosamente"<<endl<<endl;
				cout<<"\tLos elementos de la Torre de Origen son: ";
				mostrar(O);
				cout<<"\n";
				system("pause");
				break;
			case 2:
				cout<<"\t"<<endl<<endl;
				torreHanoi(n, O, A, D, o, a, d);
				cout<<"\n\t\t\tDiscos movidos exitosamente"<<endl;
				cout<<"\t\tLos elementos de la Torre de Destino son: ";
				mostrar(D);
				cout<<"\n\t"<<endl;
				cout<<"\n";
				system("pause");
				break;
			default:
				cout<<"\n\t\tDesea regresar al menu (s/n)?:";
			    cin>>salir;
			    
			    if((salir == 'n'  ) || (salir == 'N')) {
			   		opcion=3;
					   	cout<<"\n\t\t--EL PROCESAMIENTO TORRE DE HANOI Y DEMOSTRACION DE RECURENCIA NO HOMOGENEA HA FINALIZADO--"<<endl;		
						system("pause");	   	
				}
				else {
					texto="\t\t\tNUEVA PRUEBA";
					opcion=0;			
				}					
					cout<<endl;		
				break;
		}
		system("cls");
	}while(opcion != 3);
}

int push(TDA_PILA& p, int e) {
	if (p.tope == TAMANIO - 1)
		return 0;
	p.item[++p.tope] = e;
	return 1;
}

int pop(TDA_PILA& p, int& e) {
	if (torreVacia(p))
		return 0;
	e = p.item[p.tope--];
	return 1;
}

int pila(TDA_PILA p, int& e) {
	if (torreVacia(p))
		return 0;
	e = p.item[p.tope];
	return 1;
}

int torreVacia(TDA_PILA p) {
	if (p.tope == -1)
		return 1;
	return 0;
}

void iniciarPila(TDA_PILA& p) {
	p.tope = -1;
}

void torreHanoi(int n, TDA_PILA& O, TDA_PILA& A, TDA_PILA& D,TDA_PILA* o, TDA_PILA* a, TDA_PILA* d) {
	int e;
	char aux, aux1;

	if (o == &O)
		aux = 'O';
	else if (a == &O)
		aux = 'A';
	else if (d == &O)
		aux = 'D';

	if (o == &D)
		aux1 = 'O';
	else if (a == &D)
		aux1 = 'A';
	else if (d == &D)
		aux1 = 'D';

	if (n == 1) {
		pop(O, e);
		push(D, e);
		cout<<"\t\tDisco "<<n<<" movido de la Torre "<<aux<<" a la Torre "<<aux1<<endl;

	}
	else {
		torreHanoi(n - 1, O, D, A, o, a, d);
		pop(O, e);
		push(D, e);
		cout<<"\t\tDisco "<<n<<" movido de la Torre "<<aux<<" a la Torre "<<aux1<<endl;
		torreHanoi(n - 1, A, O, D, o, a, d);
	}

}

void mostrar(TDA_PILA D) {
	int e;
	while (pop(D, e))
		cout<<" "<<e;
		
}
