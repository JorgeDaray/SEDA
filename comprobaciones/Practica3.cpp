#include <iostream>
#include <string.h>
#define TAMMAX 4
using namespace std;

typedef struct impresion{
    char nombre [30];
    char texto [100];
}impresion;

struct Cola {
        impresion texto[TAMMAX];
        int frente, fin;
        Cola(){
        frente = 0;
        fin = TAMMAX-1;
        }
        bool vacia();
        bool llena();
        void encolar(Cola *texto);
        impresion desencolar();
        impresion frent();
        void imprimir(Cola *Cola);
};

int main()
{
    Cola Cola;
    int opc=0;
    do{
	cout<<"***************************"<<endl;
	cout<<"  1) Encolar"<<endl;
	cout<<"  2) Desencolar"<<endl;
	cout<<"  3) Frente"<<endl;
	cout<<"  4) Imprimir cola"<<endl;
    cout<<"  5) Salir"<<endl;
    cout<<"  seleccione opcion:"<<endl;
    cin>>opc;
	switch(opc){

		case 1: system("cls");
                    cin.ignore();
                    Cola.encolar(&Cola);
                break;
        case 2:system("cls");
                    Cola.desencolar();
                break;
        case 3:system("cls");
                    Cola.frent();
                break;
        case 4:system("cls");
                    Cola.imprimir(&Cola);
                break;
        case 5:system("cls");
        break;
        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
   cout<<"Continuar 1 salir 5:"<<endl;cin>>opc;
   }while(opc!=5);
    return 0;
}

void Cola::imprimir(Cola *micola){
    if (vacia())
    {
        cout<<"La cola esta vacia"<<endl;
        system("pause");
        return;
    }
    for(int i = frente; i <= fin; i ++)
    {
        cout << "nombre : "<<texto[i].nombre<<endl;
        cout << "texto : "<<texto[i].texto<<endl;
        cout<<"***************************"<<endl;
        if (frente < fin)
        {
            for(int i = fin; i <= frente; i ++)
            {
                cout << "nombre : "<<texto[i].nombre<<endl;
                cout << "texto : "<<texto[i].texto<<endl;
                cout<<"***************************"<<endl;
            }
        }
    }
}

void Cola::encolar(Cola *micola)
{
    if (llena())
    {
        cout<<"La cola esta llena"<<endl;
        system("pause");
        return;
    }
    else
    {
        fin++;
        if (fin == TAMMAX)
        {
            fin = 0;
        }
        cout << "Introduzca el nombre con el que se guardara el archivo "<<endl;
        gets(texto[fin].nombre);
        cout << "Introduzca lo que llevara el archivo: "<<endl;
        gets(texto[fin].texto);
    }
}

bool Cola::llena()
{
    if ((frente == fin + 2) || (frente == 0 && fin == TAMMAX - 2) || (frente == 1 && fin == TAMMAX - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool Cola::vacia()
{
    if ((frente == fin+1) || (frente == 0 && fin == TAMMAX - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

impresion Cola::desencolar(){
    if(vacia())
    {
        cout<<"La cola esta vacia"<<endl;
        system("pause");
    }
    else
    {
        cout << "nombre : "<<texto[frente].nombre<<endl;
        cout << "datos : "<<texto[frente].texto<<endl;
        frente++;
        if (frente == TAMMAX)
        {
            frente = 0;
        }
        return texto[frente];
    }
}

impresion Cola::frent(){
    if(vacia())
    {
        cout<<"La cola esta vacia"<<endl;
        system("pause");
    }
    else
    {
        cout << "nombre : "<<texto[frente].nombre<<endl;
        cout << "datos : "<<texto[frente].texto<<endl;
        return texto[frente];
    }
}
