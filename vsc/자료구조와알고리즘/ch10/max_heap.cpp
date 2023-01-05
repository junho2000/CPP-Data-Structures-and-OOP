#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class MaxHeap
{
private:
    vector<int> vec;
    int parent(int i) { return i / 2; }
    int left(int i) { return i * 2; }
    int right(int i) { return i * 2 + 1; }
    void heapify_up(int i)
    {
        if(i>1 && vec[i] > vec[parent(i)]) //삽입한 노드가 루트 노드가 아니고 부모노드보다 큰 경우
        {
            swap(vec[i],vec[parent(i)]);
            heapify_up(parent(i));
        }
    }
    void heapify_down(int i)
    {
        int largest = i;
        if(left(i) < vec.size() && vec[largest] < vec[left(i)]) //왼쪽 자식노드가 존재하고 왼쪽 자식노드가 부모노드보다 큰 경우
            largest = left(i);
        if(right(i) < vec.size() && vec[largest] < vec[right(i)]) //오른쪽 자식노드가 존재하고 오른쪽 자식노드가 위에서 비교한 노드보다 큰 경우
            largest = right(i);
        if(largest != i) //자식노드가 하나라도 부모노드보단 큰 경우
        {
            swap(vec[i],vec[largest]);
            heapify_down(largest);
        }
    }
public:
    MaxHeap() : vec(1) {}
    void push(int value)
    {
        vec.push_back(value); //원소 삽입
        heapify_up(vec.size() - 1); //원소 인덱스
    }
    void pop()
    {
        vec[1] = vec.back();
        vec.pop_back();
        heapify_down(1);
    }
    int top() const { return vec[1]; }
    int size() { return vec.size() - 1; }
    bool empty() { return vec.size() == 1; }
    void print()
    {
        for(auto a : vec)
            cout<<a<<" ";
        cout<<endl;
    }
};
int main()
{
    MaxHeap heap;
    heap.push(10);
    heap.push(5);
    heap.push(15);
    heap.push(7);
    heap.push(3);
    heap.push(9);
    heap.push(14);
    heap.push(8);
    heap.push(2);
    heap.push(4);
    heap.print();

    while(!heap.empty())
    {
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;

    return 0;
}