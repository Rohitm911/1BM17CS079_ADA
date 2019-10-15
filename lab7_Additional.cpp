#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
        dp[i] = new int[n + 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[m - i] == s2[n - j])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(1 + dp[i - 1][j - 1],min(1 + dp[i][j - 1], 1 + dp[i - 1][j]));
        }
    }

    int ans = dp[m][n];
    for (int i = 0; i <= m; i++)
        delete[] dp[i];
    delete[] dp;
    return ans;
}
