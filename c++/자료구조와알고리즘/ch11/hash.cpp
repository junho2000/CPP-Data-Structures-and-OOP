#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class hash_set
{
private:
    int sz; // size
    vector<int> data;
public:
    hash_set(int n) : sz(n), data(sz, -1) {}
    int hash(int key) { return key % sz; }
    void insert(int value) { data[hash(value)] = value; }
    bool find(int value) { return data[hash(value)] == value; }
    void erase(int value) { data[hash(value)] = -1; }
    void print()
    {
        for(auto a : data)
            cout<<a<<", ";
        cout<<endl;
    }
};

int main()
{
    hash_set num_set(7); // -1 -1 -1 -1 -1 -1 -1
    num_set.insert(10); // 3
    num_set.insert(15); // 1
    num_set.insert(20); // 6
    num_set.insert(100); // 2
    num_set.print();

    int value = 10;
    if(num_set.find(value))
        cout<<value<<" is found!"<<endl;
    else
        cout<<value<<" is not found!"<<endl;

    num_set.insert(2); //충돌..!! -> chaining으로 해결
    num_set.print();

    int value1 = 100;
    if(num_set.find(value1))
        cout<<value<<" is found!"<<endl;
    else
        cout<<value<<" is not found!"<<endl;

    return 0;
}