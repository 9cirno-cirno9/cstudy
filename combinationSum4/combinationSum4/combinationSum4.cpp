class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 0;t <= target;t++)
        {
            for (int k = 0;k < n;k++)
            {
                int num = nums[k];
                if (t >= num)
                    dp[t] += dp[t - num];
            }
        }
        return dp[target];
    }
};