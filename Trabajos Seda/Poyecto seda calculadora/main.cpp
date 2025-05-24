#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstdlib>

using namespace std;

class Suma{
    private:
        double numero1;
        double numero2;
        double suma_resultado;
    public:
        void setSuma(double);
        double getSuma();
        void setSuma2(double);
        double getSuma2();
        void CalcularSuma();
        double getSuma_resultado();
};

class Multiplicacion{
    private:
        double numero1;
        double numero2;
        double multi_resultado;
    public:
        void setMulti(double);
        double getMulti();
        void setMulti2(double);
        double getMulti2();
        void CalcularMulti();
        double getMulti_resultado();
};

class Resta{
    private:
        double numero1;
        double numero2;
        double resta_resultado;
    public:
        void setResta(double);
        double getResta();
        void setResta2(double);
        double getResta2();
        void CalcularResta();
        double getResta_resultado();
};

class Division{
    private:
        double numero1;
        double numero2;
        double Division_resultado;
    public:
        void setDivison(double);
        double getDivision();
        void setDivision2(double);
        double getDivision2();
        void CalcularDivision();
        double getDivision_resultado();
};

class Potencia{
    private:
        double numero1;
        double numero2;
        double potencia_resultado;
    public:
        void setPotencia(double);
        double getPotencia();
        void setPotencia2(double);
        double getPotencia2();
        void CalcularPotencia();
        double getPotencia_resultado();
};

class Factorial{
    private:
        double numero1;
        double factorial_resultado;
    public:
        void setFactorial(double);
        double getFactorial();
        void CalcularFactorial();
        double getFactorial_resultado();
};

class Decimal_Binario{
    private:
        int numerob;
        int Binario_resultado;
    public:
        void setBinario(int);
        int getBinario();
        void CalcularBinario();
        int getBinario_resultado();
};

class Binario_Decimal{
    private:
        double numero1;
        double Binario_resultado;
    public:
        void setBinario(double);
        double getBinario();
        void CalcularBinario();
        double getBinario_resultado();
};

class Decimal_Octal{
    private:
        int numerob;
        int octal_resultado;
    public:
        void setOctal(int);
        int getOctal();
        void CalcularOctal();
        int getOctal_resultado();
};

class Octal_Decimal{
    private:
        int numerob;
        int octal_resultado;
    public:
        void setOctal(int);
        int getOctal();
        void CalcularOctal();
        int getOctal_resultado();
};



void Octal_Decimal::setOctal(int numerob){
    this->numerob=numerob;
}
int Octal_Decimal::getOctal(){
    return this->numerob;
}
void Octal_Decimal::CalcularOctal(){
    int rem, i = 1, octalNumber = 0;
    while (this->numerob != 0)
    {
        rem = this->numerob % 8;
        this->numerob /= 8;
        octalNumber += rem * i;
        i *= 10;
    }
    this->octal_resultado = octalNumber;
}
int Octal_Decimal::getOctal_resultado(){
    return this->octal_resultado;
}

