#include<iostream>
#include<queue>
using namespace std;
//list(doubly linked list)를 사용해서 queue 구현

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();

    cout<<q.front()<<endl;
    q.push(40);

    while(!q.empty())
    {
        auto& a = q.front();
        cout<<a<<", ";
        q.pop();
    }
    cout<<endl;

    return 0;
}