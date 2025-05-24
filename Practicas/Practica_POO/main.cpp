#include <iostream>

using namespace std;

class StructBase{
typedef struct Address{
    private:
    char name[50];
    char street[100];
    char city[50];
    char state[20];
    int pin;
    public:
    void setname(char);
    char getname();
    void setstreet(char);
    char getstreet();
    void setcity(char);
    char getcity();
    void setstate(char);
    char getstate();
    void setpin(int);
    int getpin();
    int data;
    struct Address *next;
}Address;
};

class List: public StructBase{
 public:
int insertNode();
void seekNode();
void showList();
void modifyNode();
void eliminateNode();
};


/*class ListDouble : List{
ShowReverse();
insert();
insertFirst();
insertLast();
insertMiddle();
}*/


//Clase padre
void StructBase::Address::setname(char name){
    this->name[50]=name;
}
char StructBase::Address::getname(){
    return this->name[50];
}
void StructBase::Address::setstreet(char street){
    this->street[100]=street;
}
char StructBase::Address::getstreet(){
    return this->street[100];
}

void StructBase::Address::setcity(char city){
    this->city[50]=city;
}
char StructBase::Address::getcity(){
    return this->city[50];
}

void StructBase::Address::setstate(char state){
    this->state[20]=state;
}
char StructBase::Address::getstate(){
    return this->state[20];
}

void StructBase::Address::setpin(int pin){
    this->pin=pin;
}
int StructBase::Address::getpin(){
    return this->pin;
}

List Lista_ligada_simple;
void menu(){
int opc;
    do{
    printf("\tINTRODUCE AN OPCION:\n");
    printf("1.-Lista simplemente ligada\n");
    scanf("%d", &opc);

    switch(opc){
        case 1: printf("\tLista simplemente ligada");
                int opc;
                do{
                    printf("\tINTRODUCE AN OPCION:\n");
                    printf("1.-Introduce\n2.-Seek\n3.-Show\n4.-Modify\n5.-Eliminate\n6.-Exit\n");
                    scanf("%d", &opc);

                    switch(opc){
                        case 1: printf("\tInsert a node in the list\n\n");
                        Lista_ligada_simple.insertNode();
                        break;
                        case 2: printf("\tSeek a node in the list\n\n");
                        Lista_ligada_simple.seekNode();
                        system("pause");
                        break;
                        case 3: printf("\tShow the list\n\n");
                        Lista_ligada_simple.showList();
                        system("pause");
                        break;
                        case 4: printf("\tModify the list\n\n");
                        Lista_ligada_simple.modifyNode();
                        system("pause");
                        break;
                        case 5: printf("\tEliminate node\n\n");
                        Lista_ligada_simple.eliminateNode();
                        system("pause");
                        break;
                        case 6: printf("\tGoodbye");
                        break;
                        default: printf("\tChoose a correct value");
                        break;
                    }
                    system("cls");
                }while(opc!=6);
                break;
        /*case 2: printf("\tSeek a node in the list\n\n");
                seekNode();
                system("pause");
                break;
       case 3: printf("\tShow the list\n\n");
                showList();
                system("pause");
                break;
        case 4: printf("\tModify the list\n\n");
                modifyNode();
                system("pause");
                break;
        case 5: printf("\tEliminate node\n\n");
                eliminateNode();
                system("pause");
                break;
        case 6: printf("\tGoodbye");
                break;*/
        default: printf("\tChoose a correct value");
                break;
    }
    system("cls");
    }while(opc!=6);

}

