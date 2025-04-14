class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference)
    {
        int n = arr.size();
        vector<int> dp(n, 1);        //dp【i】以i结尾最长子序列
        for (int i = 1;i <= n - 1;i++)
            for (int j = 0;j < i;j++)
            {
                if (arr[i] - arr[j] == difference)
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
        return *max_element(dp.begin(), dp.end());
    }
};