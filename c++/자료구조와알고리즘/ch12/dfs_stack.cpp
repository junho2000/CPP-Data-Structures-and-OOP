#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> dfs(const vector<vector<int>>& adj_list, int s) // s = start point
{
    vector<bool> visited(adj_list.size(), false);
    vector<int> visited_order;

    stack<int> stk;
    stk.push(s);

    while (!stk.empty())
    {
        int v = stk.top();
        stk.pop();

        if(visited[v]) continue;
        visited[v] = true;
        visited_order.push_back(v); // 실행하고 싶은 문장

        for(int a : adj_list[v])
            if(!visited[a])
                stk.push(a);
    }
    return visited_order;
}

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

    for(auto a : dfs(adj_list, 0))
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
