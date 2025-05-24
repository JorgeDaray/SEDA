#include <iostream>
#include <cmath>
#define TAMMAX 10
void menu();
using namespace std;

void Rendimiento_activos(){
float k = 0, p = 0, p1 = 0, c = 0;
char desicion;
int tiempo = 0;
cout << "Introduce el precio del activo en el momento t: " <<endl;cin >> p;
cout << "Introduce el precio del activo en el momento t-1: " <<endl;cin >> p1;
cout << "Introduce el flujo de efectivo de la inversion en el periodo: " <<endl;cin >> c;
cout << "Introduce los meses o los años del retorno : " <<endl;cin >> tiempo;
cout << "el programa es en meses o en años m/a : " <<endl;cin >> desicion;

if (desicion == 'a' || desicion == 'A'){
    k = ((p - p1 + c)/ p1);
    cout << "precio del activo en el momento t: " << p << endl;
    cout << "precio del activo en el momento t-1: " << p1 <<endl;
    cout << "flujo de efectivo de la inversion en el periodo: " << c <<endl;
    k = k * 100;
    cout << "Tasa de rendimiento esperada al 1er año es : %" << k << endl;
    k = ((p - p1 + (c/12))/ p1);
    k = k * 100;
    cout << "Tasa de rendimiento esperada al 1er mes es : %" << k << endl;
    k = (p + (c * tiempo))/p1;
    k = k * 100;
    cout << "Tasa de rendimiento esperada en "<< tiempo << " años es : %" << k << endl;
    k = k/tiempo;
    cout << "Tasa de rendimiento esperada al año es : %" << k << endl;
    k = k/12;
    cout << "Tasa de rendimiento esperada al mes es : %" << k << endl;
}else if (desicion == 'm' or desicion == 'M'){
    k = ((p - p1 + c)/ p1);
    cout << "precio del activo en el momento t: " << p << endl;
    cout << "precio del activo en el momento t-1: " << p1 <<endl;
    cout << "flujo de efectivo de la inversion en el periodo: " << c <<endl;
    k = k * 100;
    cout << "Tasa de rendimiento esperada al 1er mes es : %" << k << endl;
    k = ((p - p1 + (c*12))/ p1);
    k = k * 100;
    cout << "Tasa de rendimiento esperada al 1er año es : %" << k << endl;
    k = (p + (c * tiempo))/p1;
    k = k * 100;
    cout << "Tasa de rendimiento esperada en "<< tiempo << " meses es : %" << k << endl;
    k = k/tiempo;
    cout << "Tasa de rendimiento esperada al mes es : %" << k << endl;
    k = k*12;
    cout << "Tasa de rendimiento esperada al año es : %" << k << endl;
}else {
    cout << "opcion invalida" << endl;
}
}

