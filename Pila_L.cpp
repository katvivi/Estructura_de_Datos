# include<iostream>

using namespace std;
struct Vehiculo {
	int valor;
	int placa;
	int horaEntrada;
	int horaSalida;
	Vehiculo *siguiente;
};
Vehiculo*pilaoriginal;
Vehiculo*pilaauxiliar;

void pushVehiculo();
void mostrarVehiculos();
void popVehiculo();
void buscar();
void calcularGanancia(int ganancia);
int total, ganancia;

		
int main(){
	
	int opcion;
	do{
		cout<<"SISTEMA DE ESTACIONAMIENTO"<<endl<<endl;
	    cout<<"-------------------"<<endl;
		cout<<"1.-Ingresar Datos de vehiculo"<<endl;
		cout<<"2.-Mostrar Elementos a la Pila"<<endl;
		cout<<"3.-Consultar vehiculo"<<endl;
		cout<<"4.-Retirar vehiculo"<<endl;
		cout<<"5.-Consultar ingresos"<<endl;
		cout<<"6.-Salir"<<endl;
		
		cout<<"Ingrese un opcion: "<<endl;
		cin>>opcion;
		
		switch(opcion){
			case 1: 				
				pushVehiculo();
			break;
			
			case 2: 
				mostrarVehiculos();
			break;
		
			case 3:
				buscar();
			break;
			
			case 4:
				popVehiculo();
			break;
			
			case 5:
				cout<<"\nGanancias: "<<ganancia*2<<endl;
			break;
		}		
	}
	while (opcion!=6);
	cout<<"Gracias por usar nuestro Software... "<<endl;
	system ("pause");
	return 0;
}
void pushVehiculo(){
	if (pilaoriginal== NULL){
		pilaoriginal = new(Vehiculo);
		
		cout<<"Ingrese el numero de placa del vehiculo"<<endl;
		cin>>pilaoriginal->placa;
		
		//Ingreso hora de entrada
		cout<<"Ingrese la hora de entrada (formato 24 horas)"<<endl;
		cin>>pilaoriginal->horaEntrada;
		//Ingreso hora de salida
		cout<<"Ingrese la hora de salida (formato 24 horas)"<<endl;
		cin>>pilaoriginal->horaSalida;

		cout<<"Costo por hora de 2 dolares"<<endl;
		total = pilaoriginal->horaSalida - pilaoriginal->horaEntrada; 
		cout<<"--Elemento ingresado correctamente"<<endl;
		pilaoriginal->siguiente=NULL;
		
		total = pilaoriginal->horaSalida - pilaoriginal->horaEntrada;
		cout<<"Total horas: "<<total<<endl;
		ganancia = ganancia + total;
	}
	
	pilaauxiliar=new(Vehiculo);
	cout<<"Ingrese el numero de placa del vehiculo"<<endl;
		cin>>pilaauxiliar->placa;
		
		//Ingreso hora de entrada
		cout<<"Ingrese la hora de entrada (formato 24 horas)"<<endl;
		cin>>pilaauxiliar->horaEntrada;
		//Ingreso hora de salida
		cout<<"Ingrese la hora de salida (formato 24 horas)"<<endl;
		cin>>pilaauxiliar->horaSalida;
		
		pilaauxiliar->siguiente=pilaoriginal;
		cout<<"Costo por hora de 2 dolares"<<endl;
		
		total = pilaauxiliar->horaSalida - pilaauxiliar->horaEntrada;
		cout<<"Total horas: "<<total<<endl;
		
	ganancia = ganancia + total;
	pilaoriginal=pilaauxiliar;
	
}
void mostrarVehiculos(){
	if(pilaoriginal== NULL){
		cout<<"No hay datos en la pila"<<endl;
	}
	pilaauxiliar=pilaoriginal;
	cout<<"los vehiculos ingresados en  la pila son:"<<endl;
	
	while (pilaauxiliar!= NULL){
		cout<<"-----------------------------------"<<endl;
		cout<<"Placa: "<<pilaauxiliar->placa<<endl;
		cout<<"Hora de entrada: "<<pilaauxiliar->horaEntrada<<endl;
		cout<<"Hora de salida: "<<pilaauxiliar->horaSalida<<endl;
		cout<<"Horas: "<<total<<endl;
		pilaauxiliar=pilaauxiliar->siguiente;	
		cout<<"-----------------------------------"<<endl;
	}

}

void popVehiculo(){

	if(pilaoriginal==NULL){
		cout<<"No hay datos en la pila"<<endl;
	}
	pilaauxiliar=new(Vehiculo);
	pilaauxiliar=pilaoriginal;
	cout<<"-Retiro de vehiculo"<<pilaauxiliar->placa<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"\n\t\t\tFACTURA"<<endl;
	cout<<"\tNumero de placa: "<<pilaauxiliar->placa<<endl;
	cout<<"\tHora de Ingreso : "<<pilaauxiliar->horaEntrada<<endl;
	cout<<"\tHora de Salida: "<<pilaauxiliar->horaSalida<<endl;
	cout<<"-----------------------------------"<<endl;
	pilaoriginal=pilaauxiliar->siguiente;
	delete(pilaauxiliar);
}
void buscar(){
	if(pilaoriginal==NULL){
		cout<<"La pila esta vacia"<<endl;
	}
	int buscardatos;
	bool encontrado=false;
	pilaauxiliar=pilaoriginal;
	cout<<"Ingrese el numero de placa a buscar: "<<endl;
	cin>>buscardatos;
	while(pilaauxiliar!=NULL){
		if(buscardatos==pilaauxiliar->placa){
			cout<<"Vehiculo encontrado, su placa es: "<<pilaauxiliar->placa<<endl;
			encontrado=true;
		}
		pilaauxiliar=pilaauxiliar->siguiente;
	}
	if(encontrado==false){
		cout<<"No se encontro el numero de placa"<<endl;
	}
}
