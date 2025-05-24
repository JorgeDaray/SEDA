#include <iostream>
#define TAMMAX 500

using namespace std;
typedef char tipo_dato;
void menu();

class Pila{
    public:
        tipo_dato datos[TAMMAX];
        int tope, valor, valorc;
        Pila();
        bool vacia();
        bool llena();
        void push(tipo_dato elem);
        tipo_dato pop();
        tipo_dato top();
        void imprimir_pila();
        void imprimir_pila2();
        void imprimir_pila3();
        void ganador();
        };

Pila::Pila(){
    tope = -1;
    valor = -1;
    valorc = -1;
}

bool Pila::vacia()
{
    return tope==-1;
}

bool Pila::llena()
{
    return tope == TAMMAX-1;
}

void Pila::push(tipo_dato e)
{
    if (llena()){
        cout<<"desbordamiento de datos"<<endl;
        system("pause");
        return;
    }
    else{
        tope++;
        datos[tope] = e;
    }
}

tipo_dato Pila::pop(){
    if(vacia()){
        cout<<"Insuficiencia de datos"<<endl;
        system("pause");
        return false;
    } else {
        tope--;
        return datos[tope+1];
    }
}

tipo_dato Pila::top(){
    if(vacia()){
        cout<<"Insuficiencia de datos"<<endl;
        system("pause");
        return false;
    } else {
        return datos[tope+1];
    }
}

void Pila::imprimir_pila(){
    cout << "tope: "<<tope<<endl;
    for (int t = tope; t > -1; t--){
        std::cout <<"["<<datos[t]<<"]"<< std::endl;
    }
            std::cout <<"_____"<< std::endl;
            std::cout <<"Pila1"<< std::endl;
}

void Pila::imprimir_pila2(){
            for (int t = tope; t > -1; t--){
            std::cout <<"\t\t["<<datos[t]<<"]"<< std::endl;
            }
            std::cout <<"\t\t_____"<< std::endl;
            std::cout <<"\t\tPila2"<< std::endl;
}

void Pila::imprimir_pila3(){
             for (int t = tope; t > -1; t--){
            std::cout <<"\t\t\t\t["<<datos[t]<<"]"<< std::endl;
            }
            std::cout <<"\t\t\t\t_____"<< std::endl;
            std::cout <<"\t\t\t\tPila3"<< std::endl;
}

using namespace std;

int main()
{
    int opc=0;
    do{
   	system("cls");
   	 menu();
    cout<<"Continuar 1 salir 4:"<<endl;cin>>opc;
   }while(opc!=4);
    system("pause>>cls");
    return 0;
}

