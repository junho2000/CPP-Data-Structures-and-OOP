#include <iostream>

using namespace std;

namespace AAA
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        }
    }
}

int val = 100;//global variable

int main(void)
{
    int val = 30;//local variable
    val+=3; //전역변수가 지역변수한테 가려짐
    ::val+=7;
    cout<<val<<" "<<::val<<endl;

    int num = 0;
    cout<<"Hello World"<<endl;
    cout<<"Hello"<<"World!"<<endl;
    cout<<num<<' '<<'A';
    cout<<' '<<3.14<<endl;

    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num1 = 30;

    namespace ABC=AAA::BBB::CCC; //namespace 별칭지정 

    cout<<ABC::num1<<endl;
    cout<<ABC::num2<<endl;

    return 0;
}