#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
    set<int> odds;
    odds.insert(1);
    odds.insert(7);
    odds.insert(5);
    odds.insert(3);
    odds.insert(9); //내부적으로는 오름차순으로 정렬된 상태

    for(auto n : odds)
        cout<<n<<" ";
    cout<<endl;

    set<int> odds {1,7,5,3,9};
    set<int,greater<>> evens {2,4,6,8}; //내림차순으로 정렬
    evens.insert(10);
    evens.insert(2); //중복되기 때문에 무시
    for(auto n : evens)
        cout<<n<<" ";
    cout<<endl; 

    if(evens.find(4) != evens.end()) //찾으면 해당위치의 반복자 반환, 찾지 못하면 end()에 해당하는 반복자 반환
        cout<<"4 is found!"<<endl;
    else
        cout<<"4 is not found!"<<endl;

    using psi = pair<string,int>; //first, second, 기본적으로 first로 정렬 후 같으면 second로 정렬
    set<psi> managers {{"Amelia", 29}, {"Noah", 25}, {"Olivia", 31}, {"Sophia", 40}}; //pair로 묶음
    managers.insert(make_pair("George", 35));

    psi person1 = {"Noah", 25};
    if(managers.find(person1) != managers.end())
        cout<<person1.first<<"is a manager!"<<endl;
    else
        cout<<person1.first<<"is not a manager!"<<endl;

    managers.erase({"Sophia", 40});
    managers.erase({"Noah", 25});
    for(const auto& a : managers)
        cout<<a.first<<"("<<a.second<<")"<<" ";
    cout<<endl;

    return 0;
}