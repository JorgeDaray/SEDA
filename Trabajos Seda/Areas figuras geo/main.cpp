#include <iostream>
#include <cstdlib>

using namespace std;
class Triangulo{
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

void Rectangulo::setBase(double base){
    this->base=base;
}
double Rectangulo::getBase(){
    return this->base;
}
void Rectangulo::setAltura(double altura){
    this->altura=altura;
}
double Rectangulo::getAltura(){
    return this->altura;
}
void Rectangulo::CalcularArea(){
    this->area=(this->base*this->altura);
}
double Rectangulo::getArea(){
    return this->area;
}

void Cuadrado::setBase(double base){
    this->base=base;
}
double Cuadrado::getBase(){
    return this->base;
}
void Cuadrado::CalcularArea(){
    this->area=(this->base*this->base);
}
double Cuadrado::getArea(){
    return this->area;
}

void Triangulo::setBase(double base){
    this->base=base;
}
double Triangulo::getBase(){
    return this->base;
}
void Triangulo::setAltura(double altura){
    this->altura=altura;
}
double Triangulo::getAltura(){
    return this->altura;
}
void Triangulo::CalcularArea(){
    this->area=(this->base*this->altura)/2;
}
double Triangulo::getArea(){
    return this->area;
}

int main()
{
    double base=0,altura=0;
    int opc=0;
    Triangulo t;
    Cuadrado c;
    Rectangulo r;

    do{
        cout<<"Menu"<<endl;
        cout<<"1)Triangulo"<<endl;
        cout<<"2)Cuadrado"<<endl;
        cout<<"3)Rectangulo"<<endl;
        cout<<"4)Salir"<<endl;
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
            case 2:{
            cout<<"ingrese el lado: "<<endl;
            cin>>base;
            c.setBase(base);
            c.CalcularArea();
            cout<<"Area: "<<c.getArea()<<endl;
            }break;
            case 3:{
            cout<<"ingrese base:"<<endl;
            cin>>base;
            cout<<"ingrese altura:"<<endl;
            cin>>altura;
            r.setBase(base);
            r.setAltura(altura);
            r.CalcularArea();
            cout<<"Area: "<<r.getArea()<<endl;
            }
            }

    }while(opc!=4);
        system("pause>>cls");
    return 0;
}
