#include <iostream>
using namespace std;

int main(void)
{
    const int num =12;
    const int *ptr = &num;
    const int *(&rptr) = ptr;
    
    cout << "포인터의 변수의 값:" << *ptr << endl << "참조자의 값:" << *rptr << endl;

    return 0;
}


// int ConstAdder(const int &num1, const int &num2)
// {
//     return num1 + num2;
// }
// int Adder(int a, int b)
// {
//     return a + b;
// }

// int main(void)
// {
//     cout<<Adder(3,4)<<endl;
//     cout<<ConstAdder(3,4)<<endl;
//     return 0;
// }