#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print_vector(const vector<int> vec)
{
    for(int v : vec)
        cout<<v<<" ";
    cout<<endl;
}
void permutation(vector<int> &vec, int k) // permutation .. 모든 원소를 서로 다른 원소로 출력하는 방법의 수
{
    if (vec.size() - 1 == k) {
        print_vector(vec);
        return;
    }
    for (int i = k; i < vec.size(); i++) {
        swap(vec[k], vec[i]);
        permutation(vec, k + 1);
        swap(vec[k], vec[i]);
    }
}
void hanoi(int n, int from, int to, int by)//tower of hanoi
{
    if(n==1)
        cout<<from<<"->"<<to<<endl;
    else
    {
        hanoi(n-1, from, by, to);
        cout<<from<<"->"<<to<<endl;
        hanoi(n-1, by ,to , from);
    }
}
int main()
{
    vector<int> vec {1,2,3,4};
    permutation(vec,0);

    sort(vec.begin(),vec.end());
    do{
        print_vector(vec);
    }while(next_permutation(vec.begin(), vec.end())); //오름차순 되었을 때 false 리턴, vec을 바꿈

    hanoi(2,1,3,2); //2개의 원판, 기둥 1 2 3, 1에서 출발 쌓을 곳은 3 2를 거쳐

    return 0;
}
