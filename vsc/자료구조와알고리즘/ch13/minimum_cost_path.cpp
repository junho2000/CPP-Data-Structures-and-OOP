#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//dynamic programming tabulation type
// C(x,y) = min(C(x-1, y), C(x, y-1)) + m(x,y)

// C(x,y) = m(x,y)                                          if x = 1 and y =1
//        = C(x, y-1) + m(x,y)                              if x = 1
//        = C(x-1, y) + m(x,y)                              if y = 1
//        = min(C(x-1, y), C(x, y-1)) + (x,y)               else

int solution(vector<vector<int>> m)
{
    int rows = m.size();
    int cols = m[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for(int y = 0; y < rows; y++)
    {
        for(int x = 0; x < cols; x++)
        {
            if(x == 0 && y == 0) dp[y][x] = m[y][x];
            else if(y == 0) dp[y][x] = dp[y][x-1] + m[x][y];
            else if(x == 0) dp[y][x] = dp[y-1][x] + m[x][y];
            else dp[y][x] = min(dp[y-1][x], dp[y][x-1]) + m[y][x];
        }
    }
    return dp[rows-1][cols-1];
}

int main()
{
    vector<vector<int>> m = {
        {2,7,5,4},
        {5,3,6,8},
        {7,8,7,4},
        {8,1,9,5}
    };

    cout<<"Minimum cost is "<<solution(m)<<endl;
    return 0;
}