#include <iostream>
#include <windows.h>
#define TAMMAX 10
void menu();
using namespace std;

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon,dwPos);
}

void imprimir0(){
            gotoxy(54,14);
            cout <<" -- "<<endl;
            gotoxy(54,15);
            cout <<"|  | "<<endl;
            gotoxy(54,16);
            cout <<"     "<<endl;
            gotoxy(54,17);
            cout <<"|  | "<<endl;
            gotoxy(54,18);
            cout <<" -- "<<endl;
}

void imprimir1(){
            gotoxy(1,14);
            cout <<" | "<<endl;
            gotoxy(1,15);
            cout <<" | "<<endl;
            gotoxy(1,16);
            cout <<"   "<<endl;
            gotoxy(1,17);
            cout <<" | "<<endl;
            gotoxy(1,18);
            cout <<" | "<<endl;
}

void imprimir2(){
            gotoxy(6,14);
            cout <<" -- "<<endl;
            gotoxy(6,15);
            cout <<"   | "<<endl;
            gotoxy(6,16);
            cout <<" -- "<<endl;
            gotoxy(6,17);
            cout <<"| "<<endl;
            gotoxy(6,18);
            cout <<" -- "<<endl;
}

void imprimir3(){
            gotoxy(12,14);
            cout <<" -- "<<endl;
            gotoxy(12,15);
            cout <<"   | "<<endl;
            gotoxy(12,16);
            cout <<" -- "<<endl;
            gotoxy(12,17);
            cout <<"   | "<<endl;
            gotoxy(12,18);
            cout <<" -- "<<endl;
}

void imprimir4(){
            gotoxy(18,14);
            cout <<"|  |"<<endl;
            gotoxy(18,15);
            cout <<"|  |"<<endl;
            gotoxy(18,16);
            cout <<" --  "<<endl;
            gotoxy(18,17);
            cout <<"   |"<<endl;
            gotoxy(18,18);
            cout <<"   |"<<endl;
}

void imprimir5(){
            gotoxy(24,14);
            cout <<" -- "<<endl;
            gotoxy(24,15);
            cout <<"|  "<<endl;
            gotoxy(24,16);
            cout <<" -- "<<endl;
            gotoxy(24,17);
            cout <<"   |"<<endl;
            gotoxy(24,18);
            cout <<" -- "<<endl;
}

void imprimir6(){
            gotoxy(30,14);
            cout <<" -- "<<endl;
            gotoxy(30,15);
            cout <<"|  "<<endl;
            gotoxy(30,16);
            cout <<" -- "<<endl;
            gotoxy(30,17);
            cout <<"|  |"<<endl;
            gotoxy(30,18);
            cout <<" -- "<<endl;
}

void imprimir7(){
            gotoxy(36,14);
            cout <<" -- "<<endl;
            gotoxy(36,15);
            cout <<"|  |"<<endl;
            gotoxy(36,16);
            cout <<"|  |"<<endl;
            gotoxy(36,17);
            cout <<"   |"<<endl;
            gotoxy(36,18);
            cout <<"   |"<<endl;
}

void imprimir8(){
            gotoxy(42,14);
            cout <<" -- "<<endl;
            gotoxy(42,15);
            cout <<"|  | "<<endl;
            gotoxy(42,16);
            cout <<" -- "<<endl;
            gotoxy(42,17);
            cout <<"|  | "<<endl;
            gotoxy(42,18);
            cout <<" -- "<<endl;
}

void imprimir9(){
            gotoxy(48,14);
            cout <<" -- "<<endl;
            gotoxy(48,15);
            cout <<"|  | "<<endl;
            gotoxy(48,16);
            cout <<" -- "<<endl;
            gotoxy(48,17);
            cout <<"   | "<<endl;
            gotoxy(48,18);
            cout <<" -- "<<endl;
}

void imprimir(int c){
        if (c == '0'){
            imprimir0();
        }
        if (c == '1'){
            imprimir1();
        }
        if (c == '2'){
            imprimir2();
        }
        if (c == '3'){
            imprimir3();
        }
        if (c == '4'){
            imprimir4();
        }
        if (c == '5'){
            imprimir5();
        }
        if (c == '6'){
            imprimir6();
        }
        if (c == '7'){
            imprimir7();
        }
        if (c == '8'){
            imprimir8();
        }
        if (c == '9'){
            imprimir9();
        }
}

void ingresar(){
    char c;
    int nc = 0;
    cin.ignore();
    cout << "Ingrese numeros: "<<endl;
    while ((c = getchar()) != '\n'){
            nc++;
            imprimir(c);
    }
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
	cout<<"*\tEJERCICIO 4\t*"<<endl;
	cout<<"1) Ingresar numeros"<<endl;
	cout<<"2) Salir"<<endl;
    cout<<"Seleccione opcion:"<<endl;
    cin>>opc;
	switch(opc){

		case 1:{
		    ingresar();
		}
        break;

        case 2:break;

        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}
