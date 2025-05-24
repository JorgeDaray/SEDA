#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct jugador{
   int cve;
   char nombre[30];

}a[5];

int numero=-1;
int index=0;
int numeroguia=0;
void menu();
void registrar();

int main(int argc, char** argv) {
   int opc=0;
   do{
   	system("cls");
   	 menu();
    cout<<"Continuar 1 salir 2:"<<endl;
    cin>>opc;
   }while(opc!=2);
   system("pause>>cls");
	return 0;
}
void menu(){
	int opc=0,cve=0;
	cout<<"Tarea 1"<<endl;
	cout<<"1) crear jugador"<<endl;
    cout<<"Seleccione opcion:"<<endl;
    cin>>opc;
	switch(opc){
		case 1: registrar();break;
	}
}

void registrar(){
	char n[10][30];
	a[index].cve=numeroguia+1;
	int vactor[1];
int cve;
    int elector;
    srand(time(NULL));
    int g;
    for (int i=0;i<=20;i++){
    g=1;
    elector=1 + rand()%(1000-9999);
for (int d=0;d<=g;d++){
    if (elector==vactor[d]){
        g=g-g;
        i=i-1;
    }

    while ((g==1)&&(elector!=vactor[d])&&(d==i)){
        vactor[i]=elector;
        cin>>cve;
        cout<<vactor[i]<<endl;
    }
}
}
}

