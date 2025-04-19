class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        int n = coins.size();
        int coin;
        dp[0] = 0;
        for (int i = 0;i < n;i++)
        {
            coin = coins[i];
            for (int j = coin;j <= amount;j++)
            {
                if (dp[j - coin] != amount + 1)
                    dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
        if (dp[amount] == amount + 1)
            return -1;
        else
            return dp[amount];
    }
};


