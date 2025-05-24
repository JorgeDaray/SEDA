#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
using std::fstream;

class StructBase
{
protected:
    typedef struct Passenger
    {
        char name[50];
        char origen[50];
        char fecha_salida[50];
        char hora_salida[50];
        char destino[50];
        char fecha_llegada[50];
        char hora_llegada[50];
        struct Passenger *next;
        struct Passenger *before;
    }Passenger;
        Passenger * first;
        Passenger * last;
        int contador;
};

class List: StructBase
{
    protected:
        void inicializa()
    {
        first = nullptr;
        last = nullptr;
        contador = 0;
    }

    void show()
    {
    Passenger *temp = (Passenger *) malloc(sizeof(Passenger));
    temp = first;
    if (first != NULL){
        cout << "Tamaño :"<<contador<<endl;
        int i = 0;
        while (temp != NULL){
                printf("--------------------------------------------------------------\n");
            printf("Actual %d\n", i);
            printf("\tName: %s\n", temp->name);
            temp = temp ->next;
            i++;
        }
    }
    else{
        printf("\n The list is empty\n");
    }
    }

    void seekNode()
    {
    Passenger *temp = (Passenger *) malloc(sizeof(Passenger));
    temp = first;
    int found = 0 ;
    char cadena[50];
    fflush(stdin);
    printf(" Introduce the name of the node that you want to seek: ");
    gets(cadena);
    if (first != NULL){
            int i=0;
        while (temp != NULL && found != 1){
            if ( strcmp(temp->name, cadena)==0 ){
                printf("Actual %d", i);
                printf("\n Name: %s\n", temp->name);
                printf("\tOrigen: %s\n", temp->origen);
                printf("\tfecha de salida: %s\n", temp->fecha_salida);
                printf("\tHora de salida: %s\n", temp->hora_salida);
                printf("\tDestino: %s\n", temp->destino);
                printf("\tFecha de llegada: %s\n", temp->fecha_llegada);
                printf("\tHora de llegada: %s\n", temp->hora_llegada);
                found = 1;
            }
            temp = temp ->next;
            i++;
        }
        if (found == 0){
            printf("El nodo no fue encontrado");
        }
    }
    else{
        printf("\n The list is empty\n");
    }
    }

    /*void Localiza()
        {
        Passenger *temp = (Passenger *) malloc(sizeof(Passenger));
        temp = first;
        int found = 0 ;
        int pos;
        printf(" Introduce the pos of the node that you want to locate: ");
        scanf("%d", &pos);
        if (first != NULL){
                int i=0;
            while (temp != NULL && found != 1){
                if ( i == pos ){
                    printf("Actual %d", i++);
                    printf("\n Name: %s\n", temp->name);
                    printf("street: %s\n", temp->street);
                    printf("City: %s\n", temp->city);
                    printf("State: %s\n", temp->state);
                    printf("pin: %i\n\n", temp->pin);
                    found = 1;
                }
                temp = temp ->next;
                i++;
            }
            if (found == 0){
                printf("El nodo no fue encontrado");
            }
        }
        else{
            printf("\n The list is empty\n");
        }
    }*/
    int tam()
    {
        return contador;
    }

    void eliminateNode()
    {
        Passenger *actual = (Passenger *) malloc(sizeof(Passenger));
        actual = first;

        Passenger* before = (Passenger *) malloc(sizeof(Passenger));
        before = NULL;

        int found = 0;

        char cadena[50];
        fflush(stdin);
        printf(" Introduce the name of the node that you want to eliminate: ");
        gets(cadena);

        if(first != NULL){
            while(actual != NULL && found != 1){

                if ( strcmp(actual->name, cadena)==0 ){
                    printf("\n Name: %s\n", actual->name);
                    printf("\tOrigen: %s\n", actual->origen);
                    printf("\tfecha de salida: %s\n", actual->fecha_salida);
                    printf("\tHora de salida: %s\n", actual->hora_salida);
                    printf("\tDestino: %s\n", actual->destino);
                    printf("\tFecha de llegada: %s\n", actual->fecha_llegada);
                    printf("\tHora de llegada: %s\n", actual->hora_llegada);
                    char eleccion[10];
                    int resultado;
                    printf("\nThe name of the passenger is found\n");
                    printf("Quieres eliminar al pasajero ?: 1 para si, 2 para no");
                    gets(eleccion);
                    resultado = atoi(eleccion);
                    if (resultado == 1)
                    {
                        found = 1;
                    }
                    else
                    {
                        cout <<"Cancelado"<<endl;
                        return;
                    }
                    if(actual == first){
                        first = first ->next;
                    }
                    else if (actual == last)
                    {
                        last = before;
                        before -> next = actual -> next;
                    }
                    else{
                            before -> next = actual -> next;
                        }
                    }
                    before = actual;
                    actual = actual ->next;
                }
                if(found == 0){
                    printf("\nthe node was not found\n\n");
                }
                else{
                    free(before);
                    contador--;
                    printf("\n\nNODE ELIMINATED SUCCESSFUL");
                    system("pause");
                }
            }
            else{
                printf("\nTHE LIST IS EMPTY\n\n");
            }
            printf("\n");
    }

