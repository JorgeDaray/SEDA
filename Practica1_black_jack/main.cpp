#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define Maxarreglo 52
#define Maxjugador 11

using namespace std;
int Arreglo_baraja [Maxarreglo], Arreglo_barajaj [Maxarreglo], Arreglo_barajac [Maxarreglo];
int valor_carta, contador = 0, contadorj = 0, contadorc = 0,contador_cartasjuego = 0;
int head = 0, headj = 0, headc = 0;
int dinero = 100;
int totaldj = 0,totaldc = 0, totaldj2 = 0, totaldc2 = 0;

struct Black_jack{
    char name[Maxarreglo];
    char name_jugador[Maxjugador];
    char name_compu[Maxjugador];
}Arreglo_jugador [Maxjugador], Arreglo_compu [Maxjugador], Arreglo_baraja2[Maxarreglo];

bool validar(int num, int pos)
{
    for(int i = head; i < pos; i ++)
            {
                if (num == Arreglo_baraja[i])
                {
                    return true;
                }
            }
            return false;
}

void random()
{
    int num;
    srand(time(NULL));
    for(int i = head; i < Maxarreglo; i ++)
    {
        num = rand()%52;
        while (validar(num, i) == true)
        {
            num = rand()%52;
        }
        Arreglo_baraja[i] = num;
    }
}

