#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(const vector<vector<int>>& adj_list, int s) // s = start point
{
    vector<bool> visited(adj_list.size(), false);
    vector<int> visited_order;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if(visited[v]) continue;
        visited[v] = true;
        visited_order.push_back(v); // 실행하고 싶은 문장

        for(int a : adj_list[v])
            if(!visited[a])
                q.push(a);
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

    for(auto a : bfs(adj_list, 0))
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
