//RECURSIVIDAD | N Factorial
#include <iostream>
using namespace std;

int factorial(int);

int main(){
	int n;
	cout<<"\tIngrese numero: ";
	cin>>n;
	cout<<"\tFactorial: "<<factorial(n);
}

int factorial(int num){
	if (num == 0){
		num = 1;
	}
	else{
		num = num * factorial(num-1);
	}
	return num;
}
