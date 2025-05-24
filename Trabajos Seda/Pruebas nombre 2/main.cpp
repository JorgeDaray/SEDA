#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {
int vactor[1];
int cve;
    int elector;
    srand(time(NULL));
    int g;
    for (int i=0;i<=20;i++){
    g=1;
    elector=1 + rand()%(1000-9999);
for (int d=0;d<=g;d++){
    if (elector==vactor[d]){
        g=g-g;
        i=i-1;
    }

    while ((g==1)&&(elector!=vactor[d])&&(d==i)){
        vactor[i]=elector;
        cout<<"precione cualquier tecla para continuar:"<<endl;
        cin>>cve;
        cout<<"Este e tu id:"<<vactor[i]<<endl;
    }
}
}

	return 0;
}