    /*void inserfirst()
    {
        Passenger *in_first = (Passenger *) malloc(sizeof(Passenger));
        if(!in_first){// new_==NULL
            printf("Memory allocation error, new node could not be created");
            return;
        }

        printf("INTRODUCE THE VALUE OF THE NEW NODE: \n");
            printf("Give the name ");
            scanf("%s", &in_first->name);
            printf("Give the street ");
            scanf("%s", &in_first->street);
            printf("Give the city ");
            scanf("%s", &in_first->city);
            printf("Estado: ");
            scanf("%s", &in_first->state);
            printf("pin: ");
            scanf("%i",&in_first->pin);
        if(first == NULL){
            first = in_first;
            in_first->before = NULL;
            first ->next = NULL;
            last = in_first;
        }
        else{
            in_first->before = NULL;
            in_first->next = first;
            first->before = in_first;
            first=in_first;
        }
            contador++;
            printf("\nTHE NODE HAVE BEEN INTRODUCE CORRECTLY\n\n");
            system("pause");
    }*/

    void insertlast()
    {
        Passenger *in_last = (Passenger *) malloc(sizeof(Passenger));
        if(!in_last){// new_==NULL
            printf("Memory allocation error, new node could not be created");
            return;
        }

        printf("INTRODUCE THE VALUE OF THE NEW NODE: \n");
        fflush(stdin);
            printf("Give the name :");
            gets(in_last->name);
            printf("Origen: ");
            gets(in_last->origen);
            printf("fecha de salida: ");
            gets(in_last->fecha_salida);
            printf("Hora de salida: ");
            gets(in_last->hora_salida);
            printf("Destino: ");
            gets(in_last->destino);
            printf("Fecha de llegada:");
            gets(in_last->fecha_llegada);
            printf("Hora de llegada: ");
            gets(in_last->hora_llegada);
        if(last == NULL){
            in_last->before = NULL;
            first = in_last;
            first ->next = NULL;
            last = in_last;
        }
        else{
            last -> next = in_last;
            in_last-> before = NULL;
            in_last -> next = NULL;
            last = in_last;
        }
        contador++;
            printf("\nTHE NODE HAVE BEEN INTRODUCE CORRECTLY\n\n");
    }

    /*void Anula()
    {
    Passenger *actual = (Passenger *) malloc(sizeof(Passenger));
    actual = first;

    Passenger* before = (Passenger *) malloc(sizeof(Passenger));
    before = NULL;

        if(first != NULL)
        {
            while(actual != NULL)
            {
                before = actual;
                actual = actual ->next;
                free(before);
                contador--;
            }
            printf("\n\nLIST ELIMINATED SUCCESSFUL");
        }
        else
        {
        printf("\nTHE LIST IS EMPTY\n\n");
        }
    printf("\n");
    inicializa();
    }*/

    public:
    /*void insertNode(int pos)
    {
    Passenger *aux = nullptr;
    aux = new Passenger;
        if (pos == 0)
        {
            inserfirst();
        }
        else if (pos == tam())
        {
            insertlast();
        }
        else if(pos >= 1 && pos < tam())
        {
        printf("Give the name ");
        scanf("%s", &aux->name);
        Passenger *aux2, *aux3;
        aux2 = first;
        for (int i=0; i<pos; i++)
        {
            aux3 = aux2;
            aux2 = aux2->next;
        }
        aux3->next = aux;
        aux->next = aux2;
        contador++;
        printf("\nTHE NODE HAVE BEEN INTRODUCE CORRECTLY\n\n");
        system("pause");
        }
        }*/

/*void top()
{
    Passenger *temp = (Passenger *) malloc(sizeof(Passenger));
    temp = first;
    if (first != NULL){
        int i = 0;
            printf("Actual %d", i);
            printf("\n Name: %s\n", temp->name);
            printf("street: %s\n", temp->street);
            printf("City: %s\n", temp->city);
            printf("State: %s\n", temp->state);
            printf("pin: %i\n\n", temp->pin);
        }
    else{
        printf("\n The list is empty\n");
    }
}*/

/*void pop()
    {
    Passenger *actual = (Passenger *) malloc(sizeof(Passenger));
    actual = first;

    Passenger* before = (Passenger *) malloc(sizeof(Passenger));
    before = NULL;

    if(first != NULL){
            printf("\n Name: %s\n", actual->name);
            printf("street: %s\n", actual->street);
            printf("City: %s\n", actual->city);
            printf("State: %s\n", actual->state);
            printf("pin: %i\n\n", actual->pin);
            before = actual;
                first = first ->next;
                actual = actual ->next;
                free(before);
                contador--;
                printf("\n\nNODE ELIMINATED SUCCESSFUL");
    }
        else{
            printf("\nTHE LIST IS EMPTY\n\n");
        }
        printf("\n");
    }*/

