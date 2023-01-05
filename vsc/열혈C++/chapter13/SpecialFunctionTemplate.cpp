#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
T MAX(T a, T b)
{
    return a > b ? a : b ;
}
template<>
char* MAX(char* a, char* b)//char*형 템플릿 함수가 필요한 경우엔 별도로 만들지 말고 이걸 써라
{
    cout<<"char* MAX<char*>(char* a, char* b)"<<endl;
    return strlen(a) > strlen(b) ? a : b ;
}
template<>
const char* MAX(const char* a, const char* b)
{
    cout<<"const char* MAX<const char*>(const char* a, const char* b)"<<endl;
    return strcmp(a, b) > 0 ? a : b ;
}
int main(void)
{
    cout<<MAX(11,15)<<endl;
    cout<<MAX('T', 'Q')<<endl;
    cout<<MAX(3.5, 7.5)<<endl;
    cout<< MAX<const char*>("Simple", "Best") <<endl; //상수

    char str1[] = "Simple";
    char str2[] = "Best";
    cout<< MAX<char*>(str1, str2) <<endl; //변수

    return 0;
}