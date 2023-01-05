#include <iostream>

using namespace std;

bool IsPositive(int num)
{
    if(num > 0)
        return true;
    else 
        return false;
}

int main(void)
{
    bool isPos;
    int num;
    cout<<"input number: ";
    cin>>num;

    isPos = IsPositive(num);
    if(isPos)
    {
        cout<<"positive number"<<endl;
    }
    else
    {
        cout<<"negative number"<<endl;
    }

    return 0;
}