    /*void deque() //eliminar el ultimo nodo.
    {
    Passenger *actual = (Passenger *) malloc(sizeof(Passenger));
    actual = first;

    Passenger* before = (Passenger *) malloc(sizeof(Passenger));
    before = NULL;

    if(first != NULL){
        while(actual != NULL){
                if (actual == first && contador == 1){
                    printf("\n Name: %s\n", actual->name);
                    printf("street: %s\n", actual->street);
                    printf("City: %s\n", actual->city);
                    printf("State: %s\n", actual->state);
                    printf("pin: %i\n\n", actual->pin);
                    system("pause");
                    Anula();
                    return;
                }
                if (actual == last)
                {
                    printf("\n Name: %s\n", actual->name);
                    printf("street: %s\n", actual->street);
                    printf("City: %s\n", actual->city);
                    printf("State: %s\n", actual->state);
                    printf("pin: %i\n\n", actual->pin);
                    last = before;
                    before -> next = actual -> next;
                }
                before = actual;
                actual = actual ->next;
            }
                free(before);
                contador--;
                cout << "Tamaño :"<<contador<<endl;
        }
        else{
            printf("\nTHE LIST IS EMPTY\n\n");
        }
        printf("\n");
    }*/

    /*void showreverse()
    {
    Passenger *temp = (Passenger *) malloc(sizeof(Passenger));
    temp = last;
    if (first != NULL){
        int i = 0;
        while (temp != NULL){
            printf("Actual %d", i+1);
            printf("\n Name: %s\n", temp->name);
            printf("street: %s\n", temp->street);
            printf("City: %s\n", temp->city);
            printf("State: %s\n", temp->state);
            printf("pin: %i\n\n", temp->pin);
            temp = temp -> before;
            i++;
        }
    }
    else{
        printf("\n The list is empty\n");
    }
    }*/

        void getshow(){
            return show();
        }
        void getseeknode(){
            return seekNode();
        }
        void geteliminatenode(){
            return eliminateNode();
        }
        /*void getinsertfirst(){
            return inserfirst();
        }*/
        void getinsertlast(){
            return insertlast();
        }
        /*void getLocaliza(){
            return Localiza();
        }*/
        /*void getAnula(){
            return Anula();
        }*/
        void getinicializa(){
            return inicializa();
        }
        /*void gettop(){
            return top();
        }
        void getpop(){
            return pop();
        }*/
        /*void getdeque(){
            return deque();
        }*/
        /*void getshowreverse(){
            return showreverse();
        }*/
};




void menu()
{
    fstream archDeportENSA("Libros.dat", ios::out | ios::in );
    if ( !archDeportENSA)
    {
        cerr << "No se pudo abrir el archivo ensa." << endl;
        exit( 1 );
    } // fin de if
    int opc;
    List mi_lista_doble;
    int pos;
    mi_lista_doble.getinicializa();

    do{
    printf("\tINTRODUCE AN OPCION:\n");
    printf("0.-Exit\n1.-Double list\n");
    scanf("%d", &opc);


    switch(opc){
        case 0: printf("\tGoodbye");
                system("pause");
                break;
        case 1: printf("\tMENU – LISTA DE PASAJEROS\n\n");
                int opcion;
                do{
                printf("\tINTRODUCE AN OPCION:\n");
                printf("0.-Exit\n1.-Insert last\n2.-Delete node\n3.-Seek\n4.-Show the list\n");
                scanf("%d", &opcion);
                    switch(opcion){
                        case 0: printf("\t Adios\n");
                            system("pause");
                            break;
                        case 1:
                            printf("\tInsert last\n\n");
                            mi_lista_doble.getinsertlast();
                            break;
                        case 2:
                            system("cls");
                            printf("\tDelete node\n\n");
                            mi_lista_doble.geteliminatenode();
                            break;
                        case 3:
                            system("cls");
                            printf("\tSeek a passenger in the list\n\n");
                            mi_lista_doble.getseeknode();
                            break;
                        case 4:
                            printf("\tShow the list\n\n");
                            system("cls");
                            mi_lista_doble.getshow();
                            system("pause");
                            break;
                    }
                }while(opcion!=0);
                break;
        default: printf("\tChoose a correct value");
                break;
    }
    system("cls");
    }while(opc!=0);

}

int main()
{

    menu();
    return 0;
}
