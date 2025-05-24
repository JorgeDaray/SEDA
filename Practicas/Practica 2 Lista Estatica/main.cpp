#include <iostream>
#include <cstring>

#define TAMLISTA 10

using namespace std;

void menu();

typedef int tipo_dato;

struct Lista{
tipo_dato datos[TAMLISTA];
void inicializa();
bool vacia();
bool llena();
void insertar(int pos, tipo_dato elem);
void elimina(int pos);
int ultimo;
int primero;
void localiza(tipo_dato dato);
void recupera(int pos);
void imprimir();
void anular();

Lista(){
inicializa();
}
};

void Lista::inicializa(){
ultimo = -1;
primero = 0;
}

bool Lista::vacia(){
return ultimo == -1;
}

bool Lista::llena(){
return ultimo == TAMLISTA - 1;
}


void Lista::insertar(int pos, tipo_dato elem){

    if (llena() || pos < 0 || pos > ultimo + 1){

        cout<<"Ingresa un elemento consecutivo valido"<<endl;
        system("pause");
        return;
    }

    for(int i = ultimo+1 ; i > pos ; i-- ){

        datos[i] = datos[i - 1];
    }

        datos[pos] = elem;

    ultimo++;
}


void Lista::elimina(int pos){
    if (vacia() || pos < 0 || pos > ultimo ){

        cout<<"La lista esta vacia"<<endl;
        system("pause");

        return;
    }

    for (int i = pos ; i < ultimo ; i++){

    datos[i] = datos[i + 1];

    ultimo--;
    }
}

void Lista::imprimir(){
    if (vacia()){

        cout<<"La lista esta vacia"<<endl;
        system("pause");
        return;
    }
    for(int i = primero ; i <= ultimo ; i++){
    cout<<"Posicion numero: "<<i<<"\n Dato: "<<datos[i]<< " "<<endl;
    }
}

void Lista::recupera(int pos){
    if (vacia() || pos < 0 || pos > ultimo ){

        cout<<"La lista esta vacia"<<endl;
        system("pause");

        return;
    }

    cout<<"Posicion numero: "<<pos<<"\n Dato: "<<datos[pos]<<" "<<endl;
    cout<<endl;
}

void Lista::localiza(tipo_dato dato){
    if (vacia()){

        cout<<"La lista esta vacia"<<endl;
        system("pause");

        return;
    }

    int i;
    for (i=primero;i<=ultimo;i++){
        if (datos[i] == dato){
            cout<<"Posicion numero: "<<i<<"\n Dato: "<<datos[i]<<" "<<endl;
            cout<<endl;
        }
    }
}

void Lista::anular(){
ultimo = -1;
}


struct Lista mi_lista;
int main(){
int opc=0;
    do{
   	system("cls");
   	 menu();
    cout<<"Continuar 1 salir 7:"<<endl;cin>>opc;
   }while(opc!=7);
    system("pause>>cls");
return 0;
}

void menu(){
int opc=0;
int dato,pos;
	cout<<" Practica 2"<<endl;
	cout<<"1) Insertar elemento (Por posicion)"<<endl;
	cout<<"2) Eliminar elemento"<<endl;
	cout<<"3) recupera elemento"<<endl;
	cout<<"4) localiza posicion"<<endl;
	cout<<"5) Imprimir Lista"<<endl;
    cout<<"6) Anular Lista"<<endl;
    cout<<"7) Salir"<<endl;
    cout<<"Seleccione opcion:"<<endl;
    cin>>opc;
	switch(opc){

		case 1: {
        cout<<"En que posicion desea insertar el elemento :"<<endl;cin>>pos;
        cout<<"Inserte elemento: "<<endl;cin>>dato;
        mi_lista.insertar(pos,dato);

        }break;
        case 2: {
        cout<<"Que posicion deseas eliminar :"<<endl;cin>>pos;
        mi_lista.elimina(pos);
        }break;
        case 3: {
        cout<<"Que posicion deseas consultar :"<<endl;cin>>pos;
        mi_lista.recupera(pos);
        }break;

        case 4: {
        cout<<"Que dato deseas buscar :"<<endl;cin>>dato;
        mi_lista.localiza(dato);
        }break;

        case 5: {
        mi_lista.imprimir();
        }break;

        case 6: {
        mi_lista.anular();
        }break;

        case 7:break;

        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}
