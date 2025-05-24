#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class Figuras{
    private:
        double base;
        double altura;
    public:
        void setBase(double);
        double getBase();
        void setAltura(double);
        double getAltura();
};

class Triangulo: public Figuras{
    private:
        double area;
    public:
        void CalcularArea();
        double getArea();
};

class Cuadrado{
    private:
        double base;
        double area;
    public:
        void setBase(double);
        double getBase();
        void CalcularArea();
        double getArea();
};

class Rectangulo{
    private:
        double base;
        double altura;
        double area;
    public:
        void setBase(double);
        double getBase();
        void setAltura(double);
        double getAltura();
        void CalcularArea();
        double getArea();
};
//Clase padre
void Figuras::setBase(double base){
    this->base=base;
}
double Figuras::getBase(){
    return this->base;
}
void Figuras::setAltura(double altura){
    this->altura=altura;
}
double Figuras::getAltura(){
    return this->altura;
}

void Triangulo::CalcularArea(){
    this->area=(this->getBase()*this->getAltura())/2;
}
double Triangulo::getArea(){
    return this->area;
}

int main()
{

    double base=0,altura=0;
    int opc=0;
    Triangulo t;

    do{
        cout<<"Menu"<<endl;
        cout<<"1)Triangulo"<<endl;
        cout<<"2)Cuadrado"<<endl;
        cout<<"3)Rectangulo"<<endl;
        cout<<"4)Poligono"<<endl;
        cout<<"5)Salir"<<endl;
        cout<<"seleccione una opcion:"<<endl;
        cin>>opc;
        switch(opc){
            case 1:{
            cout<<"ingrese base:"<<endl;
            cin>>base;
            cout<<"ingrese altura:"<<endl;
            cin>>altura;
            t.setBase(base);
            t.setAltura(altura);
            t.CalcularArea();
            cout<<"Area: "<<t.getArea()<<endl;
            }break;
            }

    }while(opc!=5);
        system("pause>>cls");
    return 0;
}
