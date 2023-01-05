#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int fibo1(int n)
{
    if(n<2)
        return n; //base condition

    return fibo1(n-1) + fibo1(n-2);
}

vector<int> memo(50, -1);
//memoization
int fibo2(int n)
{
    if(n<2)
        return n; //base condition

    if(memo[n] != -1)
        return memo[n];
    
    memo[n] = fibo2(n-2) + fibo2(n-1);

    return memo[n];
}
//tabulation
int fibo3(int n)
{
    vector<int> dp(n+1, 0);
    dp[1] = 1; //base condition

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[n];
}
int main()
{
    cout<<fibo1(10)<<endl;
    cout<<fibo2(10)<<endl;
    cout<<fibo3(10)<<endl;

    return 0;
}