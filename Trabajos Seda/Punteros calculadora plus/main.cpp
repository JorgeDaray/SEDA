#include <iostream>
#include <cstdlib>
using namespace std;

int *ptr1=NULL;
void binario(int*a);
int a=0;

int main(int argc, char** argv) {
system("cls");
cout<<"ingrese número 1"<<endl;
cin>>a;
ptr1=&a;
binario(ptr1);
return 0;
}

void binario(int *a){
int *cociente=NULL;
int *residuo=NULL;
while(*a/2>0){
*cociente=*a/2;
*residuo=*a%2;
cout<< *residuo;
}
cout<< *cociente;
}
