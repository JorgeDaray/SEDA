#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc,char** argv)
{
    char dato='\x0'; //Iniciador dato Null
    system("cls");

    cout<< "ingrese un caracter: "<< endl;
    cin>>dato;

    if(int(dato)>=48 && int(dato)<=57){
        cout<<"el dato ingresado es numero "<<endl;
    }else if(int(dato)>=65 && int(dato)<=89){
        cout<<"el dato ingresado es Mayuscula"<<endl;
    }else if(int(dato)>=97 && int(dato)<=122){
        cout<<"el dato ingresado es en letras minusculas"<<endl;
    }else {
        cout<<"el dato ingresado no es identificado"<<endl;
    }
    system("pause>>cls");


    return 0;
}
/*char dato='\x0'; //Iniciador dato Null
    system("cls");

    cout << "ingrese un caracter: "<<endl;
    cin >> dato;

    if (isdigit(dato))//datos es numero
        cout << "el dato ingresado es numero"<<endl;
    else
        cout << "el dato ingresado no es numero"<<endl;
    system("pause>>cls");*/
