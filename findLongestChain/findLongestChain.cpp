class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        int n = pairs.size();
        vector<int> dp(n, 1);     //dp[i]以i结尾
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        for (int i = 0;i < n;i++)
            for (int j = 0;j < i;j++)
            {
                if (pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        return *max_element(dp.begin(), dp.end());
    }
};
