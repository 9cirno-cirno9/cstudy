class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        int** dp;
        dp = new int* [n];
        for (int r = 0;r < n;r++)
            dp[r] = new int[n]();
        dp[n - 1][n - 1] = 1;
        for (int i = n - 2;i >= 0;i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1;j < n;j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
        for (int v = 0;v < n;v++)
            delete[]dp[v];
        delete[]dp;
    }
};