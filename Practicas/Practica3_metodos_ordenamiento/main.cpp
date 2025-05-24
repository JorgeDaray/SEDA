#include <iostream>
#include <cstring>

#define TAMLISTA 20

using namespace std;

void menu();

typedef int tipo_dato,temp;

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
void burbuja_mejorada();
void insercion();
void seleccion();
void mezcla( int , int );
void quicksort ( int , int );
bool lista_ordenada ();
temp arreglo_copia[TAMLISTA];

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

void Lista::anular(){
ultimo = -1;
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

    for (int i = pos ; i <= ultimo ; i++){

    datos[i] = datos[i + 1];

    }
    ultimo--;
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

bool Lista::lista_ordenada(){
    int j = primero, i = ultimo;
        while (j < i){
            if (datos[j] > datos[j+1]){
                    return 1;
            }
            j++;
        }
        i--;
    return 0
    ;
}

void Lista::localiza(tipo_dato dato){
    int opc;
    if (vacia()){

        cout<<"La lista esta vacia"<<endl;
        system("pause");

        return;
    }
   	system("cls");
    cout<<"Que metodo quieres usar :"<<endl;
    cout<<"1) Metodo lineal"<<endl;
	cout<<"2) metodo binario"<<endl;
	cout<<"2) Seleccione opcion : "<<endl;
	cin>>opc;
	switch(opc){

        case 1:{
            cout<<"\n Metodo lineal\n\n"<<endl;
            int i;
            bool encontrado;
            for ( i = primero ; i <= ultimo ; i++ ){
                if (datos[i] == dato){
                    cout<<" Posicion numero: "<<i<<"\n Dato: "<<datos[i]<<" "<<endl;
                    cout<<endl;
                    encontrado = true;
                }
            }
                if (encontrado == false){
                    cout<<" Dato no encontrado: "<<endl;
                }
        }break;

        case 2:{
    if (lista_ordenada()){
        cout<<" La lista no esta ordenada"<<endl;
        return;
    }
        int i = 0, j = ultimo, m;
        bool encontrado;
        while ( i <= j ){
            m = ( i + j )/2;
            if ( datos[m] == dato ){
                cout<<" Posicion numero: "<<m<<"\n Dato: "<<datos[m]<<" "<<endl;
                cout<<endl;
                encontrado = true;
            }
            if ( dato < datos[m] ){
                j = m - 1;
            }
            else{
                i = m + 1;
            }
        }
        if (encontrado == false){
            cout<<" Dato no encontrado: "<<endl;
        }
        }break;
	}
}

void Lista::burbuja_mejorada(){
if (vacia()){

        cout<<"La lista esta vacia"<<endl;
        system("pause");

        return;
    }
        int i = ultimo, j;
        int aux;
        bool cambio;
        do{
            cambio = false;
            j = 0;
            while (j < i){
                if (datos[j] > datos[j+1]){
                    aux = datos[j];
                    datos[j] = datos[j+1];
                    datos[j+1] = aux;
                    cambio = true;
                }
                j++;
            }
            i--;
        }while(cambio);
}

void Lista::insercion(){
int i = 1, j;
int aux;
    while(i <= ultimo){
        aux = datos[i];
        j = i;
        while( j > 0 && aux < datos[j-1]){
            datos[j] = datos[j-1];
            j--;
        }
        if(i != j){
            datos[j] = aux;
        }
        i++;
    }
}

void Lista::seleccion(){
    int i = 0, j, m;
    int aux;
    while( i < ultimo ){
        m = i;
        j = i +1;
        while( j <= ultimo ){
            if( datos[j] < datos[m] ){
                m = j;
            }
            j++;
        }
            if( m!= i ){
                aux = datos[i];
                datos[i] = datos[m];
                datos[m] = aux;
            }
        i++;
    }

}

void Lista::mezcla( int primero, int ultimo ){
    if ( primero >= ultimo ){
        return;
    }

    int medio = ((primero + ultimo)/2);
    mezcla ( primero, medio );
    mezcla ( medio + 1, ultimo );

    for ( int c = primero ; c <= ultimo ; c++ ){
        arreglo_copia[c] = datos[c];
    }

    int i = primero, j = medio + 1, x = primero;
    while ( i <= medio && j <= ultimo ){
        while ( i <= medio && arreglo_copia[i] <= arreglo_copia[j] ){
            datos[x++] = arreglo_copia[i++];
        }
        if ( i <= medio ){
            while ( j <= ultimo && arreglo_copia[j] <= arreglo_copia[i] ){
                datos[x++] = arreglo_copia[j++];
            }
        }
    }
    while ( i <= medio ){
        datos[x++] = arreglo_copia[i++];
    }
    while ( j <= ultimo ){
        datos[x++] = arreglo_copia[j++];
    }
}

void Lista::quicksort( int primero, int ultimo ){
    int aux, j, i;
    if ( primero >= ultimo ){
        return;
    }

    aux = datos[(primero + ultimo)/2];
    datos[(primero + ultimo)/2] = datos[ultimo];
    datos[ultimo] = aux;


    i = primero, j = ultimo;
    while ( i < j ){
        while ( i < j && datos[i] <= datos[ultimo] ){
            i++;
        }
        while ( i < j && datos[j] >= datos[ultimo] ){
            j--;
        }
        if ( i != j ){
            aux = datos[i];
            datos[i] = datos[j];
            datos[j] = aux;
        }
    }
        if ( i != ultimo ){
            aux = datos[i];
            datos[i] = datos[ultimo];
            datos[ultimo] = aux;
        }
    quicksort( primero ,i-1 );
    quicksort( i+1 ,ultimo );

}

struct Lista mi_lista;
int main(){
int opc=0;
    do{
   	system("cls");
   	 menu();
    cout<<"Continuar 1 salir 12:"<<endl;cin>>opc;
   }while(opc!=12);
    system("pause>>cls");
return 0;
}

void menu(){
int opc=0;
int dato,pos;
	cout<<" Practica 3"<<endl;
	cout<<"1) Insertar elemento (Por posicion)"<<endl;
	cout<<"2) Eliminar elemento"<<endl;
	cout<<"3) recupera elemento"<<endl;
	cout<<"4) localiza posicion"<<endl;
	cout<<"5) Imprimir Lista"<<endl;
    cout<<"6) Anular Lista"<<endl;
    cout<<"7) Ordenamiento_Burbuja"<<endl;
    cout<<"8) Ordenamiento_Insercion"<<endl;
    cout<<"9) Ordenamiento_Seleccion"<<endl;
    cout<<"10) Ordenamiento_Mezcla"<<endl;
    cout<<"11) Ordenamiento_Quicksort"<<endl;
    cout<<"12) Salir"<<endl;
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

        case 7: {
        mi_lista.burbuja_mejorada();
        }break;

        case 8: {
        mi_lista.insercion();
        }break;

        case 9: {
        mi_lista.seleccion();
        }break;

        case 10: {
        mi_lista.mezcla(mi_lista.primero, mi_lista.ultimo);
        }break;

        case 11: {
        mi_lista.quicksort(mi_lista.primero, mi_lista.ultimo);
        }break;

        case 12:break;

        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}