int insertNode()
{
    Address *new_n = (Address *) malloc(sizeof(Address));
if(!new_n){// new_==NULL
printf("Memory allocation error, new node could not be created");
return -1;
}
    //Allocates requested size of bytes and returns a pointer first byte of allocated space

    printf("INTRODUCE THE VALUE OF THE NEW NODE: ");
    scanf("%d", &new_n -> data);
    //se guardara en el nuevo nodo en su propiedad dato

    if(first == NULL){
        first = new_n;
        first ->next = NULL;
        last = new_n;
    }
    else{
        last -> next = new_n;
        new_n -> next = NULL;
        last = new_n;
    }
    /*if the list is empty then we need to create
    a new node (the first one).
    else, last will pass at the end of the list*/
        printf("Give the name ");
        scanf("%s", &new_n->name);
        printf("Give the street ");
        scanf("%s", &new_n->street);
        printf("Give the city ");
        scanf("%s", &new_n->city);
        printf("Estado: ");
        scanf("%s", &new_n->state);
        printf("pin: ");
        scanf("%i",&new_n->pin);
    printf("\nTHE NODE HAVE BEEN INTRODUCE CORRECTLY\n\n");
    system("pause");
return 0;
}

void Lista_ligada_simple::showList(){
    node *temp = (node *) malloc(sizeof(node));
    temp = first;
    if (first != NULL){
        while (temp != NULL){
            printf("Actual %d", temp->data);
            printf("\n Name: %s\n", temp->name);
            printf("street: %s\n", temp->street);
            printf("City: %s\n", temp->city);
            printf("State: %s\n", temp->state);
            printf("pin: %i\n\n", temp->pin);
            temp = temp ->next;
        }
    }
    else{
        printf("\n The list is empty\n");
    }
}

void Lista_ligada_simple::eliminateNode()
{
    node *actual = (node *) malloc(sizeof(node));
    actual = first;

    node* before = (node *) malloc(sizeof(node));
    before = NULL;

    int soughtnode = 0, found = 0 ;

    printf(" Introduce the pin of the node that you want to eliminate: ");
    scanf("%d", &soughtnode);

    if(first != NULL){
        while(actual != NULL && found != 1){

            if(actual -> pin == soughtnode){

                if(actual == first){
                    first = first ->next;
                }
                else{
                    before -> next = actual -> next;
                }
                printf("\nThe link of the node have been eliminated");
                found = 1;
            }
            before = actual;
            actual = actual ->next;
        }
        if(found == 0){
            printf("\nthe node was not found\n\n");
        }
        else{
            //->->->->->->->->->->->->->->->->->->
            free(before);
            printf("\n\nNODE ELIMINATED SUCCESSFUL");
        }
    }
    else{
        printf("\nTHE LIST IS EMPTY\n\n");
    }
    printf("\n");
}

void Lista_ligada_simple::seekNode(){
 node *temp = (node *) malloc(sizeof(node));
    temp = first;
    int found = 0 ;
    char cadena[50];
    printf(" Introduce the name of the node that you want to seek: ");
    scanf("%s", &cadena);
    if (first != NULL){
        while (temp != NULL && found != 1){
            if ( strcmp(temp->name, cadena)==0 ){
                printf("Actual %d", temp->data);
                printf("\n Name: %s\n", temp->name);
                printf("street: %s\n", temp->street);
                printf("City: %s\n", temp->city);
                printf("State: %s\n", temp->state);
                printf("pin: %i\n\n", temp->pin);
                found = 1;
            }
            temp = temp ->next;
        }
        if (found == 0){
            printf("El nodo no fue encontrado");
        }
    }
    else{
        printf("\n The list is empty\n");
    }
}

void Lista_ligada_simple::modifyNode(){
node *temp = (node *) malloc(sizeof(node));
    temp = first;
    int soughtnode = 0, found = 0 ;

    printf(" Introduce the pin of the node that you want to modificate: ");
    scanf("%d", &soughtnode);

    if (first != NULL){
        while (temp != NULL && found != 1){
            if (temp -> pin == soughtnode){
                printf("\n Introduce la nueva informacion: ");
                printf("Give the name ");
                scanf("%s", temp->name);
                printf("Give the street ");
                scanf("%s", temp->street);
                printf("Give the city ");
                scanf("%s", temp->city);
                printf("Estado: ");
                scanf("%s", temp->state);
                printf("pin: ");
                scanf("%i",&temp->pin);
                found = 1;
            }
            temp = temp ->next;
        }
        if (found == 0){
            printf("El nodo no fue encontrado");
        }
    }
    else{
        printf("\n The list is empty\n");
    }
}
