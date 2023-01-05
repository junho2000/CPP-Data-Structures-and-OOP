#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 6;
bool gVisited[N] = {};

void dfs_recursion(const vector<vector<int>>& adj_list, int s)
{
    if(gVisited[s])
        return;

    gVisited[s] = true;
    cout<<s<<", ";//실행할 문장
    
    for(int a : adj_list[s])
        dfs_recursion(adj_list, a);
}
// s = 0 -> v = 1 3 4
// s = 1 -> v = 2 4
// s = 2 -> v = 0 5
// s = 5 -> v = 2
// s = 4 -> v = 0 1 3
// s = 3 -> v = 0 4 ...end

int main()
{
    //adjacency list 인접 리스트
    vector<vector<int>> adj_list = {
        {1,3,4},
        {0,2,4},
        {1,5},
        {0,4},
        {0,1,3},
        {2}
    };

    dfs_recursion(adj_list, 0);
    cout<<endl;
    return 0;
}