void menu(){
int opc=0;
	cout<<"**\tTORRE DE HANOI\t****"<<endl;
	cout<<"4) Salir"<<endl;
	cout<<"1) Nivel 1 (3 torres)"<<endl;
	cout<<"2) Nivel 2 (4 torres)"<<endl;
	cout<<"3) Nivel 3 (5 torres)"<<endl;
    cout<<"Seleccione opcion:"<<endl;
    cin>>opc;
	switch(opc){

		case 1: {
		    Pila miPila,miPila2,miPila3;
		    miPila.push('3');
            miPila.push('2');
            miPila.push('1');
            miPila.imprimir_pila();
            miPila2.imprimir_pila2();
            miPila3.imprimir_pila3();
            cout <<"Tope 1:"<<miPila.tope<<endl;
            cout <<"Tope 2:"<<miPila2.tope<<endl;
            cout <<"Tope 3:"<<miPila3.tope<<endl;
            cout <<"valor 1:"<<miPila.valor<<endl;
            cout <<"valor 2:"<<miPila.valor<<endl;
            cout <<"valor 3:"<<miPila.valor<<endl;
            cout <<"valorc 1:"<<miPila.datos[miPila.top()]<<endl;
            cout <<"valorc 2:"<<miPila2.datos[miPila2.top()]<<endl;
            cout <<"valorc 3:"<<miPila3.datos[miPila3.top()]<<endl;
            do{
            int opc1=0;
                cout<<"4) Salir"<<endl;
                cout<<"1) jugar"<<endl;
                cout<<"Seleccione opcion:"<<endl;
                cin>>opc1;
                switch(opc1){

                case 1: {
                    int torre = 0;
                    int torr = 0;
                    miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                    cout <<"De que pila quiere sacar el disco ?:"<<endl;cin>>torre;
                    cout <<"En que pila quiere meter el disco ?:"<<endl;cin>>torr;
                    if (torre == 1){
                        if (miPila.vacia()){
                            cout << "no se puede esta vacia" <<endl;
                            miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                            break;
                        }
                        else if (miPila.datos[miPila.tope] == '1'){
                            miPila.valor = 1;
                        }
                        else if(miPila.datos[miPila.tope] == '2'){
                            miPila.valor = 2;
                        }
                        else if(miPila.datos[miPila.tope] == '3'){
                            miPila.valor = 3;
                        }
                        if (torr == 1 && miPila.datos[miPila.tope] > miPila.datos[miPila.tope]){
                        cout << "Movimiento invalido " <<endl;
                        miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                        break;
                        }
                        else if (torr == 2 && miPila2.datos[miPila2.tope] > miPila.datos[miPila.tope]){
                        cout << "Movimiento invalido " <<endl;
                        miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                        break;
                        }
                        else if (torr == 3 && miPila3.datos[miPila3.tope] > miPila.datos[miPila.tope]){
                        cout << "Movimiento invalido " <<endl;
                        miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                        break;
                        }
                        cout << "dato: "<<miPila.datos[miPila.tope]<<endl;
                        std::cout << miPila.pop() << std::endl;
                    }
                    if (torre == 2){
                        if (miPila2.vacia()){
                            cout << "no se puede esta vacia" <<endl;
                            miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                            break;
                        }
                        else if (miPila2.datos[miPila2.tope] == '1'){
                            miPila.valor = 1;
                        }
                        else if(miPila2.datos[miPila2.tope] == '2'){
                            miPila.valor = 2;
                        }
                        else if(miPila2.datos[miPila2.tope] == '3'){
                            miPila.valor = 3;
                        }
                        if (torr == 1 && miPila.datos[miPila.tope] < miPila2.datos[miPila2.tope]){
                        cout << "Movimiento invalido " <<endl;
                        miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                        break;
                        }
                        else if (torr == 2 && miPila2.datos[miPila2.tope] > miPila2.datos[miPila2.tope]){
                        cout << "Movimiento invalido " <<endl;
                        miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                        break;
                        }
                        else if (torr == 3 && miPila3.datos[miPila3.tope] < miPila2.datos[miPila2.tope]){
                        cout << "Movimiento invalido " <<endl;
                        miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                        break;
                        }
                        cout << "dato: "<<miPila2.datos[miPila2.tope]<<endl;
                        std::cout << miPila2.pop() << std::endl;
                    }
                    if (torre == 3){
                        if (miPila3.vacia()){
                            cout << "no se puede esta vacia" <<endl;
                            miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                            break;
                        }
                        else if (miPila3.datos[miPila3.tope] == '1'){
                            miPila.valor = 1;
                        }
                        else if(miPila3.datos[miPila3.tope] == '2'){
                            miPila.valor = 2;
                        }
                        else if(miPila3.datos[miPila3.tope] == '3'){
                            miPila.valor = 3;
                        }
                        if (torr == 1 && miPila.datos[miPila.tope] <  miPila3.datos[miPila3.tope]){
                        cout << "Movimiento invalido " <<endl;
                        miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                        break;
                        }
                        else if (torr == 2 && miPila2.datos[miPila2.tope] <  miPila3.datos[miPila3.tope]){
                        cout << "Movimiento invalido " <<endl;
                        miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                        break;
                        }
                        else if (torr == 3 && miPila3.datos[miPila3.tope] >  miPila3.datos[miPila3.tope]){
                        cout << "Movimiento invalido " <<endl;
                        miPila.imprimir_pila();
                            miPila2.imprimir_pila2();
                            miPila3.imprimir_pila3();
                        break;
                        }
                        cout << "dato: "<<miPila3.datos[miPila3.tope]<<endl;
                        std::cout << miPila3.pop() << std::endl;
                    }
                    if (torr == 1 && miPila.valor == 1 ){
                        miPila.push('1');
                    }
                    else if (torr == 1 && miPila.valor == 2){
                        miPila.push('2');
                    }
                    else if (torr == 1 && miPila.valor == 3){
                        miPila.push('3');
                    }
                    if (torr == 2 && miPila.valor == 1){
                         miPila2.push('1');
                    }
                    else if (torr == 2 && miPila.valor == 2){
                         miPila2.push('2');
                    }
                    else if (torr == 2 && miPila.valor == 3){
                         miPila2.push('3');
                    }
                    if (torr == 3 && miPila.valor == 1){
                         miPila3.push('1');
                    }
                    else if (torr == 3 && miPila.valor == 2){
                         miPila3.push('2');
                    }
                    else if (torr == 3 && miPila.valor == 3){
                         miPila3.push('3');
                    }
                    miPila.imprimir_pila();
                    miPila2.imprimir_pila2();
                    miPila3.imprimir_pila3();
            cout <<"Tope 1:"<<miPila.tope<<endl;
            cout <<"Tope 2:"<<miPila2.tope<<endl;
            cout <<"Tope 3:"<<miPila3.tope<<endl;
            cout <<"valor 1:"<<miPila.valor<<endl;
            cout <<"valor 2:"<<miPila.valor<<endl;
            cout <<"valor 3:"<<miPila.valor<<endl;
            cout <<"valorc 1:"<<miPila.datos[miPila.tope]<<endl;
            cout <<"valorc 2:"<<miPila2.datos[miPila2.tope]<<endl;
            cout <<"valorc 3:"<<miPila3.datos[miPila3.tope]<<endl;
                    if (miPila.vacia() && miPila2.vacia()){
                            system("cls");
                        cout << "Ganaste Felicidades" <<endl;
                            system("pause");
                            return;
                    }
                }break;

                case 4:
                    return;
                    break;

                default:
                cout<<"La opcion: "<<opc1<<"No existe"<<endl;
                }
                }while(opc!=4);
        }break;
        /*case 2: {
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
        }break;*/

        case 4:break;

        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}
