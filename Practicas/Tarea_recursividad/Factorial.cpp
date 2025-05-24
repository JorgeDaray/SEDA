#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int fact(int);

int main(int argc, char *argv[])
{
    int n;
    if (argc < 2)
    {
        cout << "Introduzca numero: ";
        cin >> n;
    }
    else
        n = atoi(argv[1]);
    cout << "factorial: " << fact(n) << endl;
    system("pause");
}

int fact(int n)
{
    int val;
    if (n==1)
        return 1;
    else
        printf ("fac (%i)\n", n);
    val = fact(n-1)*n;
    return val;
}
