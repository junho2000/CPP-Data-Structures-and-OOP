#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int data[] = {1, 2, 3, 5, 7, 10, 13, 15, 18, 23, 25, 27, 28, 30, 33};
    int target = 23;

    bool res = binary_search(begin(data), end(data), target); //반복자 형식으로 처음과 끝 지정

    cout<<res<<endl;

    return 0;   
}