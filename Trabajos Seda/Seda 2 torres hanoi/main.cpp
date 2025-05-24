#include <iostream>
#include <cstring>
#define TAMMAX 500

using namespace std;

void menu();

typedef int tipo_dato,temp;

struct Pila{
tipo_dato datos[TAMMAX];
void inicializa();
int tope;
bool vacia();
bool llena();
void push(tipo_dato elem);
void pop();
int top();
void dibujar_torres();
bool lista_ordenada ();

Pila(){
inicializa();
}
};

void Pila::inicializa(){
tope = -1;
}

bool Pila::vacia(){
if (tope == -1)
{
    return true;
}
else{
    return false;
}
}

bool Pila::llena(){
if (tope == TAMMAX -1 ){
    return true;
}
else{
    return false;
}
}

//Ingresar los discos a la torre
void Pila::push(tipo_dato elem){
if (llena()){
    cout<<"desbordamiento de datos"<<endl;
    system("pause");
    return;
}
else{
    tope = tope + 1;
    datos[tope] = elem;
}
}

//Sacar los discos a la torre
void Pila::pop(){
if (vacia()){
    cout<<"Insuficiencia de datos"<<endl;
    system("pause");
    return;
}
else{
    tope = tope - 1;
}
}

int Pila::top(){
if (vacia()){
    cout<<"Insuficiencia de datos"<<endl;
    system("pause");
    return false;
}
else{
    return datos[tope];
}
}

void Pila::dibujar_torres(){

    for fila in torres:
        for col in fila:
            if col == 0:
                print(" "*(discos+4), "*", " "*(discos+4), end="")
            else:
                print(" "*(discos-col+3), "[", "*"*(2*col-1), "]", " "*(discos-col+3), end="")
        print()
    time.sleep(0.9)

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
    int numdiscos;
    cout<<"******\tTORRE DE HANOI\t******"<<endl;

	cout<<"\nIngrese la cantidad de disco(s): "<<endl;cin>>numdiscos;

	cout<<("\n\t");
	system("pause");
}


