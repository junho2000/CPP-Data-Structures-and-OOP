//shift + option + F -> set code standard coding convention
// 반복자는 컨테이너 객체에서 범위의 첫 번째 원소를 가리키는 begin반복자와 마지막 원소를 가리키는 end반복자로 
// begin()과 end()멤버 함수를 호출해서 지정한 원소들을 얻어 범위를 표현.
// begin()은 첫 번째 원소, end()는 마지막 원소를 하나 더 지나친 위치를 가리키는 반복자를 반환.
// 컨테이너에 있는 원소들 전체를 표현할 때 end()멤버가 반환하는 end반복자는 어떤 원소도 가리키지 않으므로 역참조하거나 증가시킬 수 없다.
// 배열, 컨테이너 또는 문자열 객체의 const반복자를 반환하는 전역 함수로 cbegin()과 cend()가 있다.
// const 반복자는 변경되지 말아야 할 객체를 가리키지만, 반복자 자체는 바꿀 수 있다. 

#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main()
{
    vector<int>::iterator itr;
    vector<int>::const_iterator citr; //반복자가 가리키는 원소의 값을 변경하지 못한다.

    vector<int> v1 {1,2,3,4};
    itr = v1.begin() + 2;
    cout<< *itr <<endl; //원소의 세번째 값 리턴

    itr = v1.begin(); //초기화

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    vector<int> v2;
    for(int i = 0; i < 10; i++)
        v2.push_back(i);

    itr = v2.begin();

    while(itr != v2.end()) // while 문 사용
    { 
        cout<< *itr <<" "; 
        itr++;
    }
    cout<<endl;

    for(auto itr = v2.begin(); itr != v2.end(); itr++) //for문 사용
        cout<< *itr <<" ";
    cout<<endl;

    for(auto& itr : v2)
        cout<<itr<<" ";
    cout<<endl;
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


    


    

    return 0;
}