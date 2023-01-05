#include<iostream>
#include<forward_list> //linked_list
using namespace std;

int main()
{
    forward_list<int> l1 {10,20,30,40};
    l1.push_front(40);
    l1.push_front(30);

    for(auto i : l1)
        cout<<i<<", ";
    cout<<endl;

    int cnt = distance(l1.begin(), l1.end()); //size() 지원 안함.
    cout<<cnt<<endl;
    
    l1.remove(40); //40값을 가지는 모든 노드를 삭제
    for(auto i : l1)
        cout<<i<<", ";
    cout<<endl;
    
    l1.remove_if([](int n) { return n > 20; }); //람다 함수로 조건을 줄수 있음.
    for(auto i : l1)
        cout<<i<<", ";
    cout<<endl;
    

    

    return 0;
}
