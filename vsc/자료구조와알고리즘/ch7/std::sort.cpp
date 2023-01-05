#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
//sort(iter, iter, way), O(nlogn)

bool abs_cmp(const int a, const int b)
{
    return abs(a) < abs(b);
}
class AbsCmp
{
public:
    inline bool operator()(int a, int b) const
    {
        return abs(a) < abs(b);
    }
};
class Person
{
public:
    string name;
    int age;

    bool operator<(const Person& a) const
    {
        return this->age < a.age;
    }
    void print() const
    {
        cout<<name<<" : "<<age<<endl;
    }
};

int main()
{
    int arr[5] = {5, 3, 4, 1, 2};
    sort(arr, arr+5);
    sort(begin(arr), end(arr)); //기본 오름차순
    for(auto a : arr)
        cout<<a<<" ";
    cout<<endl;
    
    vector<int> vec1 {5,3,4,1,2};
    sort(vec1.begin(), vec1.end());
    for(auto a : vec1)
        cout<<a<<" ";
    cout<<endl;
    
    vector<string> vec2 {"orange", "banana", "apple", "lemon"};
    sort(vec2.begin(), vec2.end());
    for(auto a : vec2)
        cout<<a<<" ";
    cout<<endl;


    int arr2[5] = {5, 3, 4, 1, 2};
    sort(begin(arr2), end(arr2), greater<>()); // 내림차순
    for(auto a : arr2)
        cout<<a<<" ";
    cout<<endl;
    
    vector<string> vec3 {"orange", "banana", "apple", "lemon"};
//    sort(vec3.begin(), vec3.end(), greater<>());
    sort(vec3.begin(), vec3.end(), [](string a, string b){ return a > b; });
    for(auto a : vec3)
        cout<<a<<" ";
    cout<<endl;

    vector<int> nums = {10, 2, -3, 5, 7};
//    sort(nums.begin(), nums.end(), abs_cmp); //절대값이 큰 순서
//    sort(nums.begin(), nums.end(), AbsCmp()); //절대값이 큰 순서
    sort(nums.begin(), nums.end(), [](int a, int b){ return abs(a) < abs(b); }); //람다표현식


    vector<Person> v;
    v.push_back({"Amelia", 29});
    v.push_back({"Noah", 25});
    v.push_back({"Olivia", 31});
    v.push_back({"Sophia", 40});
    v.push_back({"George", 35});

    sort(v.begin(), v.end()); //bool operator<를 지정하지 않으면 오류
    for(const auto& p : v)
        p.print();

    return 0;
}