void inicializa()
{
    random();
    for(int i = head; i < Maxarreglo; i ++){
    switch(Arreglo_baraja[i]){
    case 0: strcpy(Arreglo_baraja2[i].name, "AS"); valor_carta = 1; Arreglo_baraja[i] = valor_carta; break;
    case 1: strcpy(Arreglo_baraja2[i].name, "AS"); valor_carta = 1; Arreglo_baraja[i] = valor_carta; break;
    case 2: strcpy(Arreglo_baraja2[i].name, "AS"); valor_carta = 1; Arreglo_baraja[i] = valor_carta; break;
    case 3: strcpy(Arreglo_baraja2[i].name, "AS"); valor_carta = 1; Arreglo_baraja[i] = valor_carta; break;
    case 4: strcpy(Arreglo_baraja2[i].name, "2"); valor_carta = 2; Arreglo_baraja[i] = valor_carta; break;
    case 5: strcpy(Arreglo_baraja2[i].name, "2"); valor_carta = 2; Arreglo_baraja[i] = valor_carta; break;
    case 6: strcpy(Arreglo_baraja2[i].name, "2"); valor_carta = 2; Arreglo_baraja[i] = valor_carta; break;
    case 7: strcpy(Arreglo_baraja2[i].name, "2"); valor_carta = 2;Arreglo_baraja[i] = valor_carta; break;
    case 8: strcpy(Arreglo_baraja2[i].name, "3"); valor_carta = 3;Arreglo_baraja[i] = valor_carta; break;
    case 9: strcpy(Arreglo_baraja2[i].name, "3"); valor_carta = 3;Arreglo_baraja[i] = valor_carta; break;
    case 10: strcpy(Arreglo_baraja2[i].name, "3"); valor_carta = 3;Arreglo_baraja[i] = valor_carta; break;
    case 11: strcpy(Arreglo_baraja2[i].name, "3"); valor_carta = 3;Arreglo_baraja[i] = valor_carta; break;
    case 12: strcpy(Arreglo_baraja2[i].name, "4"); valor_carta = 4;Arreglo_baraja[i] = valor_carta; break;
    case 13: strcpy(Arreglo_baraja2[i].name, "4"); valor_carta = 4;Arreglo_baraja[i] = valor_carta; break;
    case 14: strcpy(Arreglo_baraja2[i].name, "4"); valor_carta = 4;Arreglo_baraja[i] = valor_carta; break;
    case 15: strcpy(Arreglo_baraja2[i].name, "4"); valor_carta = 4;Arreglo_baraja[i] = valor_carta; break;
    case 16: strcpy(Arreglo_baraja2[i].name, "5"); valor_carta = 5;Arreglo_baraja[i] = valor_carta; break;
    case 17: strcpy(Arreglo_baraja2[i].name, "5"); valor_carta = 5;Arreglo_baraja[i] = valor_carta; break;
    case 18: strcpy(Arreglo_baraja2[i].name, "5"); valor_carta = 5;Arreglo_baraja[i] = valor_carta; break;
    case 19: strcpy(Arreglo_baraja2[i].name, "5"); valor_carta = 5;Arreglo_baraja[i] = valor_carta; break;
    case 20: strcpy(Arreglo_baraja2[i].name, "6"); valor_carta = 6;Arreglo_baraja[i] = valor_carta; break;
    case 21: strcpy(Arreglo_baraja2[i].name, "6"); valor_carta = 6;Arreglo_baraja[i] = valor_carta; break;
    case 22: strcpy(Arreglo_baraja2[i].name, "6"); valor_carta = 6;Arreglo_baraja[i] = valor_carta; break;
    case 23: strcpy(Arreglo_baraja2[i].name, "6"); valor_carta = 6;Arreglo_baraja[i] = valor_carta; break;
    case 24: strcpy(Arreglo_baraja2[i].name, "7"); valor_carta = 7;Arreglo_baraja[i] = valor_carta; break;
    case 25: strcpy(Arreglo_baraja2[i].name, "7"); valor_carta = 7;Arreglo_baraja[i] = valor_carta; break;
    case 26: strcpy(Arreglo_baraja2[i].name, "7"); valor_carta = 7;Arreglo_baraja[i] = valor_carta; break;
    case 27: strcpy(Arreglo_baraja2[i].name, "7"); valor_carta = 7;Arreglo_baraja[i] = valor_carta; break;
    case 28: strcpy(Arreglo_baraja2[i].name, "8"); valor_carta = 8;Arreglo_baraja[i] = valor_carta; break;
    case 29: strcpy(Arreglo_baraja2[i].name, "8"); valor_carta = 8;Arreglo_baraja[i] = valor_carta; break;
    case 30: strcpy(Arreglo_baraja2[i].name, "8"); valor_carta = 8;Arreglo_baraja[i] = valor_carta; break;
    case 31: strcpy(Arreglo_baraja2[i].name, "8"); valor_carta = 8;Arreglo_baraja[i] = valor_carta; break;
    case 32: strcpy(Arreglo_baraja2[i].name, "9"); valor_carta = 9;Arreglo_baraja[i] = valor_carta; break;
    case 33: strcpy(Arreglo_baraja2[i].name, "9"); valor_carta = 9;Arreglo_baraja[i] = valor_carta; break;
    case 34: strcpy(Arreglo_baraja2[i].name, "9"); valor_carta = 9;Arreglo_baraja[i] = valor_carta; break;
    case 35: strcpy(Arreglo_baraja2[i].name, "9"); valor_carta = 9;Arreglo_baraja[i] = valor_carta; break;
    case 36: strcpy(Arreglo_baraja2[i].name, "10"); valor_carta = 10;Arreglo_baraja[i] = valor_carta; break;
    case 37: strcpy(Arreglo_baraja2[i].name, "10"); valor_carta = 10;Arreglo_baraja[i] = valor_carta; break;
    case 38: strcpy(Arreglo_baraja2[i].name, "10"); valor_carta = 10;Arreglo_baraja[i] = valor_carta; break;
    case 39: strcpy(Arreglo_baraja2[i].name, "10"); valor_carta = 10;Arreglo_baraja[i] = valor_carta; break;
    case 40: strcpy(Arreglo_baraja2[i].name, "Joto"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 41: strcpy(Arreglo_baraja2[i].name, "Joto"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 42: strcpy(Arreglo_baraja2[i].name, "Joto"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 43: strcpy(Arreglo_baraja2[i].name, "Joto"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 44: strcpy(Arreglo_baraja2[i].name, "Quenn"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 45: strcpy(Arreglo_baraja2[i].name, "Quenn"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 46: strcpy(Arreglo_baraja2[i].name, "Quenn"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 47: strcpy(Arreglo_baraja2[i].name, "Quenn"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 48: strcpy(Arreglo_baraja2[i].name, "K"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 49: strcpy(Arreglo_baraja2[i].name, "K"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 50: strcpy(Arreglo_baraja2[i].name, "K"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    case 51: strcpy(Arreglo_baraja2[i].name, "K"); valor_carta = 10; Arreglo_baraja[i] = valor_carta; break;
    }
    cout <<"valor de carta:"<<Arreglo_baraja[i]<<endl;
    contador ++;
    }
    cout <<"contador: "<<contador<<endl;
}

void prueba()
{
    for(int i = head; i < Maxarreglo; i ++){
    cout<<" posicion :"<<i<<endl;
    cout <<"Cartas :"<<Arreglo_baraja2[i].name<<endl;
    }
    cout <<"contador: "<<contador<<endl;
}

void repartir_cartasi()
{
    if (contador < 4)
    {
        cout <<"Ya se acabaron las cartas"<<endl;
        return;
    }
    for (int i = head; i < 4; i++)
    {
        if (i < 2)
        {
            strcpy(Arreglo_jugador[i].name_jugador, Arreglo_baraja2[i].name);
            Arreglo_barajaj[i] = Arreglo_baraja[i];
            contador_cartasjuego++;
            contadorj++;
        }
        if (i >= 2)
        {
            strcpy(Arreglo_compu[i-2].name_compu, Arreglo_baraja2[i].name);
            Arreglo_barajac[i-2] = Arreglo_baraja[i];
            contador_cartasjuego++;
            contadorc++;
        }
        contador--;
        head++;
    }
}

void pedir_cartasc()
{
    if(totaldj > totaldc)
        {
            for (int i = head; i < head+1; i++)
            {
            strcpy(Arreglo_compu[i-2].name_compu, Arreglo_baraja2[i].name);
            Arreglo_barajac[i-2] = Arreglo_baraja[i];
            contador_cartasjuego++;
            contadorc++;
            contador--;
            }
            head++;
        }
        else{
            if(totaldj2 > totaldc2)
            {
                for (int i = head; i < head+1; i++)
                {
                strcpy(Arreglo_compu[i-2].name_compu, Arreglo_baraja2[i].name);
                Arreglo_barajac[i-2] = Arreglo_baraja[i];
                contador_cartasjuego++;
                contadorc++;
                contador--;
                }
                head++;
            }
        }
}

void eliminar_juegos()
{
    for (int i = 0; i < contadorj ; i++){
    Arreglo_barajaj[i] = Arreglo_barajaj[i + 1];
    headj --;
    }
    for (int i = 0; i < contadorc ; i++){
    Arreglo_barajac[i] = Arreglo_barajac[i + 1];
    headc--;
    }
}

void comprobar_win()
{
            if (totaldj == 21)
            {
                cout << "ganaste"<<endl;
                system("pause");
                eliminar_juegos();
                return;
            }
            if (totaldj > 21)
            {
                cout << "gano la maquina"<<endl;
                system("pause");
                eliminar_juegos();
                return;
            }
            if (totaldc == 21)
            {
                cout << "gano la maquina"<<endl;
                system("pause");
                eliminar_juegos();
                return;
            }
            if (totaldc > 21)
            {
                cout << "ganaste"<<endl;
                system("pause");
                eliminar_juegos();
                return;
            }
            if (totaldj2 == 21)
            {
                cout << "ganaste"<<endl;
                system("pause");
                eliminar_juegos();
                return;
            }
            if (totaldj2 > 21)
            {
                cout << "gano la maquina"<<endl;
                system("pause");
                eliminar_juegos();
                return;
            }
            if (totaldc2 == 21)
            {
                cout << "gano la maquina"<<endl;
                system("pause");
                eliminar_juegos();
                return;
            }
            if (totaldc2 > 21)
            {
                cout << "ganaste"<<endl;
                system("pause");
                eliminar_juegos();
                return;
            }
}

void pedir_cartas()
{
    char letra;
    int c = 2;
    cout <<"Quieres otra carta ? pon 's' para si o 'n'  para no: "<<endl;cin >> letra;
    if (letra == 's')
    {
        for (int i = head; i < head+1; i++)
        {
            strcpy(Arreglo_jugador[i-c].name_jugador, Arreglo_baraja2[i].name);
            Arreglo_barajaj[i-c] = Arreglo_baraja[i];
            contador_cartasjuego++;
            contadorj++;
            contador--;
        }
        head++;
    }
    else{
        return;
    }
}

void imprimir_juego()
{
    int nuevo_valor = 11;
    if (contador_cartasjuego < 5)
    {
        int total = 0, totalc = 0;
        for(int i = headj; i < contadorj; i ++){
            cout<<"Cartas jugador: "<<Arreglo_jugador[i].name_jugador<<endl;
            if (Arreglo_barajaj[i] == 1 && total < 21)
            {
                if (Arreglo_barajaj[i] == 1 && total == 11)
                {
                    comprobar_win();
                    return;
                }
                else{
                    if(Arreglo_barajaj[i] == 1 && total < 21)
                    {
                        Arreglo_barajaj[i] = nuevo_valor;
                    }
                }
            }
            total = total + Arreglo_barajaj[i];
        }
        cout << "Total suma jugador: "<<total<<endl;
        totaldj = total;
        comprobar_win();
        for(int i = headc; i < contadorc; i ++){
            cout<<"Cartas compu: "<<Arreglo_compu[i].name_compu<<endl;
            if (Arreglo_barajac[i] == 1 && totalc < 21)
            {
                if (Arreglo_barajac[i] == 1 && totalc == 11)
                {
                    comprobar_win();
                    return;
                }
                else{
                    if(Arreglo_barajac[i] == 1 && totalc < 21)
                    {
                        Arreglo_barajac[i] = nuevo_valor;
                    }
                }
            }
            totalc = totalc + Arreglo_barajac[i];
        }
        totaldc = totalc;
        cout << "Total suma compu: "<<totalc<<endl;
        pedir_cartasc();
        comprobar_win();
    }
    else{
        int total = 0, totalc = 0, totaldj = 0,totaldc = 0;
        for(int i = headj; i < contadorj; i ++){
            cout<<"Cartas jugador: "<<Arreglo_jugador[i].name_jugador<<endl;
            if (Arreglo_barajaj[i] == 1 && total < 21)
            {
                if (Arreglo_barajaj[i] == 1 && total == 11)
                {
                    comprobar_win();
                    return;
                }
                else{
                    if(Arreglo_barajaj[i] == 1 && total < 21)
                    {
                        Arreglo_barajaj[i] = nuevo_valor;
                    }
                }
            }
            total = total + Arreglo_barajaj[i];
        }
        cout << "Total suma jugador: "<<total<<endl;
        totaldj2 = total;
        comprobar_win();
        for(int i = headc; i < contadorc; i ++){
            cout<<"Cartas compu: "<<Arreglo_compu[i].name_compu<<endl;
            if (Arreglo_barajac[i] == 1 && totalc < 21)
            {
                if (Arreglo_barajac[i] == 1 && totalc == 11)
                {
                    comprobar_win();
                    return;
                }
                else{
                    if(Arreglo_barajac[i] == 1 && totalc < 21)
                    {
                        Arreglo_barajac[i] = nuevo_valor;
                    }
                }
            }
            totalc = totalc + Arreglo_barajac[i];
        }
        totaldc2 = totalc;
        cout << "Total suma compu: "<<totalc<<endl;
        pedir_cartasc();
        comprobar_win();
    }
    pedir_cartas();
}

int main(){
    int opcion;
    while(opcion!=6){
        cout<<"\n Que opcion deseas, \n6-Salir \n1-barajear cartas \n2-imprime cartas barajeadas \n3-repartir cartas \n4-imprimir juego ";
        cout<<"\n5-eliminar juego \nOpcion: "<<endl;
        cin>>opcion;

        switch(opcion){
            case 1: system("cls");
                inicializa();
                cout<<" head :"<<head<<endl;
                break;
            case 2: system("cls");
                prueba();
                cout<<" head :"<<head<<endl;
                break;
            case 3: system("cls");
                repartir_cartasi();
                cout<<" head :"<<head<<endl;
                break;
            case 4: system("cls");
                imprimir_juego();
                cout<<" head :"<<head<<endl;
                break;
            case 5: system("cls");
                eliminar_juegos();
                cout<<" head :"<<head<<endl;
                break;
            case 6: break;
            default: printf("Esa opcion no existe...\n");
        }
    }

    return 0;
}
