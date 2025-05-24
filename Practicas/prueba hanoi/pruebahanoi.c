#include<stdio.h>

#define tam_max 20

typedef struct{

int altura; /*altura de la torre a considerar*/

int num_hijos; /*nº de hijos a los que ha llamado la función recursiva*/

char caracter1,caracter2,caracter3;

} elemento;

/*cada elemento de la pila va a ser un registro elemento*/

/*defino el tipo pila usando vectores:*/

typedef struct {

int tope;

elemento v[tam_max];

} pila;

int main(){

int n,vacia(),sacar(), meter();

pila pila1, *punt_pila;

elemento registro_aux, cima(), crear_registro();

pila1.tope=tam_max;

punt_pila=&pila1;

printf(" TORRES DE HANOI ELIMINANDO LA RECURSION\n");

do{

printf("\n Dame el numero de discos de la torre: ");

scanf("%d",&n);

if (n<=1) printf("\n Debe ser mayor que 1\n");

}while(n<=1);

registro_aux.altura=n; /*el primer elemento de la pila va a ser siempre este*/

registro_aux.num_hijos=0;

registro_aux.caracter1='O';

registro_aux.caracter2='A';

registro_aux.caracter3='D';

meter(registro_aux,punt_pila);

/*ahora entro en un bucle que, dependiendo de lo que haya en la cima

de la pila hace una cosa u otra*/

while(vacia(pila1)==0){

if(cima(pila1).altura==1){/*llego al caso base*/

printf("\n Mover de %c a %c\n",cima(pila1).caracter1,cima(pila1).caracter3);

sacar(punt_pila);

}

else{/*altura>1*/

switch(cima(pila1).num_hijos){

case 2:{/*las 2 llamadas correspondientes a este nodo están hechas*/

sacar(punt_pila);

};break;

case 1:{

printf("\n Mover de %c a %c\n",cima(pila1).caracter1,cima(pila1).caracter3);

registro_aux=cima(pila1);

sacar(punt_pila);

registro_aux.num_hijos=registro_aux.num_hijos+1;/*como voy a meter

algo en la pila, he llamado a otro hijo*/

meter(registro_aux,punt_pila);

/*las 4 últimas líneas son solo para sumar 1 a num_hijos*/

meter(crear_registro(cima(pila1)),punt_pila);

};break;

case 0:{

registro_aux=cima(pila1);

sacar(punt_pila);

registro_aux.num_hijos=registro_aux.num_hijos+1;/*como voy a meter

algo en la pila, he llamado a otro hijo*/

meter(registro_aux,punt_pila);

/*las 4 últimas líneas son solo para sumar 1 a num_hijos*/

meter(crear_registro(cima(pila1)),punt_pila);

};break;

}/*fin switch*/

} /*fin if*/

}/*fin while*/

printf("\n");

}/************FIN MAIN************/

elemento crear_registro(registro_anterior)

elemento registro_anterior;

{

elemento registro_creado;

registro_creado.altura=registro_anterior.altura-1;

registro_creado.num_hijos=0;/*como lo creo, aún no tiene hijos*/

if(registro_anterior.num_hijos==1){/*esto quiere decir que aun no tiene

hijos y que el que vamos a crear es el primero*/

registro_creado.caracter1=registro_anterior.caracter1;

registro_creado.caracter2=registro_anterior.caracter3;

registro_creado.caracter3=registro_anterior.caracter2;

}

else{/*ya ha llamado a un hijo y vamos a crear el 2º y a meterlo en la pila*/

registro_creado.caracter1=registro_anterior.caracter2;

registro_creado.caracter2=registro_anterior.caracter1;

registro_creado.caracter3=registro_anterior.caracter3;

}

return registro_creado;

}/*FIN CREAR_REGISTRO*/
