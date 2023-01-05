#include <iostream>

using namespace std;

int main(void)
{
    int num = 100;
    int &num1 = num;//reference declare
    
    num1 = 3047;
    cout<<"Val: "<<num<<endl;
    cout<<"Ref: "<<num1<<endl;

    cout<<"Val add: "<<&num<<endl;
    cout<<"Ref add: "<<&num1<<endl;


    return 0;
}