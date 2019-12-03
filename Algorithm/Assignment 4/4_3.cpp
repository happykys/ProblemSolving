#include <iostream>
#define maxValue 999999999

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, k;
    int stair[10004];
    int cost[10004];
    int dp[10004];

    cin >> n >> k;

    for(int i = 0 ; i < k ; i++) cin >> stair[i];
    for(int i = 1 ; i <= n ; i++) cin >> cost[i];

    cost[0] = 0;

    for(int i = 0 ; i <= n ; i++) dp[i] = 0;

    for(int i = 0 ; i < k ; i++)
    {
        dp[stair[i]] = cost[stair[i]];
    }


    for(int i = 1 ; i <= n ; i++)
    {
        if(dp[i] == 0)
        {
            int minValue = maxValue;
            for(int j = 0 ; j < k ; j++)
            {
                if(i > stair[j] && dp[i-stair[j]] > 0)
                {
                    minValue = min(minValue, dp[i-stair[j]]);
                }
            }
            if(minValue != maxValue) dp[i] = minValue + cost[i];
        }
    }

    if(dp[n] == 0) cout << -1;
    else cout << dp[n];

    return 0;
}
