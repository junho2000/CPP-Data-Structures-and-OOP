#include <iostream>
using namespace std;

// int Adder(const int &num1, const int &num2)// const int &num1 = 3, const int &num2 = 4
// {
//     //num1 is 3, num2 is 4
//     return num1 + num2;
// }
// int JustAdder(int num1, int num2)
// {
//     return num1 + num2;
// }// 무슨 차이야..?

// int main(void)
// {
//     cout<<Adder(3,4)<<endl;
//     cout<<JustAdder(3,4)<<endl;
//     return 0;
// }
int main(void)
{
    const int num = 12;// num is 12
    const int *ptr = &num;// ptr -> num is 12
    const int *(rptr) = ptr;// ptr, rptr -> num is 12

    cout<<*ptr<<endl;
    cout<<*rptr<<endl;
    


    return 0;
}