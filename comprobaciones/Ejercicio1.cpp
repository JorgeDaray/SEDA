#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

void menu();
void mostrar_fibo();
long fibonacci (int);
int MCD(int,int);
void mostrar_mcd();
int suma_datos_vector(int[],int);
void mostrar_suma();

int main()
{
int opc=0;
do{
system("cls");
menu();
cout<<"Continuar 1 salir 2:"<<endl;cin>>opc;
}while(opc!=2);
system("pause>>cls");
return 0;

}

long fibonacci(int n){
if (1 == n || 2 == n) {
return 1;
} else {
return (fibonacci(n-1) + fibonacci(n-2));
}
}

void menu(){
int opc=0;
cout<<" Practica 1"<<endl;
cout<<"1) fibonacci"<<endl;
cout<<"2) MCD"<<endl;
cout<<"3) Suma de vectores"<<endl;
cout<<"4) salir"<<endl;
cout<<"Seleccione opcion:"<<endl;
cin>>opc;
switch(opc){

case 1: {
mostrar_fibo();
}break;

case 2: {
mostrar_mcd();
}break;
case 3: {
mostrar_suma();

}break;
}
}

void mostrar_fibo()
{
cout<<"::serie de fibonacci::"<<endl;
int n;
cout<<"Introduce un numero positivo: "<<endl;cin>> n;
cout<<"El numero " <<n<<" de Fibonacci es :"<<fibonacci(n)<<endl;
}

int MCD(int x, int y)
{
if(y==0)
return x;
else
return MCD(y, x%y);
}

void mostrar_mcd()
{
int num1=0,num2=0;
cout<<"::Maximo Comun Divisor::"<<endl;
cout<<"Introduce el primer numero: "<<endl;cin>>num1;
cout<<"Introduce el segundo numero: "<<endl;cin>>num2;
cout<<"El resultado es: "<<MCD(num1, num2)<<endl;
}

int suma_datos_vector(int vec[],int n){
if (n == 0){
return vec[n];
}else{
n--;
return vec[n+1] + suma_datos_vector(vec, n);
}

}

void mostrar_suma()
{
cout<<"::Suma de vectores::"<<endl;
int n;
cout<< "ingresa el valor de n: "<<endl;cin>>n;
int vec[n];
srand(time(NULL));
for (int i=0;i < n;i++){
vec[i] =(int)((rand()/32767.1)*1000);
cout<<vec[i]<<endl;
}
cout<<"la suma de datos del vector es: "<<suma_datos_vector(vec, n-1)<<endl;
}
