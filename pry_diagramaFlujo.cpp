#include <iostream>

using namespace std;

int main() {
	int i = 1;
	cin>>i;
	cout<<"Numero de serie de Pala Cargadora"<<endl;
	do {
		cout<<i<<endl;
		i = i + 1;
		cin>>i;	
	}while(i != 78345);
	
	cout<<i<<endl;
	i = i +1;
	cin>>i;
	cout<<"Numero de serie de retroexcavadoras"<<endl;
	
	do {
		cout<<i<<endl;
		i = i + 1;
		cin>>i;	
	}while(i != 33287);
	cout<<i<<endl;
	i = i +1;
	cin>>i;
	cout<<"Numero de series dumpers"<<endl;
	
	do {
		cout<<i<<endl;
		i = i + 1;
		cin>>i;	
	}while(i != 63287);
	cout<<i<<endl;

	cout<<"Finaliza la extraccion desde el archivo, el total de la maquina es: "<<i<<endl;
	
	
}
