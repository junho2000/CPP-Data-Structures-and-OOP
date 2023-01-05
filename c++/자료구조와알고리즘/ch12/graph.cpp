#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> get_adj_list(const vector<vector<int>>& mat)
{
    vector<vector<int>> adj_list(mat.size());

    for(int r = 0; r < mat.size(); r++)
    {
        for(int c = 0; c < mat[r].size(); c++)
            if(mat[r][c] == 1)
                adj_list[r].push_back(c);
    }
    return adj_list;
} 

int main()
{
    //adjacency matrix 인접 행렬
	vector<vector<int>> adj_matrix = {
		{0, 1, 0, 1, 1, 0},
		{1, 0, 1, 0, 1, 0},
		{0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0},
		{1, 1, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 0}
	};
    //adjacency list 인접 리스트
    // vector<vector<int>> adj_list = {
    //     {1,3,4},
    //     {0,2,4},
    //     {1,5},
    //     {0,4},
    //     {0,1,3},
    //     {2}
    // };

    vector<vector<int>> adj_list = get_adj_list(adj_matrix);
    for(const auto& a : adj_list)
    {
        for(const auto b : a)
            cout<<b<<", ";
        cout<<endl;
    }

	return 0;
}