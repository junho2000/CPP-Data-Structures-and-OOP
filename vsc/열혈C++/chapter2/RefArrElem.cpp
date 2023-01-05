#include <iostream>
using namespace std;

int main(void)
{
    // int arr[3] = {1,3,5};
    // int &ref1 =arr[0];
    // int &ref2 =arr[1];
    // int &ref3 =arr[2];

    // cout<<ref1<<endl;
    // cout<<ref2<<endl;
    // cout<<ref3<<endl;


    //pointer도 reference 선언가능 
    int num = 20;
    int *ptr = &num;// ptr -> num
    int **dptr = &ptr;// dptr -> ptr -> num

    int &ref = num;// num, ref is 20
    int *(&pref) = ptr;// pref, ptr -> num
    int **(&dpref) = dptr;// dpref, dptr -> ptr -> num

    cout<<ref<<endl;
    cout<<*pref<<endl;
    cout<<**dpref<<endl;


    return 0;
}