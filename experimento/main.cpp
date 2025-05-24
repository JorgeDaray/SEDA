#include <iostream>
#include <string.h>
#define MaxData 100

using namespace std;

int Arreglo [MaxData];
void inserta(int cantidad){
    if (cantidad < 0 || cantidad > MaxData){

    cout<<"Ingresa un elemento valido"<<endl;
    system("pause");
    return;
}
    for(int i = 0; i < cantidad; i ++){
    cout <<" introduce el elemento :"<<endl;
    cin >> Arreglo[i];
    }
}

void imprimeLista(int cantidad){
    int i;
    for(i = 0; i < cantidad; i ++){
    cout<<" posicion :"<<i<<endl;
    cout<<" dato: "<<Arreglo[i]<<endl;
    }
}

void Promedio(int cantidad){
    int i,s = 0,prom;
    for(i = 0; i < cantidad; i ++){
    s = s+Arreglo[i];
    }
    prom = s/cantidad;
    cout << "\n suma:"<<s<<"\n promedio:"<<prom<<endl;
}

void moda(int cantidad){
    int i = 0,maxre = 0;
    int m, repeticiones = 0;
    while( i < cantidad )
    {
        int j = 0;
        while (j < cantidad)
        {
            if (Arreglo[i] == Arreglo[j] && i != j)
            {
                repeticiones++;
            }
            j++;
        }
            if (repeticiones > maxre)
            {
                m = Arreglo[i];
                maxre = repeticiones;
            }
            i++;
            repeticiones = 0;
    }
    cout <<"La moda es: "<<m<<"\n que aparece: "<<maxre+1<<"veces"<<endl;

    int modasre[50];
    int indice = 0, modas;
    modas = maxre;
	repeticiones = 0, maxre = 0;
	modasre[0] = m, i = 0;
	bool bandera = true;

	while( i < cantidad )
    {
        int j = 0;
        while (j < cantidad)
        {
            if (Arreglo[i] == Arreglo[j] && i != j)
            {
                repeticiones++;
            }
            j++;
        }
            if (repeticiones > maxre)
            {
                m = Arreglo[i];
                maxre = repeticiones;
            }

		if (repeticiones == modas)
		{
		    int r = 0;
			while (r <= indice)
            {
                if (modasre[r] == Arreglo[i])
                {
                    bandera = false;
                }
                r++;
			}

			if(bandera == true)
			{
				indice++;
				modasre[indice] = Arreglo[i];
				cout <<"\n La moda es: "<<modasre[indice]<<"\n que aparece: "<<maxre+1<<"veces"<<endl;
			}

		}

		bandera = true;
		repeticiones = 0;
		i++;
	}
}


int main(){
    int opcion, cantidad;
    while(opcion!=5){
        cout<<"\n Que opcion deseas, \n5-Salir \n1-insertar elementos \n2-imprime lista \n3-Promedio y suma \n4-Moda \nOpcion: "<<endl;
        cin>>opcion;

        switch(opcion){
            case 1: system("cls");
                cout<<"Inserta la cantidad de elementos a insertar :"<<endl;cin>>cantidad;
                inserta(cantidad);
                break;
            case 2: system("cls");
                imprimeLista(cantidad);
                break;
            case 3: system("cls");
                Promedio(cantidad);
                break;
            case 4: system("cls");
                moda(cantidad);
                break;
            case 5: break;
            default: printf("Esa opcion no existe...\n");
        }
    }

    return 0;
}
