class Solution {
public:
    int numSquares(int n)
    {
        int m = sqrt(n);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 99999));   //dp【i】【j】从前i个完全平方数找出等于j的最小
        for (int k = 0;k <= m;k++)
            dp[k][0] = 0;


        for (int i = 1;i <= m;i++)
            for (int j = 1;j <= n;j++)
            {
                if (j < i * i)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - i * i] + 1);
            }
        return dp[m][n];
    }
};