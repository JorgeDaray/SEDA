#include <iostream>
using namespace std;

//Funcion paso por valor
void multiplicacion(int numero1, int numero2){
    numero1 = numero1 * numero2;
    cout << "\n multiplicacion :"<<numero1<<endl;
}

//Funcion paso por referencia
void multiplicacion(int *n, int &n2){
   *n = *n * n2;
   cout << "Resultado : "<<*n<<endl;
}


int main(){
    int opcion, numero1, numero2;
    while(opcion!=5){
        cout<<"\n Que opcion deseas, \n5-Salir \n1-multiplicacion por valor \n2-multiplicacion por referencia \nOpcion: "<<endl;
        cin>>opcion;

        switch(opcion){
            case 1: system("cls");
                cout<<"Inserta el primer numero a multiplicar:"<<endl;cin>>numero1;
                cout<<"Inserta el segundo numero a multiplicar:"<<endl;cin>>numero2;
                multiplicacion(numero1,numero2);
                break;
            case 2: system("cls");
                cout<<"Inserta el primer numero a multiplicar:"<<endl;cin>>numero1;
                cout<<"Inserta el segundo numero a multiplicar:"<<endl;cin>>numero2;
                multiplicacion(numero1,numero2);
                break;
            case 5: break;
            default: printf("Esa opcion no existe...\n");
        }
    }

    return 0;
}
