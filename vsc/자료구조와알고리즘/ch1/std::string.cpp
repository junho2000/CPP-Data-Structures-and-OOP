#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    
    //문자열 입력 받기
    string str;
    //cin>>str; // 공백 이전까지의 문자열을 받음.
    //getline(cin,str); // \n 이전까지의 문자열을 받음.
    //getline(cin,str,'A'); // 'A' 이전까지의 문자열을 받음. A가 \n으로 되면 getline(cin,str);
    
    for(auto a : str)
        cout<<a;
    cout<<endl;
    
    //string 선언
    string st1 = "string!";
    string st2; st2 = "string!";
    string st3("string!");
    string st4(st3);
    char s[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    string st5(s);
    string* st6 = new string("string!");
    delete st6;
    
    //string class operator < > == +....
    cout<<st1 + st2<<endl;
    
    //string member function
    // idex, size...
    cout<<st1.at(1)<<st1[1]<<endl;// at(idx) index 위치의 문자 반환. 유효한 범위인지 체크 O, [] index 위치의 문자 반환
    cout<<st1.front()<<st1.back()<<endl; //front(), back() 문자열의 첫번째와 마지막 번째 문자 반환
    cout<<st1.length()<<st1.size()<<endl; // length(), size() 모두 문자열의 크기 반환 서로 같음.
    st1.resize(5); st1.resize(8, '!'); //resize(size, char)
    cout<<st1<<endl;
    cout<<st1.empty()<<endl; // empty() 문자열이 비여있으면 1 반환
    
    //insert, erase....
    st1.insert(1,st2); // insert(idx , string) index 앞에 문자열을 삽입함.
    cout<<st1<<endl;
    st1.replace(1,2,st2); // replace(idx, n, string) index부터 n개의 문자를 문자열로 대체함
    cout<<st1<<endl;
    st1.clear(); // clear() 저장된 문자열을 모두 지움, st1.erase()랑 같음
    cout<<"capacity: "<<st1.capacity()<<"\nsize: "<<st1.size()<<"\nlength: "<<st1.length()<<endl;;
    cout<<st1.empty()<<endl;
    st1.shrink_to_fit();
    cout<<"capacity: "<<st1.capacity()<<"\nsize: "<<st1.size()<<"\nlength: "<<st1.length()<<endl;;
    
    st1 = "string!";
    st1.erase(st1.begin(), st1.end()); //erase(itr1, itr2) iterator를 이용해 itr1 ~ itr2 까지 지움.
    st1.erase(0,st1.size()); // erase(idx ,n) idx부터 n개를 지움
    st1.push_back('!');
    st1.pop_back();
    cout<<st1<<endl;
    
    //기타 유용한 멤버 함수
    st1 = "string!";
    cout<<st1.find("ring")<<endl; //find(string) string이 st1에 포함되어있는지를 확인. 찾으면 해당 부분의 첫번째 index를 반환
    string a = "hello";
    string b = "world";
    swap(a,b); // swap(string, string)
    cout<<a<<" "<<b<<endl;
    a.compare(b); // str.compare(st2) str과 str2가 같은지를 비교. 같다면 0, str<str2 인 경우 음수, str>str2 인 경우 양수를 반환
    cout<<a.substr(2)<<" "<<a.substr(1,2)<<endl; //substr(idx, n) idx부터 n개의 문자를 반환 n이 없으면 전체 반환
    
    return 0;
}
