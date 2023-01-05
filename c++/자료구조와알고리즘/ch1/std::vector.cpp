#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iterator>
//#include <algorithm>
using namespace std;

void print_vector(vector<int> vec)
{
    for(auto a : vec)
        cout<<a<<" ";
    cout<<endl;
}
int main()
{
    vector<int> v {1,2,3,4,5};
    vector<int> v1;
    v1.assign(5, 2); // assign( size , value )
    cout<<v.at(3)<<endl; // 유효한 인덱스인지 확인 []연산보다 살짝 느림
    cout<<v.front()<<" "<<v.back()<<endl; //front, back 첫번째 원소와 마지막 원소 출력
    print_vector(v1);
    print_vector(v);
    v1.clear(); // capacity 는 그대로 size만 줄임
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    
    vector<int>::iterator itr = v.begin(); //begin() 첫번째 원소를 가리키는 반복자 반환
    for(;itr != v.end(); itr++) //end() 마지막 원소 다음을 가리키는 반복자 반환
        cout<<*itr<<" ";
    cout<<endl;
    
    vector<int> v2 {0,1,2,3,4,5,6,7,8,9};
    v2.push_back(10);
    v2.pop_back();
    print_vector(v2);
    v2.insert(v2.begin()+3, 10); //v2.begin() + 3 = 0 + 3 = 3, 3번 인덱스 원소 앞에 삽입 그리고 해당 위치를 가리키는 반복자 반환
    print_vector(v2);
    v2.erase(--v2.end()); //erase 반복자가 가리키는 원소 삭제
    print_vector(v2);
    
    vector<int> v3 {0,1,2,3,4,5,6,7,8,9};
    print_vector(v3);
    vector<int>::reverse_iterator riter; //vector<T>::reverse_iterator
    for(riter = v3.rbegin(); riter != v3.rend(); riter++)
        cout<<*riter<<" ";
    cout<<endl;
    
    cout<<"vector size :"<<v3.size()<<"\nvector capacity :"<<v3.capacity()<<endl;
    v3.resize(5); // resize(size) 사이즈 조절을 하는데 공간이 넘치면 0 대입 부족하면 짜름.
    v3.resize(10,1); // resize(size, value)
    print_vector(v3);
    
    vector<int> a {1,2,3,4,5};
    vector<int> b {5,4,3,2,1};
    a.swap(b); //swap vector a and b
    print_vector(a);
    print_vector(b);
    cout<<a.empty()<<" "; a.clear(); cout<<a.empty()<<endl;
    
    cout<<a.capacity()<<" ";
    a.shrink_to_fit(); // capacity를 실제 vector의 size에 맞춤
    cout<<a.capacity()<<endl;
    
    vector<vector<int>> tdim(3,vector<int>(5,1));
    for(auto a : tdim)
    {
        for(auto b : a)
                    cout<<b<<" ";
        cout<<endl;
    }
    
    //#include <algorithm>
    //unique(itr, itr) 중복된 원소를 지우기 위해서는 미리 정렬을 해둬야 한다.
    vector<int> c = { 1, 3, 2, 1, 8, 3, 5, 2, 6, 5, 8 };
    sort(c.begin(), c.end());
    print_vector(c);
    c.erase(unique(c.begin(), c.end()), c.end()); //unique함수를 수행하고 나면 중복되지 않은 원소들만 담은 vector의 끝 iterator가 반환
//    c.resize(unique(c.begin(), c.end()) - c.begin());
    print_vector(c);
    
    //pair
    vector<pair<int,int>> pv;
    pv.push_back(make_pair(12, 3));
    pv.push_back({3,4});
    for(auto a : pv)
        cout<<a.first<<" : "<<a.second<<endl;
    
    return 0;
}
