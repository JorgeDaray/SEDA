#include <iostream>
#include <string.h>
#define TAMMAX 5

using namespace std;

void menu();

class impresion{
    public:
    char nombre [30];
    char dat [100];
    int bandera;
};

class Cola {
    public:
        impresion datos[TAMMAX];
        int frente, fin;
        void inicializa();
        bool vacia();
        bool llena();
        void encolar(Cola *elem);
        impresion desencolar();
        impresion frent();
        void imprimir_persona(Cola *micola);
        Cola(){
        inicializa();
        }
};

void Cola::inicializa(){
    frente = 0;
    fin = TAMMAX-1;
}

bool Cola::vacia()
{
    if ((frente == fin+1) || (frente == 0 && fin == TAMMAX - 1))
    {
        return true;
    }else{
        return false;
    }
}

bool Cola::llena()
{
    if ((frente == fin + 2) || (frente == 0 && fin == TAMMAX - 2) || (frente == 1 && fin == TAMMAX - 1))
    {
        return true;
    }else{
        return false;
    }
}

 Cola micola;

void Cola::encolar(Cola *micola)
{
    if (llena()){
        cout<<"desbordamiento de datos"<<endl;
        system("pause");
        return;
    }
    else{
        fin++;
        if (fin == TAMMAX)
        {
            fin = 0;
        }
        cout << "Digite el nombre del archivo: "<<endl;
        gets(datos[fin].nombre);
        cout << "Ponga los datos que llevara el archivo: "<<endl;
        gets(datos[fin].dat);
        datos[fin].bandera = 1;
    }
}

void Cola::imprimir_persona(Cola *micola){
    if (vacia()){

        cout<<"La lista esta vacia"<<endl;
        system("pause");
        return;
    }
            for(int i = 0; i<= TAMMAX; i ++){
            if(datos[i].bandera == 1){
            cout << "nombre : "<<datos[i].nombre<<endl;
            cout << "datos : "<<datos[i].dat<<endl;
            }
            }
}

impresion Cola::desencolar(){
    if(vacia()){
        cout<<"Insuficiencia de datos"<<endl;
        system("pause");
    } else {
        datos[frente].bandera=0;
        cout << "nombre : "<<datos[frente].nombre<<endl;
        cout << "datos : "<<datos[frente].dat<<endl;
        frente++;
        if (frente == TAMMAX){
            frente = 0;
        }
        return datos[frente];
    }
}

impresion Cola::frent(){
    if(vacia()){
        cout<<"Insuficiencia de datos"<<endl;
        system("pause");
    } else {
        cout << "nombre : "<<datos[frente].nombre<<endl;
        cout << "datos : "<<datos[frente].dat<<endl;
        return datos[frente];
    }
}

int main()
{
    int opc=0;
    do{
   	system("cls");
   	 menu();
   cout<<"Continuar 1 salir 5:"<<endl;cin>>opc;
   }while(opc!=5);
    system("pause>>cls");
    return 0;
}

void menu(){
int opc=0;
	cout<<"*\tCOLA ESTATICA\t*"<<endl;
	cout<<"5) Salir"<<endl;
	cout<<"1) Encolar"<<endl;
	cout<<"2) Desencolar"<<endl;
	cout<<"3) Frente"<<endl;
	cout<<"4) Imprimir cola"<<endl;
    cout<<"Seleccione opcion:"<<endl;
    cin>>opc;
    cin.ignore();
	switch(opc){

		case 1: {
                    micola.encolar(&micola);
                }break;
        case 2: {
                    micola.desencolar();
                }break;
        case 3: {
                    micola.frent();
                }break;
        case 4: {
                    micola.imprimir_persona(&micola);
                }break;
        case 5:{
        break;
        }

        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}
