#include <iostream>
using namespace std;
//1. add 1
//2. change sig

int AddOne(int &num)
{
    return num++;
}
int ChangeSig(int &ref)
{
    ref *= -1;
    return ref;
}

int main(void)
{
    int num = 0;
    int i = 0;
    cout<<"Pls input number: ";
    cin>>num;
    
    AddOne(num);
    cout<<num<<endl;
    
    ChangeSig(num);
    cout<<num<<endl;

    return 0;
}