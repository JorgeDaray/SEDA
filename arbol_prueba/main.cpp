
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

 void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void colos(int X){
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),X);
}

struct Nodo{
 int dato;
 Nodo *izq;
 Nodo *der;
 int x;
 int y;
 Nodo *sig;
};

Nodo *crearNodo(int n);
void insertarNodo(Nodo *&, int, int);
void menu();
void mostrar(int *, int);
void burbuja();
void tree(int *, int);
void reseteo();

Nodo *arbol=NULL;
Nodo *cab=NULL;
Nodo *ult=NULL;
int level=2;
int coordenada=40;

int main(){
 system("mode 120,45");
 system("color 7");
 hidecursor();

 menu();

 getch();
 return 0;
}

Nodo *crearNodo(int n){
 Nodo *nuevo_nodo=new Nodo();

 nuevo_nodo->dato=n;
 nuevo_nodo->izq=NULL;
 nuevo_nodo->der=NULL;
 nuevo_nodo->sig=NULL;

 return nuevo_nodo;
}

int once=1;

void insertarNodo(Nodo *&arbol, int n, int level){

 if(arbol==NULL){
  Nodo *nuevo_nodo=crearNodo(n);
  arbol=nuevo_nodo;

  if(once==1){
   cab=ult=nuevo_nodo;
   once=0;
  }else{
   ult->sig=nuevo_nodo;
   ult=nuevo_nodo;
  }

  nuevo_nodo->y=level;

 }else{
  int valorRaiz=arbol->dato;
  if(n<valorRaiz){
   insertarNodo(arbol->izq,n,(level+1));

  }else if(n>valorRaiz){
   insertarNodo(arbol->der,n,(level+1));
  }
 }
 burbuja();
}

int x=3;
int y=3;
string a="->";
int op;

string opciones[]={".....Menu.....","Insertar","Salir"};

void menu(){
 system("cls");
 while(true){
  gotoxy(6,1);cout<<opciones[0];
  gotoxy(6,3);cout<<opciones[1];
  gotoxy(6,4);cout<<opciones[2];

  gotoxy(x,y);cout<<a;

  op=getch();
  gotoxy(x,y);cout<<"  ";

  switch(op){
   case 72:
    if(y==3){
     y=4;
    }else{
     y--;
    }
    break;
   case 80:
    if(y==4){
     y=3;
    }else{
     y++;
    }
    break;
   case 13:
    if(y==3){
     int dat;
     gotoxy(3,7);cout<<"=> ";cin>>dat;
     insertarNodo(arbol,dat,level);
    }
    if(y==4){
     exit(1);
    }
    break;
  }
 }


}

Nodo *aux;
void mostrar(int *lista, int numero){
 if(cab!=NULL){
  system("cls");
  gotoxy(10,38);cout<<"NORMAL:   ";
  aux=cab;
  do{
   cout<<aux->dato;
   aux=aux->sig;
   cout<<" >> ";
  }while(aux!=NULL);
  cout<<"NULL";

  gotoxy(10,40);cout<<"ORDENADO: ";
  for(int i=0;i<numero;i++){
   cout<<*(lista++);
   cout<<" == ";
  }
  cout<<"NULL";


  aux=cab;
  do{
   gotoxy(aux->x,aux->y);
   cout<<aux->dato;
   aux=aux->sig;
  }while(aux!=NULL);
 }

}



Nodo *p;
int *lista;

void burbuja(){

 p=cab;

 int numero=0;

 while(p!=NULL){
  p=p->sig;
  numero++;
 }

 gotoxy(-1,-1);cout<<numero;

 p=cab;
 lista = new int[numero];

 for(int i=0;i<numero;i++){
  *(lista+i)=p->dato;
  p=p->sig;
 }

 int auxiliar;
 for(int i=0;i<numero;i++){
  for(int j=0;j<numero-1;j++){
   if( *(lista+j) > *(lista+j+1)  ){
    auxiliar=*(lista+j) ;
    *(lista+j)=*(lista+j+1);
    *(lista+j+1)=auxiliar;
   }
  }
 }


 tree(lista,numero);
 mostrar(lista,numero);

}


Nodo *r;
void tree(int *lista,int numero){
 Nodo *help;
 int coordenada=40;
 for(int i=0;i<numero;i++){
  help->dato=*(lista+i);



  r=cab;
  for(int j=0;j<numero;j++){
   if(  help->dato == (r->dato)  ){
    r->x=coordenada;
   }
   r=r->sig;
  }
  coordenada=coordenada+2;
 }
}
