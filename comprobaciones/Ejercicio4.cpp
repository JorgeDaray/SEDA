#include <iostream>

void menu();
using namespace std;

int operacion(int inicio){
    int aux;
    while(inicio != 1){
        if (inicio%2 == 0){
            inicio = inicio/2;
        }
        else if(inicio%2 == 1){
            inicio = (inicio*3) + 1;
        }
        aux++;
    }
    return aux;
}

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

void menu(){
int opc=0, inicio, fin;
	cout<<"\tEJERCICIO 4\t"<<endl;
	cout<<"1) Ingresar numeros"<<endl;
	cout<<"2) Salir"<<endl;
    cout<<"Seleccione opcion:"<<endl;
    cin>>opc;
	switch(opc){

		case 1:{
		cout << "Ingresar numero de inicio:" <<endl;cin>>inicio;
        cout << "Ingresar numero de final:"<<endl;cin>>fin;
        for (int i = inicio; i <= fin; i++){
            cout << "Para ["<<i<<"] faltan ["<<operacion(i)<<"] pasos"<<endl;
        }
		}
        break;

        case 2:break;

        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}
