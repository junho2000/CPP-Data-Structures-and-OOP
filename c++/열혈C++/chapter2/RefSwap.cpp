#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2)//함수 호출과 동시에 int &ref1 = val1, int &ref2 = val2
{
    //ref1, val1 is 100, ref2, val2 is 200
    int temp = 0;
    temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}
void SwapByAdd(int *p1, int *p2)
{
    int temp = 0;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(void)
{  
    int val1 = 100;
    int val2 = 200;
    cout<<val1<<"\n"<<val2<<endl;
    SwapByRef2(val1, val2);//val1 <-> val2
    cout<<val1<<"\n"<<val2<<endl;
    SwapByAdd(&val1, &val2);
    cout<<val1<<"\n"<<val2<<endl;

    return 0;
}