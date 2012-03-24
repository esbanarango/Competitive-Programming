#include<iostream>

using namespace std;

void factorial(int num);

int main()
{
    int num;
    
    cout<<"Entre el numero al que le desea calcular el factorial "<<endl;
    cin>>num;
    factorial(num);
    system("pause");
    
    return 0;
}

void factorial(int num)
{
     int numero=num;
     int contador=1;
     int acomulador=1;
     while(contador<numero)
     {
       contador=contador+1;
       acomulador=acomulador*contador;
       }
     cout<<"El factorial es: "<<acomulador<<endl;

     }
