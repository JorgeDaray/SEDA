#include <iostream>
#include <cstdlib>

using namespace std;
class Celcius_Kelvin{
    private:
        double grado;
        double gradoN;
    public:
        void setGrado(double);
        double getGrado();
        void CalcularGrados();
        double getGrados();
};

class Kelvin_Celsius{
    private:
        double grado;
        double gradoN;
    public:
        void setGrado(double);
        double getGrado();
        void CalcularGrados();
        double getGrados();
};

class Celsius_Farenheit{
    private:
        double grado;
        double gradosN;
    public:
        void setGrado(double);
        double getGrado();
        void CalcularGrados();
        double getGrados();
};

class Fahrenheit_Celsius{
    private:
        double grado;
        double gradosN;
    public:
        void setGrado(double);
        double getGrado();
        void CalcularGrados();
        double getGrados();
};

void Fahrenheit_Celsius::setGrado(double grado){
    this->grado=grado;
}
double Fahrenheit_Celsius::getGrado(){
    return this->grado;
}
void Fahrenheit_Celsius::CalcularGrados(){
    this->gradosN=((this->grado-32)/1.8);
}
double Fahrenheit_Celsius::getGrados(){
    return this->gradosN;
}

void Celsius_Farenheit::setGrado(double grado){
    this->grado=grado;
}
double Celsius_Farenheit::getGrado(){
    return this->grado;
}
void Celsius_Farenheit::CalcularGrados(){
    this->gradosN=((this->grado*9)/5)+32;
}
double Celsius_Farenheit::getGrados(){
    return this->gradosN;
}

void Kelvin_Celsius::setGrado(double grado){
    this->grado=grado;
}
double Kelvin_Celsius::getGrado(){
    return this->grado;
}
void Kelvin_Celsius::CalcularGrados(){
    this->gradoN=(this->grado-273.15);
}
double Kelvin_Celsius::getGrados(){
    return this->gradoN;
}

void Celcius_Kelvin::setGrado(double grado){
    this->grado=grado;
}
double Celcius_Kelvin::getGrado(){
    return this->grado;
}
void Celcius_Kelvin::CalcularGrados(){
    this->gradoN=(this->grado+273.15);
}
double Celcius_Kelvin::getGrados(){
    return this->gradoN;
}

int main()
{
    double grado=0;
    int opc=0;
    Celcius_Kelvin k;
    Kelvin_Celsius c;
    Celsius_Farenheit f;
    Fahrenheit_Celsius m;

    do{
        cout<<"Menu"<<endl;
        cout<<"1)Celsius a Kelvin"<<endl;
        cout<<"2)Kelvin a Celsius"<<endl;
        cout<<"3)Celsius a Fahrenheit"<<endl;
        cout<<"4)Fahrenheit a Celsius"<<endl;
        cout<<"5)Salir"<<endl;
        cout<<"seleccione una opcion:"<<endl;
        cin>>opc;
        switch(opc){
            case 1:{
            cout<<"ingrese grados en celcius:"<<endl;
            cin>>grado;
            k.setGrado(grado);
            k.CalcularGrados();
            cout<<"Grados kelvin: "<<k.getGrados()<<endl;
            }break;
            case 2:{
            cout<<"ingrese grados en Kelvin: "<<endl;
            cin>>grado;
            c.setGrado(grado);
            c.CalcularGrados();
            cout<<"Grados celsius: "<<c.getGrados()<<endl;
            }break;
            case 3:{
            cout<<"ingrese grados en Celsius:"<<endl;
            cin>>grado;
            f.setGrado(grado);
            f.CalcularGrados();
            cout<<"Grados Fahrenheit: "<<f.getGrados()<<endl;
            }break;
            case 4:{
            cout<<"ingrese grados en Fahrenheit:"<<endl;
            cin>>grado;
            m.setGrado(grado);
            m.CalcularGrados();
            cout<<"Grados Celsius: "<<m.getGrados()<<endl;
            }break;
            }

    }while(opc!=5);
        system("pause>>cls");
    return 0;
}