void Decimal_Octal::setOctal(int numerob){
    this->numerob=numerob;
}
int Decimal_Octal::getOctal(){
    return this->numerob;
}
void Decimal_Octal::CalcularOctal(){
    int decimalNumber = 0, i = 0, rem;
    while (this->numerob != 0)
    {
        rem = this->numerob % 10;
        this->numerob /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    this->octal_resultado = decimalNumber;
}
int Decimal_Octal::getOctal_resultado(){
    return this->octal_resultado;
}

void Binario_Decimal::setBinario(double numero1){
    this->numero1=numero1;
}
double Binario_Decimal::getBinario(){
    return this->numero1;
}
void Binario_Decimal::CalcularBinario(){
    int exp,digito;
    double decimal;
   exp=0;
   decimal=0;
   while(((int)(this->numero1/10))!=0)
   {
           digito = (int)this->numero1 % 10;
           decimal = decimal + digito * pow(2.0,exp);
           exp++;
           this->numero1=(int)(this->numero1/10);
   }
   decimal=decimal + this->numero1 * pow(2.0,exp);
    this->Binario_resultado = decimal;
}
double Binario_Decimal::getBinario_resultado(){
    return this->Binario_resultado;
}

void Decimal_Binario::setBinario(int numerob){
    this->numerob=numerob;
}
int Decimal_Binario::getBinario(){
    return this->numerob;
}
void Decimal_Binario::CalcularBinario(){
    int exp, digito;
    double binario;
    exp=0;
   binario=0;
   while(this->numerob/2!=0)
   {
           digito = this->numerob % 2;
           binario = binario + digito * pow(10.0,exp);
           exp++;
           this->numerob=this->numerob/2;
   }
   binario = binario + this->numerob * pow(10.0,exp);
    this->Binario_resultado = binario;
}
int Decimal_Binario::getBinario_resultado(){
    return this->Binario_resultado;
}

void Factorial::setFactorial(double numero1){
    this->numero1=numero1;
}
double Factorial::getFactorial(){
    return this->numero1;
}
void Factorial::CalcularFactorial(){
    int i;
    long double factorial;
    factorial=1;
   for(i=1;i<=this->numero1;i++)
        factorial = factorial * i;
    this->factorial_resultado = factorial;
}
double Factorial::getFactorial_resultado(){
    return this->factorial_resultado;
}

void Potencia::setPotencia(double numero1){
    this->numero1=numero1;
}
double Potencia::getPotencia(){
    return this->numero1;
}
void Potencia::setPotencia2(double numero2){
    this->numero2=numero2;
}
double Potencia::getPotencia2(){
    return this->numero2;
}
void Potencia::CalcularPotencia(){
    this->potencia_resultado=(pow(this->numero1,this->numero2));
}
double Potencia::getPotencia_resultado(){
    return this->potencia_resultado;
}


void Division::setDivison(double numero1){
    this->numero1=numero1;
}
double Division::getDivision(){
    return this->numero1;
}
void Division::setDivision2(double numero2){
    this->numero2=numero2;
}
double Division::getDivision2(){
    return this->numero2;
}
void Division::CalcularDivision(){
    this->Division_resultado=(this->numero1/this->numero2);
}
double Division::getDivision_resultado(){
    return this->Division_resultado;
}


void Resta::setResta(double numero1){
    this->numero1=numero1;
}
double Resta::getResta(){
    return this->numero1;
}
void Resta::setResta2(double numero2){
    this->numero2=numero2;
}
double Resta::getResta2(){
    return this->numero2;
}
void Resta::CalcularResta(){
    this->resta_resultado=(this->numero1-this->numero2);
}
double Resta::getResta_resultado(){
    return this->resta_resultado;
}

void Multiplicacion::setMulti(double numero1){
    this->numero1=numero1;
}
double Multiplicacion::getMulti(){
    return this->numero1;
}
void Multiplicacion::setMulti2(double numero2){
    this->numero2=numero2;
}
double Multiplicacion::getMulti2(){
    return this->numero2;
}
void Multiplicacion::CalcularMulti(){
    this->multi_resultado=(this->numero1*this->numero2);
}
double Multiplicacion::getMulti_resultado(){
    return this->multi_resultado;
}

void Suma::setSuma(double numero1){
    this->numero1=numero1;
}
double Suma::getSuma(){
    return this->numero1;
}
void Suma::setSuma2(double numero2){
    this->numero2=numero2;
}
double Suma::getSuma2(){
    return this->numero2;
}
void Suma::CalcularSuma(){
    this->suma_resultado=(this->numero1+this->numero2);
}
double Suma::getSuma_resultado(){
    return this->suma_resultado;
}

int main()
{
    double grado=0,numero1,numero2;
    int numerob;
    int opc=0;
    system("cls");
    Suma s;
    Multiplicacion m;
    Resta r;
    Division d;
    Potencia p;
    Factorial f;
    Decimal_Binario b;
    Binario_Decimal c;
    Decimal_Octal o;
    Octal_Decimal x;

    do{
        cout<<"Menu"<<endl;
        cout<<"1)Suma"<<endl;
        cout<<"2)Resta"<<endl;
        cout<<"3)Multiplicacion"<<endl;
        cout<<"4)Division"<<endl;
        cout<<"5)Potencia"<<endl;
        cout<<"6)Factorial"<<endl;
        cout<<"7)decimal_binario"<<endl;
        cout<<"8)binario_decimal"<<endl;
        cout<<"9)Decimal_octal"<<endl;
        cout<<"10)Octal_Decimal"<<endl;
        cout<<"11)Decimal_Hexadecimal"<<endl;
        cout<<"12)Hexadecimal_Decimal"<<endl;
        cout<<"seleccione una opcion:"<<endl;
        cout<<"13)Salir"<<endl;
        cin>>opc;
        switch(opc){
            case 1:{
                cout<<"ingrese el primer numero a sumar:"<<endl;
                cin>>numero1;
                cout<<"ingrese el segundo numero a sumar:"<<endl;
                cin>>numero2;
                s.setSuma(numero1);
                s.setSuma2(numero2);
                s.CalcularSuma();
                cout<<"Suma: "<<s.getSuma_resultado()<<endl;
                system("pause>>cls");
            }break;
            case 2:{
            cout<<"ingrese el primer numero a restar:"<<endl;
            cin>>numero1;
            cout<<"ingrese el segundo numero a restar:"<<endl;
            cin>>numero2;
            r.setResta(numero1);
            r.setResta2(numero2);
            r.CalcularResta();
            cout<<"Resta: "<<r.getResta_resultado()<<endl;
            system("pause>>cls");
            }break;
            case 3:{
            cout<<"ingrese el primer numero a multiplicar: "<<endl;
            cin>>numero1;
            cout<<"ingrese el segundo numero a multiplicar:"<<endl;
            cin>>numero2;
            m.setMulti(numero1);
            m.setMulti2(numero2);
            m.CalcularMulti();
            cout<<"Multiplicacion: "<<m.getMulti_resultado()<<endl;
            system("pause>>cls");
            }break;
            case 4:{
            cout<<"ingrese el primer numero a dividir: "<<endl;
            cin>>numero1;
            cout<<"ingrese el segundo numero a dividir:"<<endl;
            cin>>numero2;
            d.setDivison(numero1);
            d.setDivision2(numero2);
            d.CalcularDivision();
            cout<<"division: "<<d.getDivision_resultado()<<endl;
            system("pause>>cls");
            }break;
            case 5:{
            cout<<"ingrese el nuumero que quiere elevar: "<<endl;
            cin>>numero1;
            cout<<"ingrese la cantidad a lo que desea elevar:"<<endl;
            cin>>numero2;
            p.setPotencia(numero1);
            p.setPotencia2(numero2);
            p.CalcularPotencia();
            cout<<"Numero elevado: "<<p.getPotencia_resultado()<<endl;
            system("pause>>cls");
            }break;
            case 6:{
            cout<<"ingrese el nuumero del factorial: "<<endl;
            cin>>numero1;
            f.setFactorial(numero1);
            f.CalcularFactorial();
            cout<<"Numero en factorial: "<<f.getFactorial_resultado()<<endl;
            system("pause>>cls");
            }break;
            case 7:{
            cout<<"ingrese un numero entero: "<<endl;
            cin>>numero1;
            b.setBinario(numero1);
            b.CalcularBinario();
            cout<<"Numero en binario: "<<b.getBinario_resultado()<<endl;
            system("pause>>cls");
            }break;
            case 8:{
            cout<<"ingrese el numero en binario: "<<endl;
            cin>>numero1;
            c.setBinario(numero1);
            c.CalcularBinario();
            cout<<"Numero en decimal: "<<c.getBinario_resultado()<<endl;
            system("pause>>cls");
            }break;
            case 9:{
            cout<<"ingrese el numero en decimal: "<<endl;
            cin>>numerob;
            x.setOctal(numerob);
            x.CalcularOctal();
            cout<<"Numero en decimal: "<<x.getOctal_resultado()<<endl;
            system("pause>>cls");
            }break;
            case 10:{
            cout<<"ingrese el numero en decimal: "<<endl;
            cin>>numerob;
            o.setOctal(numerob);
            o.CalcularOctal();
            cout<<"Numero en decimal: "<<o.getOctal_resultado()<<endl;
            system("pause>>cls");
            }break;
            case 11:{

            }break;
            }

    }while(opc!=13);
        system("pause>>cls");
    return 0;
}