void valuacion_acciones(){
    int opc = 0;
    cout << "1) modelo crecimiento cero"<< endl;
    cout << "2) modelo crecimiento constante"<< endl;
    cout << "3) modelo crecimiento no constante"<< endl;
cout << " Escoje una opcion : "<<endl; cin>>opc;
	switch(opc){
		case 1:{
		  float  p0 = 0, d0 =0, ren = 0;
		  float r = 0, k = 0;
		  cout << " Introduzca el precio actual de la accion :"<<endl;cin>>p0;
		  cout << "Introduzca el dividendo preferente por accion :"<<endl;cin>>d0;
		  cout << "Introduzca el dividendo requerido por accion :"<<endl;cin>>ren;
		  r = p0 * (d0 / 100);
		  k = r/(ren/100);
		  cout << "El precio justo del mercado es :"<<k<<endl;
		}
        break;
        case 2:{
             float d1 = 0, k = 0, g = 0;
             float p0 = 0;
            cout << "Introduzca el dividendo esperado el proximo año :"<<endl;cin>>d1;
            cout << " Introduzca el rendimiento requerido por accion comun :"<<endl;cin>>k;
            cout << "Introduzca la tasa de rendimiento constante :"<<endl;cin>>g;
            p0 = (d1*(1+g/100))/((k/100)-(g/100));
            cout << "El precio justo del mercado es :"<<p0<<endl;
        }break;

        case 3:{
            float dt = 0, ks = 0, dt1 = 0;
            int n = 0;
            float p0 = 0, rp = 0;
            cout << "Introduzca el dividendo mas reciente declarado :"<<endl;cin>>dt;
            cout << "Introduzca el rendimiento requerido por accion comun :"<<endl;cin>>ks;
            cout << "Introduzca el numero de años que dura el crecimiento no constante :"<<endl;cin>>n;
            float c[n];
            for (int i = 0; i < n; i++){
                cout << "Ingrese el rendimiento del año "<<i+1<< " : "<<endl;
                cin >>c[i];
                dt1 = dt*(c[i]/100);
                dt = dt + dt1;
                cout << "rendimiento del año "<<i+1<< " : "<<c[i]<<endl;
                cout << "dividendo esperado: "<<dt<<endl;
                if (i+1 != n){
                    rp = dt /std::pow((1 + (ks/100)),i+1);
                    p0 = p0 + rp;
                    cout << "El precio justo del mercado es :"<<p0<<endl;
                }
                else{
                    rp = dt / ((ks/100) - (c[i]/100)) * 1 / std::pow((1 + (ks/100)),i);
                    cout << "Rp :"<<rp<<endl;
                    cout << "i :"<<i<<endl;
                    p0 = p0 + rp;
                }
            }
            cout << "El precio justo del mercado es :"<<p0<<endl;
            }
        break;
        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}

void valuacion_bonos(){
    int opc = 0;
    cout << "1) Con servicio de interes"<< endl;
    cout << "2) Capitalizacion de intereses"<< endl;
    cout << "3) Rembolso sobre par con primas"<< endl;
    cout << "3) Rembolso sobre par con primas"<< endl;
    cout << " Escoje una opcion : "<<endl; cin>>opc;
	switch(opc){
		case 1:{
            float ve = 0, r = 0, t = 0, t1 = 0, precio_bono = 0, cupones = 0;
            int n = 0, bonos = 0;
            cout << "Ingresa los bonos : "<<endl; cin>>bonos;
            cout << "Ingresa el precio de los bonos : "<<endl; cin >> precio_bono;
            cout << "Ingresa los cupones :"<<endl; cin >> cupones;
            cout << "Ingresa la tasa vigente del mercado: "<<endl; cin >> t1;
            cout << "Ingresa los años para reembolso :"<<endl; cin >> n;
            if (t1 == 0){
                r = bonos * precio_bono;
                t = cupones/precio_bono;
                ve = ((r*t)*(1-pow((1+t),-n))/t) + (r/pow((1+t),n));
                cout << "Valor de emision :"<<ve<<endl;
            }
            else {
                r = bonos * precio_bono;
                t = cupones/precio_bono;
                t1 = t1/100;
                ve = ((r*t)*(1-pow((1+t1),-n))/t1) + (r/pow((1+t1),n));
                cout << "Valor de emision :"<<ve<<endl;
            }
        }break;
        case 2:{
            float ve = 0, r = 0, t = 0, t1 = 0, precio_bono = 0, cupones = 0;
            float pago = 0, diferencia = 0;
            int n = 0, bonos = 0;
            cout << "Ingresa los bonos : "<<endl; cin>>bonos;
            cout << "Ingresa el precio de los bonos : "<<endl; cin >> precio_bono;
            cout << "Ingresa los cupones :"<<endl; cin >> cupones;
            cout << "Ingresa la tasa vigente del mercado: "<<endl; cin >> t1;
            cout << "Ingresa los años para reembolso :"<<endl; cin >> n;
            if (t1 == 0){
                r = bonos * precio_bono;
                t = cupones/precio_bono;
                ve = ((r*t)*(1-pow((1+t),-n))/t) + (r/pow((1+t),n));
                cout << "Valor de emision :"<<ve<<endl;
            }
            else {
                r = bonos * precio_bono;
                t = cupones/precio_bono;
                t1 = t1/100;
                ve = ((r*t)*(1-pow((1+t1),-n))/t1) + (r/pow((1+t1),n));
                cout << "Valor de emision :"<<ve<<endl;
            }
            diferencia = r - ve;
            pago = (t1-t)*r;
            float s[n], ta[n], a[n];
            for (int i = 0; i < n; i++){
                if (i == 0){
                    s[i] = diferencia - a[i-1];
                    ta[i] = s[i] * t1;
                    a[i] = pago - ta[i];
                }
                else{
                    s[i] = s[i-1] - a[i-1];
                    ta[i] = s[i] * t1;
                    a[i] = pago - ta[i];
                }
                cout << "rendimiento del año "<<i+1<< " | ";
                cout << "| Saldo vencido: "<<s[i]<<"| Tasa de interes: "<<ta[i];
                cout << "| Amortizacion: "<<a[i]<<"| Pago: "<<pago<<endl;
            }
        }break;

        case 3:{

        break;
        }
        case 4:{

        break;
        }
        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}

void VPN()
{
            float inversion_inicial = 0, in_i = 0, Valor_PN = 0, vpn = 0, costo_oportunidad_empresa = 0;
            int n = 0;
            cout << "Introduzca la inversion inicial :"<<endl;cin>>inversion_inicial;
            cout << "Introduzca el costo de oportunidad de la empresa :"<<endl;cin>>costo_oportunidad_empresa;
            cout << "Introduzca el numero de años de flujos que tendra :"<<endl;cin>>n;
            costo_oportunidad_empresa = costo_oportunidad_empresa / 100;
            float c[n];
            for (int i = 0; i < n; i++){
                cout << "Ingrese el flujo del año "<<i+1<< " : "<<endl;
                cin >>c[i];
                cout <<"costo_oportunidad_empresa: "<<costo_oportunidad_empresa<<endl;
                vpn = c[i] / pow(1.0 + costo_oportunidad_empresa, i+1);
                cout << " VPN del año "<<i+1<< " = "<<vpn<<endl;
                Valor_PN = Valor_PN + vpn;
            }
            in_i = in_i - inversion_inicial;
            inversion_inicial = in_i + Valor_PN;
            cout << "El VPN final es de :"<<inversion_inicial<<endl;
}

void ROI()
{
    float valor_final = 0, valor_inicial = 0, ir = 0;
        cout << "Introduzca el valor inicial de la inversion :"<<endl;cin>>valor_inicial;
        cout << "Introduzca el valor final de la inversion :"<<endl;cin>>valor_final;
        ir = (valor_final - valor_inicial) / valor_inicial * 100;
        cout << "ROI :"<<ir<<endl;
}

int main()
{
    int opc=0;
    do{
   	system("cls");
   	 menu();
    cout<<"Continuar 1 salir 9:"<<endl;cin>>opc;
   }while(opc!=9);
    system("pause>>cls");
    return 0;
}

void menu_examen2()
{
    int opc=0;
	cout<<"**\tEJERCICIOS DIFERENTES\t****"<<endl;
	cout<<"1) VPN Valor Presente Neto"<<endl;
	cout<<"2) ROI Indice de rentabilidad "<<endl;
	cout<<"9) Salir"<<endl;
    cout<<"Seleccione opcion:"<<endl;
    cin>>opc;
	switch(opc){

		case 1:{
		    VPN();
		}break;
        case 2:{
           ROI();
        }break;
        case 3:{
            //valuacion_bonos();
        }break;
        case 4:{

        }break;
        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}

void menu(){
int opc=0;
	cout<<"**\tTASA DE RENDIMIENTOS\t****"<<endl;
	cout<<"1) Rendimiento de activos"<<endl;
	cout<<"2) Valuacion de acciones"<<endl;
	cout<<"3) Valuacion de bonos"<<endl;
	cout<<"4) Ejercicios diferentes menu"<<endl;
	cout<<"9) Salir"<<endl;
    cout<<"Seleccione opcion:"<<endl;
    cin>>opc;
	switch(opc){

		case 1:{
		    Rendimiento_activos();
		}break;
        case 2:{
            valuacion_acciones();
        }break;
        case 3:{
            valuacion_bonos();
        }break;
        case 4:{
            menu_examen2();
        }break;
        default:
            cout<<"La opcion: "<<opc<<"No existe"<<endl;
	}
}
