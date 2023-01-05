#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
//priority queue도 어짜피 데이터 정렬하는 건데 차이가 뭐지
template <typename T>
void print_queue(T q)
{
    while(!q.empty())
    {
        cout<<q.top()<<", ";
        q.pop();
    }
    cout<<endl;
}

class Student
{
public:
    string name;
    int score;

    bool operator< (const Student& st) const
    {
        return score < st.score;
    }
};


int main()
{   
    vector<int> vec {4,2,3,5,1};

    priority_queue<int> pq1; //정수값이 클수록 우선 순위가 높음
    for(auto n : vec)
        pq1.push(n);

    priority_queue<int, vector<int>, greater<int>> pq2(vec.begin(), vec.end()); //정수값이 작을수록 우선순위가 높음
    print_queue(pq2);

    priority_queue<Student> students;
    students.push({"Amelia", 80});
    students.push({"Noah", 40});
    students.push({"Olivia", 95});
    students.push({"Sophia", 75});

    while(!students.empty())
    {
        auto& s = students.top();
        cout<<s.name<<" ("<<s.score<<")"<<endl;
        students.pop();
    }

    return 0;
}