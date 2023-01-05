#include<iostream>
#include<list>
using namespace std;
//list(doubly linked list)를 사용해서 queue 구현

template <typename T>
class Queue
{
private:
    list<T> lst;
public:
    Queue() {}
    void enqueue(const T& a) { lst.push_back(a); }
    void dequeue() { lst.pop_front(); }
    const T& front() { return lst.front(); }

    bool empty() { return lst.empty(); }
    int size() {return lst.size(); }
};
int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();

    cout<<q.front()<<endl;
    q.enqueue(40);

    while(!q.empty())
    {
        auto& a = q.front();
        cout<<a<<", ";
        q.dequeue();
    }
    cout<<endl;

    return 0;
}