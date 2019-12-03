#include <iostream>

using namespace std;

int main()
{
    int n;
    dp[21];
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    for(int i = 5 ; i <= n ; i++)
    {
        dp[i] = dp[i-1] + dp[i-3] + dp[i-4];
    }

    cout << dp[n];
    return 0;
}
