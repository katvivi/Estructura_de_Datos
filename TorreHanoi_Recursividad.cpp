//Torre de Hanoi - recursividad

#include<iostream>
using namespace std;

void hanoi(int n,char origen,char destino,char auxiliar){
	if(n>0){
		hanoi(n-1,origen,auxiliar,destino);
		cout<<origen<<"-->"<<destino<<endl;
		hanoi(n-1,auxiliar,destino,origen);
	}
}
int main(){
	int n;
	cout<< "Numero de Torres: ";
	cin>> n ;
	hanoi(n,'A','C','B');
	return 0;
}

