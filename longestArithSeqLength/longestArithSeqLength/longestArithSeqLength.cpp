class Solution {
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        int leng = 1;
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        int x;

        for (int d = -m;d <= m;d++)
        {
            vector<int> dp(m + 1, 0);
            for (int i = 0;i <= n - 1;i++)
            {
                x = nums[i];
                if (0 <= x - d && x - d <= m)
                    dp[x] = dp[x - d] + 1;
                else
                    dp[x] = 1;
            }
            leng = max(leng, *max_element(dp.begin(), dp.end()));
        }
        return leng;
    }
};