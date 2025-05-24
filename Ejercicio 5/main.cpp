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

void imprimir0(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<" -- "<<endl;
            gotoxy(contador,15);
            cout <<"|  | "<<endl;
            gotoxy(contador,16);
            cout <<"     "<<endl;
            gotoxy(contador,17);
            cout <<"|  | "<<endl;
            gotoxy(contador,18);
            cout <<" -- "<<endl;
}

void imprimir1(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<" | "<<endl;
            gotoxy(contador,15);
            cout <<" | "<<endl;
            gotoxy(contador,16);
            cout <<"   "<<endl;
            gotoxy(contador,17);
            cout <<" | "<<endl;
            gotoxy(contador,18);
            cout <<" | "<<endl;
}

void imprimir2(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<" -- "<<endl;
            gotoxy(contador,15);
            cout <<"   | "<<endl;
            gotoxy(contador,16);
            cout <<" -- "<<endl;
            gotoxy(contador,17);
            cout <<"| "<<endl;
            gotoxy(contador,18);
            cout <<" -- "<<endl;
}

void imprimir3(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<" -- "<<endl;
            gotoxy(contador,15);
            cout <<"   | "<<endl;
            gotoxy(contador,16);
            cout <<" -- "<<endl;
            gotoxy(contador,17);
            cout <<"   | "<<endl;
            gotoxy(contador,18);
            cout <<" -- "<<endl;
}

void imprimir4(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<"|  |"<<endl;
            gotoxy(contador,15);
            cout <<"|  |"<<endl;
            gotoxy(contador,16);
            cout <<" --  "<<endl;
            gotoxy(contador,17);
            cout <<"   |"<<endl;
            gotoxy(contador,18);
            cout <<"   |"<<endl;
}

void imprimir5(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<" -- "<<endl;
            gotoxy(contador,15);
            cout <<"|  "<<endl;
            gotoxy(contador,16);
            cout <<" -- "<<endl;
            gotoxy(contador,17);
            cout <<"   |"<<endl;
            gotoxy(contador,18);
            cout <<" -- "<<endl;
}

void imprimir6(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<" -- "<<endl;
            gotoxy(contador,15);
            cout <<"|  "<<endl;
            gotoxy(contador,16);
            cout <<" -- "<<endl;
            gotoxy(contador,17);
            cout <<"|  |"<<endl;
            gotoxy(contador,18);
            cout <<" -- "<<endl;
}

void imprimir7(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<" -- "<<endl;
            gotoxy(contador,15);
            cout <<"|  |"<<endl;
            gotoxy(contador,16);
            cout <<"|  |"<<endl;
            gotoxy(contador,17);
            cout <<"   |"<<endl;
            gotoxy(contador,18);
            cout <<"   |"<<endl;
}

void imprimir8(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<" -- "<<endl;
            gotoxy(contador,15);
            cout <<"|  | "<<endl;
            gotoxy(contador,16);
            cout <<" -- "<<endl;
            gotoxy(contador,17);
            cout <<"|  | "<<endl;
            gotoxy(contador,18);
            cout <<" -- "<<endl;
}

void imprimir9(int nc){
            int contador = 1;
            for (int i = 0; i < nc; i++)
                contador = contador + 6;
            gotoxy(contador,14);
            cout <<" -- "<<endl;
            gotoxy(contador,15);
            cout <<"|  | "<<endl;
            gotoxy(contador,16);
            cout <<" -- "<<endl;
            gotoxy(contador,17);
            cout <<"   | "<<endl;
            gotoxy(contador,18);
            cout <<" -- "<<endl;
}

void imprimir(int c, int nc){
        if (c == '0'){
            imprimir0(nc);
        }
        if (c == '1'){
            imprimir1(nc);
        }
        if (c == '2'){
            imprimir2(nc);
        }
        if (c == '3'){
            imprimir3(nc);
        }
        if (c == '4'){
            imprimir4(nc);
        }
        if (c == '5'){
            imprimir5(nc);
        }
        if (c == '6'){
            imprimir6(nc);
        }
        if (c == '7'){
            imprimir7(nc);
        }
        if (c == '8'){
            imprimir8(nc);
        }
        if (c == '9'){
            imprimir9(nc);
        }
}

void ingresar(){
    char c;
    int nc = 0;
    cin.ignore();
    cout << "Ingrese numeros: "<<endl;
    while ((c = getchar()) != '\n'){
            nc++;
            imprimir(c, nc);
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
int opc=0;
	cout<<"**\tEJERCICIO 4\t****"<<endl;
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
