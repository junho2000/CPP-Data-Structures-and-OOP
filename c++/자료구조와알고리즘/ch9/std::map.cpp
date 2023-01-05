#include<iostream>
#include<map>
#include<string>
using namespace std;
//key value
int main()
{
    map<string,int> fruits; //key:string, value:int
    fruits.insert({"apple",1000});
    fruits.insert(make_pair("banana", 1500));//내부에서 자체적으로 정렬
    cout<<fruits["apple"]<<endl;
    fruits["orange"] = 3000; //초기화안하면 0으로 초기화
    fruits["grape"] = 4000;
    fruits["lemon"] = 5000;

    fruits["apple"] = 2000;
    fruits.erase("grape");

    for(const auto& a : fruits) //a의 type은 pair
        cout<<a.first<<" is "<<a.second<<" won."<<endl;
    
    for(auto [name, price] : fruits) //a의 type은 pair
        cout<<name<<" is "<<price<<" won."<<endl;


    return 0;
}