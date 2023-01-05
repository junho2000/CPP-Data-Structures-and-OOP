#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

// class Calculator
// {
// private:
//         int AddCount;
//         int SubCount;
//         int DivCount;
//         int MulCount;
// public:
//         void Init(void);
//         float Add(float a, float b);
//         float Divide(float a, float b);
//         float Multiple(float a, float b);
//         float Subtract(float a, float b);
//         void ShowOpCount(void);
// };

// float Calculator::Add(float a, float b)
// {
//         AddCount++;
//         return a + b;
// }
// float Calculator::Divide(float a, float b)
// {
//         DivCount++;
//         return a / b;
// }
// float Calculator::Multiple(float a, float b)
// {
//         MulCount++;
//         return a * b;
// }
// float Calculator::Subtract(float a, float b)
// {
//         SubCount++;
//         return a - b;
// }
// void Calculator::Init(void)
// {
//         AddCount = 0;
//         SubCount = 0;
//         DivCount = 0;
//         MulCount = 0;
// }
// void Calculator::ShowOpCount(void)
// {
//         cout<<"덧셈: "<<AddCount;
//         cout<<" 뺄셈: "<<SubCount;
//         cout<<" 곱셈: "<<MulCount;
//         cout<<" 나눗셈: "<<DivCount<<endl;
// }


// int main(void)
// {
//         Calculator cal;
//         cal.Init();
//         cout << "3.2+2.4= " << cal.Add(3.2, 2.4) << endl;
//         cout << "3.5/1.7=" << cal.Divide(3.5, 1.7) << endl;
//         cout << "2.2-1.5=" << cal.Subtract(2.2, 1.5) << endl;
//         cout << "4.9/1.2=" << cal.Divide(4.9, 1.2) << endl;
//         cal.ShowOpCount();
//         return 0;
// }

class Printer
{
private:
        char arr[30];
public:
        void SetString(char *ptr);
        void ShowString(void);
};

void Printer::SetString(char *ptr)//클래스 안에 있는 함수
{
        strcpy(arr, ptr);
}
void Printer::ShowString(void)
{
        // printf("%s\n", arr);
        cout<<arr<<endl;
}

int main(void)
{
        Printer pnt;
        pnt.SetString("Hello world!");
        pnt.ShowString();
 
        pnt.SetString("I love C++");
        pnt.ShowString();
        return 0;
}