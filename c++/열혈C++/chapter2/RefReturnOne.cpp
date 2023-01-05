#include <iostream>
using namespace std;

int &RefRetFuncOne(int &ref)// int &ref = num1;
{
    ref++;
    return ref;// ref
}

int main(void)
{
    int num1  = 1;
    int &number = num1;// number, num1 is 1 with same address
    int &a = number;
    int num2 = RefRetFuncOne(num1); 

    num1++; 
    num2 += 100;
    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;


    return 0;
}