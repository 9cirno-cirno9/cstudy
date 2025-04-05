int uniquePaths(int m, int n)
{
    int dp[m][n];
    for (int p = 0;p <= m - 1;p++)
        dp[p][0] = 1;
    for (int a = 0;a <= n - 1;a++)
        dp[0][a] = 1;
    for (int f = 1;f <= m - 1;f++)
        for (int q = 1;q <= n - 1;q++)
        {
            dp[f][q] = dp[f - 1][q] + dp[f][q - 1];
        }
    return dp[m - 1][n - 1];
}