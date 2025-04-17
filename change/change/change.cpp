class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int m = amount;
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
        for (int p = 0;p <= n;p++)
            dp[p][0] = 1;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                if (coins[i - 1] <= j)
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
};