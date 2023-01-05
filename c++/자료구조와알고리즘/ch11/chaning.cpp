#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

class hash_set
{
private:
    int sz; // size
    vector<list<int>> data; //vector<list<pair<string, int>>> data; key, data
    
public:
    hash_set(int n) : sz(n), data(sz) {}
    int hash(int key) { return key % sz; }
    void insert(int value) { data[hash(value)].push_back(value); }
    bool find(int value)
    {
        auto& entries = data[hash(value)];
        return std::find(entries.begin(), entries.end(), value) != entries.end(); //왜 굳이 std::find라고 하는건지?
    }
    void erase(int value)
    {
        auto& entries = data[hash(value)];
        auto itr = std::find(entries.begin(), entries.end(), value);
        if(itr != entries.end())
            entries.erase(itr);
    }
    void print()
    {
        for (int i = 0; i < sz; i++)
        {
            cout << i << ": ";
            for (auto n : data[i])
            {
                cout << n << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    hash_set num_set(7); // -1 -1 -1 -1 -1 -1 -1
    num_set.insert(10); // 3
    num_set.insert(15); // 1
    num_set.insert(20); // 6
    num_set.insert(100); // 2


    int value = 10;
    if(num_set.find(value))
        cout<<value<<" is found!"<<endl;
    else
        cout<<value<<" is not found!"<<endl;

    num_set.insert(2); //충돌..!! -> chaining으로 해결
    int value1 = 100;
    if(num_set.find(value1))
        cout<<value1<<" is found!"<<endl;
    else
        cout<<value1<<" is not found!"<<endl;
    
    num_set.print();

    return 0;
}
