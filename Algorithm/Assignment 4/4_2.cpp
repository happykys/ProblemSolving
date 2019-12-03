#include <iostream>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n;
    int cost[10004];
    int dp[21];
    cin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> cost[i];
    }

    dp[0] = 0;
    dp[1] = cost[1];
    dp[2] = dp[1] + cost[2];
    dp[3] = cost[3];
    dp[4] = cost[4];

    for(int i = 5 ; i <= n ; i++)
    {
        dp[i] = min(dp[i-1], min(dp[i-3], dp[i-4])) + cost[i];
    }

    cout << dp[n];
    return 0;
}
