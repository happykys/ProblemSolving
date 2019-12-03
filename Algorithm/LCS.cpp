#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    string dp[100][100];

    for(int i = 0 ; i < s1.length()+1 ; i++) dp[i][0] = "";
    for(int j = 0 ; j < s2.length()+1 ; j++) dp[0][j] = "";

    for(int i = 1 ; i < s1.length()+1 ; i++)
    {
        int i2 = i - 1;
        for(int j = 1 ; j < s2.length()+1 ; j++)
        {
            int j2 = j - 1;
            if(s1[i2] == s2[j2])
            {
                if(dp[i-1][j-1] == "x") dp[i][j] = s1[i2];
                else dp[i][j] = dp[i-1][j-1] + s1[i2];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    for(int i = 0 ; i < s2.length() ; i++)
    {
        cout << '\t' << s2[i];
    }
    cout << endl << "     ____";
    for(int i = 0 ; i < s2.length() ; i++)
    {
        cout << "________";
    }
    cout << endl;
    for(int i = 1 ; i < s1.length()+1 ; i++)
    {
        cout << s1[i-1] << "   |";
        for(int j = 1 ; j < s2.length()+1 ; j++)
        {
            if(dp[i][j].empty()) cout << '\t' << "X";
            else cout << '\t' << dp[i][j];
        }
        cout << endl;
    }
    // cout << dp[s1.length()][s2.length()];

    return 0;
}
