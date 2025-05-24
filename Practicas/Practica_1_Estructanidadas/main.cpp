#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string.h>

using namespace std;

const int MaxData=10;

struct Address{
    char street[100];
    char city[50];
    char state[20];
};

struct persona{
    char name[50];
    struct Address Address_persona;
    int codigo_postal;
    int bandera = 0;
}data[10];

int head=0;
int actual=0;

void inserta(int pos){
    if (pos < 0 || pos >= MaxData-1){

    cout<<"Ingresa un elemento valido"<<endl;
    system("pause");
    return;
}
    fflush(stdin);
    cout<<"Give the name: ";
    cin.getline(data[pos].name,50);
    cout<<"Give the street ";
    cin.getline(data[pos].Address_persona.street,100);
    cout<<"Give the city ";
    cin.getline(data[pos].Address_persona.city,50);
    cout<<"Give the state: ";
    cin.getline(data[pos].Address_persona.state,20);
    cout<<"Codigo postal: ";
    scanf("%i",&data[pos].codigo_postal);
    data[pos].bandera = 1;
}

void imprimeLista(int pos){
    int i;
    for(i=head; i<= MaxData; i ++){
    if(data[i].bandera == 1){
    cout<<" posicion :"<<i<<endl;
    cout<<" Name: "<<data[i].name<<endl;
    cout<<" street: "<<data[i].Address_persona.street<<endl;
    cout<<" Codigo postal: "<<data[i].codigo_postal<<endl<<endl;
    }
}
}
void buscar(int pos){
    cout<<"posicion: "<<pos<<endl;
    if (pos > MaxData || pos <head || data[pos].bandera == 0){
        cout<<"posicion no encontrada"<<endl;
        return;
    }
    cout<<"\nName: "<<data[pos].name<<endl;
    cout<<"street: "<<data[pos].Address_persona.street<<endl;
    cout<<"City: "<<data[pos].Address_persona.city<<endl;
    cout<<"State: "<<data[pos].Address_persona.state<<endl;
    cout<<"codigo postal: "<<data[pos].codigo_postal<<endl;
    pos++;
    }

void remover(){
int indice;
cout<<"Que nodo quieres remover?"<<endl; cin>>indice;
    if (indice > MaxData || indice <head || data[indice].bandera == 0 ){
    cout<<"indice fuera de rango"<<endl;
    return;
    }
int i;
    for(i=indice; i<=MaxData; i++){
    data[indice].bandera = 0;
    }
    if(indice == MaxData-1){
    strcpy(data[indice].name,"");
    strcpy(data[indice].Address_persona.city,"");
    strcpy(data[indice].Address_persona.street,"");
    strcpy(data[indice].Address_persona.state,"");
    data[indice].codigo_postal=0;
    }
    actual=head;
}

int main(){
    int opcion, pos;
    while(opcion!=5){
        cout<<"Que opcion deseas, \n1-insertar por posicion \n2-imprime lista \n3-remover por posicion \n4-buscar por posicion \n5-salir \nOpcion: "<<endl;
        cin>>opcion;

        switch(opcion){
            case 1: system("cls");
                cout<<"En que posicion desea insertar el elemento :"<<endl;cin>>pos;
                inserta(pos);
                break;
            case 2: system("cls");
                imprimeLista(pos);
                break;
            case 3: system("cls");
                remover();
                system("pause");
                break;
            case 4: system("cls");
                cout<<"Que posicion deseas consultar : "<<endl; cin>>pos;
                buscar(pos);
                break;
            case 5: break;
            default: printf("Esa opcion no existe...\n");
        }
    }

    return 0;
}

